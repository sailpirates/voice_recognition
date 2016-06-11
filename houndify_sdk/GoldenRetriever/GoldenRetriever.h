/* file "GoldenRetriever.h" */

/* Copyright 2012-2016 SoundHound, Incorporated.  All rights reserved. */


#ifndef GOLDENRETRIEVER_H
#define GOLDENRETRIEVER_H


#include <stddef.h>
#include <sys/types.h>


class HTTPHandler
  {
  public:
    virtual void handleHTTPVersion(const char *version)  { }
    virtual void handleParameter(const char *key, const char *value)  { }
    virtual void handleContentByteCount(size_t byteCount)  { }
    virtual void handleHeaderDone(void)  { }
    virtual void handleContent(size_t byteCount, const void *bytes)  { }
    virtual void handleContentEnd(void)  { }

  protected:
    HTTPHandler(void)  { }
    ~HTTPHandler(void)  { }
  };

class HTTPRawWriter
  {
  protected:
    HTTPRawWriter(void)  { }

  public:
    virtual ~HTTPRawWriter(void)  { }

    virtual void write(const char *to_write) = 0;
    virtual void write(const char *to_write, size_t byte_count) = 0;
    virtual ssize_t read(char *buffer, size_t byte_count) = 0;
    virtual void set_timeout_seconds(double seconds)  { }
  };

class HTTPRawReader
  {
  protected:
    HTTPRawReader(void)  { }

  public:
    virtual ~HTTPRawReader(void)  { }

    virtual char *readLine(void) = 0;
    virtual bool has_bytes(void) = 0;
    virtual ssize_t read_bytes(char *buffer, size_t byte_count) = 0;
    virtual void check_for_errors(void) = 0;
  };

class GoldenRetriever
  {
  protected:
    bool have_content_length;
    unsigned long content_length;
    bool chunked;

    GoldenRetriever(void);
    ~GoldenRetriever(void)  { }

    void handle_header_line(char *this_line, HTTPHandler *handler);
    void handleParametersAndBody(HTTPHandler *handler, HTTPRawReader *reader);
    static void error(const char *format, ...);
  };


#endif /* GOLDENRETRIEVER_H */
