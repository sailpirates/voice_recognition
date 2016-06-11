/* file "HoundServerJSON.cpp" */

/* Generated automatically by Classy JSON. */

#include "HoundServerJSON.h"


char HoundServerJSON::Generator::lowerBoundNumToReturn[] = "0";
char HoundServerJSON::TypeDisambiguationJSON::Generator::lowerBoundNumToShow[] = "1";
void HoundServerJSON::TypeDisambiguationJSON::TypeChoiceDataJSON::fromJSONTranscription(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field Transcription of TypeChoiceDataJSON is not a string.");
    setTranscription(std::string(json_string->getData()));
  }

void HoundServerJSON::TypeDisambiguationJSON::TypeChoiceDataJSON::fromJSONConfidenceScore(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field ConfidenceScore of TypeChoiceDataJSON is not a number.");
          }
      }
    setConfidenceScore(the_double);
  }

void HoundServerJSON::TypeDisambiguationJSON::TypeChoiceDataJSON::fromJSONFixedTranscription(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field FixedTranscription of TypeChoiceDataJSON is not a string.");
    setFixedTranscription(std::string(json_string->getData()));
  }

HoundServerJSON::TypeDisambiguationJSON::TypeChoiceDataJSON *HoundServerJSON::TypeDisambiguationJSON::TypeChoiceDataJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    TypeChoiceDataJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<TypeChoiceDataJSON>, TypeChoiceDataJSON *, bool> generator("Type TypeChoiceData", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
void HoundServerJSON::TypeDisambiguationJSON::fromJSONNumToShow(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONIntegerValue *json_integer = json_value->integer_value();
    if (json_integer == NULL)
        throw("The value for field NumToShow of TypeDisambiguationJSON is not an integer.");
    setNumToShow(OInteger(json_integer->getData()));
  }

void HoundServerJSON::TypeDisambiguationJSON::fromJSONChoiceData(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    JSONArrayValue *json_array1 = json_value->array_value();
    if (json_array1 == NULL)
        throw("The value for field ChoiceData of TypeDisambiguationJSON is not an array.");
    size_t count1 = json_array1->componentCount();
    if (count1 < 1)
        throw("The value for field ChoiceData of TypeDisambiguationJSON has too few elements.");
    std::vector< TypeChoiceDataJSON * > vector_ChoiceData1(count1);
    for (size_t num1 = 0; num1 < count1; ++num1)
      {
        TypeChoiceDataJSON *convert_classy = TypeChoiceDataJSON::from_json(json_array1->component(num1), ignore_extras);
        convert_classy->add_reference();
        vector_ChoiceData1[num1] = convert_classy;
      }
    assert(vector_ChoiceData1.size() >= 1);
    initChoiceData();
    for (size_t num1 = 0; num1 < vector_ChoiceData1.size(); ++num1)
        appendChoiceData(vector_ChoiceData1[num1]);
    for (size_t num1 = 0; num1 < vector_ChoiceData1.size(); ++num1)
      {
        vector_ChoiceData1[num1]->remove_reference();
      }
  }

HoundServerJSON::TypeDisambiguationJSON *HoundServerJSON::TypeDisambiguationJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    TypeDisambiguationJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<TypeDisambiguationJSON>, TypeDisambiguationJSON *, bool> generator("Type TypeDisambiguation", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
void HoundServerJSON::TypeDomainUsageJSON::fromJSONDomain(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field Domain of TypeDomainUsageJSON is not a string.");
    setDomain(std::string(json_string->getData()));
  }

void HoundServerJSON::TypeDomainUsageJSON::fromJSONDomainUniqueID(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field DomainUniqueID of TypeDomainUsageJSON is not a string.");
    setDomainUniqueID(std::string(json_string->getData()));
  }

void HoundServerJSON::TypeDomainUsageJSON::fromJSONCreditsUsed(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field CreditsUsed of TypeDomainUsageJSON is not a number.");
          }
      }
    setCreditsUsed(the_double);
  }

