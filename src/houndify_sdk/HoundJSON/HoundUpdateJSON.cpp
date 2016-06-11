/* file "HoundUpdateJSON.cpp" */

/* Generated automatically by Classy JSON. */

#include "HoundUpdateJSON.h"


char HoundUpdateJSON::Generator::lowerBoundIndex[] = "0";
void HoundUpdateJSON::fromJSONFormat(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field Format of HoundUpdateJSON is not a string.");
    if (!(strcmp(json_string->getData(), "HoundQueryUpdate") == 0))
        throw("The value for field Format of HoundUpdateJSON is not `HoundQueryUpdate'.");
    setFormat();
  }

void HoundUpdateJSON::fromJSONFormatVersion(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field FormatVersion of HoundUpdateJSON is not a string.");
    if (!(strcmp(json_string->getData(), "1.0") == 0))
        throw("The value for field FormatVersion of HoundUpdateJSON is not `1.0'.");
    setFormatVersion();
  }

void HoundUpdateJSON::fromJSONIndex(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONIntegerValue *json_integer = json_value->integer_value();
    if (json_integer == NULL)
        throw("The value for field Index of HoundUpdateJSON is not an integer.");
    setIndex(OInteger(json_integer->getData()));
  }

void HoundUpdateJSON::fromJSONResult(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    CommandResultJSON *convert_classy = CommandResultJSON::from_json(json_value, ignore_extras);
    convert_classy->add_reference();
    setResult(convert_classy);
    convert_classy->remove_reference();
  }

void HoundUpdateJSON::fromJSONIsFinal(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field IsFinal of HoundUpdateJSON is not true for false.");
          }
      }
    setIsFinal(the_bool);
  }

HoundUpdateJSON *HoundUpdateJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    HoundUpdateJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<HoundUpdateJSON>, HoundUpdateJSON *, bool> generator("Type HoundUpdate", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
