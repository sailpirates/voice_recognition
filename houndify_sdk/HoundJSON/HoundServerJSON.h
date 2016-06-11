/* file "HoundServerJSON.h" */

/* Generated automatically by Classy JSON. */


#ifndef HOUNDSERVERJSON_H
#define HOUNDSERVERJSON_H

#include "JSONRep.h"
#include "JSONHoldingGenerator.h"
#include "JSONObjectGenerator.h"
#include "JSONHoldingArrayGenerator.h"
#include "JSONStringGenerator.h"
#include "JSONDoubleGenerator.h"
#include "JSONIntegerLowerBoundOnlyGenerator.h"
#include "JSONBooleanGenerator.h"
#include <vector>
#include <string>
#include <OInteger.h>
#include "CommandResultJSON.h"
#include "BuildInfoJSON.h"
#include "JSONHandler.h"
#include "JSONCheckingHandler.h"
#include "ReferenceCounted.h"
#include "RCHandle.h"
#include "JSONParse.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


class HoundServerJSON : public ReferenceCounted
  {
  public:
    enum TypeFormat
      {
        Format_SoundHoundVoiceSearchResult,
        Format_HoundQueryResult
      };

    static TypeFormat stringToFormat(const char *chars)
      {
        if (strcmp(chars, "SoundHoundVoiceSearchResult") == 0)
            return Format_SoundHoundVoiceSearchResult;
        else if (strcmp(chars, "HoundQueryResult") == 0)
            return Format_HoundQueryResult;
        else
            throw("The value for field `Format' is not one of the legal values.");
      }

    static const char *stringFromFormat(TypeFormat the_enum)
      {
        switch (the_enum)
          {
            case Format_SoundHoundVoiceSearchResult:
                return "SoundHoundVoiceSearchResult";
            case Format_HoundQueryResult:
                return "HoundQueryResult";
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

    enum TypeStatus
      {
        Status_OK,
        Status_Error
      };

    static TypeStatus stringToStatus(const char *chars)
      {
        if (strcmp(chars, "OK") == 0)
            return Status_OK;
        else if (strcmp(chars, "Error") == 0)
            return Status_Error;
        else
            throw("The value for field `Status' is not one of the legal values.");
      }

    static const char *stringFromStatus(TypeStatus the_enum)
      {
        switch (the_enum)
          {
            case Status_OK:
                return "OK";
            case Status_Error:
                return "Error";
            default:
                assert(false);
                return NULL;
          }
      }

    class TypeDisambiguationJSON : public ReferenceCounted
      {
      public:
        class TypeChoiceDataJSON : public ReferenceCounted
          {
          private:
            bool flagHasTranscription;
            std::string storeTranscription;
            bool flagHasConfidenceScore;
            double storeConfidenceScore;
            bool flagHasFixedTranscription;
            std::string storeFixedTranscription;

            TypeChoiceDataJSON(const TypeChoiceDataJSON &)  { assert(false); }
            TypeChoiceDataJSON &operator=(const TypeChoiceDataJSON &other)  { assert(false); throw "Illegal operator=() call."; }


            void fromJSONTranscription(JSONValue *json_value, bool ignore_extras = false);
            void fromJSONConfidenceScore(JSONValue *json_value, bool ignore_extras = false);
            void fromJSONFixedTranscription(JSONValue *json_value, bool ignore_extras = false);

          public:
            TypeChoiceDataJSON(void) :
                    flagHasTranscription(false),
                    flagHasConfidenceScore(false),
                    flagHasFixedTranscription(false)
              {
              }
            virtual ~TypeChoiceDataJSON(void)
              {
              }

            bool hasTranscription(void) const  { return flagHasTranscription; }
            std::string getTranscription(void)
              {
                assert(flagHasTranscription);
                return storeTranscription;
              }
            const std::string getTranscription(void) const
              {
                assert(flagHasTranscription);
                return storeTranscription;
              }
            bool hasConfidenceScore(void) const  { return flagHasConfidenceScore; }
            double getConfidenceScore(void)
              {
                assert(flagHasConfidenceScore);
                return storeConfidenceScore;
              }
            const double getConfidenceScore(void) const
              {
                assert(flagHasConfidenceScore);
                return storeConfidenceScore;
              }
            bool hasFixedTranscription(void) const  { return flagHasFixedTranscription; }
            std::string getFixedTranscription(void)
              {
                assert(flagHasFixedTranscription);
                return storeFixedTranscription;
              }
            const std::string getFixedTranscription(void) const
              {
                assert(flagHasFixedTranscription);
                return storeFixedTranscription;
              }


            void setTranscription(std::string new_value)
              {
                flagHasTranscription = true;
                storeTranscription = new_value;
              }
            void unsetTranscription(void)
              {
                flagHasTranscription = false;
              }
            void setConfidenceScore(double new_value)
              {
                flagHasConfidenceScore = true;
                if (new_value < 0)
                    throw("The value for field ConfidenceScore of TypeChoiceDataJSON is less than the lower bound (0) for that field.");
                if (new_value > 1)
                    throw("The value for field ConfidenceScore of TypeChoiceDataJSON is greater than the upper bound (1) for that field.");
                storeConfidenceScore = new_value;
              }
            void unsetConfidenceScore(void)
              {
                flagHasConfidenceScore = false;
              }
            void setFixedTranscription(std::string new_value)
              {
                flagHasFixedTranscription = true;
                storeFixedTranscription = new_value;
              }
            void unsetFixedTranscription(void)
              {
                flagHasFixedTranscription = false;
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
                assert(flagHasTranscription);
                handler->start_pair("Transcription");
                handler->string_value(storeTranscription);
                assert(flagHasConfidenceScore);
                handler->start_pair("ConfidenceScore");
                if (((double)(long int)storeConfidenceScore) == storeConfidenceScore)
                    handler->number_value((long int)storeConfidenceScore);
                else
                    handler->number_value(storeConfidenceScore);
                if (flagHasFixedTranscription)
                  {
                    handler->start_pair("FixedTranscription");
                    handler->string_value(storeFixedTranscription);
                  }
              }

            static TypeChoiceDataJSON *from_json(JSONValue *json_value, bool ignore_extras = false);
            static TypeChoiceDataJSON *from_text(const char *text, bool ignore_extras = false)
              {
                TypeChoiceDataJSON *result;
                  {
                    JSONHoldingGenerator<Generator, RCHandle<TypeChoiceDataJSON>, TypeChoiceDataJSON *, bool> generator("Type TypeChoiceData", ignore_extras);
                    parse_json_value(text, &generator);
                    assert(generator.have_value);
                    result = generator.value.referenced();
                    result->add_reference();
                  };
                result->remove_reference_no_delete();
                return result;
              }
            static TypeChoiceDataJSON *from_file(FILE *fp, const char *file_name, bool ignore_extras = false)
              {
                TypeChoiceDataJSON *result;
                  {
                    JSONHoldingGenerator<Generator, RCHandle<TypeChoiceDataJSON>, TypeChoiceDataJSON *, bool> generator("Type TypeChoiceData", ignore_extras);
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
                JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorTranscription;
                JSONHoldingGenerator<JSONDoubleGenerator, double, double > fieldGeneratorConfidenceScore;
                JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorFixedTranscription;
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
                    TypeChoiceDataJSON *result = new TypeChoiceDataJSON();
                    assert(result != NULL);
                    RCHandle<TypeChoiceDataJSON> result_holder = result;
                    finish(result);
                    handle_result(result);
                  }
                void finish(TypeChoiceDataJSON *result)
                  {
                    if (fieldGeneratorTranscription.have_value)
                      {
                        result->setTranscription(fieldGeneratorTranscription.value);
                        fieldGeneratorTranscription.have_value = false;
                      }
                    else if (!(result->hasTranscription()))
                      {
                        error("When parsing the object for %what%, the \"Transcription\" field was missing.");
                      }
                    if (fieldGeneratorConfidenceScore.have_value)
                      {
                        result->setConfidenceScore(fieldGeneratorConfidenceScore.value);
                        fieldGeneratorConfidenceScore.have_value = false;
                      }
                    else if (!(result->hasConfidenceScore()))
                      {
                        error("When parsing the object for %what%, the \"ConfidenceScore\" field was missing.");
                      }
                    if (fieldGeneratorFixedTranscription.have_value)
                      {
                        result->setFixedTranscription(fieldGeneratorFixedTranscription.value);
                        fieldGeneratorFixedTranscription.have_value = false;
                      }
                  }
                virtual void handle_result(TypeChoiceDataJSON *new_result) = 0;
                virtual JSONHandler *start_known_field(const char *field_name)
                  {
                    switch (field_name[0])
                      {
                        case 'C':
                            if (strcmp(&(field_name[1]), "onfidenceScore") == 0)
                                return &fieldGeneratorConfidenceScore;
                            break;
                        case 'F':
                            if (strcmp(&(field_name[1]), "ixedTranscription") == 0)
                                return &fieldGeneratorFixedTranscription;
                            break;
                        case 'T':
                            if (strcmp(&(field_name[1]), "ranscription") == 0)
                                return &fieldGeneratorTranscription;
                            break;
                        default:
                            break;
                      }
                    return NULL;
                  }

              public:
                Generator(bool ignore_extras = false) : fieldGeneratorTranscription("field \"Transcription\" of the TypeChoiceData class"), fieldGeneratorConfidenceScore("field \"ConfidenceScore\" of the TypeChoiceData class"), fieldGeneratorFixedTranscription("field \"FixedTranscription\" of the TypeChoiceData class")
                  {
                    set_what("the TypeChoiceData class");
                  }
                ~Generator(void)
                  {
                  }

                void reset(void)
                  {
                    fieldGeneratorTranscription.reset();
                    fieldGeneratorConfidenceScore.reset();
                    fieldGeneratorFixedTranscription.reset();
                    JSONObjectGenerator::reset();
                    unknownFieldGenerator.reset();
                  }
              };
          };

      private:
        bool flagHasNumToShow;
        OInteger storeNumToShow;
        bool flagHasChoiceData;
        std::vector< TypeChoiceDataJSON * > storeChoiceData;

        TypeDisambiguationJSON(const TypeDisambiguationJSON &)  { assert(false); }
        TypeDisambiguationJSON &operator=(const TypeDisambiguationJSON &other)  { assert(false); throw "Illegal operator=() call."; }


        void fromJSONNumToShow(JSONValue *json_value, bool ignore_extras = false);
        void fromJSONChoiceData(JSONValue *json_value, bool ignore_extras = false);

      public:
        TypeDisambiguationJSON(void) :
                flagHasNumToShow(false),
                flagHasChoiceData(false)
          {
          }
        virtual ~TypeDisambiguationJSON(void)
          {
            if (flagHasChoiceData)
              {
                for (size_t num1 = 0; num1 < storeChoiceData.size(); ++num1)
                  {
                    storeChoiceData[num1]->remove_reference();
                  }
              }
          }

        bool hasNumToShow(void) const  { return flagHasNumToShow; }
        OInteger getNumToShow(void)
          {
            assert(flagHasNumToShow);
            return storeNumToShow;
          }
        const OInteger getNumToShow(void) const
          {
            assert(flagHasNumToShow);
            return storeNumToShow;
          }
        bool hasChoiceData(void) const  { return flagHasChoiceData; }
        size_t countOfChoiceData(void) const
          {
            assert(flagHasChoiceData);
            return storeChoiceData.size();
          }
        TypeChoiceDataJSON * elementOfChoiceData(size_t element_num)
          {
            assert(flagHasChoiceData);
            return storeChoiceData[element_num];
          }
        const TypeChoiceDataJSON * elementOfChoiceData(size_t element_num) const
          {
            assert(flagHasChoiceData);
            return storeChoiceData[element_num];
          }
        std::vector< TypeChoiceDataJSON * > getChoiceData(void)
          {
            assert(flagHasChoiceData);
            return storeChoiceData;
          }
        const std::vector< TypeChoiceDataJSON * > getChoiceData(void) const
          {
            assert(flagHasChoiceData);
            return storeChoiceData;
          }


        void setNumToShow(OInteger new_value)
          {
            flagHasNumToShow = true;
            if (new_value < 1)
                throw("The value for field NumToShow of TypeDisambiguationJSON is less than the lower bound (1) for that field.");
            storeNumToShow = new_value;
          }
        void unsetNumToShow(void)
          {
            flagHasNumToShow = false;
          }
        void initChoiceData(void)
          {
            if (flagHasChoiceData)
              {
                for (size_t num2 = 0; num2 < storeChoiceData.size(); ++num2)
                  {
                    storeChoiceData[num2]->remove_reference();
                  }
              }
            flagHasChoiceData = true;
            storeChoiceData.clear();
          }
        void appendChoiceData(TypeChoiceDataJSON * to_append)
          {
            if (!flagHasChoiceData)
              {
                flagHasChoiceData = true;
                storeChoiceData.clear();
              }
            assert(flagHasChoiceData);
            to_append->add_reference();
            storeChoiceData.push_back(to_append);
          }
        void unsetChoiceData(void)
          {
            if (flagHasChoiceData)
              {
                for (size_t num3 = 0; num3 < storeChoiceData.size(); ++num3)
                  {
                    storeChoiceData[num3]->remove_reference();
                  }
              }
            flagHasChoiceData = false;
            storeChoiceData.clear();
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
            assert(flagHasNumToShow);
            handler->start_pair("NumToShow");
            handler->number_value(storeNumToShow.get_o_integer());
            assert(flagHasChoiceData);
            handler->start_pair("ChoiceData");
            assert(storeChoiceData.size() >= 1);
            handler->start_array();
            for (size_t num1 = 0; num1 < storeChoiceData.size(); ++num1)
              {
                storeChoiceData[num1]->write_as_json(handler);
              }
            handler->finish_array();
          }

        static TypeDisambiguationJSON *from_json(JSONValue *json_value, bool ignore_extras = false);
        static TypeDisambiguationJSON *from_text(const char *text, bool ignore_extras = false)
          {
            TypeDisambiguationJSON *result;
              {
                JSONHoldingGenerator<Generator, RCHandle<TypeDisambiguationJSON>, TypeDisambiguationJSON *, bool> generator("Type TypeDisambiguation", ignore_extras);
                parse_json_value(text, &generator);
                assert(generator.have_value);
                result = generator.value.referenced();
                result->add_reference();
              };
            result->remove_reference_no_delete();
            return result;
          }
        static TypeDisambiguationJSON *from_file(FILE *fp, const char *file_name, bool ignore_extras = false)
          {
            TypeDisambiguationJSON *result;
              {
                JSONHoldingGenerator<Generator, RCHandle<TypeDisambiguationJSON>, TypeDisambiguationJSON *, bool> generator("Type TypeDisambiguation", ignore_extras);
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
            static char lowerBoundNumToShow[];
            JSONHoldingGenerator<JSONIntegerLowerBoundOnlyGenerator<lowerBoundNumToShow>, OInteger, o_integer > fieldGeneratorNumToShow;
            JSONHoldingArrayGenerator<TypeChoiceDataJSON::Generator, RCHandle<TypeChoiceDataJSON>, TypeChoiceDataJSON *, bool > fieldGeneratorChoiceData;
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
                TypeDisambiguationJSON *result = new TypeDisambiguationJSON();
                assert(result != NULL);
                RCHandle<TypeDisambiguationJSON> result_holder = result;
                finish(result);
                handle_result(result);
              }
            void finish(TypeDisambiguationJSON *result)
              {
                if (fieldGeneratorNumToShow.have_value)
                  {
                    result->setNumToShow(fieldGeneratorNumToShow.value);
                    fieldGeneratorNumToShow.have_value = false;
                  }
                else if (!(result->hasNumToShow()))
                  {
                    error("When parsing the object for %what%, the \"NumToShow\" field was missing.");
                  }
                if (fieldGeneratorChoiceData.have_value)
                  {
                    result->initChoiceData();
                    size_t count = fieldGeneratorChoiceData.value.size();
                    for (size_t num = 0; num < count; ++num)
                      {
                        result->appendChoiceData(fieldGeneratorChoiceData.value[num].referenced());
                      }
                    fieldGeneratorChoiceData.value.clear();
                    fieldGeneratorChoiceData.have_value = false;
                  }
                else if (!(result->hasChoiceData()))
                  {
                    error("When parsing the object for %what%, the \"ChoiceData\" field was missing.");
                  }
              }
            virtual void handle_result(TypeDisambiguationJSON *new_result) = 0;
            virtual JSONHandler *start_known_field(const char *field_name)
              {
                switch (field_name[0])
                  {
                    case 'C':
                        if (strcmp(&(field_name[1]), "hoiceData") == 0)
                            return &fieldGeneratorChoiceData;
                        break;
                    case 'N':
                        if (strcmp(&(field_name[1]), "umToShow") == 0)
                            return &fieldGeneratorNumToShow;
                        break;
                    default:
                        break;
                  }
                return NULL;
              }

          public:
            Generator(bool ignore_extras = false) : fieldGeneratorNumToShow("field \"NumToShow\" of the TypeDisambiguation class"), fieldGeneratorChoiceData("field \"ChoiceData\" of the TypeDisambiguation class", ignore_extras)
              {
                set_what("the TypeDisambiguation class");
              }
            ~Generator(void)
              {
              }

            void reset(void)
              {
                fieldGeneratorNumToShow.reset();
                fieldGeneratorChoiceData.reset();
                JSONObjectGenerator::reset();
                unknownFieldGenerator.reset();
              }
          };
      };
    class TypeDomainUsageJSON : public ReferenceCounted
      {
      private:
        bool flagHasDomain;
        std::string storeDomain;
        bool flagHasDomainUniqueID;
        std::string storeDomainUniqueID;
        bool flagHasCreditsUsed;
        double storeCreditsUsed;

        TypeDomainUsageJSON(const TypeDomainUsageJSON &)  { assert(false); }
        TypeDomainUsageJSON &operator=(const TypeDomainUsageJSON &other)  { assert(false); throw "Illegal operator=() call."; }


        void fromJSONDomain(JSONValue *json_value, bool ignore_extras = false);
        void fromJSONDomainUniqueID(JSONValue *json_value, bool ignore_extras = false);
        void fromJSONCreditsUsed(JSONValue *json_value, bool ignore_extras = false);

      public:
        TypeDomainUsageJSON(void) :
                flagHasDomain(false),
                flagHasDomainUniqueID(false),
                flagHasCreditsUsed(false)
          {
          }
        virtual ~TypeDomainUsageJSON(void)
          {
          }

        bool hasDomain(void) const  { return flagHasDomain; }
        std::string getDomain(void)
          {
            assert(flagHasDomain);
            return storeDomain;
          }
        const std::string getDomain(void) const
          {
            assert(flagHasDomain);
            return storeDomain;
          }
        bool hasDomainUniqueID(void) const  { return flagHasDomainUniqueID; }
        std::string getDomainUniqueID(void)
          {
            assert(flagHasDomainUniqueID);
            return storeDomainUniqueID;
          }
        const std::string getDomainUniqueID(void) const
          {
            assert(flagHasDomainUniqueID);
            return storeDomainUniqueID;
          }
        bool hasCreditsUsed(void) const  { return flagHasCreditsUsed; }
        double getCreditsUsed(void)
          {
            assert(flagHasCreditsUsed);
            return storeCreditsUsed;
          }
        const double getCreditsUsed(void) const
          {
            assert(flagHasCreditsUsed);
            return storeCreditsUsed;
          }


        void setDomain(std::string new_value)
          {
            flagHasDomain = true;
            storeDomain = new_value;
          }
        void unsetDomain(void)
          {
            flagHasDomain = false;
          }
        void setDomainUniqueID(std::string new_value)
          {
            flagHasDomainUniqueID = true;
            storeDomainUniqueID = new_value;
          }
        void unsetDomainUniqueID(void)
          {
            flagHasDomainUniqueID = false;
          }
        void setCreditsUsed(double new_value)
          {
            flagHasCreditsUsed = true;
            if (new_value < 0)
                throw("The value for field CreditsUsed of TypeDomainUsageJSON is less than the lower bound (0) for that field.");
            storeCreditsUsed = new_value;
          }
        void unsetCreditsUsed(void)
          {
            flagHasCreditsUsed = false;
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
            assert(flagHasDomain);
            handler->start_pair("Domain");
            handler->string_value(storeDomain);
            assert(flagHasDomainUniqueID);
            handler->start_pair("DomainUniqueID");
            handler->string_value(storeDomainUniqueID);
            assert(flagHasCreditsUsed);
            handler->start_pair("CreditsUsed");
            if (((double)(long int)storeCreditsUsed) == storeCreditsUsed)
                handler->number_value((long int)storeCreditsUsed);
            else
                handler->number_value(storeCreditsUsed);
          }

        static TypeDomainUsageJSON *from_json(JSONValue *json_value, bool ignore_extras = false);
        static TypeDomainUsageJSON *from_text(const char *text, bool ignore_extras = false)
          {
            TypeDomainUsageJSON *result;
              {
                JSONHoldingGenerator<Generator, RCHandle<TypeDomainUsageJSON>, TypeDomainUsageJSON *, bool> generator("Type TypeDomainUsage", ignore_extras);
                parse_json_value(text, &generator);
                assert(generator.have_value);
                result = generator.value.referenced();
                result->add_reference();
              };
            result->remove_reference_no_delete();
            return result;
          }
        static TypeDomainUsageJSON *from_file(FILE *fp, const char *file_name, bool ignore_extras = false)
          {
            TypeDomainUsageJSON *result;
              {
                JSONHoldingGenerator<Generator, RCHandle<TypeDomainUsageJSON>, TypeDomainUsageJSON *, bool> generator("Type TypeDomainUsage", ignore_extras);
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
            JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorDomain;
            JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorDomainUniqueID;
            JSONHoldingGenerator<JSONDoubleGenerator, double, double > fieldGeneratorCreditsUsed;
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
                TypeDomainUsageJSON *result = new TypeDomainUsageJSON();
                assert(result != NULL);
                RCHandle<TypeDomainUsageJSON> result_holder = result;
                finish(result);
                handle_result(result);
              }
            void finish(TypeDomainUsageJSON *result)
              {
                if (fieldGeneratorDomain.have_value)
                  {
                    result->setDomain(fieldGeneratorDomain.value);
                    fieldGeneratorDomain.have_value = false;
                  }
                else if (!(result->hasDomain()))
                  {
                    error("When parsing the object for %what%, the \"Domain\" field was missing.");
                  }
                if (fieldGeneratorDomainUniqueID.have_value)
                  {
                    result->setDomainUniqueID(fieldGeneratorDomainUniqueID.value);
                    fieldGeneratorDomainUniqueID.have_value = false;
                  }
                else if (!(result->hasDomainUniqueID()))
                  {
                    error("When parsing the object for %what%, the \"DomainUniqueID\" field was missing.");
                  }
                if (fieldGeneratorCreditsUsed.have_value)
                  {
                    result->setCreditsUsed(fieldGeneratorCreditsUsed.value);
                    fieldGeneratorCreditsUsed.have_value = false;
                  }
                else if (!(result->hasCreditsUsed()))
                  {
                    error("When parsing the object for %what%, the \"CreditsUsed\" field was missing.");
                  }
              }
            virtual void handle_result(TypeDomainUsageJSON *new_result) = 0;
            virtual JSONHandler *start_known_field(const char *field_name)
              {
                switch (field_name[0])
                  {
                    case 'C':
                        if (strcmp(&(field_name[1]), "reditsUsed") == 0)
                            return &fieldGeneratorCreditsUsed;
                        break;
                    case 'D':
                        if (strncmp(&(field_name[1]), "omain", 5) == 0)
                          {
                            switch (field_name[6])
                              {
                                case 0:
                                    return &fieldGeneratorDomain;
                                case 'U':
                                    if (strcmp(&(field_name[7]), "niqueID") == 0)
                                        return &fieldGeneratorDomainUniqueID;
                                    break;
                                default:
                                    break;
                              }
                          }
                        break;
                    default:
                        break;
                  }
                return NULL;
              }

          public:
            Generator(bool ignore_extras = false) : fieldGeneratorDomain("field \"Domain\" of the TypeDomainUsage class"), fieldGeneratorDomainUniqueID("field \"DomainUniqueID\" of the TypeDomainUsage class"), fieldGeneratorCreditsUsed("field \"CreditsUsed\" of the TypeDomainUsage class")
              {
                set_what("the TypeDomainUsage class");
              }
            ~Generator(void)
              {
              }

            void reset(void)
              {
                fieldGeneratorDomain.reset();
                fieldGeneratorDomainUniqueID.reset();
                fieldGeneratorCreditsUsed.reset();
                JSONObjectGenerator::reset();
                unknownFieldGenerator.reset();
              }
          };
      };

  private:
    bool flagHasFormat;
    TypeFormat storeFormat;
    bool flagHasFormatVersion;
    bool flagHasStatus;
    TypeStatus storeStatus;
    bool flagHasErrorMessage;
    std::string storeErrorMessage;
    bool flagHasNumToReturn;
    OInteger storeNumToReturn;
    bool flagHasAllResults;
    std::vector< CommandResultJSON * > storeAllResults;
    bool flagHasDisambiguation;
    TypeDisambiguationJSON * storeDisambiguation;
    bool flagHasResultsAreFinal;
    std::vector< bool > storeResultsAreFinal;
    bool flagHasDomainUsage;
    std::vector< TypeDomainUsageJSON * > storeDomainUsage;
    bool flagHasBuildInfo;
    BuildInfoJSON * storeBuildInfo;
    bool flagHasServerGeneratedId;
    std::string storeServerGeneratedId;
    bool flagHasAudioLength;
    double storeAudioLength;
    bool flagHasRealSpeechTime;
    double storeRealSpeechTime;
    bool flagHasCpuSpeechTime;
    double storeCpuSpeechTime;
    bool flagHasRealTime;
    double storeRealTime;
    bool flagHasCpuTime;
    double storeCpuTime;

    HoundServerJSON(const HoundServerJSON &)  { assert(false); }
    HoundServerJSON &operator=(const HoundServerJSON &other)  { assert(false); throw "Illegal operator=() call."; }


    void fromJSONFormat(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONFormatVersion(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONStatus(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONErrorMessage(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONNumToReturn(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONAllResults(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONDisambiguation(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONResultsAreFinal(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONDomainUsage(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONBuildInfo(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONServerGeneratedId(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONAudioLength(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONRealSpeechTime(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONCpuSpeechTime(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONRealTime(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONCpuTime(JSONValue *json_value, bool ignore_extras = false);

  public:
    HoundServerJSON(void) :
            flagHasFormat(false),
            flagHasFormatVersion(false),
            flagHasStatus(false),
            flagHasErrorMessage(false),
            flagHasNumToReturn(false),
            flagHasAllResults(false),
            flagHasDisambiguation(false),
            flagHasResultsAreFinal(false),
            flagHasDomainUsage(false),
            flagHasBuildInfo(false),
            flagHasServerGeneratedId(false),
            flagHasAudioLength(false),
            flagHasRealSpeechTime(false),
            flagHasCpuSpeechTime(false),
            flagHasRealTime(false),
            flagHasCpuTime(false)
      {
      }
    virtual ~HoundServerJSON(void)
      {
        if (flagHasAllResults)
          {
            for (size_t num1 = 0; num1 < storeAllResults.size(); ++num1)
              {
                storeAllResults[num1]->remove_reference();
              }
          }
        if (flagHasDisambiguation)
          {
            storeDisambiguation->remove_reference();
          }
        if (flagHasDomainUsage)
          {
            for (size_t num2 = 0; num2 < storeDomainUsage.size(); ++num2)
              {
                storeDomainUsage[num2]->remove_reference();
              }
          }
        if (flagHasBuildInfo)
          {
            storeBuildInfo->remove_reference();
          }
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
    bool hasStatus(void) const  { return flagHasStatus; }
    TypeStatus getStatus(void)
      {
        assert(flagHasStatus);
        return storeStatus;
      }
    const TypeStatus getStatus(void) const
      {
        assert(flagHasStatus);
        return storeStatus;
      }
    const char *getStatusAsChars(void) const
      {
        return stringFromStatus(getStatus());
      }
    std::string getStatusAsString(void) const
      {
        return stringFromStatus(getStatus());
      }
    bool hasErrorMessage(void) const  { return flagHasErrorMessage; }
    std::string getErrorMessage(void)
      {
        assert(flagHasErrorMessage);
        return storeErrorMessage;
      }
    const std::string getErrorMessage(void) const
      {
        assert(flagHasErrorMessage);
        return storeErrorMessage;
      }
    bool hasNumToReturn(void) const  { return flagHasNumToReturn; }
    OInteger getNumToReturn(void)
      {
        assert(flagHasNumToReturn);
        return storeNumToReturn;
      }
    const OInteger getNumToReturn(void) const
      {
        assert(flagHasNumToReturn);
        return storeNumToReturn;
      }
    bool hasAllResults(void) const  { return flagHasAllResults; }
    size_t countOfAllResults(void) const
      {
        assert(flagHasAllResults);
        return storeAllResults.size();
      }
    CommandResultJSON * elementOfAllResults(size_t element_num)
      {
        assert(flagHasAllResults);
        return storeAllResults[element_num];
      }
    const CommandResultJSON * elementOfAllResults(size_t element_num) const
      {
        assert(flagHasAllResults);
        return storeAllResults[element_num];
      }
    std::vector< CommandResultJSON * > getAllResults(void)
      {
        assert(flagHasAllResults);
        return storeAllResults;
      }
    const std::vector< CommandResultJSON * > getAllResults(void) const
      {
        assert(flagHasAllResults);
        return storeAllResults;
      }
    bool hasDisambiguation(void) const  { return flagHasDisambiguation; }
    TypeDisambiguationJSON * getDisambiguation(void)
      {
        assert(flagHasDisambiguation);
        return storeDisambiguation;
      }
    const TypeDisambiguationJSON * getDisambiguation(void) const
      {
        assert(flagHasDisambiguation);
        return storeDisambiguation;
      }
    bool hasResultsAreFinal(void) const  { return flagHasResultsAreFinal; }
    size_t countOfResultsAreFinal(void) const
      {
        assert(flagHasResultsAreFinal);
        return storeResultsAreFinal.size();
      }
    bool elementOfResultsAreFinal(size_t element_num)
      {
        assert(flagHasResultsAreFinal);
        return storeResultsAreFinal[element_num];
      }
    const bool elementOfResultsAreFinal(size_t element_num) const
      {
        assert(flagHasResultsAreFinal);
        return storeResultsAreFinal[element_num];
      }
    std::vector< bool > getResultsAreFinal(void)
      {
        assert(flagHasResultsAreFinal);
        return storeResultsAreFinal;
      }
    const std::vector< bool > getResultsAreFinal(void) const
      {
        assert(flagHasResultsAreFinal);
        return storeResultsAreFinal;
      }
    bool hasDomainUsage(void) const  { return flagHasDomainUsage; }
    size_t countOfDomainUsage(void) const
      {
        assert(flagHasDomainUsage);
        return storeDomainUsage.size();
      }
    TypeDomainUsageJSON * elementOfDomainUsage(size_t element_num)
      {
        assert(flagHasDomainUsage);
        return storeDomainUsage[element_num];
      }
    const TypeDomainUsageJSON * elementOfDomainUsage(size_t element_num) const
      {
        assert(flagHasDomainUsage);
        return storeDomainUsage[element_num];
      }
    std::vector< TypeDomainUsageJSON * > getDomainUsage(void)
      {
        assert(flagHasDomainUsage);
        return storeDomainUsage;
      }
    const std::vector< TypeDomainUsageJSON * > getDomainUsage(void) const
      {
        assert(flagHasDomainUsage);
        return storeDomainUsage;
      }
    bool hasBuildInfo(void) const  { return flagHasBuildInfo; }
    BuildInfoJSON * getBuildInfo(void)
      {
        assert(flagHasBuildInfo);
        return storeBuildInfo;
      }
    const BuildInfoJSON * getBuildInfo(void) const
      {
        assert(flagHasBuildInfo);
        return storeBuildInfo;
      }
    bool hasServerGeneratedId(void) const  { return flagHasServerGeneratedId; }
    std::string getServerGeneratedId(void)
      {
        assert(flagHasServerGeneratedId);
        return storeServerGeneratedId;
      }
    const std::string getServerGeneratedId(void) const
      {
        assert(flagHasServerGeneratedId);
        return storeServerGeneratedId;
      }
    bool hasAudioLength(void) const  { return flagHasAudioLength; }
    double getAudioLength(void)
      {
        assert(flagHasAudioLength);
        return storeAudioLength;
      }
    const double getAudioLength(void) const
      {
        assert(flagHasAudioLength);
        return storeAudioLength;
      }
    bool hasRealSpeechTime(void) const  { return flagHasRealSpeechTime; }
    double getRealSpeechTime(void)
      {
        assert(flagHasRealSpeechTime);
        return storeRealSpeechTime;
      }
    const double getRealSpeechTime(void) const
      {
        assert(flagHasRealSpeechTime);
        return storeRealSpeechTime;
      }
    bool hasCpuSpeechTime(void) const  { return flagHasCpuSpeechTime; }
    double getCpuSpeechTime(void)
      {
        assert(flagHasCpuSpeechTime);
        return storeCpuSpeechTime;
      }
    const double getCpuSpeechTime(void) const
      {
        assert(flagHasCpuSpeechTime);
        return storeCpuSpeechTime;
      }
    bool hasRealTime(void) const  { return flagHasRealTime; }
    double getRealTime(void)
      {
        assert(flagHasRealTime);
        return storeRealTime;
      }
    const double getRealTime(void) const
      {
        assert(flagHasRealTime);
        return storeRealTime;
      }
    bool hasCpuTime(void) const  { return flagHasCpuTime; }
    double getCpuTime(void)
      {
        assert(flagHasCpuTime);
        return storeCpuTime;
      }
    const double getCpuTime(void) const
      {
        assert(flagHasCpuTime);
        return storeCpuTime;
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
    void setStatus(TypeStatus new_value)
      {
        flagHasStatus = true;
        storeStatus = new_value;
      }
    void setStatus(const char *chars)
      {
        setStatus(stringToStatus(chars));
      }
    void setStatus(std::string the_string)
      {
        setStatus(stringToStatus(the_string.c_str()));
      }
    void unsetStatus(void)
      {
        flagHasStatus = false;
      }
    void setErrorMessage(std::string new_value)
      {
        flagHasErrorMessage = true;
        storeErrorMessage = new_value;
      }
    void unsetErrorMessage(void)
      {
        flagHasErrorMessage = false;
      }
    void setNumToReturn(OInteger new_value)
      {
        flagHasNumToReturn = true;
        if (new_value < 0)
            throw("The value for field NumToReturn of HoundServerJSON is less than the lower bound (0) for that field.");
        storeNumToReturn = new_value;
      }
    void unsetNumToReturn(void)
      {
        flagHasNumToReturn = false;
      }
    void initAllResults(void)
      {
        if (flagHasAllResults)
          {
            for (size_t num3 = 0; num3 < storeAllResults.size(); ++num3)
              {
                storeAllResults[num3]->remove_reference();
              }
          }
        flagHasAllResults = true;
        storeAllResults.clear();
      }
    void appendAllResults(CommandResultJSON * to_append)
      {
        if (!flagHasAllResults)
          {
            flagHasAllResults = true;
            storeAllResults.clear();
          }
        assert(flagHasAllResults);
        to_append->add_reference();
        storeAllResults.push_back(to_append);
      }
    void unsetAllResults(void)
      {
        if (flagHasAllResults)
          {
            for (size_t num4 = 0; num4 < storeAllResults.size(); ++num4)
              {
                storeAllResults[num4]->remove_reference();
              }
          }
        flagHasAllResults = false;
        storeAllResults.clear();
      }
    void setDisambiguation(TypeDisambiguationJSON * new_value)
      {
        new_value->add_reference();
        if (flagHasDisambiguation)
          {
            storeDisambiguation->remove_reference();
          }
        flagHasDisambiguation = true;
        storeDisambiguation = new_value;
      }
    void unsetDisambiguation(void)
      {
        if (flagHasDisambiguation)
          {
            storeDisambiguation->remove_reference();
          }
        flagHasDisambiguation = false;
      }
    void initResultsAreFinal(void)
      {
        flagHasResultsAreFinal = true;
        storeResultsAreFinal.clear();
      }
    void appendResultsAreFinal(bool to_append)
      {
        if (!flagHasResultsAreFinal)
          {
            flagHasResultsAreFinal = true;
            storeResultsAreFinal.clear();
          }
        assert(flagHasResultsAreFinal);
        storeResultsAreFinal.push_back(to_append);
      }
    void unsetResultsAreFinal(void)
      {
        flagHasResultsAreFinal = false;
        storeResultsAreFinal.clear();
      }
    void initDomainUsage(void)
      {
        if (flagHasDomainUsage)
          {
            for (size_t num5 = 0; num5 < storeDomainUsage.size(); ++num5)
              {
                storeDomainUsage[num5]->remove_reference();
              }
          }
        flagHasDomainUsage = true;
        storeDomainUsage.clear();
      }
    void appendDomainUsage(TypeDomainUsageJSON * to_append)
      {
        if (!flagHasDomainUsage)
          {
            flagHasDomainUsage = true;
            storeDomainUsage.clear();
          }
        assert(flagHasDomainUsage);
        to_append->add_reference();
        storeDomainUsage.push_back(to_append);
      }
    void unsetDomainUsage(void)
      {
        if (flagHasDomainUsage)
          {
            for (size_t num6 = 0; num6 < storeDomainUsage.size(); ++num6)
              {
                storeDomainUsage[num6]->remove_reference();
              }
          }
        flagHasDomainUsage = false;
        storeDomainUsage.clear();
      }
    void setBuildInfo(BuildInfoJSON * new_value)
      {
        new_value->add_reference();
        if (flagHasBuildInfo)
          {
            storeBuildInfo->remove_reference();
          }
        flagHasBuildInfo = true;
        storeBuildInfo = new_value;
      }
    void unsetBuildInfo(void)
      {
        if (flagHasBuildInfo)
          {
            storeBuildInfo->remove_reference();
          }
        flagHasBuildInfo = false;
      }
    void setServerGeneratedId(std::string new_value)
      {
        flagHasServerGeneratedId = true;
        storeServerGeneratedId = new_value;
      }
    void unsetServerGeneratedId(void)
      {
        flagHasServerGeneratedId = false;
      }
    void setAudioLength(double new_value)
      {
        flagHasAudioLength = true;
        if (new_value < 0)
            throw("The value for field AudioLength of HoundServerJSON is less than the lower bound (0) for that field.");
        storeAudioLength = new_value;
      }
    void unsetAudioLength(void)
      {
        flagHasAudioLength = false;
      }
    void setRealSpeechTime(double new_value)
      {
        flagHasRealSpeechTime = true;
        if (new_value < 0)
            throw("The value for field RealSpeechTime of HoundServerJSON is less than the lower bound (0) for that field.");
        storeRealSpeechTime = new_value;
      }
    void unsetRealSpeechTime(void)
      {
        flagHasRealSpeechTime = false;
      }
    void setCpuSpeechTime(double new_value)
      {
        flagHasCpuSpeechTime = true;
        if (new_value < 0)
            throw("The value for field CpuSpeechTime of HoundServerJSON is less than the lower bound (0) for that field.");
        storeCpuSpeechTime = new_value;
      }
    void unsetCpuSpeechTime(void)
      {
        flagHasCpuSpeechTime = false;
      }
    void setRealTime(double new_value)
      {
        flagHasRealTime = true;
        if (new_value < 0)
            throw("The value for field RealTime of HoundServerJSON is less than the lower bound (0) for that field.");
        storeRealTime = new_value;
      }
    void unsetRealTime(void)
      {
        flagHasRealTime = false;
      }
    void setCpuTime(double new_value)
      {
        flagHasCpuTime = true;
        if (new_value < 0)
            throw("The value for field CpuTime of HoundServerJSON is less than the lower bound (0) for that field.");
        storeCpuTime = new_value;
      }
    void unsetCpuTime(void)
      {
        flagHasCpuTime = false;
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
            case Format_SoundHoundVoiceSearchResult:
                handler->string_value("SoundHoundVoiceSearchResult");
                break;
            case Format_HoundQueryResult:
                handler->string_value("HoundQueryResult");
                break;
            default:
                assert(false);
          }
        assert(flagHasFormatVersion);
        handler->start_pair("FormatVersion");
        handler->string_value("1.0");
        assert(flagHasStatus);
        handler->start_pair("Status");
        switch (storeStatus)
          {
            case Status_OK:
                handler->string_value("OK");
                break;
            case Status_Error:
                handler->string_value("Error");
                break;
            default:
                assert(false);
          }
        if (flagHasErrorMessage)
          {
            handler->start_pair("ErrorMessage");
            handler->string_value(storeErrorMessage);
          }
        if (flagHasNumToReturn)
          {
            handler->start_pair("NumToReturn");
            handler->number_value(storeNumToReturn.get_o_integer());
          }
        if (flagHasAllResults)
          {
            handler->start_pair("AllResults");
            handler->start_array();
            for (size_t num1 = 0; num1 < storeAllResults.size(); ++num1)
              {
                storeAllResults[num1]->write_as_json(handler);
              }
            handler->finish_array();
          }
        if (flagHasDisambiguation)
          {
            handler->start_pair("Disambiguation");
            storeDisambiguation->write_as_json(handler);
          }
        if (flagHasResultsAreFinal)
          {
            handler->start_pair("ResultsAreFinal");
            handler->start_array();
            for (size_t num2 = 0; num2 < storeResultsAreFinal.size(); ++num2)
              {
                handler->boolean_value(storeResultsAreFinal[num2]);
              }
            handler->finish_array();
          }
        assert(flagHasDomainUsage);
        handler->start_pair("DomainUsage");
        handler->start_array();
        for (size_t num3 = 0; num3 < storeDomainUsage.size(); ++num3)
          {
            storeDomainUsage[num3]->write_as_json(handler);
          }
        handler->finish_array();
        if (flagHasBuildInfo)
          {
            handler->start_pair("BuildInfo");
            storeBuildInfo->write_as_json(handler);
          }
        if (flagHasServerGeneratedId)
          {
            handler->start_pair("ServerGeneratedId");
            handler->string_value(storeServerGeneratedId);
          }
        if (flagHasAudioLength)
          {
            handler->start_pair("AudioLength");
            if (((double)(long int)storeAudioLength) == storeAudioLength)
                handler->number_value((long int)storeAudioLength);
            else
                handler->number_value(storeAudioLength);
          }
        if (flagHasRealSpeechTime)
          {
            handler->start_pair("RealSpeechTime");
            if (((double)(long int)storeRealSpeechTime) == storeRealSpeechTime)
                handler->number_value((long int)storeRealSpeechTime);
            else
                handler->number_value(storeRealSpeechTime);
          }
        if (flagHasCpuSpeechTime)
          {
            handler->start_pair("CpuSpeechTime");
            if (((double)(long int)storeCpuSpeechTime) == storeCpuSpeechTime)
                handler->number_value((long int)storeCpuSpeechTime);
            else
                handler->number_value(storeCpuSpeechTime);
          }
        if (flagHasRealTime)
          {
            handler->start_pair("RealTime");
            if (((double)(long int)storeRealTime) == storeRealTime)
                handler->number_value((long int)storeRealTime);
            else
                handler->number_value(storeRealTime);
          }
        if (flagHasCpuTime)
          {
            handler->start_pair("CpuTime");
            if (((double)(long int)storeCpuTime) == storeCpuTime)
                handler->number_value((long int)storeCpuTime);
            else
                handler->number_value(storeCpuTime);
          }
      }

    static HoundServerJSON *from_json(JSONValue *json_value, bool ignore_extras = false);
    static HoundServerJSON *from_text(const char *text, bool ignore_extras = false)
      {
        HoundServerJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<HoundServerJSON>, HoundServerJSON *, bool> generator("Type HoundServer", ignore_extras);
            parse_json_value(text, &generator);
            assert(generator.have_value);
            result = generator.value.referenced();
            result->add_reference();
          };
        result->remove_reference_no_delete();
        return result;
      }
    static HoundServerJSON *from_file(FILE *fp, const char *file_name, bool ignore_extras = false)
      {
        HoundServerJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<HoundServerJSON>, HoundServerJSON *, bool> generator("Type HoundServer", ignore_extras);
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
    class FieldGeneratorStatus : public JSONStringGenerator
          {
          protected:
            FieldGeneratorStatus(const char *what)
              {
                set_what(what);
              }
            FieldGeneratorStatus(void)
              {
              }
            void handle_result(const char *result)
              {
                handle_result(stringToStatus(result));
              }
            virtual void handle_result(TypeStatus result) = 0;
          };
        JSONHoldingGenerator<FieldGeneratorStatus, TypeStatus, TypeStatus > fieldGeneratorStatus;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorErrorMessage;
        static char lowerBoundNumToReturn[];
        JSONHoldingGenerator<JSONIntegerLowerBoundOnlyGenerator<lowerBoundNumToReturn>, OInteger, o_integer > fieldGeneratorNumToReturn;
        JSONHoldingArrayGenerator<CommandResultJSON::Generator, RCHandle<CommandResultJSON>, CommandResultJSON *, bool > fieldGeneratorAllResults;
        JSONHoldingGenerator<TypeDisambiguationJSON::Generator, RCHandle<TypeDisambiguationJSON>, TypeDisambiguationJSON *, bool > fieldGeneratorDisambiguation;
        JSONHoldingArrayGenerator<JSONBooleanGenerator, bool, bool > fieldGeneratorResultsAreFinal;
        JSONHoldingArrayGenerator<TypeDomainUsageJSON::Generator, RCHandle<TypeDomainUsageJSON>, TypeDomainUsageJSON *, bool > fieldGeneratorDomainUsage;
        JSONHoldingGenerator<BuildInfoJSON::Generator, RCHandle<BuildInfoJSON>, BuildInfoJSON *, bool > fieldGeneratorBuildInfo;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorServerGeneratedId;
        JSONHoldingGenerator<JSONDoubleGenerator, double, double > fieldGeneratorAudioLength;
        JSONHoldingGenerator<JSONDoubleGenerator, double, double > fieldGeneratorRealSpeechTime;
        JSONHoldingGenerator<JSONDoubleGenerator, double, double > fieldGeneratorCpuSpeechTime;
        JSONHoldingGenerator<JSONDoubleGenerator, double, double > fieldGeneratorRealTime;
        JSONHoldingGenerator<JSONDoubleGenerator, double, double > fieldGeneratorCpuTime;
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
            HoundServerJSON *result = new HoundServerJSON();
            assert(result != NULL);
            RCHandle<HoundServerJSON> result_holder = result;
            finish(result);
            handle_result(result);
          }
        void finish(HoundServerJSON *result)
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
            if (fieldGeneratorStatus.have_value)
              {
                result->setStatus(fieldGeneratorStatus.value);
                fieldGeneratorStatus.have_value = false;
              }
            else if (!(result->hasStatus()))
              {
                error("When parsing the object for %what%, the \"Status\" field was missing.");
              }
            if (fieldGeneratorErrorMessage.have_value)
              {
                result->setErrorMessage(fieldGeneratorErrorMessage.value);
                fieldGeneratorErrorMessage.have_value = false;
              }
            if (fieldGeneratorNumToReturn.have_value)
              {
                result->setNumToReturn(fieldGeneratorNumToReturn.value);
                fieldGeneratorNumToReturn.have_value = false;
              }
            if (fieldGeneratorAllResults.have_value)
              {
                result->initAllResults();
                size_t count = fieldGeneratorAllResults.value.size();
                for (size_t num = 0; num < count; ++num)
                  {
                    result->appendAllResults(fieldGeneratorAllResults.value[num].referenced());
                  }
                fieldGeneratorAllResults.value.clear();
                fieldGeneratorAllResults.have_value = false;
              }
            if (fieldGeneratorDisambiguation.have_value)
              {
                result->setDisambiguation(fieldGeneratorDisambiguation.value.referenced());
                fieldGeneratorDisambiguation.have_value = false;
              }
            if (fieldGeneratorResultsAreFinal.have_value)
              {
                result->initResultsAreFinal();
                size_t count = fieldGeneratorResultsAreFinal.value.size();
                for (size_t num = 0; num < count; ++num)
                  {
                    result->appendResultsAreFinal(fieldGeneratorResultsAreFinal.value[num]);
                  }
                fieldGeneratorResultsAreFinal.value.clear();
                fieldGeneratorResultsAreFinal.have_value = false;
              }
            if (fieldGeneratorDomainUsage.have_value)
              {
                result->initDomainUsage();
                size_t count = fieldGeneratorDomainUsage.value.size();
                for (size_t num = 0; num < count; ++num)
                  {
                    result->appendDomainUsage(fieldGeneratorDomainUsage.value[num].referenced());
                  }
                fieldGeneratorDomainUsage.value.clear();
                fieldGeneratorDomainUsage.have_value = false;
              }
            else if (!(result->hasDomainUsage()))
              {
                error("When parsing the object for %what%, the \"DomainUsage\" field was missing.");
              }
            if (fieldGeneratorBuildInfo.have_value)
              {
                result->setBuildInfo(fieldGeneratorBuildInfo.value.referenced());
                fieldGeneratorBuildInfo.have_value = false;
              }
            if (fieldGeneratorServerGeneratedId.have_value)
              {
                result->setServerGeneratedId(fieldGeneratorServerGeneratedId.value);
                fieldGeneratorServerGeneratedId.have_value = false;
              }
            if (fieldGeneratorAudioLength.have_value)
              {
                result->setAudioLength(fieldGeneratorAudioLength.value);
                fieldGeneratorAudioLength.have_value = false;
              }
            if (fieldGeneratorRealSpeechTime.have_value)
              {
                result->setRealSpeechTime(fieldGeneratorRealSpeechTime.value);
                fieldGeneratorRealSpeechTime.have_value = false;
              }
            if (fieldGeneratorCpuSpeechTime.have_value)
              {
                result->setCpuSpeechTime(fieldGeneratorCpuSpeechTime.value);
                fieldGeneratorCpuSpeechTime.have_value = false;
              }
            if (fieldGeneratorRealTime.have_value)
              {
                result->setRealTime(fieldGeneratorRealTime.value);
                fieldGeneratorRealTime.have_value = false;
              }
            if (fieldGeneratorCpuTime.have_value)
              {
                result->setCpuTime(fieldGeneratorCpuTime.value);
                fieldGeneratorCpuTime.have_value = false;
              }
          }
        virtual void handle_result(HoundServerJSON *new_result) = 0;
        virtual JSONHandler *start_known_field(const char *field_name)
          {
            switch (field_name[0])
              {
                case 'A':
                    switch (field_name[1])
                      {
                        case 'l':
                            if (strcmp(&(field_name[2]), "lResults") == 0)
                                return &fieldGeneratorAllResults;
                            break;
                        case 'u':
                            if (strcmp(&(field_name[2]), "dioLength") == 0)
                                return &fieldGeneratorAudioLength;
                            break;
                        default:
                            break;
                      }
                    break;
                case 'B':
                    if (strcmp(&(field_name[1]), "uildInfo") == 0)
                        return &fieldGeneratorBuildInfo;
                    break;
                case 'C':
                    if (strncmp(&(field_name[1]), "pu", 2) == 0)
                      {
                        switch (field_name[3])
                          {
                            case 'S':
                                if (strcmp(&(field_name[4]), "peechTime") == 0)
                                    return &fieldGeneratorCpuSpeechTime;
                                break;
                            case 'T':
                                if (strcmp(&(field_name[4]), "ime") == 0)
                                    return &fieldGeneratorCpuTime;
                                break;
                            default:
                                break;
                          }
                      }
                    break;
                case 'D':
                    switch (field_name[1])
                      {
                        case 'i':
                            if (strcmp(&(field_name[2]), "sambiguation") == 0)
                                return &fieldGeneratorDisambiguation;
                            break;
                        case 'o':
                            if (strcmp(&(field_name[2]), "mainUsage") == 0)
                                return &fieldGeneratorDomainUsage;
                            break;
                        default:
                            break;
                      }
                    break;
                case 'E':
                    if (strcmp(&(field_name[1]), "rrorMessage") == 0)
                        return &fieldGeneratorErrorMessage;
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
                case 'N':
                    if (strcmp(&(field_name[1]), "umToReturn") == 0)
                        return &fieldGeneratorNumToReturn;
                    break;
                case 'R':
                    if (strncmp(&(field_name[1]), "e", 1) == 0)
                      {
                        switch (field_name[2])
                          {
                            case 'a':
                                if (strncmp(&(field_name[3]), "l", 1) == 0)
                                  {
                                    switch (field_name[4])
                                      {
                                        case 'S':
                                            if (strcmp(&(field_name[5]), "peechTime") == 0)
                                                return &fieldGeneratorRealSpeechTime;
                                            break;
                                        case 'T':
                                            if (strcmp(&(field_name[5]), "ime") == 0)
                                                return &fieldGeneratorRealTime;
                                            break;
                                        default:
                                            break;
                                      }
                                  }
                                break;
                            case 's':
                                if (strcmp(&(field_name[3]), "ultsAreFinal") == 0)
                                    return &fieldGeneratorResultsAreFinal;
                                break;
                            default:
                                break;
                          }
                      }
                    break;
                case 'S':
                    switch (field_name[1])
                      {
                        case 'e':
                            if (strcmp(&(field_name[2]), "rverGeneratedId") == 0)
                                return &fieldGeneratorServerGeneratedId;
                            break;
                        case 't':
                            if (strcmp(&(field_name[2]), "atus") == 0)
                                return &fieldGeneratorStatus;
                            break;
                        default:
                            break;
                      }
                    break;
                default:
                    break;
              }
            return NULL;
          }

      public:
        Generator(bool ignore_extras = false) : fieldGeneratorFormat("field \"Format\" of the HoundServer class"), fieldGeneratorFormatVersion("field \"FormatVersion\" of the HoundServer class"), fieldGeneratorStatus("field \"Status\" of the HoundServer class"), fieldGeneratorErrorMessage("field \"ErrorMessage\" of the HoundServer class"), fieldGeneratorNumToReturn("field \"NumToReturn\" of the HoundServer class"), fieldGeneratorAllResults("field \"AllResults\" of the HoundServer class", ignore_extras), fieldGeneratorDisambiguation("field \"Disambiguation\" of the HoundServer class", ignore_extras), fieldGeneratorResultsAreFinal("field \"ResultsAreFinal\" of the HoundServer class"), fieldGeneratorDomainUsage("field \"DomainUsage\" of the HoundServer class", ignore_extras), fieldGeneratorBuildInfo("field \"BuildInfo\" of the HoundServer class", ignore_extras), fieldGeneratorServerGeneratedId("field \"ServerGeneratedId\" of the HoundServer class"), fieldGeneratorAudioLength("field \"AudioLength\" of the HoundServer class"), fieldGeneratorRealSpeechTime("field \"RealSpeechTime\" of the HoundServer class"), fieldGeneratorCpuSpeechTime("field \"CpuSpeechTime\" of the HoundServer class"), fieldGeneratorRealTime("field \"RealTime\" of the HoundServer class"), fieldGeneratorCpuTime("field \"CpuTime\" of the HoundServer class")
          {
            set_what("the HoundServer class");
          }
        ~Generator(void)
          {
          }

        void reset(void)
          {
            fieldGeneratorFormat.reset();
            fieldGeneratorFormatVersion.reset();
            fieldGeneratorStatus.reset();
            fieldGeneratorErrorMessage.reset();
            fieldGeneratorNumToReturn.reset();
            fieldGeneratorAllResults.reset();
            fieldGeneratorDisambiguation.reset();
            fieldGeneratorResultsAreFinal.reset();
            fieldGeneratorDomainUsage.reset();
            fieldGeneratorBuildInfo.reset();
            fieldGeneratorServerGeneratedId.reset();
            fieldGeneratorAudioLength.reset();
            fieldGeneratorRealSpeechTime.reset();
            fieldGeneratorCpuSpeechTime.reset();
            fieldGeneratorRealTime.reset();
            fieldGeneratorCpuTime.reset();
            JSONObjectGenerator::reset();
            unknownFieldGenerator.reset();
          }
      };
  };

#endif /* HOUNDSERVERJSON_H */
