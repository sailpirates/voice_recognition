/* file "CommandResultJSON.cpp" */

/* Generated automatically by Classy JSON. */

#include "CommandResultJSON.h"
#include "ClientMatchCommandJSON.h"


void CommandResultJSON::fromJSONSpokenResponse(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field SpokenResponse of CommandResultJSON is not a string.");
    setSpokenResponse(std::string(json_string->getData()));
  }

void CommandResultJSON::fromJSONSpokenResponseLong(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field SpokenResponseLong of CommandResultJSON is not a string.");
    setSpokenResponseLong(std::string(json_string->getData()));
  }

void CommandResultJSON::fromJSONWrittenResponse(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field WrittenResponse of CommandResultJSON is not a string.");
    setWrittenResponse(std::string(json_string->getData()));
  }

void CommandResultJSON::fromJSONWrittenResponseLong(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field WrittenResponseLong of CommandResultJSON is not a string.");
    setWrittenResponseLong(std::string(json_string->getData()));
  }

void CommandResultJSON::fromJSONAutoListen(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONTrueValue *json_true = json_value->true_value();
    bool the_bool;
    if (json_true != NULL)
      {
        the_bool = true;
      }
    else
      {
        const JSONFalseValue *json_false = json_value->false_value();
        if (json_false != NULL)
          {
            the_bool = false;
          }
        else
          {
            throw("The value for field AutoListen of CommandResultJSON is not true for false.");
          }
      }
    setAutoListen(the_bool);
  }

void CommandResultJSON::fromJSONConversationState(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    ConversationStateJSON *convert_classy = ConversationStateJSON::from_json(json_value, ignore_extras);
    convert_classy->add_reference();
    setConversationState(convert_classy);
    convert_classy->remove_reference();
  }

CommandResultJSON *CommandResultJSON::createForKey(const char *key, string_index *other_field_index)
  {
    if (strcmp(key, "ClientMatchCommand") == 0)
        return new ClientMatchCommandJSON();

    class GenericCommandResultJSON : public CommandResultJSON
      {
      private:
        std::string key;

      public:
        GenericCommandResultJSON(const char *init_key) : key(init_key)
          {
          }
        ~GenericCommandResultJSON(void)
          {
          }

        const char *getCommandKind(void) const  { return key.c_str(); }
        void write_as_json(JSONHandler *handler) const
          {
            handler->start_object();
            write_fields_as_json(handler);
            handler->finish_object();
          }
      };
    return new GenericCommandResultJSON(key);
  }
CommandResultJSON *CommandResultJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    CommandResultJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<CommandResultJSON>, CommandResultJSON *, bool> generator("Type CommandResult", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
