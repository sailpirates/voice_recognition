/* file "ClientMatchJSON.h" */

/* Generated automatically by Classy JSON. */


#ifndef CLIENTMATCHJSON_H
#define CLIENTMATCHJSON_H

#include "JSONRep.h"
#include "JSONHoldingGenerator.h"
#include "JSONObjectGenerator.h"
#include "JSONStringGenerator.h"
#include "JSONBooleanGenerator.h"
#include <string>
#include "JSONHandler.h"
#include "JSONCheckingHandler.h"
#include "ReferenceCounted.h"
#include "RCHandle.h"
#include "JSONParse.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


class ClientMatchJSON : public ReferenceCounted
  {
  private:
    bool flagHasExpression;
    std::string storeExpression;
    bool flagHasResult;
    JSONValue * storeResult;
    bool flagHasSpokenResponse;
    std::string storeSpokenResponse;
    bool flagHasSpokenResponseLong;
    std::string storeSpokenResponseLong;
    bool flagHasWrittenResponse;
    std::string storeWrittenResponse;
    bool flagHasWrittenResponseLong;
    std::string storeWrittenResponseLong;
    bool flagHasAutoListen;
    bool storeAutoListen;

    ClientMatchJSON(const ClientMatchJSON &)  { assert(false); }
    ClientMatchJSON &operator=(const ClientMatchJSON &other)  { assert(false); throw "Illegal operator=() call."; }


    void fromJSONExpression(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONResult(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONSpokenResponse(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONSpokenResponseLong(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONWrittenResponse(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONWrittenResponseLong(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONAutoListen(JSONValue *json_value, bool ignore_extras = false);

  public:
    ClientMatchJSON(void) :
            flagHasExpression(false),
            flagHasResult(false),
            flagHasSpokenResponse(false),
            flagHasSpokenResponseLong(false),
            flagHasWrittenResponse(false),
            flagHasWrittenResponseLong(false),
            flagHasAutoListen(false)
      {
      }
    virtual ~ClientMatchJSON(void)
      {
        if (flagHasResult)
          {
            storeResult->remove_reference();
          }
      }

    bool hasExpression(void) const  { return flagHasExpression; }
    std::string getExpression(void)
      {
        assert(flagHasExpression);
        return storeExpression;
      }
    const std::string getExpression(void) const
      {
        assert(flagHasExpression);
        return storeExpression;
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
    bool hasSpokenResponse(void) const  { return flagHasSpokenResponse; }
    std::string getSpokenResponse(void)
      {
        assert(flagHasSpokenResponse);
        return storeSpokenResponse;
      }
    const std::string getSpokenResponse(void) const
      {
        assert(flagHasSpokenResponse);
        return storeSpokenResponse;
      }
    bool hasSpokenResponseLong(void) const  { return flagHasSpokenResponseLong; }
    std::string getSpokenResponseLong(void)
      {
        assert(flagHasSpokenResponseLong);
        return storeSpokenResponseLong;
      }
    const std::string getSpokenResponseLong(void) const
      {
        assert(flagHasSpokenResponseLong);
        return storeSpokenResponseLong;
      }
    bool hasWrittenResponse(void) const  { return flagHasWrittenResponse; }
    std::string getWrittenResponse(void)
      {
        assert(flagHasWrittenResponse);
        return storeWrittenResponse;
      }
    const std::string getWrittenResponse(void) const
      {
        assert(flagHasWrittenResponse);
        return storeWrittenResponse;
      }
    bool hasWrittenResponseLong(void) const  { return flagHasWrittenResponseLong; }
    std::string getWrittenResponseLong(void)
      {
        assert(flagHasWrittenResponseLong);
        return storeWrittenResponseLong;
      }
    const std::string getWrittenResponseLong(void) const
      {
        assert(flagHasWrittenResponseLong);
        return storeWrittenResponseLong;
      }
    bool hasAutoListen(void) const  { return flagHasAutoListen; }
    bool getAutoListen(void)
      {
        assert(flagHasAutoListen);
        return storeAutoListen;
      }
    const bool getAutoListen(void) const
      {
        assert(flagHasAutoListen);
        return storeAutoListen;
      }


    void setExpression(std::string new_value)
      {
        flagHasExpression = true;
        storeExpression = new_value;
      }
    void unsetExpression(void)
      {
        flagHasExpression = false;
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
    void setSpokenResponse(std::string new_value)
      {
        flagHasSpokenResponse = true;
        storeSpokenResponse = new_value;
      }
    void unsetSpokenResponse(void)
      {
        flagHasSpokenResponse = false;
      }
    void setSpokenResponseLong(std::string new_value)
      {
        flagHasSpokenResponseLong = true;
        storeSpokenResponseLong = new_value;
      }
    void unsetSpokenResponseLong(void)
      {
        flagHasSpokenResponseLong = false;
      }
    void setWrittenResponse(std::string new_value)
      {
        flagHasWrittenResponse = true;
        storeWrittenResponse = new_value;
      }
    void unsetWrittenResponse(void)
      {
        flagHasWrittenResponse = false;
      }
    void setWrittenResponseLong(std::string new_value)
      {
        flagHasWrittenResponseLong = true;
        storeWrittenResponseLong = new_value;
      }
    void unsetWrittenResponseLong(void)
      {
        flagHasWrittenResponseLong = false;
      }
    void setAutoListen(bool new_value)
      {
        flagHasAutoListen = true;
        storeAutoListen = new_value;
      }
    void unsetAutoListen(void)
      {
        flagHasAutoListen = false;
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
        assert(flagHasExpression);
        handler->start_pair("Expression");
        handler->string_value(storeExpression);
        assert(flagHasResult);
        handler->start_pair("Result");
        storeResult->write(handler);
        assert(flagHasSpokenResponse);
        handler->start_pair("SpokenResponse");
        handler->string_value(storeSpokenResponse);
        assert(flagHasSpokenResponseLong);
        handler->start_pair("SpokenResponseLong");
        handler->string_value(storeSpokenResponseLong);
        assert(flagHasWrittenResponse);
        handler->start_pair("WrittenResponse");
        handler->string_value(storeWrittenResponse);
        assert(flagHasWrittenResponseLong);
        handler->start_pair("WrittenResponseLong");
        handler->string_value(storeWrittenResponseLong);
        if (flagHasAutoListen)
          {
            handler->start_pair("AutoListen");
            handler->boolean_value(storeAutoListen);
          }
      }

    static ClientMatchJSON *from_json(JSONValue *json_value, bool ignore_extras = false);
    static ClientMatchJSON *from_text(const char *text, bool ignore_extras = false)
      {
        ClientMatchJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<ClientMatchJSON>, ClientMatchJSON *, bool> generator("Type ClientMatch", ignore_extras);
            parse_json_value(text, &generator);
            assert(generator.have_value);
            result = generator.value.referenced();
            result->add_reference();
          };
        result->remove_reference_no_delete();
        return result;
      }
    static ClientMatchJSON *from_file(FILE *fp, const char *file_name, bool ignore_extras = false)
      {
        ClientMatchJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<ClientMatchJSON>, ClientMatchJSON *, bool> generator("Type ClientMatch", ignore_extras);
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
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorExpression;
        JSONHoldingGenerator<JSONValueHandler, RCHandle<JSONValue>, JSONValue * > fieldGeneratorResult;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorSpokenResponse;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorSpokenResponseLong;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorWrittenResponse;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorWrittenResponseLong;
        JSONHoldingGenerator<JSONBooleanGenerator, bool, bool > fieldGeneratorAutoListen;
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
            ClientMatchJSON *result = new ClientMatchJSON();
            assert(result != NULL);
            RCHandle<ClientMatchJSON> result_holder = result;
            finish(result);
            handle_result(result);
          }
        void finish(ClientMatchJSON *result)
          {
            if (fieldGeneratorExpression.have_value)
              {
                result->setExpression(fieldGeneratorExpression.value);
                fieldGeneratorExpression.have_value = false;
              }
            else if (!(result->hasExpression()))
              {
                error("When parsing the object for %what%, the \"Expression\" field was missing.");
              }
            if (fieldGeneratorResult.have_value)
              {
                result->setResult(fieldGeneratorResult.value.referenced());
                fieldGeneratorResult.have_value = false;
              }
            else if (!(result->hasResult()))
              {
                error("When parsing the object for %what%, the \"Result\" field was missing.");
              }
            if (fieldGeneratorSpokenResponse.have_value)
              {
                result->setSpokenResponse(fieldGeneratorSpokenResponse.value);
                fieldGeneratorSpokenResponse.have_value = false;
              }
            else if (!(result->hasSpokenResponse()))
              {
                error("When parsing the object for %what%, the \"SpokenResponse\" field was missing.");
              }
            if (fieldGeneratorSpokenResponseLong.have_value)
              {
                result->setSpokenResponseLong(fieldGeneratorSpokenResponseLong.value);
                fieldGeneratorSpokenResponseLong.have_value = false;
              }
            else if (!(result->hasSpokenResponseLong()))
              {
                error("When parsing the object for %what%, the \"SpokenResponseLong\" field was missing.");
              }
            if (fieldGeneratorWrittenResponse.have_value)
              {
                result->setWrittenResponse(fieldGeneratorWrittenResponse.value);
                fieldGeneratorWrittenResponse.have_value = false;
              }
            else if (!(result->hasWrittenResponse()))
              {
                error("When parsing the object for %what%, the \"WrittenResponse\" field was missing.");
              }
            if (fieldGeneratorWrittenResponseLong.have_value)
              {
                result->setWrittenResponseLong(fieldGeneratorWrittenResponseLong.value);
                fieldGeneratorWrittenResponseLong.have_value = false;
              }
            else if (!(result->hasWrittenResponseLong()))
              {
                error("When parsing the object for %what%, the \"WrittenResponseLong\" field was missing.");
              }
            if (fieldGeneratorAutoListen.have_value)
              {
                result->setAutoListen(fieldGeneratorAutoListen.value);
                fieldGeneratorAutoListen.have_value = false;
              }
          }
        virtual void handle_result(ClientMatchJSON *new_result) = 0;
        virtual JSONHandler *start_known_field(const char *field_name)
          {
            switch (field_name[0])
              {
                case 'A':
                    if (strcmp(&(field_name[1]), "utoListen") == 0)
                        return &fieldGeneratorAutoListen;
                    break;
                case 'E':
                    if (strcmp(&(field_name[1]), "xpression") == 0)
                        return &fieldGeneratorExpression;
                    break;
                case 'R':
                    if (strcmp(&(field_name[1]), "esult") == 0)
                        return &fieldGeneratorResult;
                    break;
                case 'S':
                    if (strncmp(&(field_name[1]), "pokenResponse", 13) == 0)
                      {
                        switch (field_name[14])
                          {
                            case 0:
                                return &fieldGeneratorSpokenResponse;
                            case 'L':
                                if (strcmp(&(field_name[15]), "ong") == 0)
                                    return &fieldGeneratorSpokenResponseLong;
                                break;
                            default:
                                break;
                          }
                      }
                    break;
                case 'W':
                    if (strncmp(&(field_name[1]), "rittenResponse", 14) == 0)
                      {
                        switch (field_name[15])
                          {
                            case 0:
                                return &fieldGeneratorWrittenResponse;
                            case 'L':
                                if (strcmp(&(field_name[16]), "ong") == 0)
                                    return &fieldGeneratorWrittenResponseLong;
                                break;
                            default:
                                break;
                          }
                      }
                    break;
                default:
                    break;
              }
            return NULL;
          }

      public:
        Generator(bool ignore_extras = false) : fieldGeneratorExpression("field \"Expression\" of the ClientMatch class"), fieldGeneratorResult("field \"Result\" of the ClientMatch class"), fieldGeneratorSpokenResponse("field \"SpokenResponse\" of the ClientMatch class"), fieldGeneratorSpokenResponseLong("field \"SpokenResponseLong\" of the ClientMatch class"), fieldGeneratorWrittenResponse("field \"WrittenResponse\" of the ClientMatch class"), fieldGeneratorWrittenResponseLong("field \"WrittenResponseLong\" of the ClientMatch class"), fieldGeneratorAutoListen("field \"AutoListen\" of the ClientMatch class")
          {
            set_what("the ClientMatch class");
          }
        ~Generator(void)
          {
          }

        void reset(void)
          {
            fieldGeneratorExpression.reset();
            fieldGeneratorResult.reset();
            fieldGeneratorSpokenResponse.reset();
            fieldGeneratorSpokenResponseLong.reset();
            fieldGeneratorWrittenResponse.reset();
            fieldGeneratorWrittenResponseLong.reset();
            fieldGeneratorAutoListen.reset();
            JSONObjectGenerator::reset();
            unknownFieldGenerator.reset();
          }
      };
  };

#endif /* CLIENTMATCHJSON_H */
