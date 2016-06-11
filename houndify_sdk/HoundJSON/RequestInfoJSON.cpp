/* file "RequestInfoJSON.cpp" */

/* Generated automatically by Classy JSON. */

#include "RequestInfoJSON.h"


char RequestInfoJSON::Generator::lowerBoundPreferredImageSize[] = "1";
char RequestInfoJSON::Generator::lowerBoundClientVersion_1[] = "0";
char RequestInfoJSON::Generator::lowerBoundMinResults[] = "1";
char RequestInfoJSON::Generator::lowerBoundMaxResults[] = "1";
void RequestInfoJSON::fromJSONLatitude(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field Latitude of RequestInfoJSON is not a number.");
          }
      }
    setLatitude(the_double);
  }

void RequestInfoJSON::fromJSONLongitude(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field Longitude of RequestInfoJSON is not a number.");
          }
      }
    setLongitude(the_double);
  }

void RequestInfoJSON::fromJSONPositionTime(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONIntegerValue *json_integer = json_value->integer_value();
    if (json_integer == NULL)
        throw("The value for field PositionTime of RequestInfoJSON is not an integer.");
    setPositionTime(OInteger(json_integer->getData()));
  }

void RequestInfoJSON::fromJSONPositionHorizontalAccuracy(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field PositionHorizontalAccuracy of RequestInfoJSON is not a number.");
          }
      }
    setPositionHorizontalAccuracy(the_double);
  }

