/* file "BuildInfoJSON.cpp" */

/* Generated automatically by Classy JSON. */

#include "BuildInfoJSON.h"


void BuildInfoJSON::fromJSONUser(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field User of BuildInfoJSON is not a string.");
    setUser(std::string(json_string->getData()));
  }

void BuildInfoJSON::fromJSONDate(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field Date of BuildInfoJSON is not a string.");
    setDate(std::string(json_string->getData()));
  }

void BuildInfoJSON::fromJSONMachine(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field Machine of BuildInfoJSON is not a string.");
    setMachine(std::string(json_string->getData()));
  }

void BuildInfoJSON::fromJSONSVNRevision(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field SVNRevision of BuildInfoJSON is not a string.");
    setSVNRevision(std::string(json_string->getData()));
  }

void BuildInfoJSON::fromJSONSVNBranch(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field SVNBranch of BuildInfoJSON is not a string.");
    setSVNBranch(std::string(json_string->getData()));
  }

void BuildInfoJSON::fromJSONBuildNumber(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field BuildNumber of BuildInfoJSON is not a string.");
    setBuildNumber(std::string(json_string->getData()));
  }

void BuildInfoJSON::fromJSONKind(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field Kind of BuildInfoJSON is not a string.");
    setKind(std::string(json_string->getData()));
  }

void BuildInfoJSON::fromJSONVariant(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field Variant of BuildInfoJSON is not a string.");
    setVariant(std::string(json_string->getData()));
  }

BuildInfoJSON *BuildInfoJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    BuildInfoJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<BuildInfoJSON>, BuildInfoJSON *, bool> generator("Type BuildInfo", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
