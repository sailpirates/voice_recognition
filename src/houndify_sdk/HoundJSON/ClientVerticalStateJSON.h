/* file "ClientVerticalStateJSON.h" */

/* Generated automatically by Classy JSON. */


#ifndef CLIENTVERTICALSTATEJSON_H
#define CLIENTVERTICALSTATEJSON_H

#include "JSONRep.h"
#include "JSONHoldingGenerator.h"
#include "JSONObjectGenerator.h"
#include "JSONStringGenerator.h"
#include "JSONHandler.h"
#include "JSONCheckingHandler.h"
#include "ReferenceCounted.h"
#include "RCHandle.h"
#include "JSONParse.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


class ClientVerticalStateJSON : public ReferenceCounted
  {
  private:

    ClientVerticalStateJSON(const ClientVerticalStateJSON &)  { assert(false); }
    ClientVerticalStateJSON &operator=(const ClientVerticalStateJSON &other)  { assert(false); throw "Illegal operator=() call."; }


  public:
    ClientVerticalStateJSON(void)
      {
      }
    virtual ~ClientVerticalStateJSON(void)
      {
      }

    virtual const char *getClientVerticalStateKind(void) const = 0;




    virtual void write_as_json(JSONHandler *handler) const
      {
        handler->start_object();
        write_fields_as_json(handler);
        handler->finish_object();
      }

    virtual void write_fields_as_json(JSONHandler *handler)
 const
      {
        handler->pair("ClientVerticalStateKind", getClientVerticalStateKind());
      }

    static ClientVerticalStateJSON *from_json(JSONValue *json_value, bool ignore_extras = false);
    static ClientVerticalStateJSON *from_text(const char *text, bool ignore_extras = false)
      {
        ClientVerticalStateJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<ClientVerticalStateJSON>, ClientVerticalStateJSON *, bool> generator("Type ClientVerticalState", ignore_extras);
            parse_json_value(text, &generator);
            assert(generator.have_value);
            result = generator.value.referenced();
            result->add_reference();
          };
        result->remove_reference_no_delete();
        return result;
      }
    static ClientVerticalStateJSON *from_file(FILE *fp, const char *file_name, bool ignore_extras = false)
      {
        ClientVerticalStateJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<ClientVerticalStateJSON>, ClientVerticalStateJSON *, bool> generator("Type ClientVerticalState", ignore_extras);
            parse_json_value(fp, file_name, &generator);
            assert(generator.have_value);
            result = generator.value.referenced();
            result->add_reference();
          };
        result->remove_reference_no_delete();
        return result;
      }
    class Generator : public JSONObjectGenerator
      {
      private:
        class UnknownFieldGenerator : public JSONValueHandler
          {
          public:
            string_index *index;
            UnknownFieldGenerator(void)
              {
                index = create_string_index();
              }
            ~UnknownFieldGenerator(void)
              {
                destroy_string_index(index);
              }


          protected:
            void new_value(JSONValue *item)
              {
              }

          public:
            void reset()
              {
                destroy_string_index(index);
                index = create_string_index();
              }
          };
        UnknownFieldGenerator unknownFieldGenerator;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char *> keyGenerator;


      protected:
        void start(void)
          {
          }
        JSONHandler *start_field(const char *field_name)
          {
            JSONHandler *result = start_known_field(field_name);
            if (result != NULL)
                return result;
            return &unknownFieldGenerator;
          }
        void finish_field(const char *field_name, JSONHandler *field_handler)
          {
          }
        void finish(void)
          {
            if (!(keyGenerator.have_value))
                throw("The `ClientVerticalStateKind' field is missing.");
            ClientVerticalStateJSON *result = createForKey(keyGenerator.value.c_str(), unknownFieldGenerator.index);
            assert(result != NULL);
            RCHandle<ClientVerticalStateJSON> result_holder = result;
            finish(result);
            handle_result(result);
          }
        std::string getClientVerticalStateJSONKey(void)
          {
            if (!(keyGenerator.have_value))
                throw("The `ClientVerticalStateKind' field is missing.");
            return keyGenerator.value;
          }
        void finish(ClientVerticalStateJSON *result)
          {
          }
        virtual void handle_result(ClientVerticalStateJSON *new_result) = 0;
        virtual JSONHandler *start_known_field(const char *field_name)
          {
            if (strcmp(field_name, "ClientVerticalStateKind") == 0)
                {
                keyGenerator.reset();
                return &keyGenerator;
                }
            return NULL;
          }

      public:
        Generator(bool ignore_extras = false) : keyGenerator("key field \"ClientVerticalStateKind\" of the ClientVerticalState class")
          {
            set_what("the ClientVerticalState class");
          }
        ~Generator(void)
          {
          }

        void reset(void)
          {
            JSONObjectGenerator::reset();
            unknownFieldGenerator.reset();
          }
      };
    static ClientVerticalStateJSON *createForKey(const char *key, string_index *other_field_index);
  };

#endif /* CLIENTVERTICALSTATEJSON_H */
