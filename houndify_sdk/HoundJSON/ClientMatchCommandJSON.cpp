/* file "ClientMatchCommandJSON.cpp" */

/* Generated automatically by Classy JSON. */

#include "ClientMatchCommandJSON.h"


void ClientMatchCommandJSON::TypeNativeDataJSON::fromJSONResult(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    setResult(json_value);
  }

ClientMatchCommandJSON::TypeNativeDataJSON *ClientMatchCommandJSON::TypeNativeDataJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    TypeNativeDataJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<TypeNativeDataJSON>, TypeNativeDataJSON *, bool> generator("Type TypeNativeData", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
void ClientMatchCommandJSON::fromJSONResult(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    setResult(json_value);
  }

void ClientMatchCommandJSON::fromJSONNativeData(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    TypeNativeDataJSON *convert_classy = TypeNativeDataJSON::from_json(json_value, ignore_extras);
    convert_classy->add_reference();
    setNativeData(convert_classy);
    convert_classy->remove_reference();
  }

void ClientMatchCommandJSON::fromJSONMatchedItem(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    ClientMatchJSON *convert_classy = ClientMatchJSON::from_json(json_value, ignore_extras);
    convert_classy->add_reference();
    setMatchedItem(convert_classy);
    convert_classy->remove_reference();
  }

ClientMatchCommandJSON *ClientMatchCommandJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    ClientMatchCommandJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<ClientMatchCommandJSON>, ClientMatchCommandJSON *, bool> generator("Type ClientMatchCommand", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
