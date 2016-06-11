/* file "RequestInfoJSON.h" */

/* Generated automatically by Classy JSON. */


#ifndef REQUESTINFOJSON_H
#define REQUESTINFOJSON_H

#include "JSONRep.h"
#include "JSONHoldingGenerator.h"
#include "JSONObjectGenerator.h"
#include "JSONObjectValueGenerator.h"
#include "JSONHoldingArrayGenerator.h"
#include "JSONStringGenerator.h"
#include "JSONDoubleGenerator.h"
#include "JSONIntegerUnboundRangeGenerator.h"
#include "JSONIntegerLowerBoundOnlyGenerator.h"
#include "JSONBooleanGenerator.h"
#include "JSONParallelGenerator.h"
#include <vector>
#include <string>
#include <OInteger.h>
#include "ConversationStateJSON.h"
#include "ClientStateJSON.h"
#include "ClientMatchJSON.h"
#include "JSONHandler.h"
#include "JSONCheckingHandler.h"
#include "ReferenceCounted.h"
#include "RCHandle.h"
#include "JSONParse.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


class RequestInfoJSON : public ReferenceCounted
  {
  public:
    enum TypeUnitPreference
      {
        UnitPreference_US,
        UnitPreference_METRIC
      };

    static TypeUnitPreference stringToUnitPreference(const char *chars)
      {
        if (strcmp(chars, "US") == 0)
            return UnitPreference_US;
        else if (strcmp(chars, "METRIC") == 0)
            return UnitPreference_METRIC;
        else
            throw("The value for field `UnitPreference' is not one of the legal values.");
      }

    static const char *stringFromUnitPreference(TypeUnitPreference the_enum)
      {
        switch (the_enum)
          {
            case UnitPreference_US:
                return "US";
            case UnitPreference_METRIC:
                return "METRIC";
            default:
                assert(false);
                return NULL;
          }
      }

    struct TypeClientVersion
      {
        size_t key;
        std::string choice0;
        OInteger choice1;
      };

  private:
    bool flagHasLatitude;
    double storeLatitude;
    bool flagHasLongitude;
    double storeLongitude;
    bool flagHasPositionTime;
    OInteger storePositionTime;
    bool flagHasPositionHorizontalAccuracy;
    double storePositionHorizontalAccuracy;
    bool flagHasStreet;
    std::string storeStreet;
    bool flagHasCity;
    std::string storeCity;
    bool flagHasState;
    std::string storeState;
    bool flagHasCountry;
    std::string storeCountry;
    bool flagHasControllableTrackPlaying;
    bool storeControllableTrackPlaying;
    bool flagHasTimeStamp;
    OInteger storeTimeStamp;
    bool flagHasTimeZone;
    std::string storeTimeZone;
    bool flagHasConversationState;
    ConversationStateJSON * storeConversationState;
    bool flagHasConversationStateTime;
    OInteger storeConversationStateTime;
    bool flagHasClientState;
    ClientStateJSON * storeClientState;
    bool flagHasSendBack;
    JSONValue * storeSendBack;
    bool flagHasPreferredImageSize;
    std::vector< OInteger > storePreferredImageSize;
    bool flagHasInputLanguage;
    std::string storeInputLanguage;
    bool flagHasOutputLanguage;
    std::string storeOutputLanguage;
    bool flagHasResultVersionAccepted;
    double storeResultVersionAccepted;
    bool flagHasUnitPreference;
    TypeUnitPreference storeUnitPreference;
    bool flagHasClientID;
    std::string storeClientID;
    bool flagHasClientVersion;
    TypeClientVersion storeClientVersion;
    bool flagHasDeviceID;
    std::string storeDeviceID;
    bool flagHasSDK;
    std::string storeSDK;
    bool flagHasSDKInfo;
    JSONObjectValue * storeSDKInfo;
    bool flagHasFirstPersonSelf;
    std::string storeFirstPersonSelf;
    bool flagHasFirstPersonSelfSpoken;
    std::string storeFirstPersonSelfSpoken;
    bool flagHasSecondPersonSelf;
    std::vector< std::string > storeSecondPersonSelf;
    bool flagHasSecondPersonSelfSpoken;
    std::vector< std::string > storeSecondPersonSelfSpoken;
    bool flagHasWakeUpPattern;
    std::string storeWakeUpPattern;
    bool flagHasUserID;
    std::string storeUserID;
    bool flagHasRequestID;
    std::string storeRequestID;
    bool flagHasSessionID;
    std::string storeSessionID;
    bool flagHasResultUpdateAllowed;
    bool storeResultUpdateAllowed;
    bool flagHasPartialTranscriptsDesired;
    bool storePartialTranscriptsDesired;
    bool flagHasMinResults;
    OInteger storeMinResults;
    bool flagHasMaxResults;
    OInteger storeMaxResults;
    bool flagHasObjectByteCountPrefix;
    bool storeObjectByteCountPrefix;
    bool flagHasClientMatches;
    std::vector< ClientMatchJSON * > storeClientMatches;
    bool flagHasClientMatchesOnly;
    bool storeClientMatchesOnly;
    bool flagHasUseContactData;
    bool storeUseContactData;
    bool flagHasUseClientTime;
    bool storeUseClientTime;
    bool flagHasForceConversationStateTime;
    OInteger storeForceConversationStateTime;

    RequestInfoJSON(const RequestInfoJSON &)  { assert(false); }
    RequestInfoJSON &operator=(const RequestInfoJSON &other)  { assert(false); throw "Illegal operator=() call."; }


    void fromJSONLatitude(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONLongitude(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONPositionTime(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONPositionHorizontalAccuracy(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONStreet(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONCity(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONState(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONCountry(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONControllableTrackPlaying(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONTimeStamp(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONTimeZone(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONConversationState(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONConversationStateTime(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONClientState(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONSendBack(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONPreferredImageSize(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONInputLanguage(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONOutputLanguage(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONResultVersionAccepted(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONUnitPreference(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONClientID(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONClientVersion(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONDeviceID(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONSDK(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONSDKInfo(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONFirstPersonSelf(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONFirstPersonSelfSpoken(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONSecondPersonSelf(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONSecondPersonSelfSpoken(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONWakeUpPattern(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONUserID(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONRequestID(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONSessionID(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONResultUpdateAllowed(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONPartialTranscriptsDesired(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONMinResults(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONMaxResults(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONObjectByteCountPrefix(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONClientMatches(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONClientMatchesOnly(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONUseContactData(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONUseClientTime(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONForceConversationStateTime(JSONValue *json_value, bool ignore_extras = false);

  public:
    RequestInfoJSON(void) :
            flagHasLatitude(false),
            flagHasLongitude(false),
            flagHasPositionTime(false),
            flagHasPositionHorizontalAccuracy(false),
            flagHasStreet(false),
            flagHasCity(false),
            flagHasState(false),
            flagHasCountry(false),
            flagHasControllableTrackPlaying(false),
            flagHasTimeStamp(false),
            flagHasTimeZone(false),
            flagHasConversationState(false),
            flagHasConversationStateTime(false),
            flagHasClientState(false),
            flagHasSendBack(false),
            flagHasPreferredImageSize(false),
            flagHasInputLanguage(false),
            flagHasOutputLanguage(false),
            flagHasResultVersionAccepted(false),
            flagHasUnitPreference(false),
            flagHasClientID(false),
            flagHasClientVersion(false),
            flagHasDeviceID(false),
            flagHasSDK(false),
            flagHasSDKInfo(false),
            flagHasFirstPersonSelf(false),
            flagHasFirstPersonSelfSpoken(false),
            flagHasSecondPersonSelf(false),
            flagHasSecondPersonSelfSpoken(false),
            flagHasWakeUpPattern(false),
            flagHasUserID(false),
            flagHasRequestID(false),
            flagHasSessionID(false),
            flagHasResultUpdateAllowed(false),
            flagHasPartialTranscriptsDesired(false),
            flagHasMinResults(false),
            flagHasMaxResults(false),
            flagHasObjectByteCountPrefix(false),
            flagHasClientMatches(false),
            flagHasClientMatchesOnly(false),
            flagHasUseContactData(false),
            flagHasUseClientTime(false),
            flagHasForceConversationStateTime(false)
      {
        storeControllableTrackPlaying = false;
        storeInputLanguage = "English";
        storeOutputLanguage = "English";
        storeFirstPersonSelf = "Hound";
        std::string element1;
        element1 = "Hound";
        storeSecondPersonSelf.push_back(element1);
        storeWakeUpPattern = "[[\"OK\"] . \"Hound\"]";
        storeResultUpdateAllowed = false;
        storePartialTranscriptsDesired = false;
        storeMinResults = 1;
        storeMaxResults = 1;
        storeObjectByteCountPrefix = false;
        storeClientMatchesOnly = false;
        storeUseContactData = true;
        storeUseClientTime = false;
      }
    virtual ~RequestInfoJSON(void)
      {
        if (flagHasConversationState)
          {
            storeConversationState->remove_reference();
          }
        if (flagHasClientState)
          {
            storeClientState->remove_reference();
          }
        if (flagHasSendBack)
          {
            storeSendBack->remove_reference();
          }
        if (flagHasSDKInfo)
          {
            storeSDKInfo->remove_reference();
          }
        if (flagHasClientMatches)
          {
            for (size_t num1 = 0; num1 < storeClientMatches.size(); ++num1)
              {
                storeClientMatches[num1]->remove_reference();
              }
          }
      }

    bool hasLatitude(void) const  { return flagHasLatitude; }
    double getLatitude(void)
      {
        assert(flagHasLatitude);
        return storeLatitude;
      }
    const double getLatitude(void) const
      {
        assert(flagHasLatitude);
        return storeLatitude;
      }
    bool hasLongitude(void) const  { return flagHasLongitude; }
    double getLongitude(void)
      {
        assert(flagHasLongitude);
        return storeLongitude;
      }
    const double getLongitude(void) const
      {
        assert(flagHasLongitude);
        return storeLongitude;
      }
    bool hasPositionTime(void) const  { return flagHasPositionTime; }
    OInteger getPositionTime(void)
      {
        assert(flagHasPositionTime);
        return storePositionTime;
      }
    const OInteger getPositionTime(void) const
      {
        assert(flagHasPositionTime);
        return storePositionTime;
      }
    bool hasPositionHorizontalAccuracy(void) const  { return flagHasPositionHorizontalAccuracy; }
    double getPositionHorizontalAccuracy(void)
      {
        assert(flagHasPositionHorizontalAccuracy);
        return storePositionHorizontalAccuracy;
      }
    const double getPositionHorizontalAccuracy(void) const
      {
        assert(flagHasPositionHorizontalAccuracy);
        return storePositionHorizontalAccuracy;
      }
    bool hasStreet(void) const  { return flagHasStreet; }
    std::string getStreet(void)
      {
        assert(flagHasStreet);
        return storeStreet;
      }
    const std::string getStreet(void) const
      {
        assert(flagHasStreet);
        return storeStreet;
      }
    bool hasCity(void) const  { return flagHasCity; }
    std::string getCity(void)
      {
        assert(flagHasCity);
        return storeCity;
      }
    const std::string getCity(void) const
      {
        assert(flagHasCity);
        return storeCity;
      }
    bool hasState(void) const  { return flagHasState; }
    std::string getState(void)
      {
        assert(flagHasState);
        return storeState;
      }
    const std::string getState(void) const
      {
        assert(flagHasState);
        return storeState;
      }
    bool hasCountry(void) const  { return flagHasCountry; }
    std::string getCountry(void)
      {
        assert(flagHasCountry);
        return storeCountry;
      }
    const std::string getCountry(void) const
      {
        assert(flagHasCountry);
        return storeCountry;
      }
    bool hasControllableTrackPlaying(void) const  { return flagHasControllableTrackPlaying; }
    bool getControllableTrackPlaying(void)
      {
        return storeControllableTrackPlaying;
      }
    const bool getControllableTrackPlaying(void) const
      {
        return storeControllableTrackPlaying;
      }
    bool hasTimeStamp(void) const  { return flagHasTimeStamp; }
    OInteger getTimeStamp(void)
      {
        assert(flagHasTimeStamp);
        return storeTimeStamp;
      }
    const OInteger getTimeStamp(void) const
      {
        assert(flagHasTimeStamp);
        return storeTimeStamp;
      }
    bool hasTimeZone(void) const  { return flagHasTimeZone; }
    std::string getTimeZone(void)
      {
        assert(flagHasTimeZone);
        return storeTimeZone;
      }
    const std::string getTimeZone(void) const
      {
        assert(flagHasTimeZone);
        return storeTimeZone;
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
    bool hasConversationStateTime(void) const  { return flagHasConversationStateTime; }
    OInteger getConversationStateTime(void)
      {
        assert(flagHasConversationStateTime);
        return storeConversationStateTime;
      }
    const OInteger getConversationStateTime(void) const
      {
        assert(flagHasConversationStateTime);
        return storeConversationStateTime;
      }
    bool hasClientState(void) const  { return flagHasClientState; }
    ClientStateJSON * getClientState(void)
      {
        assert(flagHasClientState);
        return storeClientState;
      }
    const ClientStateJSON * getClientState(void) const
      {
        assert(flagHasClientState);
        return storeClientState;
      }
    bool hasSendBack(void) const  { return flagHasSendBack; }
    JSONValue * getSendBack(void)
      {
        assert(flagHasSendBack);
        return storeSendBack;
      }
    const JSONValue * getSendBack(void) const
      {
        assert(flagHasSendBack);
        return storeSendBack;
      }
    bool hasPreferredImageSize(void) const  { return flagHasPreferredImageSize; }
    size_t countOfPreferredImageSize(void) const
      {
        assert(flagHasPreferredImageSize);
        return storePreferredImageSize.size();
      }
    OInteger elementOfPreferredImageSize(size_t element_num)
      {
        assert(flagHasPreferredImageSize);
        return storePreferredImageSize[element_num];
      }
    const OInteger elementOfPreferredImageSize(size_t element_num) const
      {
        assert(flagHasPreferredImageSize);
        return storePreferredImageSize[element_num];
      }
    std::vector< OInteger > getPreferredImageSize(void)
      {
        assert(flagHasPreferredImageSize);
        return storePreferredImageSize;
      }
    const std::vector< OInteger > getPreferredImageSize(void) const
      {
        assert(flagHasPreferredImageSize);
        return storePreferredImageSize;
      }
    bool hasInputLanguage(void) const  { return flagHasInputLanguage; }
    std::string getInputLanguage(void)
      {
        return storeInputLanguage;
      }
    const std::string getInputLanguage(void) const
      {
        return storeInputLanguage;
      }
    bool hasOutputLanguage(void) const  { return flagHasOutputLanguage; }
    std::string getOutputLanguage(void)
      {
        return storeOutputLanguage;
      }
    const std::string getOutputLanguage(void) const
      {
        return storeOutputLanguage;
      }
    bool hasResultVersionAccepted(void) const  { return flagHasResultVersionAccepted; }
    double getResultVersionAccepted(void)
      {
        assert(flagHasResultVersionAccepted);
        return storeResultVersionAccepted;
      }
    const double getResultVersionAccepted(void) const
      {
        assert(flagHasResultVersionAccepted);
        return storeResultVersionAccepted;
      }
    bool hasUnitPreference(void) const  { return flagHasUnitPreference; }
    TypeUnitPreference getUnitPreference(void)
      {
        assert(flagHasUnitPreference);
        return storeUnitPreference;
      }
    const TypeUnitPreference getUnitPreference(void) const
      {
        assert(flagHasUnitPreference);
        return storeUnitPreference;
      }
    const char *getUnitPreferenceAsChars(void) const
      {
        return stringFromUnitPreference(getUnitPreference());
      }
    std::string getUnitPreferenceAsString(void) const
      {
        return stringFromUnitPreference(getUnitPreference());
      }
    bool hasClientID(void) const  { return flagHasClientID; }
    std::string getClientID(void)
      {
        assert(flagHasClientID);
        return storeClientID;
      }
    const std::string getClientID(void) const
      {
        assert(flagHasClientID);
        return storeClientID;
      }
    bool hasClientVersion(void) const  { return flagHasClientVersion; }
    TypeClientVersion getClientVersion(void)
      {
        assert(flagHasClientVersion);
        return storeClientVersion;
      }
    const TypeClientVersion getClientVersion(void) const
      {
        assert(flagHasClientVersion);
        return storeClientVersion;
      }
    bool hasDeviceID(void) const  { return flagHasDeviceID; }
    std::string getDeviceID(void)
      {
        assert(flagHasDeviceID);
        return storeDeviceID;
      }
    const std::string getDeviceID(void) const
      {
        assert(flagHasDeviceID);
        return storeDeviceID;
      }
    bool hasSDK(void) const  { return flagHasSDK; }
    std::string getSDK(void)
      {
        assert(flagHasSDK);
        return storeSDK;
      }
    const std::string getSDK(void) const
      {
        assert(flagHasSDK);
        return storeSDK;
      }
    bool hasSDKInfo(void) const  { return flagHasSDKInfo; }
    JSONObjectValue * getSDKInfo(void)
      {
        assert(flagHasSDKInfo);
        return storeSDKInfo;
      }
    const JSONObjectValue * getSDKInfo(void) const
      {
        assert(flagHasSDKInfo);
        return storeSDKInfo;
      }
    bool hasFirstPersonSelf(void) const  { return flagHasFirstPersonSelf; }
    std::string getFirstPersonSelf(void)
      {
        return storeFirstPersonSelf;
      }
    const std::string getFirstPersonSelf(void) const
      {
        return storeFirstPersonSelf;
      }
    bool hasFirstPersonSelfSpoken(void) const  { return flagHasFirstPersonSelfSpoken; }
    std::string getFirstPersonSelfSpoken(void)
      {
        assert(flagHasFirstPersonSelfSpoken);
        return storeFirstPersonSelfSpoken;
      }
    const std::string getFirstPersonSelfSpoken(void) const
      {
        assert(flagHasFirstPersonSelfSpoken);
        return storeFirstPersonSelfSpoken;
      }
    bool hasSecondPersonSelf(void) const  { return flagHasSecondPersonSelf; }
    size_t countOfSecondPersonSelf(void) const
      {
        return storeSecondPersonSelf.size();
      }
    std::string elementOfSecondPersonSelf(size_t element_num)
      {
        return storeSecondPersonSelf[element_num];
      }
    const std::string elementOfSecondPersonSelf(size_t element_num) const
      {
        return storeSecondPersonSelf[element_num];
      }
    std::vector< std::string > getSecondPersonSelf(void)
      {
        return storeSecondPersonSelf;
      }
    const std::vector< std::string > getSecondPersonSelf(void) const
      {
        return storeSecondPersonSelf;
      }
    bool hasSecondPersonSelfSpoken(void) const  { return flagHasSecondPersonSelfSpoken; }
    size_t countOfSecondPersonSelfSpoken(void) const
      {
        assert(flagHasSecondPersonSelfSpoken);
        return storeSecondPersonSelfSpoken.size();
      }
    std::string elementOfSecondPersonSelfSpoken(size_t element_num)
      {
        assert(flagHasSecondPersonSelfSpoken);
        return storeSecondPersonSelfSpoken[element_num];
      }
    const std::string elementOfSecondPersonSelfSpoken(size_t element_num) const
      {
        assert(flagHasSecondPersonSelfSpoken);
        return storeSecondPersonSelfSpoken[element_num];
      }
    std::vector< std::string > getSecondPersonSelfSpoken(void)
      {
        assert(flagHasSecondPersonSelfSpoken);
        return storeSecondPersonSelfSpoken;
      }
    const std::vector< std::string > getSecondPersonSelfSpoken(void) const
      {
        assert(flagHasSecondPersonSelfSpoken);
        return storeSecondPersonSelfSpoken;
      }
    bool hasWakeUpPattern(void) const  { return flagHasWakeUpPattern; }
    std::string getWakeUpPattern(void)
      {
        return storeWakeUpPattern;
      }
    const std::string getWakeUpPattern(void) const
      {
        return storeWakeUpPattern;
      }
    bool hasUserID(void) const  { return flagHasUserID; }
    std::string getUserID(void)
      {
        assert(flagHasUserID);
        return storeUserID;
      }
    const std::string getUserID(void) const
      {
        assert(flagHasUserID);
        return storeUserID;
      }
    bool hasRequestID(void) const  { return flagHasRequestID; }
    std::string getRequestID(void)
      {
        assert(flagHasRequestID);
        return storeRequestID;
      }
    const std::string getRequestID(void) const
      {
        assert(flagHasRequestID);
        return storeRequestID;
      }
    bool hasSessionID(void) const  { return flagHasSessionID; }
    std::string getSessionID(void)
      {
        assert(flagHasSessionID);
        return storeSessionID;
      }
    const std::string getSessionID(void) const
      {
        assert(flagHasSessionID);
        return storeSessionID;
      }
    bool hasResultUpdateAllowed(void) const  { return flagHasResultUpdateAllowed; }
    bool getResultUpdateAllowed(void)
      {
        return storeResultUpdateAllowed;
      }
    const bool getResultUpdateAllowed(void) const
      {
        return storeResultUpdateAllowed;
      }
    bool hasPartialTranscriptsDesired(void) const  { return flagHasPartialTranscriptsDesired; }
    bool getPartialTranscriptsDesired(void)
      {
        return storePartialTranscriptsDesired;
      }
    const bool getPartialTranscriptsDesired(void) const
      {
        return storePartialTranscriptsDesired;
      }
    bool hasMinResults(void) const  { return flagHasMinResults; }
    OInteger getMinResults(void)
      {
        return storeMinResults;
      }
    const OInteger getMinResults(void) const
      {
        return storeMinResults;
      }
    bool hasMaxResults(void) const  { return flagHasMaxResults; }
    OInteger getMaxResults(void)
      {
        return storeMaxResults;
      }
    const OInteger getMaxResults(void) const
      {
        return storeMaxResults;
      }
    bool hasObjectByteCountPrefix(void) const  { return flagHasObjectByteCountPrefix; }
    bool getObjectByteCountPrefix(void)
      {
        return storeObjectByteCountPrefix;
      }
    const bool getObjectByteCountPrefix(void) const
      {
        return storeObjectByteCountPrefix;
      }
    bool hasClientMatches(void) const  { return flagHasClientMatches; }
    size_t countOfClientMatches(void) const
      {
        assert(flagHasClientMatches);
        return storeClientMatches.size();
      }
    ClientMatchJSON * elementOfClientMatches(size_t element_num)
      {
        assert(flagHasClientMatches);
        return storeClientMatches[element_num];
      }
    const ClientMatchJSON * elementOfClientMatches(size_t element_num) const
      {
        assert(flagHasClientMatches);
        return storeClientMatches[element_num];
      }
    std::vector< ClientMatchJSON * > getClientMatches(void)
      {
        assert(flagHasClientMatches);
        return storeClientMatches;
      }
    const std::vector< ClientMatchJSON * > getClientMatches(void) const
      {
        assert(flagHasClientMatches);
        return storeClientMatches;
      }
    bool hasClientMatchesOnly(void) const  { return flagHasClientMatchesOnly; }
    bool getClientMatchesOnly(void)
      {
        return storeClientMatchesOnly;
      }
    const bool getClientMatchesOnly(void) const
      {
        return storeClientMatchesOnly;
      }
    bool hasUseContactData(void) const  { return flagHasUseContactData; }
    bool getUseContactData(void)
      {
        return storeUseContactData;
      }
    const bool getUseContactData(void) const
      {
        return storeUseContactData;
      }
    bool hasUseClientTime(void) const  { return flagHasUseClientTime; }
    bool getUseClientTime(void)
      {
        return storeUseClientTime;
      }
    const bool getUseClientTime(void) const
      {
        return storeUseClientTime;
      }
    bool hasForceConversationStateTime(void) const  { return flagHasForceConversationStateTime; }
    OInteger getForceConversationStateTime(void)
      {
        assert(flagHasForceConversationStateTime);
        return storeForceConversationStateTime;
      }
    const OInteger getForceConversationStateTime(void) const
      {
        assert(flagHasForceConversationStateTime);
        return storeForceConversationStateTime;
      }


    void setLatitude(double new_value)
      {
        flagHasLatitude = true;
        if (new_value < -90)
            throw("The value for field Latitude of RequestInfoJSON is less than the lower bound (-90) for that field.");
        if (new_value > 90)
            throw("The value for field Latitude of RequestInfoJSON is greater than the upper bound (90) for that field.");
        storeLatitude = new_value;
      }
    void unsetLatitude(void)
      {
        flagHasLatitude = false;
      }
    void setLongitude(double new_value)
      {
        flagHasLongitude = true;
        if (new_value < -180)
            throw("The value for field Longitude of RequestInfoJSON is less than the lower bound (-180) for that field.");
        if (new_value > 180)
            throw("The value for field Longitude of RequestInfoJSON is greater than the upper bound (180) for that field.");
        storeLongitude = new_value;
      }
    void unsetLongitude(void)
      {
        flagHasLongitude = false;
      }
    void setPositionTime(OInteger new_value)
      {
        flagHasPositionTime = true;
        storePositionTime = new_value;
      }
    void unsetPositionTime(void)
      {
        flagHasPositionTime = false;
      }
    void setPositionHorizontalAccuracy(double new_value)
      {
        flagHasPositionHorizontalAccuracy = true;
        if (new_value < 0)
            throw("The value for field PositionHorizontalAccuracy of RequestInfoJSON is less than the lower bound (0) for that field.");
        storePositionHorizontalAccuracy = new_value;
      }
    void unsetPositionHorizontalAccuracy(void)
      {
        flagHasPositionHorizontalAccuracy = false;
      }
    void setStreet(std::string new_value)
      {
        flagHasStreet = true;
        storeStreet = new_value;
      }
    void unsetStreet(void)
      {
        flagHasStreet = false;
      }
    void setCity(std::string new_value)
      {
        flagHasCity = true;
        storeCity = new_value;
      }
    void unsetCity(void)
      {
        flagHasCity = false;
      }
    void setState(std::string new_value)
      {
        flagHasState = true;
        storeState = new_value;
      }
    void unsetState(void)
      {
        flagHasState = false;
      }
    void setCountry(std::string new_value)
      {
        flagHasCountry = true;
        storeCountry = new_value;
      }
    void unsetCountry(void)
      {
        flagHasCountry = false;
      }
    void setControllableTrackPlaying(bool new_value)
      {
        flagHasControllableTrackPlaying = true;
        storeControllableTrackPlaying = new_value;
      }
    void unsetControllableTrackPlaying(void)
      {
        flagHasControllableTrackPlaying = false;
      }
    void setTimeStamp(OInteger new_value)
      {
        flagHasTimeStamp = true;
        storeTimeStamp = new_value;
      }
    void unsetTimeStamp(void)
      {
        flagHasTimeStamp = false;
      }
    void setTimeZone(std::string new_value)
      {
        flagHasTimeZone = true;
        storeTimeZone = new_value;
      }
    void unsetTimeZone(void)
      {
        flagHasTimeZone = false;
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
    void setConversationStateTime(OInteger new_value)
      {
        flagHasConversationStateTime = true;
        storeConversationStateTime = new_value;
      }
    void unsetConversationStateTime(void)
      {
        flagHasConversationStateTime = false;
      }
    void setClientState(ClientStateJSON * new_value)
      {
        new_value->add_reference();
        if (flagHasClientState)
          {
            storeClientState->remove_reference();
          }
        flagHasClientState = true;
        storeClientState = new_value;
      }
    void unsetClientState(void)
      {
        if (flagHasClientState)
          {
            storeClientState->remove_reference();
          }
        flagHasClientState = false;
      }
    void setSendBack(JSONValue * new_value)
      {
        new_value->add_reference();
        if (flagHasSendBack)
          {
            storeSendBack->remove_reference();
          }
        flagHasSendBack = true;
        storeSendBack = new_value;
      }
    void unsetSendBack(void)
      {
        if (flagHasSendBack)
          {
            storeSendBack->remove_reference();
          }
        flagHasSendBack = false;
      }
    void initPreferredImageSize(void)
      {
        flagHasPreferredImageSize = true;
        storePreferredImageSize.clear();
      }
    void appendPreferredImageSize(OInteger to_append)
      {
        if (!flagHasPreferredImageSize)
          {
            flagHasPreferredImageSize = true;
            storePreferredImageSize.clear();
          }
        assert(flagHasPreferredImageSize);
        storePreferredImageSize.push_back(to_append);
      }
    void unsetPreferredImageSize(void)
      {
        flagHasPreferredImageSize = false;
        storePreferredImageSize.clear();
      }
    void setInputLanguage(std::string new_value)
      {
        flagHasInputLanguage = true;
        storeInputLanguage = new_value;
      }
    void unsetInputLanguage(void)
      {
        flagHasInputLanguage = false;
      }
    void setOutputLanguage(std::string new_value)
      {
        flagHasOutputLanguage = true;
        storeOutputLanguage = new_value;
      }
    void unsetOutputLanguage(void)
      {
        flagHasOutputLanguage = false;
      }
    void setResultVersionAccepted(double new_value)
      {
        flagHasResultVersionAccepted = true;
        if (new_value < 1)
            throw("The value for field ResultVersionAccepted of RequestInfoJSON is less than the lower bound (1) for that field.");
        storeResultVersionAccepted = new_value;
      }
    void unsetResultVersionAccepted(void)
      {
        flagHasResultVersionAccepted = false;
      }
    void setUnitPreference(TypeUnitPreference new_value)
      {
        flagHasUnitPreference = true;
        storeUnitPreference = new_value;
      }
    void setUnitPreference(const char *chars)
      {
        setUnitPreference(stringToUnitPreference(chars));
      }
    void setUnitPreference(std::string the_string)
      {
        setUnitPreference(stringToUnitPreference(the_string.c_str()));
      }
    void unsetUnitPreference(void)
      {
        flagHasUnitPreference = false;
      }
    void setClientID(std::string new_value)
      {
        flagHasClientID = true;
        storeClientID = new_value;
      }
    void unsetClientID(void)
      {
        flagHasClientID = false;
      }
    void setClientVersion(TypeClientVersion new_value)
      {
        flagHasClientVersion = true;
        switch (new_value.key)
          {
            case 0:
                break;
            case 1:
                if (new_value.choice1 < 0)
                    throw("The value for case 1 of field ClientVersion of RequestInfoJSON is less than the lower bound (0) for that field.");
                break;
            default:
                assert(false);
          }
        storeClientVersion = new_value;
      }
    void unsetClientVersion(void)
      {
        flagHasClientVersion = false;
      }
    void setDeviceID(std::string new_value)
      {
        flagHasDeviceID = true;
        storeDeviceID = new_value;
      }
    void unsetDeviceID(void)
      {
        flagHasDeviceID = false;
      }
    void setSDK(std::string new_value)
      {
        flagHasSDK = true;
        storeSDK = new_value;
      }
    void unsetSDK(void)
      {
        flagHasSDK = false;
      }
    void setSDKInfo(JSONObjectValue * new_value)
      {
        new_value->add_reference();
        if (flagHasSDKInfo)
          {
            storeSDKInfo->remove_reference();
          }
        flagHasSDKInfo = true;
        storeSDKInfo = new_value;
      }
    void unsetSDKInfo(void)
      {
        if (flagHasSDKInfo)
          {
            storeSDKInfo->remove_reference();
          }
        flagHasSDKInfo = false;
      }
    void setFirstPersonSelf(std::string new_value)
      {
        flagHasFirstPersonSelf = true;
        storeFirstPersonSelf = new_value;
      }
    void unsetFirstPersonSelf(void)
      {
        flagHasFirstPersonSelf = false;
      }
    void setFirstPersonSelfSpoken(std::string new_value)
      {
        flagHasFirstPersonSelfSpoken = true;
        storeFirstPersonSelfSpoken = new_value;
      }
    void unsetFirstPersonSelfSpoken(void)
      {
        flagHasFirstPersonSelfSpoken = false;
      }
    void initSecondPersonSelf(void)
      {
        flagHasSecondPersonSelf = true;
        storeSecondPersonSelf.clear();
      }
    void appendSecondPersonSelf(std::string to_append)
      {
        if (!flagHasSecondPersonSelf)
          {
            flagHasSecondPersonSelf = true;
            storeSecondPersonSelf.clear();
          }
        assert(flagHasSecondPersonSelf);
        storeSecondPersonSelf.push_back(to_append);
      }
    void unsetSecondPersonSelf(void)
      {
        flagHasSecondPersonSelf = false;
        storeSecondPersonSelf.clear();
      }
    void initSecondPersonSelfSpoken(void)
      {
        flagHasSecondPersonSelfSpoken = true;
        storeSecondPersonSelfSpoken.clear();
      }
    void appendSecondPersonSelfSpoken(std::string to_append)
      {
        if (!flagHasSecondPersonSelfSpoken)
          {
            flagHasSecondPersonSelfSpoken = true;
            storeSecondPersonSelfSpoken.clear();
          }
        assert(flagHasSecondPersonSelfSpoken);
        storeSecondPersonSelfSpoken.push_back(to_append);
      }
    void unsetSecondPersonSelfSpoken(void)
      {
        flagHasSecondPersonSelfSpoken = false;
        storeSecondPersonSelfSpoken.clear();
      }
    void setWakeUpPattern(std::string new_value)
      {
        flagHasWakeUpPattern = true;
        storeWakeUpPattern = new_value;
      }
    void unsetWakeUpPattern(void)
      {
        flagHasWakeUpPattern = false;
      }
    void setUserID(std::string new_value)
      {
        flagHasUserID = true;
        storeUserID = new_value;
      }
    void unsetUserID(void)
      {
        flagHasUserID = false;
      }
    void setRequestID(std::string new_value)
      {
        flagHasRequestID = true;
        storeRequestID = new_value;
      }
    void unsetRequestID(void)
      {
        flagHasRequestID = false;
      }
    void setSessionID(std::string new_value)
      {
        flagHasSessionID = true;
        storeSessionID = new_value;
      }
    void unsetSessionID(void)
      {
        flagHasSessionID = false;
      }
    void setResultUpdateAllowed(bool new_value)
      {
        flagHasResultUpdateAllowed = true;
        storeResultUpdateAllowed = new_value;
      }
    void unsetResultUpdateAllowed(void)
      {
        flagHasResultUpdateAllowed = false;
      }
    void setPartialTranscriptsDesired(bool new_value)
      {
        flagHasPartialTranscriptsDesired = true;
        storePartialTranscriptsDesired = new_value;
      }
    void unsetPartialTranscriptsDesired(void)
      {
        flagHasPartialTranscriptsDesired = false;
      }
    void setMinResults(OInteger new_value)
      {
        flagHasMinResults = true;
        if (new_value < 1)
            throw("The value for field MinResults of RequestInfoJSON is less than the lower bound (1) for that field.");
        storeMinResults = new_value;
      }
    void unsetMinResults(void)
      {
        flagHasMinResults = false;
      }
    void setMaxResults(OInteger new_value)
      {
        flagHasMaxResults = true;
        if (new_value < 1)
            throw("The value for field MaxResults of RequestInfoJSON is less than the lower bound (1) for that field.");
        storeMaxResults = new_value;
      }
    void unsetMaxResults(void)
      {
        flagHasMaxResults = false;
      }
    void setObjectByteCountPrefix(bool new_value)
      {
        flagHasObjectByteCountPrefix = true;
        storeObjectByteCountPrefix = new_value;
      }
    void unsetObjectByteCountPrefix(void)
      {
        flagHasObjectByteCountPrefix = false;
      }
    void initClientMatches(void)
      {
        if (flagHasClientMatches)
          {
            for (size_t num2 = 0; num2 < storeClientMatches.size(); ++num2)
              {
                storeClientMatches[num2]->remove_reference();
              }
          }
        flagHasClientMatches = true;
        storeClientMatches.clear();
      }
    void appendClientMatches(ClientMatchJSON * to_append)
      {
        if (!flagHasClientMatches)
          {
            flagHasClientMatches = true;
            storeClientMatches.clear();
          }
        assert(flagHasClientMatches);
        to_append->add_reference();
        storeClientMatches.push_back(to_append);
      }
    void unsetClientMatches(void)
      {
        if (flagHasClientMatches)
          {
            for (size_t num3 = 0; num3 < storeClientMatches.size(); ++num3)
              {
                storeClientMatches[num3]->remove_reference();
              }
          }
        flagHasClientMatches = false;
        storeClientMatches.clear();
      }
    void setClientMatchesOnly(bool new_value)
      {
        flagHasClientMatchesOnly = true;
        storeClientMatchesOnly = new_value;
      }
    void unsetClientMatchesOnly(void)
      {
        flagHasClientMatchesOnly = false;
      }
    void setUseContactData(bool new_value)
      {
        flagHasUseContactData = true;
        storeUseContactData = new_value;
      }
    void unsetUseContactData(void)
      {
        flagHasUseContactData = false;
      }
    void setUseClientTime(bool new_value)
      {
        flagHasUseClientTime = true;
        storeUseClientTime = new_value;
      }
    void unsetUseClientTime(void)
      {
        flagHasUseClientTime = false;
      }
    void setForceConversationStateTime(OInteger new_value)
      {
        flagHasForceConversationStateTime = true;
        storeForceConversationStateTime = new_value;
      }
    void unsetForceConversationStateTime(void)
      {
        flagHasForceConversationStateTime = false;
      }


    void write_as_json(JSONHandler *handler) const
      {
        handler->start_object();
        write_fields_as_json(handler);
        handler->finish_object();
      }

    virtual void write_fields_as_json(JSONHandler *handler)
 const
      {
        if (flagHasLatitude)
          {
            handler->start_pair("Latitude");
            if (((double)(long int)storeLatitude) == storeLatitude)
                handler->number_value((long int)storeLatitude);
            else
                handler->number_value(storeLatitude);
          }
        if (flagHasLongitude)
          {
            handler->start_pair("Longitude");
            if (((double)(long int)storeLongitude) == storeLongitude)
                handler->number_value((long int)storeLongitude);
            else
                handler->number_value(storeLongitude);
          }
        if (flagHasPositionTime)
          {
            handler->start_pair("PositionTime");
            handler->number_value(storePositionTime.get_o_integer());
          }
        if (flagHasPositionHorizontalAccuracy)
          {
            handler->start_pair("PositionHorizontalAccuracy");
            if (((double)(long int)storePositionHorizontalAccuracy) == storePositionHorizontalAccuracy)
                handler->number_value((long int)storePositionHorizontalAccuracy);
            else
                handler->number_value(storePositionHorizontalAccuracy);
          }
        if (flagHasStreet)
          {
            handler->start_pair("Street");
            handler->string_value(storeStreet);
          }
        if (flagHasCity)
          {
            handler->start_pair("City");
            handler->string_value(storeCity);
          }
        if (flagHasState)
          {
            handler->start_pair("State");
            handler->string_value(storeState);
          }
        if (flagHasCountry)
          {
            handler->start_pair("Country");
            handler->string_value(storeCountry);
          }
        if (flagHasControllableTrackPlaying)
          {
            handler->start_pair("ControllableTrackPlaying");
            handler->boolean_value(storeControllableTrackPlaying);
          }
        if (flagHasTimeStamp)
          {
            handler->start_pair("TimeStamp");
            handler->number_value(storeTimeStamp.get_o_integer());
          }
        if (flagHasTimeZone)
          {
            handler->start_pair("TimeZone");
            handler->string_value(storeTimeZone);
          }
        if (flagHasConversationState)
          {
            handler->start_pair("ConversationState");
            storeConversationState->write_as_json(handler);
          }
        if (flagHasConversationStateTime)
          {
            handler->start_pair("ConversationStateTime");
            handler->number_value(storeConversationStateTime.get_o_integer());
          }
        if (flagHasClientState)
          {
            handler->start_pair("ClientState");
            storeClientState->write_as_json(handler);
          }
        if (flagHasSendBack)
          {
            handler->start_pair("SendBack");
            storeSendBack->write(handler);
          }
        if (flagHasPreferredImageSize)
          {
            handler->start_pair("PreferredImageSize");
            assert(storePreferredImageSize.size() >= 2);
            handler->start_array();
            for (size_t num1 = 0; num1 < storePreferredImageSize.size(); ++num1)
              {
                handler->number_value(storePreferredImageSize[num1].get_o_integer());
              }
            handler->finish_array();
          }
        if (flagHasInputLanguage)
          {
            handler->start_pair("InputLanguage");
            handler->string_value(storeInputLanguage);
          }
        if (flagHasOutputLanguage)
          {
            handler->start_pair("OutputLanguage");
            handler->string_value(storeOutputLanguage);
          }
        if (flagHasResultVersionAccepted)
          {
            handler->start_pair("ResultVersionAccepted");
            if (((double)(long int)storeResultVersionAccepted) == storeResultVersionAccepted)
                handler->number_value((long int)storeResultVersionAccepted);
            else
                handler->number_value(storeResultVersionAccepted);
          }
        if (flagHasUnitPreference)
          {
            handler->start_pair("UnitPreference");
            switch (storeUnitPreference)
              {
                case UnitPreference_US:
                    handler->string_value("US");
                    break;
                case UnitPreference_METRIC:
                    handler->string_value("METRIC");
                    break;
                default:
                    assert(false);
              }
          }
        if (flagHasClientID)
          {
            handler->start_pair("ClientID");
            handler->string_value(storeClientID);
          }
        if (flagHasClientVersion)
          {
            handler->start_pair("ClientVersion");
            switch (storeClientVersion.key)
              {
                case 0:
                    handler->string_value(storeClientVersion.choice0);
                    break;
                case 1:
                    handler->number_value(storeClientVersion.choice1.get_o_integer());
                    break;
                default:
                    assert(false);
              }
          }
        if (flagHasDeviceID)
          {
            handler->start_pair("DeviceID");
            handler->string_value(storeDeviceID);
          }
        if (flagHasSDK)
          {
            handler->start_pair("SDK");
            handler->string_value(storeSDK);
          }
        if (flagHasSDKInfo)
          {
            handler->start_pair("SDKInfo");
            storeSDKInfo->write(handler);
          }
        if (flagHasFirstPersonSelf)
          {
            handler->start_pair("FirstPersonSelf");
            handler->string_value(storeFirstPersonSelf);
          }
        if (flagHasFirstPersonSelfSpoken)
          {
            handler->start_pair("FirstPersonSelfSpoken");
            handler->string_value(storeFirstPersonSelfSpoken);
          }
        if (flagHasSecondPersonSelf)
          {
            handler->start_pair("SecondPersonSelf");
            handler->start_array();
            for (size_t num2 = 0; num2 < storeSecondPersonSelf.size(); ++num2)
              {
                handler->string_value(storeSecondPersonSelf[num2]);
              }
            handler->finish_array();
          }
        if (flagHasSecondPersonSelfSpoken)
          {
            handler->start_pair("SecondPersonSelfSpoken");
            handler->start_array();
            for (size_t num3 = 0; num3 < storeSecondPersonSelfSpoken.size(); ++num3)
              {
                handler->string_value(storeSecondPersonSelfSpoken[num3]);
              }
            handler->finish_array();
          }
        if (flagHasWakeUpPattern)
          {
            handler->start_pair("WakeUpPattern");
            handler->string_value(storeWakeUpPattern);
          }
        if (flagHasUserID)
          {
            handler->start_pair("UserID");
            handler->string_value(storeUserID);
          }
        if (flagHasRequestID)
          {
            handler->start_pair("RequestID");
            handler->string_value(storeRequestID);
          }
        if (flagHasSessionID)
          {
            handler->start_pair("SessionID");
            handler->string_value(storeSessionID);
          }
        if (flagHasResultUpdateAllowed)
          {
            handler->start_pair("ResultUpdateAllowed");
            handler->boolean_value(storeResultUpdateAllowed);
          }
        if (flagHasPartialTranscriptsDesired)
          {
            handler->start_pair("PartialTranscriptsDesired");
            handler->boolean_value(storePartialTranscriptsDesired);
          }
        if (flagHasMinResults)
          {
            handler->start_pair("MinResults");
            handler->number_value(storeMinResults.get_o_integer());
          }
        if (flagHasMaxResults)
          {
            handler->start_pair("MaxResults");
            handler->number_value(storeMaxResults.get_o_integer());
          }
        if (flagHasObjectByteCountPrefix)
          {
            handler->start_pair("ObjectByteCountPrefix");
            handler->boolean_value(storeObjectByteCountPrefix);
          }
        if (flagHasClientMatches)
          {
            handler->start_pair("ClientMatches");
            assert(storeClientMatches.size() >= 1);
            handler->start_array();
            for (size_t num4 = 0; num4 < storeClientMatches.size(); ++num4)
              {
                storeClientMatches[num4]->write_as_json(handler);
              }
            handler->finish_array();
          }
        if (flagHasClientMatchesOnly)
          {
            handler->start_pair("ClientMatchesOnly");
            handler->boolean_value(storeClientMatchesOnly);
          }
        if (flagHasUseContactData)
          {
            handler->start_pair("UseContactData");
            handler->boolean_value(storeUseContactData);
          }
        if (flagHasUseClientTime)
          {
            handler->start_pair("UseClientTime");
            handler->boolean_value(storeUseClientTime);
          }
        if (flagHasForceConversationStateTime)
          {
            handler->start_pair("ForceConversationStateTime");
            handler->number_value(storeForceConversationStateTime.get_o_integer());
          }
      }

    static RequestInfoJSON *from_json(JSONValue *json_value, bool ignore_extras = false);
    static RequestInfoJSON *from_text(const char *text, bool ignore_extras = false)
      {
        RequestInfoJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<RequestInfoJSON>, RequestInfoJSON *, bool> generator("Type RequestInfo", ignore_extras);
            parse_json_value(text, &generator);
            assert(generator.have_value);
            result = generator.value.referenced();
            result->add_reference();
          };
        result->remove_reference_no_delete();
        return result;
      }
    static RequestInfoJSON *from_file(FILE *fp, const char *file_name, bool ignore_extras = false)
      {
        RequestInfoJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<RequestInfoJSON>, RequestInfoJSON *, bool> generator("Type RequestInfo", ignore_extras);
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
        JSONHoldingGenerator<JSONDoubleGenerator, double, double > fieldGeneratorLatitude;
        JSONHoldingGenerator<JSONDoubleGenerator, double, double > fieldGeneratorLongitude;
        JSONHoldingGenerator<JSONIntegerUnboundRangeGenerator, OInteger, o_integer > fieldGeneratorPositionTime;
        JSONHoldingGenerator<JSONDoubleGenerator, double, double > fieldGeneratorPositionHorizontalAccuracy;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorStreet;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorCity;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorState;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorCountry;
        JSONHoldingGenerator<JSONBooleanGenerator, bool, bool > fieldGeneratorControllableTrackPlaying;
        JSONHoldingGenerator<JSONIntegerUnboundRangeGenerator, OInteger, o_integer > fieldGeneratorTimeStamp;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorTimeZone;
        JSONHoldingGenerator<ConversationStateJSON::Generator, RCHandle<ConversationStateJSON>, ConversationStateJSON *, bool > fieldGeneratorConversationState;
        JSONHoldingGenerator<JSONIntegerUnboundRangeGenerator, OInteger, o_integer > fieldGeneratorConversationStateTime;
        JSONHoldingGenerator<ClientStateJSON::Generator, RCHandle<ClientStateJSON>, ClientStateJSON *, bool > fieldGeneratorClientState;
        JSONHoldingGenerator<JSONValueHandler, RCHandle<JSONValue>, JSONValue * > fieldGeneratorSendBack;
        static char lowerBoundPreferredImageSize[];
        JSONHoldingArrayGenerator<JSONIntegerLowerBoundOnlyGenerator<lowerBoundPreferredImageSize>, OInteger, o_integer > fieldGeneratorPreferredImageSize;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorInputLanguage;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorOutputLanguage;
        JSONHoldingGenerator<JSONDoubleGenerator, double, double > fieldGeneratorResultVersionAccepted;
    class FieldGeneratorUnitPreference : public JSONStringGenerator
          {
          protected:
            FieldGeneratorUnitPreference(const char *what)
              {
                set_what(what);
              }
            FieldGeneratorUnitPreference(void)
              {
              }
            void handle_result(const char *result)
              {
                handle_result(stringToUnitPreference(result));
              }
            virtual void handle_result(TypeUnitPreference result) = 0;
          };
        JSONHoldingGenerator<FieldGeneratorUnitPreference, TypeUnitPreference, TypeUnitPreference > fieldGeneratorUnitPreference;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorClientID;
        static char lowerBoundClientVersion_1[];
    class FieldGeneratorClientVersion : public JSONParallelGenerator
          {
          private:
            JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > field0;
            JSONHoldingGenerator<JSONIntegerLowerBoundOnlyGenerator<lowerBoundClientVersion_1>, OInteger, o_integer > field1;
            JSONHandler *all_handlers[2];

          protected:
            size_t start(JSONHandler ***parallel_handlers_location)
              {
                *parallel_handlers_location = &(all_handlers[0]);
                return 2;
              }
            void finish(size_t winning_index)
              {
                TypeClientVersion result;
                result.key = winning_index;
                switch (winning_index)
                  {
                    case 0:
                      {
                        assert(field0.have_value);
                        result.choice0 = field0.value;
                        break;
                      }
                    case 1:
                      {
                        assert(field1.have_value);
                        result.choice1 = field1.value;
                        break;
                      }
                    default:
                      {
                        assert(false);
                      }
                  }
                handle_result(result);
              }
            virtual void handle_result(TypeClientVersion result) = 0;

          public:
            FieldGeneratorClientVersion(bool ignore_extras) : field0("option 0 of field \"ClientVersion\""), field1("option 1 of field \"ClientVersion\"")
              {
                all_handlers[0] = &field0;
                all_handlers[1] = &field1;
              }
            FieldGeneratorClientVersion(std::string what, bool ignore_extras) : field0("option 0 of field \"ClientVersion\""), field1("option 1 of field \"ClientVersion\"")
              {
                all_handlers[0] = &field0;
                all_handlers[1] = &field1;
              }
            ~FieldGeneratorClientVersion(void)  { }

            void reset(void)
              {
                field0.reset();
                field1.reset();
                JSONParallelGenerator::reset();
              }
          };
        class HolderClientVersion
          {
          private:
            bool have_data;
            TypeClientVersion data;

          public:
            HolderClientVersion(void) : have_data(false)  { }
            HolderClientVersion(TypeClientVersion init_data) : have_data(true), data(init_data)
              {
                if (have_data)
                  {
                    switch (data.key)
                      {
                        case 0:
                          break;
                        case 1:
                          break;
                        default:
                          assert(false);
                      }
                  }
              }
            HolderClientVersion(const HolderClientVersion &other) : have_data(other.haveData()), data(other.referenced())
              {
                if (have_data)
                  {
                    switch (data.key)
                      {
                        case 0:
                          break;
                        case 1:
                          break;
                        default:
                          assert(false);
                      }
                  }
              }
            ~HolderClientVersion(void)
              {
                if (have_data)
                  {
                    switch (data.key)
                      {
                        case 0:
                          break;
                        case 1:
                          break;
                        default:
                          assert(false);
                      }
                  }
              }

            void operator=(const HolderClientVersion &other)
              {
                TypeClientVersion new_data;
                if (other.haveData())
                  {
                    new_data = other.referenced();
                    switch (new_data.key)
                      {
                        case 0:
                          break;
                        case 1:
                          break;
                        default:
                          assert(false);
                      }
                  }
                if (have_data)
                  {
                    switch (data.key)
                      {
                        case 0:
                          break;
                        case 1:
                          break;
                        default:
                          assert(false);
                      }
                  }
                have_data = other.haveData();
                if (have_data)
                    data = new_data;
              }
            bool haveData(void) const
              {
                return have_data;
              }
            TypeClientVersion referenced(void) const
              {
                return data;
              }
          };
        JSONHoldingGenerator<FieldGeneratorClientVersion, HolderClientVersion, TypeClientVersion, bool > fieldGeneratorClientVersion;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorDeviceID;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorSDK;
        JSONHoldingGenerator<JSONObjectValueGenerator, RCHandle<JSONObjectValue>, JSONObjectValue * > fieldGeneratorSDKInfo;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorFirstPersonSelf;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorFirstPersonSelfSpoken;
        JSONHoldingArrayGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorSecondPersonSelf;
        JSONHoldingArrayGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorSecondPersonSelfSpoken;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorWakeUpPattern;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorUserID;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorRequestID;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorSessionID;
        JSONHoldingGenerator<JSONBooleanGenerator, bool, bool > fieldGeneratorResultUpdateAllowed;
        JSONHoldingGenerator<JSONBooleanGenerator, bool, bool > fieldGeneratorPartialTranscriptsDesired;
        static char lowerBoundMinResults[];
        JSONHoldingGenerator<JSONIntegerLowerBoundOnlyGenerator<lowerBoundMinResults>, OInteger, o_integer > fieldGeneratorMinResults;
        static char lowerBoundMaxResults[];
        JSONHoldingGenerator<JSONIntegerLowerBoundOnlyGenerator<lowerBoundMaxResults>, OInteger, o_integer > fieldGeneratorMaxResults;
        JSONHoldingGenerator<JSONBooleanGenerator, bool, bool > fieldGeneratorObjectByteCountPrefix;
        JSONHoldingArrayGenerator<ClientMatchJSON::Generator, RCHandle<ClientMatchJSON>, ClientMatchJSON *, bool > fieldGeneratorClientMatches;
        JSONHoldingGenerator<JSONBooleanGenerator, bool, bool > fieldGeneratorClientMatchesOnly;
        JSONHoldingGenerator<JSONBooleanGenerator, bool, bool > fieldGeneratorUseContactData;
        JSONHoldingGenerator<JSONBooleanGenerator, bool, bool > fieldGeneratorUseClientTime;
        JSONHoldingGenerator<JSONIntegerUnboundRangeGenerator, OInteger, o_integer > fieldGeneratorForceConversationStateTime;
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
            RequestInfoJSON *result = new RequestInfoJSON();
            assert(result != NULL);
            RCHandle<RequestInfoJSON> result_holder = result;
            finish(result);
            handle_result(result);
          }
        void finish(RequestInfoJSON *result)
          {
            if (fieldGeneratorLatitude.have_value)
              {
                result->setLatitude(fieldGeneratorLatitude.value);
                fieldGeneratorLatitude.have_value = false;
              }
            if (fieldGeneratorLongitude.have_value)
              {
                result->setLongitude(fieldGeneratorLongitude.value);
                fieldGeneratorLongitude.have_value = false;
              }
            if (fieldGeneratorPositionTime.have_value)
              {
                result->setPositionTime(fieldGeneratorPositionTime.value);
                fieldGeneratorPositionTime.have_value = false;
              }
            if (fieldGeneratorPositionHorizontalAccuracy.have_value)
              {
                result->setPositionHorizontalAccuracy(fieldGeneratorPositionHorizontalAccuracy.value);
                fieldGeneratorPositionHorizontalAccuracy.have_value = false;
              }
            if (fieldGeneratorStreet.have_value)
              {
                result->setStreet(fieldGeneratorStreet.value);
                fieldGeneratorStreet.have_value = false;
              }
            if (fieldGeneratorCity.have_value)
              {
                result->setCity(fieldGeneratorCity.value);
                fieldGeneratorCity.have_value = false;
              }
            if (fieldGeneratorState.have_value)
              {
                result->setState(fieldGeneratorState.value);
                fieldGeneratorState.have_value = false;
              }
            if (fieldGeneratorCountry.have_value)
              {
                result->setCountry(fieldGeneratorCountry.value);
                fieldGeneratorCountry.have_value = false;
              }
            if (fieldGeneratorControllableTrackPlaying.have_value)
              {
                result->setControllableTrackPlaying(fieldGeneratorControllableTrackPlaying.value);
                fieldGeneratorControllableTrackPlaying.have_value = false;
              }
            if (fieldGeneratorTimeStamp.have_value)
              {
                result->setTimeStamp(fieldGeneratorTimeStamp.value);
                fieldGeneratorTimeStamp.have_value = false;
              }
            if (fieldGeneratorTimeZone.have_value)
              {
                result->setTimeZone(fieldGeneratorTimeZone.value);
                fieldGeneratorTimeZone.have_value = false;
              }
            if (fieldGeneratorConversationState.have_value)
              {
                result->setConversationState(fieldGeneratorConversationState.value.referenced());
                fieldGeneratorConversationState.have_value = false;
              }
            if (fieldGeneratorConversationStateTime.have_value)
              {
                result->setConversationStateTime(fieldGeneratorConversationStateTime.value);
                fieldGeneratorConversationStateTime.have_value = false;
              }
            if (fieldGeneratorClientState.have_value)
              {
                result->setClientState(fieldGeneratorClientState.value.referenced());
                fieldGeneratorClientState.have_value = false;
              }
            if (fieldGeneratorSendBack.have_value)
              {
                result->setSendBack(fieldGeneratorSendBack.value.referenced());
                fieldGeneratorSendBack.have_value = false;
              }
            if (fieldGeneratorPreferredImageSize.have_value)
              {
                result->initPreferredImageSize();
                size_t count = fieldGeneratorPreferredImageSize.value.size();
                for (size_t num = 0; num < count; ++num)
                  {
                    result->appendPreferredImageSize(fieldGeneratorPreferredImageSize.value[num]);
                  }
                fieldGeneratorPreferredImageSize.value.clear();
                fieldGeneratorPreferredImageSize.have_value = false;
              }
            if (fieldGeneratorInputLanguage.have_value)
              {
                result->setInputLanguage(fieldGeneratorInputLanguage.value);
                fieldGeneratorInputLanguage.have_value = false;
              }
            if (fieldGeneratorOutputLanguage.have_value)
              {
                result->setOutputLanguage(fieldGeneratorOutputLanguage.value);
                fieldGeneratorOutputLanguage.have_value = false;
              }
            if (fieldGeneratorResultVersionAccepted.have_value)
              {
                result->setResultVersionAccepted(fieldGeneratorResultVersionAccepted.value);
                fieldGeneratorResultVersionAccepted.have_value = false;
              }
            if (fieldGeneratorUnitPreference.have_value)
              {
                result->setUnitPreference(fieldGeneratorUnitPreference.value);
                fieldGeneratorUnitPreference.have_value = false;
              }
            if (fieldGeneratorClientID.have_value)
              {
                result->setClientID(fieldGeneratorClientID.value);
                fieldGeneratorClientID.have_value = false;
              }
            if (fieldGeneratorClientVersion.have_value)
              {
                result->setClientVersion(fieldGeneratorClientVersion.value.referenced());
                fieldGeneratorClientVersion.have_value = false;
              }
            if (fieldGeneratorDeviceID.have_value)
              {
                result->setDeviceID(fieldGeneratorDeviceID.value);
                fieldGeneratorDeviceID.have_value = false;
              }
            if (fieldGeneratorSDK.have_value)
              {
                result->setSDK(fieldGeneratorSDK.value);
                fieldGeneratorSDK.have_value = false;
              }
            if (fieldGeneratorSDKInfo.have_value)
              {
                result->setSDKInfo(fieldGeneratorSDKInfo.value.referenced());
                fieldGeneratorSDKInfo.have_value = false;
              }
            if (fieldGeneratorFirstPersonSelf.have_value)
              {
                result->setFirstPersonSelf(fieldGeneratorFirstPersonSelf.value);
                fieldGeneratorFirstPersonSelf.have_value = false;
              }
            if (fieldGeneratorFirstPersonSelfSpoken.have_value)
              {
                result->setFirstPersonSelfSpoken(fieldGeneratorFirstPersonSelfSpoken.value);
                fieldGeneratorFirstPersonSelfSpoken.have_value = false;
              }
            if (fieldGeneratorSecondPersonSelf.have_value)
              {
                result->initSecondPersonSelf();
                size_t count = fieldGeneratorSecondPersonSelf.value.size();
                for (size_t num = 0; num < count; ++num)
                  {
                    result->appendSecondPersonSelf(fieldGeneratorSecondPersonSelf.value[num]);
                  }
                fieldGeneratorSecondPersonSelf.value.clear();
                fieldGeneratorSecondPersonSelf.have_value = false;
              }
            if (fieldGeneratorSecondPersonSelfSpoken.have_value)
              {
                result->initSecondPersonSelfSpoken();
                size_t count = fieldGeneratorSecondPersonSelfSpoken.value.size();
                for (size_t num = 0; num < count; ++num)
                  {
                    result->appendSecondPersonSelfSpoken(fieldGeneratorSecondPersonSelfSpoken.value[num]);
                  }
                fieldGeneratorSecondPersonSelfSpoken.value.clear();
                fieldGeneratorSecondPersonSelfSpoken.have_value = false;
              }
            if (fieldGeneratorWakeUpPattern.have_value)
              {
                result->setWakeUpPattern(fieldGeneratorWakeUpPattern.value);
                fieldGeneratorWakeUpPattern.have_value = false;
              }
            if (fieldGeneratorUserID.have_value)
              {
                result->setUserID(fieldGeneratorUserID.value);
                fieldGeneratorUserID.have_value = false;
              }
            if (fieldGeneratorRequestID.have_value)
              {
                result->setRequestID(fieldGeneratorRequestID.value);
                fieldGeneratorRequestID.have_value = false;
              }
            if (fieldGeneratorSessionID.have_value)
              {
                result->setSessionID(fieldGeneratorSessionID.value);
                fieldGeneratorSessionID.have_value = false;
              }
            if (fieldGeneratorResultUpdateAllowed.have_value)
              {
                result->setResultUpdateAllowed(fieldGeneratorResultUpdateAllowed.value);
                fieldGeneratorResultUpdateAllowed.have_value = false;
              }
            if (fieldGeneratorPartialTranscriptsDesired.have_value)
              {
                result->setPartialTranscriptsDesired(fieldGeneratorPartialTranscriptsDesired.value);
                fieldGeneratorPartialTranscriptsDesired.have_value = false;
              }
            if (fieldGeneratorMinResults.have_value)
              {
                result->setMinResults(fieldGeneratorMinResults.value);
                fieldGeneratorMinResults.have_value = false;
              }
            if (fieldGeneratorMaxResults.have_value)
              {
                result->setMaxResults(fieldGeneratorMaxResults.value);
                fieldGeneratorMaxResults.have_value = false;
              }
            if (fieldGeneratorObjectByteCountPrefix.have_value)
              {
                result->setObjectByteCountPrefix(fieldGeneratorObjectByteCountPrefix.value);
                fieldGeneratorObjectByteCountPrefix.have_value = false;
              }
            if (fieldGeneratorClientMatches.have_value)
              {
                result->initClientMatches();
                size_t count = fieldGeneratorClientMatches.value.size();
                for (size_t num = 0; num < count; ++num)
                  {
                    result->appendClientMatches(fieldGeneratorClientMatches.value[num].referenced());
                  }
                fieldGeneratorClientMatches.value.clear();
                fieldGeneratorClientMatches.have_value = false;
              }
            if (fieldGeneratorClientMatchesOnly.have_value)
              {
                result->setClientMatchesOnly(fieldGeneratorClientMatchesOnly.value);
                fieldGeneratorClientMatchesOnly.have_value = false;
              }
            if (fieldGeneratorUseContactData.have_value)
              {
                result->setUseContactData(fieldGeneratorUseContactData.value);
                fieldGeneratorUseContactData.have_value = false;
              }
            if (fieldGeneratorUseClientTime.have_value)
              {
                result->setUseClientTime(fieldGeneratorUseClientTime.value);
                fieldGeneratorUseClientTime.have_value = false;
              }
            if (fieldGeneratorForceConversationStateTime.have_value)
              {
                result->setForceConversationStateTime(fieldGeneratorForceConversationStateTime.value);
                fieldGeneratorForceConversationStateTime.have_value = false;
              }
          }
        virtual void handle_result(RequestInfoJSON *new_result) = 0;
        virtual JSONHandler *start_known_field(const char *field_name)
          {
            switch (field_name[0])
              {
                case 'C':
                    switch (field_name[1])
                      {
                        case 'i':
                            if (strcmp(&(field_name[2]), "ty") == 0)
                                return &fieldGeneratorCity;
                            break;
                        case 'l':
                            if (strncmp(&(field_name[2]), "ient", 4) == 0)
                              {
                                switch (field_name[6])
                                  {
                                    case 'I':
                                        if (strcmp(&(field_name[7]), "D") == 0)
                                            return &fieldGeneratorClientID;
                                        break;
                                    case 'M':
                                        if (strncmp(&(field_name[7]), "atches", 6) == 0)
                                          {
                                            switch (field_name[13])
                                              {
                                                case 0:
                                                    return &fieldGeneratorClientMatches;
                                                case 'O':
                                                    if (strcmp(&(field_name[14]), "nly") == 0)
                                                        return &fieldGeneratorClientMatchesOnly;
                                                    break;
                                                default:
                                                    break;
                                              }
                                          }
                                        break;
                                    case 'S':
                                        if (strcmp(&(field_name[7]), "tate") == 0)
                                            return &fieldGeneratorClientState;
                                        break;
                                    case 'V':
                                        if (strcmp(&(field_name[7]), "ersion") == 0)
                                            return &fieldGeneratorClientVersion;
                                        break;
                                    default:
                                        break;
                                  }
                              }
                            break;
                        case 'o':
                            switch (field_name[2])
                              {
                                case 'n':
                                    switch (field_name[3])
                                      {
                                        case 't':
                                            if (strcmp(&(field_name[4]), "rollableTrackPlaying") == 0)
                                                return &fieldGeneratorControllableTrackPlaying;
                                            break;
                                        case 'v':
                                            if (strncmp(&(field_name[4]), "ersationState", 13) == 0)
                                              {
                                                switch (field_name[17])
                                                  {
                                                    case 0:
                                                        return &fieldGeneratorConversationState;
                                                    case 'T':
                                                        if (strcmp(&(field_name[18]), "ime") == 0)
                                                            return &fieldGeneratorConversationStateTime;
                                                        break;
                                                    default:
                                                        break;
                                                  }
                                              }
                                            break;
                                        default:
                                            break;
                                      }
                                    break;
                                case 'u':
                                    if (strcmp(&(field_name[3]), "ntry") == 0)
                                        return &fieldGeneratorCountry;
                                    break;
                                default:
                                    break;
                              }
                            break;
                        default:
                            break;
                      }
                    break;
                case 'D':
                    if (strcmp(&(field_name[1]), "eviceID") == 0)
                        return &fieldGeneratorDeviceID;
                    break;
                case 'F':
                    switch (field_name[1])
                      {
                        case 'i':
                            if (strncmp(&(field_name[2]), "rstPersonSelf", 13) == 0)
                              {
                                switch (field_name[15])
                                  {
                                    case 0:
                                        return &fieldGeneratorFirstPersonSelf;
                                    case 'S':
                                        if (strcmp(&(field_name[16]), "poken") == 0)
                                            return &fieldGeneratorFirstPersonSelfSpoken;
                                        break;
                                    default:
                                        break;
                                  }
                              }
                            break;
                        case 'o':
                            if (strcmp(&(field_name[2]), "rceConversationStateTime") == 0)
                                return &fieldGeneratorForceConversationStateTime;
                            break;
                        default:
                            break;
                      }
                    break;
                case 'I':
                    if (strcmp(&(field_name[1]), "nputLanguage") == 0)
                        return &fieldGeneratorInputLanguage;
                    break;
                case 'L':
                    switch (field_name[1])
                      {
                        case 'a':
                            if (strcmp(&(field_name[2]), "titude") == 0)
                                return &fieldGeneratorLatitude;
                            break;
                        case 'o':
                            if (strcmp(&(field_name[2]), "ngitude") == 0)
                                return &fieldGeneratorLongitude;
                            break;
                        default:
                            break;
                      }
                    break;
                case 'M':
                    switch (field_name[1])
                      {
                        case 'a':
                            if (strcmp(&(field_name[2]), "xResults") == 0)
                                return &fieldGeneratorMaxResults;
                            break;
                        case 'i':
                            if (strcmp(&(field_name[2]), "nResults") == 0)
                                return &fieldGeneratorMinResults;
                            break;
                        default:
                            break;
                      }
                    break;
                case 'O':
                    switch (field_name[1])
                      {
                        case 'b':
                            if (strcmp(&(field_name[2]), "jectByteCountPrefix") == 0)
                                return &fieldGeneratorObjectByteCountPrefix;
                            break;
                        case 'u':
                            if (strcmp(&(field_name[2]), "tputLanguage") == 0)
                                return &fieldGeneratorOutputLanguage;
                            break;
                        default:
                            break;
                      }
                    break;
                case 'P':
                    switch (field_name[1])
                      {
                        case 'a':
                            if (strcmp(&(field_name[2]), "rtialTranscriptsDesired") == 0)
                                return &fieldGeneratorPartialTranscriptsDesired;
                            break;
                        case 'o':
                            if (strncmp(&(field_name[2]), "sition", 6) == 0)
                              {
                                switch (field_name[8])
                                  {
                                    case 'H':
                                        if (strcmp(&(field_name[9]), "orizontalAccuracy") == 0)
                                            return &fieldGeneratorPositionHorizontalAccuracy;
                                        break;
                                    case 'T':
                                        if (strcmp(&(field_name[9]), "ime") == 0)
                                            return &fieldGeneratorPositionTime;
                                        break;
                                    default:
                                        break;
                                  }
                              }
                            break;
                        case 'r':
                            if (strcmp(&(field_name[2]), "eferredImageSize") == 0)
                                return &fieldGeneratorPreferredImageSize;
                            break;
                        default:
                            break;
                      }
                    break;
                case 'R':
                    if (strncmp(&(field_name[1]), "e", 1) == 0)
                      {
                        switch (field_name[2])
                          {
                            case 'q':
                                if (strcmp(&(field_name[3]), "uestID") == 0)
                                    return &fieldGeneratorRequestID;
                                break;
                            case 's':
                                if (strncmp(&(field_name[3]), "ult", 3) == 0)
                                  {
                                    switch (field_name[6])
                                      {
                                        case 'U':
                                            if (strcmp(&(field_name[7]), "pdateAllowed") == 0)
                                                return &fieldGeneratorResultUpdateAllowed;
                                            break;
                                        case 'V':
                                            if (strcmp(&(field_name[7]), "ersionAccepted") == 0)
                                                return &fieldGeneratorResultVersionAccepted;
                                            break;
                                        default:
                                            break;
                                      }
                                  }
                                break;
                            default:
                                break;
                          }
                      }
                    break;
                case 'S':
                    switch (field_name[1])
                      {
                        case 'D':
                            if (strncmp(&(field_name[2]), "K", 1) == 0)
                              {
                                switch (field_name[3])
                                  {
                                    case 0:
                                        return &fieldGeneratorSDK;
                                    case 'I':
                                        if (strcmp(&(field_name[4]), "nfo") == 0)
                                            return &fieldGeneratorSDKInfo;
                                        break;
                                    default:
                                        break;
                                  }
                              }
                            break;
                        case 'e':
                            switch (field_name[2])
                              {
                                case 'c':
                                    if (strncmp(&(field_name[3]), "ondPersonSelf", 13) == 0)
                                      {
                                        switch (field_name[16])
                                          {
                                            case 0:
                                                return &fieldGeneratorSecondPersonSelf;
                                            case 'S':
                                                if (strcmp(&(field_name[17]), "poken") == 0)
                                                    return &fieldGeneratorSecondPersonSelfSpoken;
                                                break;
                                            default:
                                                break;
                                          }
                                      }
                                    break;
                                case 'n':
                                    if (strcmp(&(field_name[3]), "dBack") == 0)
                                        return &fieldGeneratorSendBack;
                                    break;
                                case 's':
                                    if (strcmp(&(field_name[3]), "sionID") == 0)
                                        return &fieldGeneratorSessionID;
                                    break;
                                default:
                                    break;
                              }
                            break;
                        case 't':
                            switch (field_name[2])
                              {
                                case 'a':
                                    if (strcmp(&(field_name[3]), "te") == 0)
                                        return &fieldGeneratorState;
                                    break;
                                case 'r':
                                    if (strcmp(&(field_name[3]), "eet") == 0)
                                        return &fieldGeneratorStreet;
                                    break;
                                default:
                                    break;
                              }
                            break;
                        default:
                            break;
                      }
                    break;
                case 'T':
                    if (strncmp(&(field_name[1]), "ime", 3) == 0)
                      {
                        switch (field_name[4])
                          {
                            case 'S':
                                if (strcmp(&(field_name[5]), "tamp") == 0)
                                    return &fieldGeneratorTimeStamp;
                                break;
                            case 'Z':
                                if (strcmp(&(field_name[5]), "one") == 0)
                                    return &fieldGeneratorTimeZone;
                                break;
                            default:
                                break;
                          }
                      }
                    break;
                case 'U':
                    switch (field_name[1])
                      {
                        case 'n':
                            if (strcmp(&(field_name[2]), "itPreference") == 0)
                                return &fieldGeneratorUnitPreference;
                            break;
                        case 's':
                            if (strncmp(&(field_name[2]), "e", 1) == 0)
                              {
                                switch (field_name[3])
                                  {
                                    case 'C':
                                        switch (field_name[4])
                                          {
                                            case 'l':
                                                if (strcmp(&(field_name[5]), "ientTime") == 0)
                                                    return &fieldGeneratorUseClientTime;
                                                break;
                                            case 'o':
                                                if (strcmp(&(field_name[5]), "ntactData") == 0)
                                                    return &fieldGeneratorUseContactData;
                                                break;
                                            default:
                                                break;
                                          }
                                        break;
                                    case 'r':
                                        if (strcmp(&(field_name[4]), "ID") == 0)
                                            return &fieldGeneratorUserID;
                                        break;
                                    default:
                                        break;
                                  }
                              }
                            break;
                        default:
                            break;
                      }
                    break;
                case 'W':
                    if (strcmp(&(field_name[1]), "akeUpPattern") == 0)
                        return &fieldGeneratorWakeUpPattern;
                    break;
                default:
                    break;
              }
            return NULL;
          }

      public:
        Generator(bool ignore_extras = false) : fieldGeneratorLatitude("field \"Latitude\" of the RequestInfo class"), fieldGeneratorLongitude("field \"Longitude\" of the RequestInfo class"), fieldGeneratorPositionTime("field \"PositionTime\" of the RequestInfo class"), fieldGeneratorPositionHorizontalAccuracy("field \"PositionHorizontalAccuracy\" of the RequestInfo class"), fieldGeneratorStreet("field \"Street\" of the RequestInfo class"), fieldGeneratorCity("field \"City\" of the RequestInfo class"), fieldGeneratorState("field \"State\" of the RequestInfo class"), fieldGeneratorCountry("field \"Country\" of the RequestInfo class"), fieldGeneratorControllableTrackPlaying("field \"ControllableTrackPlaying\" of the RequestInfo class"), fieldGeneratorTimeStamp("field \"TimeStamp\" of the RequestInfo class"), fieldGeneratorTimeZone("field \"TimeZone\" of the RequestInfo class"), fieldGeneratorConversationState("field \"ConversationState\" of the RequestInfo class", ignore_extras), fieldGeneratorConversationStateTime("field \"ConversationStateTime\" of the RequestInfo class"), fieldGeneratorClientState("field \"ClientState\" of the RequestInfo class", ignore_extras), fieldGeneratorSendBack("field \"SendBack\" of the RequestInfo class"), fieldGeneratorPreferredImageSize("field \"PreferredImageSize\" of the RequestInfo class"), fieldGeneratorInputLanguage("field \"InputLanguage\" of the RequestInfo class"), fieldGeneratorOutputLanguage("field \"OutputLanguage\" of the RequestInfo class"), fieldGeneratorResultVersionAccepted("field \"ResultVersionAccepted\" of the RequestInfo class"), fieldGeneratorUnitPreference("field \"UnitPreference\" of the RequestInfo class"), fieldGeneratorClientID("field \"ClientID\" of the RequestInfo class"), fieldGeneratorClientVersion("field \"ClientVersion\" of the RequestInfo class", ignore_extras), fieldGeneratorDeviceID("field \"DeviceID\" of the RequestInfo class"), fieldGeneratorSDK("field \"SDK\" of the RequestInfo class"), fieldGeneratorSDKInfo("field \"SDKInfo\" of the RequestInfo class"), fieldGeneratorFirstPersonSelf("field \"FirstPersonSelf\" of the RequestInfo class"), fieldGeneratorFirstPersonSelfSpoken("field \"FirstPersonSelfSpoken\" of the RequestInfo class"), fieldGeneratorSecondPersonSelf("field \"SecondPersonSelf\" of the RequestInfo class"), fieldGeneratorSecondPersonSelfSpoken("field \"SecondPersonSelfSpoken\" of the RequestInfo class"), fieldGeneratorWakeUpPattern("field \"WakeUpPattern\" of the RequestInfo class"), fieldGeneratorUserID("field \"UserID\" of the RequestInfo class"), fieldGeneratorRequestID("field \"RequestID\" of the RequestInfo class"), fieldGeneratorSessionID("field \"SessionID\" of the RequestInfo class"), fieldGeneratorResultUpdateAllowed("field \"ResultUpdateAllowed\" of the RequestInfo class"), fieldGeneratorPartialTranscriptsDesired("field \"PartialTranscriptsDesired\" of the RequestInfo class"), fieldGeneratorMinResults("field \"MinResults\" of the RequestInfo class"), fieldGeneratorMaxResults("field \"MaxResults\" of the RequestInfo class"), fieldGeneratorObjectByteCountPrefix("field \"ObjectByteCountPrefix\" of the RequestInfo class"), fieldGeneratorClientMatches("field \"ClientMatches\" of the RequestInfo class", ignore_extras), fieldGeneratorClientMatchesOnly("field \"ClientMatchesOnly\" of the RequestInfo class"), fieldGeneratorUseContactData("field \"UseContactData\" of the RequestInfo class"), fieldGeneratorUseClientTime("field \"UseClientTime\" of the RequestInfo class"), fieldGeneratorForceConversationStateTime("field \"ForceConversationStateTime\" of the RequestInfo class")
          {
            set_what("the RequestInfo class");
          }
        ~Generator(void)
          {
          }

        void reset(void)
          {
            fieldGeneratorLatitude.reset();
            fieldGeneratorLongitude.reset();
            fieldGeneratorPositionTime.reset();
            fieldGeneratorPositionHorizontalAccuracy.reset();
            fieldGeneratorStreet.reset();
            fieldGeneratorCity.reset();
            fieldGeneratorState.reset();
            fieldGeneratorCountry.reset();
            fieldGeneratorControllableTrackPlaying.reset();
            fieldGeneratorTimeStamp.reset();
            fieldGeneratorTimeZone.reset();
            fieldGeneratorConversationState.reset();
            fieldGeneratorConversationStateTime.reset();
            fieldGeneratorClientState.reset();
            fieldGeneratorSendBack.reset();
            fieldGeneratorPreferredImageSize.reset();
            fieldGeneratorInputLanguage.reset();
            fieldGeneratorOutputLanguage.reset();
            fieldGeneratorResultVersionAccepted.reset();
            fieldGeneratorUnitPreference.reset();
            fieldGeneratorClientID.reset();
            fieldGeneratorClientVersion.reset();
            fieldGeneratorDeviceID.reset();
            fieldGeneratorSDK.reset();
            fieldGeneratorSDKInfo.reset();
            fieldGeneratorFirstPersonSelf.reset();
            fieldGeneratorFirstPersonSelfSpoken.reset();
            fieldGeneratorSecondPersonSelf.reset();
            fieldGeneratorSecondPersonSelfSpoken.reset();
            fieldGeneratorWakeUpPattern.reset();
            fieldGeneratorUserID.reset();
            fieldGeneratorRequestID.reset();
            fieldGeneratorSessionID.reset();
            fieldGeneratorResultUpdateAllowed.reset();
            fieldGeneratorPartialTranscriptsDesired.reset();
            fieldGeneratorMinResults.reset();
            fieldGeneratorMaxResults.reset();
            fieldGeneratorObjectByteCountPrefix.reset();
            fieldGeneratorClientMatches.reset();
            fieldGeneratorClientMatchesOnly.reset();
            fieldGeneratorUseContactData.reset();
            fieldGeneratorUseClientTime.reset();
            fieldGeneratorForceConversationStateTime.reset();
            JSONObjectGenerator::reset();
            unknownFieldGenerator.reset();
          }
      };
  };

#endif /* REQUESTINFOJSON_H */
