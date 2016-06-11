/* file "HoundPartialTranscriptJSON.h" */

/* Generated automatically by Classy JSON. */


#ifndef HOUNDPARTIALTRANSCRIPTJSON_H
#define HOUNDPARTIALTRANSCRIPTJSON_H

#include "JSONRep.h"
#include "JSONHoldingGenerator.h"
#include "JSONObjectGenerator.h"
#include "JSONStringGenerator.h"
#include "JSONDoubleGenerator.h"
#include "JSONBooleanGenerator.h"
#include <string>
#include "JSONHandler.h"
#include "JSONCheckingHandler.h"
#include "ReferenceCounted.h"
#include "RCHandle.h"
#include "JSONParse.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


class HoundPartialTranscriptJSON : public ReferenceCounted
  {
  public:
    enum TypeFormat
      {
        Format_SoundHoundVoiceSearchParialTranscript,
        Format_HoundVoiceQueryPartialTranscript
      };

    static TypeFormat stringToFormat(const char *chars)
      {
        if (strcmp(chars, "SoundHoundVoiceSearchParialTranscript") == 0)
            return Format_SoundHoundVoiceSearchParialTranscript;
        else if (strcmp(chars, "HoundVoiceQueryPartialTranscript") == 0)
            return Format_HoundVoiceQueryPartialTranscript;
        else
            throw("The value for field `Format' is not one of the legal values.");
      }

    static const char *stringFromFormat(TypeFormat the_enum)
      {
        switch (the_enum)
          {
            case Format_SoundHoundVoiceSearchParialTranscript:
                return "SoundHoundVoiceSearchParialTranscript";
            case Format_HoundVoiceQueryPartialTranscript:
                return "HoundVoiceQueryPartialTranscript";
            default:
                assert(false);
                return NULL;
          }
      }

    enum TypeFormatVersion
      {
        FormatVersion_1_x2e_0
      };

    static TypeFormatVersion stringToFormatVersion(const char *chars)
      {
        if (strcmp(chars, "1.0") == 0)
            return FormatVersion_1_x2e_0;
        else
            throw("The value for field `FormatVersion' is not one of the legal values.");
      }

    static const char *stringFromFormatVersion(TypeFormatVersion the_enum)
      {
        switch (the_enum)
          {
            case FormatVersion_1_x2e_0:
                return "1.0";
            default:
                assert(false);
                return NULL;
          }
      }


  private:
    bool flagHasFormat;
    TypeFormat storeFormat;
    bool flagHasFormatVersion;
    bool flagHasPartialTranscript;
    std::string storePartialTranscript;
    bool flagHasDurationMS;
    double storeDurationMS;
    bool flagHasDone;
    bool storeDone;
    bool flagHasSafeToStopAudio;
    bool storeSafeToStopAudio;

    HoundPartialTranscriptJSON(const HoundPartialTranscriptJSON &)  { assert(false); }
    HoundPartialTranscriptJSON &operator=(const HoundPartialTranscriptJSON &other)  { assert(false); throw "Illegal operator=() call."; }


    void fromJSONFormat(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONFormatVersion(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONPartialTranscript(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONDurationMS(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONDone(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONSafeToStopAudio(JSONValue *json_value, bool ignore_extras = false);

  public:
    HoundPartialTranscriptJSON(void) :
            flagHasFormat(false),
            flagHasFormatVersion(false),
            flagHasPartialTranscript(false),
            flagHasDurationMS(false),
            flagHasDone(false),
            flagHasSafeToStopAudio(false)
      {
      }
    virtual ~HoundPartialTranscriptJSON(void)
      {
      }

    bool hasFormat(void) const  { return flagHasFormat; }
    TypeFormat getFormat(void)
      {
        assert(flagHasFormat);
        return storeFormat;
      }
    const TypeFormat getFormat(void) const
      {
        assert(flagHasFormat);
        return storeFormat;
      }
    const char *getFormatAsChars(void) const
      {
        return stringFromFormat(getFormat());
      }
    std::string getFormatAsString(void) const
      {
        return stringFromFormat(getFormat());
      }
    bool hasFormatVersion(void) const  { return flagHasFormatVersion; }
    TypeFormatVersion getFormatVersion(void)
      {
        assert(flagHasFormatVersion);
        return FormatVersion_1_x2e_0;
      }
    const TypeFormatVersion getFormatVersion(void) const
      {
        assert(flagHasFormatVersion);
        return FormatVersion_1_x2e_0;
      }
    const char *getFormatVersionAsChars(void) const
      {
        return stringFromFormatVersion(getFormatVersion());
      }
    std::string getFormatVersionAsString(void) const
      {
        return stringFromFormatVersion(getFormatVersion());
      }
    bool hasPartialTranscript(void) const  { return flagHasPartialTranscript; }
    std::string getPartialTranscript(void)
      {
        assert(flagHasPartialTranscript);
        return storePartialTranscript;
      }
    const std::string getPartialTranscript(void) const
      {
        assert(flagHasPartialTranscript);
        return storePartialTranscript;
      }
    bool hasDurationMS(void) const  { return flagHasDurationMS; }
    double getDurationMS(void)
      {
        assert(flagHasDurationMS);
        return storeDurationMS;
      }
    const double getDurationMS(void) const
      {
        assert(flagHasDurationMS);
        return storeDurationMS;
      }
    bool hasDone(void) const  { return flagHasDone; }
    bool getDone(void)
      {
        assert(flagHasDone);
        return storeDone;
      }
    const bool getDone(void) const
      {
        assert(flagHasDone);
        return storeDone;
      }
    bool hasSafeToStopAudio(void) const  { return flagHasSafeToStopAudio; }
    bool getSafeToStopAudio(void)
      {
        assert(flagHasSafeToStopAudio);
        return storeSafeToStopAudio;
      }
    const bool getSafeToStopAudio(void) const
      {
        assert(flagHasSafeToStopAudio);
        return storeSafeToStopAudio;
      }


    void setFormat(TypeFormat new_value)
      {
        flagHasFormat = true;
        storeFormat = new_value;
      }
    void setFormat(const char *chars)
      {
        setFormat(stringToFormat(chars));
      }
    void setFormat(std::string the_string)
      {
        setFormat(stringToFormat(the_string.c_str()));
      }
    void unsetFormat(void)
      {
        flagHasFormat = false;
      }
    void setFormatVersion(void)
      {
        flagHasFormatVersion = true;
      }
    void setFormatVersion(TypeFormatVersion new_value)
      {
        setFormatVersion();
      }
    void setFormatVersion(const char *chars)
      {
        setFormatVersion(stringToFormatVersion(chars));
      }
    void setFormatVersion(std::string the_string)
      {
        setFormatVersion(stringToFormatVersion(the_string.c_str()));
      }
    void unsetFormatVersion(void)
      {
        flagHasFormatVersion = false;
      }
    void setPartialTranscript(std::string new_value)
      {
        flagHasPartialTranscript = true;
        storePartialTranscript = new_value;
      }
    void unsetPartialTranscript(void)
      {
        flagHasPartialTranscript = false;
      }
    void setDurationMS(double new_value)
      {
        flagHasDurationMS = true;
        if (new_value < 0)
            throw("The value for field DurationMS of HoundPartialTranscriptJSON is less than the lower bound (0) for that field.");
        storeDurationMS = new_value;
      }
    void unsetDurationMS(void)
      {
        flagHasDurationMS = false;
      }
    void setDone(bool new_value)
      {
        flagHasDone = true;
        storeDone = new_value;
      }
    void unsetDone(void)
      {
        flagHasDone = false;
      }
    void setSafeToStopAudio(bool new_value)
      {
        flagHasSafeToStopAudio = true;
        storeSafeToStopAudio = new_value;
      }
    void unsetSafeToStopAudio(void)
      {
        flagHasSafeToStopAudio = false;
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
        assert(flagHasFormat);
        handler->start_pair("Format");
        switch (storeFormat)
          {
            case Format_SoundHoundVoiceSearchParialTranscript:
                handler->string_value("SoundHoundVoiceSearchParialTranscript");
                break;
            case Format_HoundVoiceQueryPartialTranscript:
                handler->string_value("HoundVoiceQueryPartialTranscript");
                break;
            default:
                assert(false);
          }
        assert(flagHasFormatVersion);
        handler->start_pair("FormatVersion");
        handler->string_value("1.0");
        assert(flagHasPartialTranscript);
        handler->start_pair("PartialTranscript");
        handler->string_value(storePartialTranscript);
        assert(flagHasDurationMS);
        handler->start_pair("DurationMS");
        if (((double)(long int)storeDurationMS) == storeDurationMS)
            handler->number_value((long int)storeDurationMS);
        else
            handler->number_value(storeDurationMS);
        assert(flagHasDone);
        handler->start_pair("Done");
        handler->boolean_value(storeDone);
        if (flagHasSafeToStopAudio)
          {
            handler->start_pair("SafeToStopAudio");
            handler->boolean_value(storeSafeToStopAudio);
          }
      }

    static HoundPartialTranscriptJSON *from_json(JSONValue *json_value, bool ignore_extras = false);
    static HoundPartialTranscriptJSON *from_text(const char *text, bool ignore_extras = false)
      {
        HoundPartialTranscriptJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<HoundPartialTranscriptJSON>, HoundPartialTranscriptJSON *, bool> generator("Type HoundPartialTranscript", ignore_extras);
            parse_json_value(text, &generator);
            assert(generator.have_value);
            result = generator.value.referenced();
            result->add_reference();
          };
        result->remove_reference_no_delete();
        return result;
      }
    static HoundPartialTranscriptJSON *from_file(FILE *fp, const char *file_name, bool ignore_extras = false)
      {
        HoundPartialTranscriptJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<HoundPartialTranscriptJSON>, HoundPartialTranscriptJSON *, bool> generator("Type HoundPartialTranscript", ignore_extras);
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
    class FieldGeneratorFormat : public JSONStringGenerator
          {
          protected:
            FieldGeneratorFormat(const char *what)
              {
                set_what(what);
              }
            FieldGeneratorFormat(void)
              {
              }
            void handle_result(const char *result)
              {
                handle_result(stringToFormat(result));
              }
            virtual void handle_result(TypeFormat result) = 0;
          };
        JSONHoldingGenerator<FieldGeneratorFormat, TypeFormat, TypeFormat > fieldGeneratorFormat;
    class FieldGeneratorFormatVersion : public JSONStringGenerator
          {
          protected:
            FieldGeneratorFormatVersion(const char *what)
              {
                set_what(what);
              }
            FieldGeneratorFormatVersion(void)
              {
              }
            void handle_result(const char *result)
              {
                handle_result(stringToFormatVersion(result));
              }
            virtual void handle_result(TypeFormatVersion result) = 0;
          };
        JSONHoldingGenerator<FieldGeneratorFormatVersion, TypeFormatVersion, TypeFormatVersion > fieldGeneratorFormatVersion;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorPartialTranscript;
        JSONHoldingGenerator<JSONDoubleGenerator, double, double > fieldGeneratorDurationMS;
        JSONHoldingGenerator<JSONBooleanGenerator, bool, bool > fieldGeneratorDone;
        JSONHoldingGenerator<JSONBooleanGenerator, bool, bool > fieldGeneratorSafeToStopAudio;
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
            HoundPartialTranscriptJSON *result = new HoundPartialTranscriptJSON();
            assert(result != NULL);
            RCHandle<HoundPartialTranscriptJSON> result_holder = result;
            finish(result);
            handle_result(result);
          }
        void finish(HoundPartialTranscriptJSON *result)
          {
            if (fieldGeneratorFormat.have_value)
              {
                result->setFormat(fieldGeneratorFormat.value);
                fieldGeneratorFormat.have_value = false;
              }
            else if (!(result->hasFormat()))
              {
                error("When parsing the object for %what%, the \"Format\" field was missing.");
              }
            if (fieldGeneratorFormatVersion.have_value)
              {
                result->setFormatVersion();
                fieldGeneratorFormatVersion.have_value = false;
              }
            else if (!(result->hasFormatVersion()))
              {
                error("When parsing the object for %what%, the \"FormatVersion\" field was missing.");
              }
            if (fieldGeneratorPartialTranscript.have_value)
              {
                result->setPartialTranscript(fieldGeneratorPartialTranscript.value);
                fieldGeneratorPartialTranscript.have_value = false;
              }
            else if (!(result->hasPartialTranscript()))
              {
                error("When parsing the object for %what%, the \"PartialTranscript\" field was missing.");
              }
            if (fieldGeneratorDurationMS.have_value)
              {
                result->setDurationMS(fieldGeneratorDurationMS.value);
                fieldGeneratorDurationMS.have_value = false;
              }
            else if (!(result->hasDurationMS()))
              {
                error("When parsing the object for %what%, the \"DurationMS\" field was missing.");
              }
            if (fieldGeneratorDone.have_value)
              {
                result->setDone(fieldGeneratorDone.value);
                fieldGeneratorDone.have_value = false;
              }
            else if (!(result->hasDone()))
              {
                error("When parsing the object for %what%, the \"Done\" field was missing.");
              }
            if (fieldGeneratorSafeToStopAudio.have_value)
              {
                result->setSafeToStopAudio(fieldGeneratorSafeToStopAudio.value);
                fieldGeneratorSafeToStopAudio.have_value = false;
              }
          }
        virtual void handle_result(HoundPartialTranscriptJSON *new_result) = 0;
        virtual JSONHandler *start_known_field(const char *field_name)
          {
            switch (field_name[0])
              {
                case 'D':
                    switch (field_name[1])
                      {
                        case 'o':
                            if (strcmp(&(field_name[2]), "ne") == 0)
                                return &fieldGeneratorDone;
                            break;
                        case 'u':
                            if (strcmp(&(field_name[2]), "rationMS") == 0)
                                return &fieldGeneratorDurationMS;
                            break;
                        default:
                            break;
                      }
                    break;
                case 'F':
                    if (strncmp(&(field_name[1]), "ormat", 5) == 0)
                      {
                        switch (field_name[6])
                          {
                            case 0:
                                return &fieldGeneratorFormat;
                            case 'V':
                                if (strcmp(&(field_name[7]), "ersion") == 0)
                                    return &fieldGeneratorFormatVersion;
                                break;
                            default:
                                break;
                          }
                      }
                    break;
                case 'P':
                    if (strcmp(&(field_name[1]), "artialTranscript") == 0)
                        return &fieldGeneratorPartialTranscript;
                    break;
                case 'S':
                    if (strcmp(&(field_name[1]), "afeToStopAudio") == 0)
                        return &fieldGeneratorSafeToStopAudio;
                    break;
                default:
                    break;
              }
            return NULL;
          }

      public:
        Generator(bool ignore_extras = false) : fieldGeneratorFormat("field \"Format\" of the HoundPartialTranscript class"), fieldGeneratorFormatVersion("field \"FormatVersion\" of the HoundPartialTranscript class"), fieldGeneratorPartialTranscript("field \"PartialTranscript\" of the HoundPartialTranscript class"), fieldGeneratorDurationMS("field \"DurationMS\" of the HoundPartialTranscript class"), fieldGeneratorDone("field \"Done\" of the HoundPartialTranscript class"), fieldGeneratorSafeToStopAudio("field \"SafeToStopAudio\" of the HoundPartialTranscript class")
          {
            set_what("the HoundPartialTranscript class");
          }
        ~Generator(void)
          {
          }

        void reset(void)
          {
            fieldGeneratorFormat.reset();
            fieldGeneratorFormatVersion.reset();
            fieldGeneratorPartialTranscript.reset();
            fieldGeneratorDurationMS.reset();
            fieldGeneratorDone.reset();
            fieldGeneratorSafeToStopAudio.reset();
            JSONObjectGenerator::reset();
            unknownFieldGenerator.reset();
          }
      };
  };

#endif /* HOUNDPARTIALTRANSCRIPTJSON_H */