HoundServerJSON::TypeDomainUsageJSON *HoundServerJSON::TypeDomainUsageJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    TypeDomainUsageJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<TypeDomainUsageJSON>, TypeDomainUsageJSON *, bool> generator("Type TypeDomainUsage", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
void HoundServerJSON::fromJSONFormat(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field Format of HoundServerJSON is not a string.");
    TypeFormat the_enum;
    if (strcmp(json_string->getData(), "SoundHoundVoiceSearchResult") == 0)
        the_enum = Format_SoundHoundVoiceSearchResult;
    else if (strcmp(json_string->getData(), "HoundQueryResult") == 0)
        the_enum = Format_HoundQueryResult;
    else
        throw("The value for field Format of HoundServerJSON is not one of the legal strings.");
    setFormat(the_enum);
  }

void HoundServerJSON::fromJSONFormatVersion(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field FormatVersion of HoundServerJSON is not a string.");
    if (!(strcmp(json_string->getData(), "1.0") == 0))
        throw("The value for field FormatVersion of HoundServerJSON is not `1.0'.");
    setFormatVersion();
  }

void HoundServerJSON::fromJSONStatus(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field Status of HoundServerJSON is not a string.");
    TypeStatus the_enum;
    if (strcmp(json_string->getData(), "OK") == 0)
        the_enum = Status_OK;
    else if (strcmp(json_string->getData(), "Error") == 0)
        the_enum = Status_Error;
    else
        throw("The value for field Status of HoundServerJSON is not one of the legal strings.");
    setStatus(the_enum);
  }

void HoundServerJSON::fromJSONErrorMessage(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field ErrorMessage of HoundServerJSON is not a string.");
    setErrorMessage(std::string(json_string->getData()));
  }

void HoundServerJSON::fromJSONNumToReturn(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONIntegerValue *json_integer = json_value->integer_value();
    if (json_integer == NULL)
        throw("The value for field NumToReturn of HoundServerJSON is not an integer.");
    setNumToReturn(OInteger(json_integer->getData()));
  }

void HoundServerJSON::fromJSONAllResults(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    JSONArrayValue *json_array1 = json_value->array_value();
    if (json_array1 == NULL)
        throw("The value for field AllResults of HoundServerJSON is not an array.");
    size_t count1 = json_array1->componentCount();
    std::vector< CommandResultJSON * > vector_AllResults1(count1);
    for (size_t num1 = 0; num1 < count1; ++num1)
      {
        CommandResultJSON *convert_classy = CommandResultJSON::from_json(json_array1->component(num1), ignore_extras);
        convert_classy->add_reference();
        vector_AllResults1[num1] = convert_classy;
      }
    initAllResults();
    for (size_t num2 = 0; num2 < vector_AllResults1.size(); ++num2)
        appendAllResults(vector_AllResults1[num2]);
    for (size_t num1 = 0; num1 < vector_AllResults1.size(); ++num1)
      {
        vector_AllResults1[num1]->remove_reference();
      }
  }

void HoundServerJSON::fromJSONDisambiguation(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    TypeDisambiguationJSON *convert_classy = TypeDisambiguationJSON::from_json(json_value, ignore_extras);
    convert_classy->add_reference();
    setDisambiguation(convert_classy);
    convert_classy->remove_reference();
  }

void HoundServerJSON::fromJSONResultsAreFinal(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    JSONArrayValue *json_array1 = json_value->array_value();
    if (json_array1 == NULL)
        throw("The value for field ResultsAreFinal of HoundServerJSON is not an array.");
    size_t count1 = json_array1->componentCount();
    std::vector< bool > vector_ResultsAreFinal1(count1);
    for (size_t num1 = 0; num1 < count1; ++num1)
      {
        const JSONTrueValue *json_true = json_array1->component(num1)->true_value();
        bool the_bool;
        if (json_true != NULL)
          {
            the_bool = true;
          }
        else
          {
            const JSONFalseValue *json_false = json_array1->component(num1)->false_value();
            if (json_false != NULL)
              {
                the_bool = false;
              }
            else
              {
                throw("The value for an element of field ResultsAreFinal of HoundServerJSON is not true for false.");
              }
          }
        vector_ResultsAreFinal1[num1] = the_bool;
      }
    initResultsAreFinal();
    for (size_t num3 = 0; num3 < vector_ResultsAreFinal1.size(); ++num3)
        appendResultsAreFinal(vector_ResultsAreFinal1[num3]);
    for (size_t num1 = 0; num1 < vector_ResultsAreFinal1.size(); ++num1)
      {
      }
  }

void HoundServerJSON::fromJSONDomainUsage(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    JSONArrayValue *json_array1 = json_value->array_value();
    if (json_array1 == NULL)
        throw("The value for field DomainUsage of HoundServerJSON is not an array.");
    size_t count1 = json_array1->componentCount();
    std::vector< TypeDomainUsageJSON * > vector_DomainUsage1(count1);
    for (size_t num1 = 0; num1 < count1; ++num1)
      {
        TypeDomainUsageJSON *convert_classy = TypeDomainUsageJSON::from_json(json_array1->component(num1), ignore_extras);
        convert_classy->add_reference();
        vector_DomainUsage1[num1] = convert_classy;
      }
    initDomainUsage();
    for (size_t num4 = 0; num4 < vector_DomainUsage1.size(); ++num4)
        appendDomainUsage(vector_DomainUsage1[num4]);
    for (size_t num1 = 0; num1 < vector_DomainUsage1.size(); ++num1)
      {
        vector_DomainUsage1[num1]->remove_reference();
      }
  }

void HoundServerJSON::fromJSONBuildInfo(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    BuildInfoJSON *convert_classy = BuildInfoJSON::from_json(json_value, ignore_extras);
    convert_classy->add_reference();
    setBuildInfo(convert_classy);
    convert_classy->remove_reference();
  }

void HoundServerJSON::fromJSONServerGeneratedId(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field ServerGeneratedId of HoundServerJSON is not a string.");
    setServerGeneratedId(std::string(json_string->getData()));
  }

void HoundServerJSON::fromJSONAudioLength(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field AudioLength of HoundServerJSON is not a number.");
          }
      }
    setAudioLength(the_double);
  }

void HoundServerJSON::fromJSONRealSpeechTime(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field RealSpeechTime of HoundServerJSON is not a number.");
          }
      }
    setRealSpeechTime(the_double);
  }

void HoundServerJSON::fromJSONCpuSpeechTime(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field CpuSpeechTime of HoundServerJSON is not a number.");
          }
      }
    setCpuSpeechTime(the_double);
  }

void HoundServerJSON::fromJSONRealTime(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field RealTime of HoundServerJSON is not a number.");
          }
      }
    setRealTime(the_double);
  }

void HoundServerJSON::fromJSONCpuTime(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field CpuTime of HoundServerJSON is not a number.");
          }
      }
    setCpuTime(the_double);
  }

HoundServerJSON *HoundServerJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    HoundServerJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<HoundServerJSON>, HoundServerJSON *, bool> generator("Type HoundServer", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
