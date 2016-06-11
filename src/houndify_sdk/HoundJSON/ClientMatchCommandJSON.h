/* file "ClientMatchCommandJSON.h" */

/* Generated automatically by Classy JSON. */


#ifndef CLIENTMATCHCOMMANDJSON_H
#define CLIENTMATCHCOMMANDJSON_H

#include "CommandResultJSON.h"
#include "JSONRep.h"
#include "JSONHoldingGenerator.h"
#include "JSONObjectGenerator.h"
#include "ClientMatchJSON.h"
#include "JSONHandler.h"
#include "JSONCheckingHandler.h"
#include "ReferenceCounted.h"
#include "RCHandle.h"
#include "JSONParse.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


class ClientMatchCommandJSON : public CommandResultJSON
  {
  public:
    class TypeNativeDataJSON : public ReferenceCounted
      {
      private:
        bool flagHasResult;
        JSONValue * storeResult;

        TypeNativeDataJSON(const TypeNativeDataJSON &)  { assert(false); }
        TypeNativeDataJSON &operator=(const TypeNativeDataJSON &other)  { assert(false); throw "Illegal operator=() call."; }


        void fromJSONResult(JSONValue *json_value, bool ignore_extras = false);

      public:
        TypeNativeDataJSON(void) :
                flagHasResult(false)
          {
          }
        virtual ~TypeNativeDataJSON(void)
          {
            if (flagHasResult)
              {
                storeResult->remove_reference();
              }
          }

        bool hasResult(void) const  { return flagHasResult; }
        JSONValue * getResult(void)
          {
            assert(flagHasResult);
            return storeResult;
          }
        const JSONValue * getResult(void) const
          {
            assert(flagHasResult);
            return storeResult;
          }


        void setResult(JSONValue * new_value)
          {
            new_value->add_reference();
            if (flagHasResult)
              {
                storeResult->remove_reference();
              }
            flagHasResult = true;
            storeResult = new_value;
          }
        void unsetResult(void)
          {
            if (flagHasResult)
              {
                storeResult->remove_reference();
              }
            flagHasResult = false;
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
            assert(flagHasResult);
            handler->start_pair("Result");
            storeResult->write(handler);
          }

        static TypeNativeDataJSON *from_json(JSONValue *json_value, bool ignore_extras = false);
        static TypeNativeDataJSON *from_text(const char *text, bool ignore_extras = false)
          {
            TypeNativeDataJSON *result;
              {
                JSONHoldingGenerator<Generator, RCHandle<TypeNativeDataJSON>, TypeNativeDataJSON *, bool> generator("Type TypeNativeData", ignore_extras);
                parse_json_value(text, &generator);
                assert(generator.have_value);
                result = generator.value.referenced();
                result->add_reference();
              };
            result->remove_reference_no_delete();
            return result;
          }
        static TypeNativeDataJSON *from_file(FILE *fp, const char *file_name, bool ignore_extras = false)
          {
            TypeNativeDataJSON *result;
              {
                JSONHoldingGenerator<Generator, RCHandle<TypeNativeDataJSON>, TypeNativeDataJSON *, bool> generator("Type TypeNativeData", ignore_extras);
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
            JSONHoldingGenerator<JSONValueHandler, RCHandle<JSONValue>, JSONValue * > fieldGeneratorResult;
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
                TypeNativeDataJSON *result = new TypeNativeDataJSON();
                assert(result != NULL);
                RCHandle<TypeNativeDataJSON> result_holder = result;
                finish(result);
                handle_result(result);
              }
            void finish(TypeNativeDataJSON *result)
              {
                if (fieldGeneratorResult.have_value)
                  {
                    result->setResult(fieldGeneratorResult.value.referenced());
                    fieldGeneratorResult.have_value = false;
                  }
                else if (!(result->hasResult()))
                  {
                    error("When parsing the object for %what%, the \"Result\" field was missing.");
                  }
              }
            virtual void handle_result(TypeNativeDataJSON *new_result) = 0;
            virtual JSONHandler *start_known_field(const char *field_name)
              {
                if (strcmp(field_name, "Result") == 0)
                    return &fieldGeneratorResult;
                return NULL;
              }

          public:
            Generator(bool ignore_extras = false) : fieldGeneratorResult("field \"Result\" of the TypeNativeData class")
              {
                set_what("the TypeNativeData class");
              }
            ~Generator(void)
              {
              }

            void reset(void)
              {
                fieldGeneratorResult.reset();
                JSONObjectGenerator::reset();
                unknownFieldGenerator.reset();
              }
          };
      };

  private:
    bool flagHasResult;
    JSONValue * storeResult;
    bool flagHasNativeData;
    TypeNativeDataJSON * storeNativeData;
    bool flagHasMatchedItem;
    ClientMatchJSON * storeMatchedItem;

    ClientMatchCommandJSON(const ClientMatchCommandJSON &)  { assert(false); }
    ClientMatchCommandJSON &operator=(const ClientMatchCommandJSON &other)  { assert(false); throw "Illegal operator=() call."; }


    void fromJSONResult(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONNativeData(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONMatchedItem(JSONValue *json_value, bool ignore_extras = false);

  public:
    ClientMatchCommandJSON(void) :
            flagHasResult(false),
            flagHasNativeData(false),
            flagHasMatchedItem(false)
      {
      }
    virtual ~ClientMatchCommandJSON(void)
      {
        if (flagHasResult)
          {
            storeResult->remove_reference();
          }
        if (flagHasNativeData)
          {
            storeNativeData->remove_reference();
          }
        if (flagHasMatchedItem)
          {
            storeMatchedItem->remove_reference();
          }
      }

    const char *getCommandKind(void) const  { return "ClientMatchCommand"; }
    bool hasResult(void) const  { return flagHasResult; }
    JSONValue * getResult(void)
      {
        assert(flagHasResult);
        return storeResult;
      }
    const JSONValue * getResult(void) const
      {
        assert(flagHasResult);
        return storeResult;
      }
    bool hasNativeData(void) const  { return flagHasNativeData; }
    TypeNativeDataJSON * getNativeData(void)
      {
        assert(flagHasNativeData);
        return storeNativeData;
      }
    const TypeNativeDataJSON * getNativeData(void) const
      {
        assert(flagHasNativeData);
        return storeNativeData;
      }
    bool hasMatchedItem(void) const  { return flagHasMatchedItem; }
    ClientMatchJSON * getMatchedItem(void)
      {
        assert(flagHasMatchedItem);
        return storeMatchedItem;
      }
    const ClientMatchJSON * getMatchedItem(void) const
      {
        assert(flagHasMatchedItem);
        return storeMatchedItem;
      }


    void setResult(JSONValue * new_value)
      {
        new_value->add_reference();
        if (flagHasResult)
          {
            storeResult->remove_reference();
          }
        flagHasResult = true;
        storeResult = new_value;
      }
    void unsetResult(void)
      {
        if (flagHasResult)
          {
            storeResult->remove_reference();
          }
        flagHasResult = false;
      }
    void setNativeData(TypeNativeDataJSON * new_value)
      {
        new_value->add_reference();
        if (flagHasNativeData)
          {
            storeNativeData->remove_reference();
          }
        flagHasNativeData = true;
        storeNativeData = new_value;
      }
    void unsetNativeData(void)
      {
        if (flagHasNativeData)
          {
            storeNativeData->remove_reference();
          }
        flagHasNativeData = false;
      }
    void setMatchedItem(ClientMatchJSON * new_value)
      {
        new_value->add_reference();
        if (flagHasMatchedItem)
          {
            storeMatchedItem->remove_reference();
          }
        flagHasMatchedItem = true;
        storeMatchedItem = new_value;
      }
    void unsetMatchedItem(void)
      {
        if (flagHasMatchedItem)
          {
            storeMatchedItem->remove_reference();
          }
        flagHasMatchedItem = false;
      }


    virtual void write_as_json(JSONHandler *handler) const
      {
        handler->start_object();
        write_fields_as_json(handler);
        handler->finish_object();
      }

    virtual void write_fields_as_json(JSONHandler *handler)
 const
      {
        CommandResultJSON::write_fields_as_json(handler);
        assert(flagHasResult);
        handler->start_pair("Result");
        storeResult->write(handler);
        if (flagHasNativeData)
          {
            handler->start_pair("NativeData");
            storeNativeData->write_as_json(handler);
          }
        if (flagHasMatchedItem)
          {
            handler->start_pair("MatchedItem");
            storeMatchedItem->write_as_json(handler);
          }
      }

    static ClientMatchCommandJSON *from_json(JSONValue *json_value, bool ignore_extras = false);
    static ClientMatchCommandJSON *from_text(const char *text, bool ignore_extras = false)
      {
        ClientMatchCommandJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<ClientMatchCommandJSON>, ClientMatchCommandJSON *, bool> generator("Type ClientMatchCommand", ignore_extras);
            parse_json_value(text, &generator);
            assert(generator.have_value);
            result = generator.value.referenced();
            result->add_reference();
          };
        result->remove_reference_no_delete();
        return result;
      }
    static ClientMatchCommandJSON *from_file(FILE *fp, const char *file_name, bool ignore_extras = false)
      {
        ClientMatchCommandJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<ClientMatchCommandJSON>, ClientMatchCommandJSON *, bool> generator("Type ClientMatchCommand", ignore_extras);
            parse_json_value(fp, file_name, &generator);
            assert(generator.have_value);
            result = generator.value.referenced();
            result->add_reference();
          };
        result->remove_reference_no_delete();
        return result;
      }
    class Generator : public CommandResultJSON::Generator
      {
      private:
        JSONHoldingGenerator<JSONValueHandler, RCHandle<JSONValue>, JSONValue * > fieldGeneratorResult;
        JSONHoldingGenerator<TypeNativeDataJSON::Generator, RCHandle<TypeNativeDataJSON>, TypeNativeDataJSON *, bool > fieldGeneratorNativeData;
        JSONHoldingGenerator<ClientMatchJSON::Generator, RCHandle<ClientMatchJSON>, ClientMatchJSON *, bool > fieldGeneratorMatchedItem;
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
            if (!(strcmp(getCommandResultJSONKey().c_str(), "ClientMatchCommand") == 0))
                throw("The key field has a value other than `ClientMatchCommand'.");
            ClientMatchCommandJSON *result = new ClientMatchCommandJSON();
            assert(result != NULL);
            RCHandle<ClientMatchCommandJSON> result_holder = result;
            finish(result);
            handle_result(result);
          }
        void handle_result(CommandResultJSON *new_result)
          {
            handle_result((ClientMatchCommandJSON *)new_result);
          }
        void finish(ClientMatchCommandJSON *result)
          {
            if (fieldGeneratorResult.have_value)
              {
                result->setResult(fieldGeneratorResult.value.referenced());
                fieldGeneratorResult.have_value = false;
              }
            else if (!(result->hasResult()))
              {
                error("When parsing the object for %what%, the \"Result\" field was missing.");
              }
            if (fieldGeneratorNativeData.have_value)
              {
                result->setNativeData(fieldGeneratorNativeData.value.referenced());
                fieldGeneratorNativeData.have_value = false;
              }
            if (fieldGeneratorMatchedItem.have_value)
              {
                result->setMatchedItem(fieldGeneratorMatchedItem.value.referenced());
                fieldGeneratorMatchedItem.have_value = false;
              }
            CommandResultJSON::Generator::finish(result);
          }
        virtual void handle_result(ClientMatchCommandJSON *new_result) = 0;
        virtual JSONHandler *start_known_field(const char *field_name)
          {
            switch (field_name[0])
              {
                case 'M':
                    if (strcmp(&(field_name[1]), "atchedItem") == 0)
                        return &fieldGeneratorMatchedItem;
                    break;
                case 'N':
                    if (strcmp(&(field_name[1]), "ativeData") == 0)
                        return &fieldGeneratorNativeData;
                    break;
                case 'R':
                    if (strcmp(&(field_name[1]), "esult") == 0)
                        return &fieldGeneratorResult;
                    break;
                default:
                    break;
              }
            return CommandResultJSON::Generator::start_known_field(field_name);
          }

      public:
        Generator(bool ignore_extras = false) : CommandResultJSON::Generator(ignore_extras), fieldGeneratorResult("field \"Result\" of the ClientMatchCommand class"), fieldGeneratorNativeData("field \"NativeData\" of the ClientMatchCommand class", ignore_extras), fieldGeneratorMatchedItem("field \"MatchedItem\" of the ClientMatchCommand class", ignore_extras)
          {
            set_what("the ClientMatchCommand class");
          }
        ~Generator(void)
          {
          }

        void reset(void)
          {
            fieldGeneratorResult.reset();
            fieldGeneratorNativeData.reset();
            fieldGeneratorMatchedItem.reset();
            CommandResultJSON::Generator::reset();
            unknownFieldGenerator.reset();
          }
      };
  };

#endif /* CLIENTMATCHCOMMANDJSON_H */
