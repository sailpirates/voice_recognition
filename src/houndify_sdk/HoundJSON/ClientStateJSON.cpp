/* file "ClientStateJSON.cpp" */

/* Generated automatically by Classy JSON. */

#include "ClientStateJSON.h"


void ClientStateJSON::fromJSONVerticalState(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    ClientVerticalStateJSON *convert_classy = ClientVerticalStateJSON::from_json(json_value, ignore_extras);
    convert_classy->add_reference();
    setVerticalState(convert_classy);
    convert_classy->remove_reference();
  }

ClientStateJSON *ClientStateJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    ClientStateJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<ClientStateJSON>, ClientStateJSON *, bool> generator("Type ClientState", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