void RequestInfoJSON::fromJSONStreet(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field Street of RequestInfoJSON is not a string.");
    setStreet(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONCity(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field City of RequestInfoJSON is not a string.");
    setCity(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONState(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field State of RequestInfoJSON is not a string.");
    setState(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONCountry(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field Country of RequestInfoJSON is not a string.");
    setCountry(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONControllableTrackPlaying(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field ControllableTrackPlaying of RequestInfoJSON is not true for false.");
          }
      }
    setControllableTrackPlaying(the_bool);
  }

void RequestInfoJSON::fromJSONTimeStamp(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONIntegerValue *json_integer = json_value->integer_value();
    if (json_integer == NULL)
        throw("The value for field TimeStamp of RequestInfoJSON is not an integer.");
    setTimeStamp(OInteger(json_integer->getData()));
  }

void RequestInfoJSON::fromJSONTimeZone(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field TimeZone of RequestInfoJSON is not a string.");
    setTimeZone(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONConversationState(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    ConversationStateJSON *convert_classy = ConversationStateJSON::from_json(json_value, ignore_extras);
    convert_classy->add_reference();
    setConversationState(convert_classy);
    convert_classy->remove_reference();
  }

void RequestInfoJSON::fromJSONConversationStateTime(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONIntegerValue *json_integer = json_value->integer_value();
    if (json_integer == NULL)
        throw("The value for field ConversationStateTime of RequestInfoJSON is not an integer.");
    setConversationStateTime(OInteger(json_integer->getData()));
  }

void RequestInfoJSON::fromJSONClientState(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    ClientStateJSON *convert_classy = ClientStateJSON::from_json(json_value, ignore_extras);
    convert_classy->add_reference();
    setClientState(convert_classy);
    convert_classy->remove_reference();
  }

void RequestInfoJSON::fromJSONSendBack(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    setSendBack(json_value);
  }

void RequestInfoJSON::fromJSONPreferredImageSize(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    JSONArrayValue *json_array1 = json_value->array_value();
    if (json_array1 == NULL)
        throw("The value for field PreferredImageSize of RequestInfoJSON is not an array.");
    size_t count1 = json_array1->componentCount();
    if (count1 < 2)
        throw("The value for field PreferredImageSize of RequestInfoJSON has too few elements.");
    std::vector< OInteger > vector_PreferredImageSize1(count1);
    for (size_t num1 = 0; num1 < count1; ++num1)
      {
        const JSONIntegerValue *json_integer = json_array1->component(num1)->integer_value();
        if (json_integer == NULL)
            throw("The value for an element of field PreferredImageSize of RequestInfoJSON is not an integer.");
        vector_PreferredImageSize1[num1] = OInteger(json_integer->getData());
      }
    assert(vector_PreferredImageSize1.size() >= 2);
    initPreferredImageSize();
    for (size_t num1 = 0; num1 < vector_PreferredImageSize1.size(); ++num1)
        appendPreferredImageSize(vector_PreferredImageSize1[num1]);
    for (size_t num1 = 0; num1 < vector_PreferredImageSize1.size(); ++num1)
      {
      }
  }

void RequestInfoJSON::fromJSONInputLanguage(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field InputLanguage of RequestInfoJSON is not a string.");
    setInputLanguage(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONOutputLanguage(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field OutputLanguage of RequestInfoJSON is not a string.");
    setOutputLanguage(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONResultVersionAccepted(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field ResultVersionAccepted of RequestInfoJSON is not a number.");
          }
      }
    setResultVersionAccepted(the_double);
  }

void RequestInfoJSON::fromJSONUnitPreference(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field UnitPreference of RequestInfoJSON is not a string.");
    TypeUnitPreference the_enum;
    if (strcmp(json_string->getData(), "US") == 0)
        the_enum = UnitPreference_US;
    else if (strcmp(json_string->getData(), "METRIC") == 0)
        the_enum = UnitPreference_METRIC;
    else
        throw("The value for field UnitPreference of RequestInfoJSON is not one of the legal strings.");
    setUnitPreference(the_enum);
  }

void RequestInfoJSON::fromJSONClientID(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field ClientID of RequestInfoJSON is not a string.");
    setClientID(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONClientVersion(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    TypeClientVersion or_result;
    bool or_done = false;
    if (!or_done)
      {
        try
          {
            const JSONStringValue *json_string = json_value->string_value();
            if (json_string == NULL)
                throw("The value for ??? is not a string.");
            or_result.choice0 = std::string(json_string->getData());
            or_result.key = 0;
            or_done = true;
          }
        catch (char *e1)
          {
            free(e1);
          }
        catch (const char *e1)
          {
          }
      }
    if (!or_done)
      {
        try
          {
            const JSONIntegerValue *json_integer = json_value->integer_value();
            if (json_integer == NULL)
                throw("The value for ??? is not an integer.");
            if (OInteger(json_integer->getData()) < 0)
                throw("The value for ??? is less than the lower bound (0) for that field.");
            or_result.choice1 = OInteger(json_integer->getData());
            or_result.key = 1;
            or_done = true;
          }
        catch (char *e1)
          {
            free(e1);
          }
        catch (const char *e1)
          {
          }
      }
    if (!or_done)
        throw("The value for field ClientVersion of RequestInfoJSON is not one of the allowed values.");
    setClientVersion(or_result);
    switch (or_result.key)
      {
        case 0:
            break;
        case 1:
            break;
        default:
            assert(false);
      }
  }

void RequestInfoJSON::fromJSONDeviceID(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field DeviceID of RequestInfoJSON is not a string.");
    setDeviceID(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONSDK(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field SDK of RequestInfoJSON is not a string.");
    setSDK(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONSDKInfo(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    if (json_value->object_value() == NULL)
        throw("The value for field SDKInfo of RequestInfoJSON is not an object.");
    json_value->object_value()->add_reference();
    setSDKInfo(json_value->object_value());
    json_value->object_value()->remove_reference();
  }

void RequestInfoJSON::fromJSONFirstPersonSelf(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field FirstPersonSelf of RequestInfoJSON is not a string.");
    setFirstPersonSelf(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONFirstPersonSelfSpoken(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field FirstPersonSelfSpoken of RequestInfoJSON is not a string.");
    setFirstPersonSelfSpoken(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONSecondPersonSelf(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    JSONArrayValue *json_array1 = json_value->array_value();
    if (json_array1 == NULL)
        throw("The value for field SecondPersonSelf of RequestInfoJSON is not an array.");
    size_t count1 = json_array1->componentCount();
    std::vector< std::string > vector_SecondPersonSelf1(count1);
    for (size_t num1 = 0; num1 < count1; ++num1)
      {
        const JSONStringValue *json_string = json_array1->component(num1)->string_value();
        if (json_string == NULL)
            throw("The value for an element of field SecondPersonSelf of RequestInfoJSON is not a string.");
        vector_SecondPersonSelf1[num1] = std::string(json_string->getData());
      }
    initSecondPersonSelf();
    for (size_t num2 = 0; num2 < vector_SecondPersonSelf1.size(); ++num2)
        appendSecondPersonSelf(vector_SecondPersonSelf1[num2]);
    for (size_t num1 = 0; num1 < vector_SecondPersonSelf1.size(); ++num1)
      {
      }
  }

void RequestInfoJSON::fromJSONSecondPersonSelfSpoken(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    JSONArrayValue *json_array1 = json_value->array_value();
    if (json_array1 == NULL)
        throw("The value for field SecondPersonSelfSpoken of RequestInfoJSON is not an array.");
    size_t count1 = json_array1->componentCount();
    std::vector< std::string > vector_SecondPersonSelfSpoken1(count1);
    for (size_t num1 = 0; num1 < count1; ++num1)
      {
        const JSONStringValue *json_string = json_array1->component(num1)->string_value();
        if (json_string == NULL)
            throw("The value for an element of field SecondPersonSelfSpoken of RequestInfoJSON is not a string.");
        vector_SecondPersonSelfSpoken1[num1] = std::string(json_string->getData());
      }
    initSecondPersonSelfSpoken();
    for (size_t num3 = 0; num3 < vector_SecondPersonSelfSpoken1.size(); ++num3)
        appendSecondPersonSelfSpoken(vector_SecondPersonSelfSpoken1[num3]);
    for (size_t num1 = 0; num1 < vector_SecondPersonSelfSpoken1.size(); ++num1)
      {
      }
  }

void RequestInfoJSON::fromJSONWakeUpPattern(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field WakeUpPattern of RequestInfoJSON is not a string.");
    setWakeUpPattern(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONUserID(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field UserID of RequestInfoJSON is not a string.");
    setUserID(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONRequestID(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field RequestID of RequestInfoJSON is not a string.");
    setRequestID(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONSessionID(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONStringValue *json_string = json_value->string_value();
    if (json_string == NULL)
        throw("The value for field SessionID of RequestInfoJSON is not a string.");
    setSessionID(std::string(json_string->getData()));
  }

void RequestInfoJSON::fromJSONResultUpdateAllowed(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field ResultUpdateAllowed of RequestInfoJSON is not true for false.");
          }
      }
    setResultUpdateAllowed(the_bool);
  }

void RequestInfoJSON::fromJSONPartialTranscriptsDesired(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field PartialTranscriptsDesired of RequestInfoJSON is not true for false.");
          }
      }
    setPartialTranscriptsDesired(the_bool);
  }

void RequestInfoJSON::fromJSONMinResults(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONIntegerValue *json_integer = json_value->integer_value();
    if (json_integer == NULL)
        throw("The value for field MinResults of RequestInfoJSON is not an integer.");
    setMinResults(OInteger(json_integer->getData()));
  }

void RequestInfoJSON::fromJSONMaxResults(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONIntegerValue *json_integer = json_value->integer_value();
    if (json_integer == NULL)
        throw("The value for field MaxResults of RequestInfoJSON is not an integer.");
    setMaxResults(OInteger(json_integer->getData()));
  }

void RequestInfoJSON::fromJSONObjectByteCountPrefix(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field ObjectByteCountPrefix of RequestInfoJSON is not true for false.");
          }
      }
    setObjectByteCountPrefix(the_bool);
  }

void RequestInfoJSON::fromJSONClientMatches(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    JSONArrayValue *json_array1 = json_value->array_value();
    if (json_array1 == NULL)
        throw("The value for field ClientMatches of RequestInfoJSON is not an array.");
    size_t count1 = json_array1->componentCount();
    if (count1 < 1)
        throw("The value for field ClientMatches of RequestInfoJSON has too few elements.");
    std::vector< ClientMatchJSON * > vector_ClientMatches1(count1);
    for (size_t num1 = 0; num1 < count1; ++num1)
      {
        ClientMatchJSON *convert_classy = ClientMatchJSON::from_json(json_array1->component(num1), ignore_extras);
        convert_classy->add_reference();
        vector_ClientMatches1[num1] = convert_classy;
      }
    assert(vector_ClientMatches1.size() >= 1);
    initClientMatches();
    for (size_t num4 = 0; num4 < vector_ClientMatches1.size(); ++num4)
        appendClientMatches(vector_ClientMatches1[num4]);
    for (size_t num1 = 0; num1 < vector_ClientMatches1.size(); ++num1)
      {
        vector_ClientMatches1[num1]->remove_reference();
      }
  }

void RequestInfoJSON::fromJSONClientMatchesOnly(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field ClientMatchesOnly of RequestInfoJSON is not true for false.");
          }
      }
    setClientMatchesOnly(the_bool);
  }

void RequestInfoJSON::fromJSONUseContactData(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field UseContactData of RequestInfoJSON is not true for false.");
          }
      }
    setUseContactData(the_bool);
  }

void RequestInfoJSON::fromJSONUseClientTime(JSONValue *json_value, bool ignore_extras)
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
            throw("The value for field UseClientTime of RequestInfoJSON is not true for false.");
          }
      }
    setUseClientTime(the_bool);
  }

void RequestInfoJSON::fromJSONForceConversationStateTime(JSONValue *json_value, bool ignore_extras)
  {
    assert(json_value != NULL);
    const JSONIntegerValue *json_integer = json_value->integer_value();
    if (json_integer == NULL)
        throw("The value for field ForceConversationStateTime of RequestInfoJSON is not an integer.");
    setForceConversationStateTime(OInteger(json_integer->getData()));
  }

RequestInfoJSON *RequestInfoJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    RequestInfoJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<RequestInfoJSON>, RequestInfoJSON *, bool> generator("Type RequestInfo", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
