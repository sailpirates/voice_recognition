/* file "FetchLowLevelPosixSockets.cpp" */

/* Copyright 2012-2016 SoundHound, Incorporated.  All rights reserved. */


#include "Fetch.h"
#include "GoldenRetrieverPosixSockets.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <vector>
#include <netinet/in.h>
#include "openssl/ssl.h"
#include "openssl/conf.h"
#include "openssl/err.h"
#include "openssl/engine.h"
#include "pthread.h"


static bool initialized = false;


class CleanupFetch
  {
  public:
    CleanupFetch(void)  { }
    ~CleanupFetch(void)
      {
        if (initialized)
          {
            CONF_modules_free();
            ERR_remove_state(0);
            ENGINE_cleanup();
            CONF_modules_unload(1);
            ERR_free_strings();
            EVP_cleanup();
            CRYPTO_cleanup_all_ex_data();
            sk_SSL_COMP_free(SSL_COMP_get_compression_methods());
            initialized = false;
          }
      }
  };
static CleanupFetch cleanup_fetch;


static int open_socket_with_timeout(struct addrinfo *address_info_list,
                                    double timeout_seconds);


static pthread_mutex_t catalog_lock = PTHREAD_MUTEX_INITIALIZER;


void Fetch::doPreHeader(const char *method)
  {
    if (!(fetches_are_enabled()))
      {
        fprintf(stderr,
                "ERROR: An attempt was made to hit an external API (URL %s) "
                "while such hits were disabled because %s.\n", url,
                fetch_disable_reason());
        exit(1);
      }

    size_t host_start;
    size_t host_length;
    unsigned port;
    size_t path_start;
    size_t path_length;
    bool is_ssl;
    bool is_script;
    parseURL(url, &host_start, &host_length, &port, &path_start, &path_length,
             &is_ssl, &is_script);

    class SocketWriter : public HTTPRawWriter
      {
      private:
        int socket_num;
        HTTPRawReader *reader;
        bool do_close;

      public:
        SocketWriter(int socket_num, HTTPRawReader *reader, bool do_close) :
                socket_num(socket_num), reader(reader), do_close(do_close)
          {
            assert(reader != NULL);
          }
        ~SocketWriter(void)
          {
            if (do_close)
                close(socket_num);
          }

        void write(const char *to_write)
          {
            write(to_write, strlen(to_write));
          }
        void write(const char *to_write, size_t byte_count)
          {
            ssize_t write_result = ::write(socket_num, to_write, byte_count);
            if (write_result != byte_count)
                throw "Socket write error.";
          }
        ssize_t read(char *buffer, size_t byte_count)
          {
            return reader->read_bytes(buffer, byte_count);
          }
      };

    if (is_script)
        throw "Scripts are not supported by this version of Golden Retriever.";

    if (getenv("GOLDEN_RETRIEVER_SHOW_REAL_URL_HITS") != NULL)
        fprintf(stderr, "Golden Retriever hitting `%s'.\n", url);

    struct addrinfo *address_info_list;
      {
        char save = url[host_start + host_length];
        url[host_start + host_length] = 0;
        struct addrinfo hints;
        memset(&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        int return_code = getaddrinfo(&(url[host_start]), NULL, &hints,
                                      &address_info_list);
        if (return_code != 0)
          {
            const char *message;
            switch (return_code)
              {
                case EAI_AGAIN:
                    message =
                            "The name could not be resolved at this time.  "
                            "Future attempts may succeed.";
                    break;
                case EAI_BADFLAGS:
                    message = "The flags parameter had an invalid value.";
                    break;
                case EAI_FAIL:
                    message =
                            "A non-recoverable error occurred when attempting "
                            "to resolve the name.";
                    break;
                case EAI_FAMILY:
                    message = "The address family was not recognized.";
                    break;
                case EAI_MEMORY:
                    message =
                            "There was a memory allocation failure when trying "
                            "to allocate storage for the return value.";
                    break;
                case EAI_NONAME:
                    message = "The host name does not resolve.";
                    break;
                case EAI_SERVICE:
                    message =
                            "The service passed was not recognized for the "
                            "specified socket type.";
                    break;
                case EAI_SOCKTYPE:
                    message = "The intended socket type was not recognized.";
                    break;
                case EAI_SYSTEM:
                    message = strerror(errno);
                    break;
                case EAI_OVERFLOW:
                    message = "An argument buffer overflowed.";
                default:
                    assert(false);
                    break;
              }
            error("Host name `%.*s' not found: %s.", (int)host_length,
                  &(url[host_start]), message);
          }
        url[host_start + host_length] = save;
      }

    int socket_num =
            open_socket_with_timeout(address_info_list, timeout_seconds);

    /* @@@ */
    ((struct sockaddr_in *)(address_info_list->ai_addr))->sin_port = htons(port);
    /* @@@ */
    int return_code = connect(socket_num, address_info_list->ai_addr,
                              address_info_list->ai_addrlen);
    if (return_code != 0)
      {
        freeaddrinfo(address_info_list);
        throw "Unable to connect.";
      }

    if (!is_ssl)
      {
        freeaddrinfo(address_info_list);

        reader = new HTTPSocketReader(socket_num);

        writer = new SocketWriter(socket_num, reader, false);

        return;
      }

    pthread_mutex_lock(&catalog_lock);

    if (!initialized)
      {
        SSL_library_init();
        initialized = true;
      }

    pthread_mutex_unlock(&catalog_lock);

    SSL_CTX *the_ctx = SSL_CTX_new(SSLv3_client_method());
    if (the_ctx == NULL)
      {
        freeaddrinfo(address_info_list);
        throw "Unable to create SSL CTX object.";
      }

    SSL *the_ssl = SSL_new(the_ctx);
    if (the_ssl == NULL)
      {
        SSL_CTX_free(the_ctx);
        freeaddrinfo(address_info_list);
        throw "Failed trying to create an SSL object";
      }

    int retcode = SSL_set_fd(the_ssl, socket_num);
    if (retcode != 1)
      {
        SSL_CTX_free(the_ctx);
        SSL_free(the_ssl);
        freeaddrinfo(address_info_list);
        throw "Failed trying to associate the SSL object with the stream.";
      }

    retcode = SSL_connect(the_ssl);
    if (retcode != 1)
      {
        SSL_CTX_free(the_ctx);
        SSL_free(the_ssl);
        close(socket_num);

        socket_num = open_socket_with_timeout(address_info_list,
                                              timeout_seconds);

        int return_code = connect(socket_num, address_info_list->ai_addr,
                                  address_info_list->ai_addrlen);
        freeaddrinfo(address_info_list);
        if (return_code != 0)
            throw "Unable to connect.";

        the_ctx = SSL_CTX_new(SSLv23_client_method());
        if (the_ctx == NULL)
            throw "Unable to create SSL CTX object.";

        the_ssl = SSL_new(the_ctx);
        if (the_ssl == NULL)
          {
            SSL_CTX_free(the_ctx);
            throw "Failed trying to create an SSL object";
          }

        int retcode = SSL_set_fd(the_ssl, socket_num);
        if (retcode != 1)
          {
            SSL_CTX_free(the_ctx);
            SSL_free(the_ssl);
            throw "Failed trying to associate the SSL object with the stream.";
          }

        retcode = SSL_connect(the_ssl);
        if (retcode != 1)
          {
            SSL_CTX_free(the_ctx);
            SSL_free(the_ssl);
            throw "SSL connection failed.";
          }
      }
    else
      {
        freeaddrinfo(address_info_list);
      }

    class SSLReader : public HTTPRawReader
      {
      private:
        SSL *the_ssl;
        SSL_CTX *the_ctx;
        int socket_num;
        std::vector<char> buffer;

      public:
        SSLReader(SSL *the_ssl, int socket_num, SSL_CTX *the_ctx) :
                the_ssl(the_ssl), socket_num(socket_num), the_ctx(the_ctx)
          {
            assert(the_ssl != NULL);
          }
        ~SSLReader(void)
          {
            SSL_CTX_free(the_ctx);
            SSL_free(the_ssl);
            close(socket_num);
          }

        char *readLine(void)
          {
            buffer.clear();
            while (true)
              {
                char local_buffer[1];
                ssize_t num = SSL_read(the_ssl, &(local_buffer[0]), 1);
                if (num != 1)
                    break;
                if (local_buffer[0] == '\r')
                    continue;
                if (local_buffer[0] == '\n')
                    break;
                buffer.push_back(local_buffer[0]);
              }
            buffer.push_back(0);
            return &(buffer[0]);
          }
        bool has_bytes(void)
          {
            if (SSL_pending(the_ssl) > 0)
                return true;
            struct pollfd data;
            data.fd = socket_num;
            data.events = POLLIN;
            return (poll(&data, 1, 0) > 0);
          }
        ssize_t read_bytes(char *buffer, size_t byte_count)
          {
            return SSL_read(the_ssl, buffer, byte_count);
          }
        void check_for_errors(void)
          {
          }
      };
    reader = new SSLReader(the_ssl, socket_num, the_ctx);

    class SSLWriter : public HTTPRawWriter
      {
      private:
        SSL *the_ssl;
        HTTPRawReader *reader;

      public:
        SSLWriter(SSL *the_ssl, HTTPRawReader *reader) : the_ssl(the_ssl),
                reader(reader)
          {
            assert(the_ssl != NULL);
            assert(reader != NULL);
          }
        ~SSLWriter(void)  { }

        void write(const char *to_write)
          {
            write(to_write, strlen(to_write));
          }
        void write(const char *to_write, size_t byte_count)
          {
            ssize_t write_result = SSL_write(the_ssl, to_write, byte_count);
            if (write_result != byte_count)
                throw "SSL socket write error.";
          }
        ssize_t read(char *buffer, size_t byte_count)
          {
            return reader->read_bytes(buffer, byte_count);
          }
      };
    writer = new SSLWriter(the_ssl, reader);
  }

extern void clean_up_fetch(void)
  {
  }


static int open_socket_with_timeout(struct addrinfo *address_info_list,
                                    double timeout_seconds)
  {
    int socket_num = socket(AF_INET, address_info_list->ai_socktype,
                            address_info_list->ai_protocol);
    if (socket_num == -1)
      {
        freeaddrinfo(address_info_list);
        throw "Unable to open a socket.";
      }

    if (timeout_seconds > 0)
      {
        struct timeval the_timeval;
        the_timeval.tv_sec = timeout_seconds;
        the_timeval.tv_usec =
                ((timeout_seconds - the_timeval.tv_sec) * 1000 * 1000);
        int result = setsockopt(socket_num, SOL_SOCKET, SO_RCVTIMEO,
                                &the_timeval, sizeof(struct timeval));
        if (result != 0)
          {
            fprintf(stderr,
                    "Warning: GoldenRetriever was unable to set the receive "
                    "timeout for a socket to %g seconds.\n", timeout_seconds);
          }
        result = setsockopt(socket_num, SOL_SOCKET, SO_SNDTIMEO, &the_timeval,
                            sizeof(struct timeval));
        if (result != 0)
          {
            fprintf(stderr,
                    "Warning: GoldenRetriever was unable to set the send "
                    "timeout for a socket to %g seconds.\n", timeout_seconds);
          }
      }

    return socket_num;
  }
