/* file "ClientMatchJSON.cpp" */

/* Generated automatically by Classy JSON. */

#include "ClientMatchJSON.h"


void ClientMatchJSON::fromJSONExpression(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field Expression of ClientMatchJSON is not a string.");
    setExpression(std::string(json_string->getData()));
  }

void ClientMatchJSON::fromJSONResult(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    setResult(json_value);
  }

void ClientMatchJSON::fromJSONSpokenResponse(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field SpokenResponse of ClientMatchJSON is not a string.");
    setSpokenResponse(std::string(json_string->getData()));
  }

void ClientMatchJSON::fromJSONSpokenResponseLong(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field SpokenResponseLong of ClientMatchJSON is not a string.");
    setSpokenResponseLong(std::string(json_string->getData()));
  }

void ClientMatchJSON::fromJSONWrittenResponse(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field WrittenResponse of ClientMatchJSON is not a string.");
    setWrittenResponse(std::string(json_string->getData()));
  }

void ClientMatchJSON::fromJSONWrittenResponseLong(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field WrittenResponseLong of ClientMatchJSON is not a string.");
    setWrittenResponseLong(std::string(json_string->getData()));
  }

void ClientMatchJSON::fromJSONAutoListen(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field AutoListen of ClientMatchJSON is not true for false.");
          }
      }
    setAutoListen(the_bool);
  }

ClientMatchJSON *ClientMatchJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    ClientMatchJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<ClientMatchJSON>, ClientMatchJSON *, bool> generator("Type ClientMatch", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
