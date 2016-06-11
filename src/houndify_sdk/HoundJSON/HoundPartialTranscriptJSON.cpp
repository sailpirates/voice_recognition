/* file "HoundPartialTranscriptJSON.cpp" */

/* Generated automatically by Classy JSON. */

#include "HoundPartialTranscriptJSON.h"


void HoundPartialTranscriptJSON::fromJSONFormat(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field Format of HoundPartialTranscriptJSON is not a string.");
    TypeFormat the_enum;
    if (strcmp(json_string->getData(), "SoundHoundVoiceSearchParialTranscript") == 0)
        the_enum = Format_SoundHoundVoiceSearchParialTranscript;
    else if (strcmp(json_string->getData(), "HoundVoiceQueryPartialTranscript") == 0)
        the_enum = Format_HoundVoiceQueryPartialTranscript;
    else
        throw("The value for field Format of HoundPartialTranscriptJSON is not one of the legal strings.");
    setFormat(the_enum);
  }

void HoundPartialTranscriptJSON::fromJSONFormatVersion(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field FormatVersion of HoundPartialTranscriptJSON is not a string.");
    if (!(strcmp(json_string->getData(), "1.0") == 0))
        throw("The value for field FormatVersion of HoundPartialTranscriptJSON is not `1.0'.");
    setFormatVersion();
  }

void HoundPartialTranscriptJSON::fromJSONPartialTranscript(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field PartialTranscript of HoundPartialTranscriptJSON is not a string.");
    setPartialTranscript(std::string(json_string->getData()));
  }

void HoundPartialTranscriptJSON::fromJSONDurationMS(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONRationalValue *json_rational = json_value->rational_value();
    double the_double;
    if (json_rational != NULL)
      {
        the_double = json_rational->getDouble();
      }
    else
      {
        const JSONIntegerValue *json_integer = json_value->integer_value();
        if (json_integer != NULL)
          {
            the_double = json_integer->getLongInt();
          }
        else
          {
            throw("The value for field DurationMS of HoundPartialTranscriptJSON is not a number.");
          }
      }
    setDurationMS(the_double);
  }

void HoundPartialTranscriptJSON::fromJSONDone(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field Done of HoundPartialTranscriptJSON is not true for false.");
          }
      }
    setDone(the_bool);
  }

void HoundPartialTranscriptJSON::fromJSONSafeToStopAudio(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field SafeToStopAudio of HoundPartialTranscriptJSON is not true for false.");
          }
      }
    setSafeToStopAudio(the_bool);
  }

HoundPartialTranscriptJSON *HoundPartialTranscriptJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    HoundPartialTranscriptJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<HoundPartialTranscriptJSON>, HoundPartialTranscriptJSON *, bool> generator("Type HoundPartialTranscript", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
