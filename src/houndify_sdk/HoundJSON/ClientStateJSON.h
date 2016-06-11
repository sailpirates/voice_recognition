/* file "ClientStateJSON.h" */

/* Generated automatically by Classy JSON. */


#ifndef CLIENTSTATEJSON_H
#define CLIENTSTATEJSON_H

#include "JSONRep.h"
#include "JSONHoldingGenerator.h"
#include "JSONObjectGenerator.h"
#include "ClientVerticalStateJSON.h"
#include "JSONHandler.h"
#include "JSONCheckingHandler.h"
#include "ReferenceCounted.h"
#include "RCHandle.h"
#include "JSONParse.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


class ClientStateJSON : public ReferenceCounted
  {
  private:
    bool flagHasVerticalState;
    ClientVerticalStateJSON * storeVerticalState;

    ClientStateJSON(const ClientStateJSON &)  { assert(false); }
    ClientStateJSON &operator=(const ClientStateJSON &other)  { assert(false); throw "Illegal operator=() call."; }


    void fromJSONVerticalState(JSONValue *json_value, bool ignore_extras = false);

  public:
    ClientStateJSON(void) :
            flagHasVerticalState(false)
      {
      }
    virtual ~ClientStateJSON(void)
      {
        if (flagHasVerticalState)
          {
            storeVerticalState->remove_reference();
          }
      }

    bool hasVerticalState(void) const  { return flagHasVerticalState; }
    ClientVerticalStateJSON * getVerticalState(void)
      {
        assert(flagHasVerticalState);
        return storeVerticalState;
      }
    const ClientVerticalStateJSON * getVerticalState(void) const
      {
        assert(flagHasVerticalState);
        return storeVerticalState;
      }


    void setVerticalState(ClientVerticalStateJSON * new_value)
      {
        new_value->add_reference();
        if (flagHasVerticalState)
          {
            storeVerticalState->remove_reference();
          }
        flagHasVerticalState = true;
        storeVerticalState = new_value;
      }
    void unsetVerticalState(void)
      {
        if (flagHasVerticalState)
          {
            storeVerticalState->remove_reference();
          }
        flagHasVerticalState = false;
      }


    void write_as_json(JSONHandler *handler) const
      {
        handler->start_object();
        write_fields_as_json(handler);
        handler->finish_object();
      }

    virtual void write_fields_as_json(JSONHandler *handler)
 const
      {
        if (flagHasVerticalState)
          {
            handler->start_pair("VerticalState");
            storeVerticalState->write_as_json(handler);
          }
      }

    static ClientStateJSON *from_json(JSONValue *json_value, bool ignore_extras = false);
    static ClientStateJSON *from_text(const char *text, bool ignore_extras = false)
      {
        ClientStateJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<ClientStateJSON>, ClientStateJSON *, bool> generator("Type ClientState", ignore_extras);
            parse_json_value(text, &generator);
            assert(generator.have_value);
            result = generator.value.referenced();
            result->add_reference();
          };
        result->remove_reference_no_delete();
        return result;
      }
    static ClientStateJSON *from_file(FILE *fp, const char *file_name, bool ignore_extras = false)
      {
        ClientStateJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<ClientStateJSON>, ClientStateJSON *, bool> generator("Type ClientState", ignore_extras);
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
        JSONHoldingGenerator<ClientVerticalStateJSON::Generator, RCHandle<ClientVerticalStateJSON>, ClientVerticalStateJSON *, bool > fieldGeneratorVerticalState;
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
            ClientStateJSON *result = new ClientStateJSON();
            assert(result != NULL);
            RCHandle<ClientStateJSON> result_holder = result;
            finish(result);
            handle_result(result);
          }
        void finish(ClientStateJSON *result)
          {
            if (fieldGeneratorVerticalState.have_value)
              {
                result->setVerticalState(fieldGeneratorVerticalState.value.referenced());
                fieldGeneratorVerticalState.have_value = false;
              }
          }
        virtual void handle_result(ClientStateJSON *new_result) = 0;
        virtual JSONHandler *start_known_field(const char *field_name)
          {
            if (strcmp(field_name, "VerticalState") == 0)
                return &fieldGeneratorVerticalState;
            return NULL;
          }

      public:
        Generator(bool ignore_extras = false) : fieldGeneratorVerticalState("field \"VerticalState\" of the ClientState class", ignore_extras)
          {
            set_what("the ClientState class");
          }
        ~Generator(void)
          {
          }

        void reset(void)
          {
            fieldGeneratorVerticalState.reset();
            JSONObjectGenerator::reset();
            unknownFieldGenerator.reset();
          }
      };
  };

#endif /* CLIENTSTATEJSON_H */
