/* file "CommandResultJSON.h" */

/* Generated automatically by Classy JSON. */


#ifndef COMMANDRESULTJSON_H
#define COMMANDRESULTJSON_H

#include "JSONRep.h"
#include "JSONHoldingGenerator.h"
#include "JSONObjectGenerator.h"
#include "JSONStringGenerator.h"
#include "JSONBooleanGenerator.h"
#include <string>
#include "ConversationStateJSON.h"
#include "JSONHandler.h"
#include "JSONCheckingHandler.h"
#include "ReferenceCounted.h"
#include "RCHandle.h"
#include "JSONParse.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


class CommandResultJSON : public ReferenceCounted
  {
  private:
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
    bool flagHasConversationState;
    ConversationStateJSON * storeConversationState;

    CommandResultJSON(const CommandResultJSON &)  { assert(false); }
    CommandResultJSON &operator=(const CommandResultJSON &other)  { assert(false); throw "Illegal operator=() call."; }


    void fromJSONSpokenResponse(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONSpokenResponseLong(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONWrittenResponse(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONWrittenResponseLong(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONAutoListen(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONConversationState(JSONValue *json_value, bool ignore_extras = false);

  public:
    CommandResultJSON(void) :
            flagHasSpokenResponse(false),
            flagHasSpokenResponseLong(false),
            flagHasWrittenResponse(false),
            flagHasWrittenResponseLong(false),
            flagHasAutoListen(false),
            flagHasConversationState(false)
      {
        storeAutoListen = false;
      }
    virtual ~CommandResultJSON(void)
      {
        if (flagHasConversationState)
          {
            storeConversationState->remove_reference();
          }
      }

    virtual const char *getCommandKind(void) const = 0;
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
        return storeAutoListen;
      }
    const bool getAutoListen(void) const
      {
        return storeAutoListen;
      }
    bool hasConversationState(void) const  { return flagHasConversationState; }
    ConversationStateJSON * getConversationState(void)
      {
        assert(flagHasConversationState);
        return storeConversationState;
      }
    const ConversationStateJSON * getConversationState(void) const
      {
        assert(flagHasConversationState);
        return storeConversationState;
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
    void setConversationState(ConversationStateJSON * new_value)
      {
        new_value->add_reference();
        if (flagHasConversationState)
          {
            storeConversationState->remove_reference();
          }
        flagHasConversationState = true;
        storeConversationState = new_value;
      }
    void unsetConversationState(void)
      {
        if (flagHasConversationState)
          {
            storeConversationState->remove_reference();
          }
        flagHasConversationState = false;
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
        handler->pair("CommandKind", getCommandKind());
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
        if (flagHasConversationState)
          {
            handler->start_pair("ConversationState");
            storeConversationState->write_as_json(handler);
          }
      }

    static CommandResultJSON *from_json(JSONValue *json_value, bool ignore_extras = false);
    static CommandResultJSON *from_text(const char *text, bool ignore_extras = false)
      {
        CommandResultJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<CommandResultJSON>, CommandResultJSON *, bool> generator("Type CommandResult", ignore_extras);
            parse_json_value(text, &generator);
            assert(generator.have_value);
            result = generator.value.referenced();
            result->add_reference();
          };
        result->remove_reference_no_delete();
        return result;
      }
    static CommandResultJSON *from_file(FILE *fp, const char *file_name, bool ignore_extras = false)
      {
        CommandResultJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<CommandResultJSON>, CommandResultJSON *, bool> generator("Type CommandResult", ignore_extras);
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
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorSpokenResponse;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorSpokenResponseLong;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorWrittenResponse;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorWrittenResponseLong;
        JSONHoldingGenerator<JSONBooleanGenerator, bool, bool > fieldGeneratorAutoListen;
        JSONHoldingGenerator<ConversationStateJSON::Generator, RCHandle<ConversationStateJSON>, ConversationStateJSON *, bool > fieldGeneratorConversationState;
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
                throw("The `CommandKind' field is missing.");
            CommandResultJSON *result = createForKey(keyGenerator.value.c_str(), unknownFieldGenerator.index);
            assert(result != NULL);
            RCHandle<CommandResultJSON> result_holder = result;
            finish(result);
            handle_result(result);
          }
        std::string getCommandResultJSONKey(void)
          {
            if (!(keyGenerator.have_value))
                throw("The `CommandKind' field is missing.");
            return keyGenerator.value;
          }
        void finish(CommandResultJSON *result)
          {
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
            if (fieldGeneratorConversationState.have_value)
              {
                result->setConversationState(fieldGeneratorConversationState.value.referenced());
                fieldGeneratorConversationState.have_value = false;
              }
          }
        virtual void handle_result(CommandResultJSON *new_result) = 0;
        virtual JSONHandler *start_known_field(const char *field_name)
          {
            switch (field_name[0])
              {
                case 'A':
                    if (strcmp(&(field_name[1]), "utoListen") == 0)
                        return &fieldGeneratorAutoListen;
                    break;
                case 'C':
                    if (strncmp(&(field_name[1]), "o", 1) == 0)
                      {
                        switch (field_name[2])
                          {
                            case 'm':
                                if (strcmp(&(field_name[3]), "mandKind") == 0)
                                    {
                                    keyGenerator.reset();
                                    return &keyGenerator;
                                    }
                                break;
                            case 'n':
                                if (strcmp(&(field_name[3]), "versationState") == 0)
                                    return &fieldGeneratorConversationState;
                                break;
                            default:
                                break;
                          }
                      }
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
        Generator(bool ignore_extras = false) : fieldGeneratorSpokenResponse("field \"SpokenResponse\" of the CommandResult class"), fieldGeneratorSpokenResponseLong("field \"SpokenResponseLong\" of the CommandResult class"), fieldGeneratorWrittenResponse("field \"WrittenResponse\" of the CommandResult class"), fieldGeneratorWrittenResponseLong("field \"WrittenResponseLong\" of the CommandResult class"), fieldGeneratorAutoListen("field \"AutoListen\" of the CommandResult class"), fieldGeneratorConversationState("field \"ConversationState\" of the CommandResult class", ignore_extras), keyGenerator("key field \"CommandKind\" of the CommandResult class")
          {
            set_what("the CommandResult class");
          }
        ~Generator(void)
          {
          }

        void reset(void)
          {
            fieldGeneratorSpokenResponse.reset();
            fieldGeneratorSpokenResponseLong.reset();
            fieldGeneratorWrittenResponse.reset();
            fieldGeneratorWrittenResponseLong.reset();
            fieldGeneratorAutoListen.reset();
            fieldGeneratorConversationState.reset();
            JSONObjectGenerator::reset();
            unknownFieldGenerator.reset();
          }
      };
    static CommandResultJSON *createForKey(const char *key, string_index *other_field_index);
  };

#endif /* COMMANDRESULTJSON_H */
