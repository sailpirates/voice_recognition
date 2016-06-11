/* file "BuildInfoJSON.h" */

/* Generated automatically by Classy JSON. */


#ifndef BUILDINFOJSON_H
#define BUILDINFOJSON_H

#include "JSONRep.h"
#include "JSONHoldingGenerator.h"
#include "JSONObjectGenerator.h"
#include "JSONStringGenerator.h"
#include <string>
#include "JSONHandler.h"
#include "JSONCheckingHandler.h"
#include "ReferenceCounted.h"
#include "RCHandle.h"
#include "JSONParse.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


class BuildInfoJSON : public ReferenceCounted
  {
  private:
    bool flagHasUser;
    std::string storeUser;
    bool flagHasDate;
    std::string storeDate;
    bool flagHasMachine;
    std::string storeMachine;
    bool flagHasSVNRevision;
    std::string storeSVNRevision;
    bool flagHasSVNBranch;
    std::string storeSVNBranch;
    bool flagHasBuildNumber;
    std::string storeBuildNumber;
    bool flagHasKind;
    std::string storeKind;
    bool flagHasVariant;
    std::string storeVariant;

    BuildInfoJSON(const BuildInfoJSON &)  { assert(false); }
    BuildInfoJSON &operator=(const BuildInfoJSON &other)  { assert(false); throw "Illegal operator=() call."; }


    void fromJSONUser(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONDate(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONMachine(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONSVNRevision(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONSVNBranch(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONBuildNumber(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONKind(JSONValue *json_value, bool ignore_extras = false);
    void fromJSONVariant(JSONValue *json_value, bool ignore_extras = false);

  public:
    BuildInfoJSON(void) :
            flagHasUser(false),
            flagHasDate(false),
            flagHasMachine(false),
            flagHasSVNRevision(false),
            flagHasSVNBranch(false),
            flagHasBuildNumber(false),
            flagHasKind(false),
            flagHasVariant(false)
      {
      }
    virtual ~BuildInfoJSON(void)
      {
      }

    bool hasUser(void) const  { return flagHasUser; }
    std::string getUser(void)
      {
        assert(flagHasUser);
        return storeUser;
      }
    const std::string getUser(void) const
      {
        assert(flagHasUser);
        return storeUser;
      }
    bool hasDate(void) const  { return flagHasDate; }
    std::string getDate(void)
      {
        assert(flagHasDate);
        return storeDate;
      }
    const std::string getDate(void) const
      {
        assert(flagHasDate);
        return storeDate;
      }
    bool hasMachine(void) const  { return flagHasMachine; }
    std::string getMachine(void)
      {
        assert(flagHasMachine);
        return storeMachine;
      }
    const std::string getMachine(void) const
      {
        assert(flagHasMachine);
        return storeMachine;
      }
    bool hasSVNRevision(void) const  { return flagHasSVNRevision; }
    std::string getSVNRevision(void)
      {
        assert(flagHasSVNRevision);
        return storeSVNRevision;
      }
    const std::string getSVNRevision(void) const
      {
        assert(flagHasSVNRevision);
        return storeSVNRevision;
      }
    bool hasSVNBranch(void) const  { return flagHasSVNBranch; }
    std::string getSVNBranch(void)
      {
        assert(flagHasSVNBranch);
        return storeSVNBranch;
      }
    const std::string getSVNBranch(void) const
      {
        assert(flagHasSVNBranch);
        return storeSVNBranch;
      }
    bool hasBuildNumber(void) const  { return flagHasBuildNumber; }
    std::string getBuildNumber(void)
      {
        assert(flagHasBuildNumber);
        return storeBuildNumber;
      }
    const std::string getBuildNumber(void) const
      {
        assert(flagHasBuildNumber);
        return storeBuildNumber;
      }
    bool hasKind(void) const  { return flagHasKind; }
    std::string getKind(void)
      {
        assert(flagHasKind);
        return storeKind;
      }
    const std::string getKind(void) const
      {
        assert(flagHasKind);
        return storeKind;
      }
    bool hasVariant(void) const  { return flagHasVariant; }
    std::string getVariant(void)
      {
        assert(flagHasVariant);
        return storeVariant;
      }
    const std::string getVariant(void) const
      {
        assert(flagHasVariant);
        return storeVariant;
      }


    void setUser(std::string new_value)
      {
        flagHasUser = true;
        storeUser = new_value;
      }
    void unsetUser(void)
      {
        flagHasUser = false;
      }
    void setDate(std::string new_value)
      {
        flagHasDate = true;
        storeDate = new_value;
      }
    void unsetDate(void)
      {
        flagHasDate = false;
      }
    void setMachine(std::string new_value)
      {
        flagHasMachine = true;
        storeMachine = new_value;
      }
    void unsetMachine(void)
      {
        flagHasMachine = false;
      }
    void setSVNRevision(std::string new_value)
      {
        flagHasSVNRevision = true;
        storeSVNRevision = new_value;
      }
    void unsetSVNRevision(void)
      {
        flagHasSVNRevision = false;
      }
    void setSVNBranch(std::string new_value)
      {
        flagHasSVNBranch = true;
        storeSVNBranch = new_value;
      }
    void unsetSVNBranch(void)
      {
        flagHasSVNBranch = false;
      }
    void setBuildNumber(std::string new_value)
      {
        flagHasBuildNumber = true;
        storeBuildNumber = new_value;
      }
    void unsetBuildNumber(void)
      {
        flagHasBuildNumber = false;
      }
    void setKind(std::string new_value)
      {
        flagHasKind = true;
        storeKind = new_value;
      }
    void unsetKind(void)
      {
        flagHasKind = false;
      }
    void setVariant(std::string new_value)
      {
        flagHasVariant = true;
        storeVariant = new_value;
      }
    void unsetVariant(void)
      {
        flagHasVariant = false;
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
        if (flagHasUser)
          {
            handler->start_pair("User");
            handler->string_value(storeUser);
          }
        if (flagHasDate)
          {
            handler->start_pair("Date");
            handler->string_value(storeDate);
          }
        if (flagHasMachine)
          {
            handler->start_pair("Machine");
            handler->string_value(storeMachine);
          }
        if (flagHasSVNRevision)
          {
            handler->start_pair("SVNRevision");
            handler->string_value(storeSVNRevision);
          }
        if (flagHasSVNBranch)
          {
            handler->start_pair("SVNBranch");
            handler->string_value(storeSVNBranch);
          }
        if (flagHasBuildNumber)
          {
            handler->start_pair("BuildNumber");
            handler->string_value(storeBuildNumber);
          }
        if (flagHasKind)
          {
            handler->start_pair("Kind");
            handler->string_value(storeKind);
          }
        if (flagHasVariant)
          {
            handler->start_pair("Variant");
            handler->string_value(storeVariant);
          }
      }

    static BuildInfoJSON *from_json(JSONValue *json_value, bool ignore_extras = false);
    static BuildInfoJSON *from_text(const char *text, bool ignore_extras = false)
      {
        BuildInfoJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<BuildInfoJSON>, BuildInfoJSON *, bool> generator("Type BuildInfo", ignore_extras);
            parse_json_value(text, &generator);
            assert(generator.have_value);
            result = generator.value.referenced();
            result->add_reference();
          };
        result->remove_reference_no_delete();
        return result;
      }
    static BuildInfoJSON *from_file(FILE *fp, const char *file_name, bool ignore_extras = false)
      {
        BuildInfoJSON *result;
          {
            JSONHoldingGenerator<Generator, RCHandle<BuildInfoJSON>, BuildInfoJSON *, bool> generator("Type BuildInfo", ignore_extras);
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
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorUser;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorDate;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorMachine;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorSVNRevision;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorSVNBranch;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorBuildNumber;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorKind;
        JSONHoldingGenerator<JSONStringGenerator, std::string, const char * > fieldGeneratorVariant;
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
            BuildInfoJSON *result = new BuildInfoJSON();
            assert(result != NULL);
            RCHandle<BuildInfoJSON> result_holder = result;
            finish(result);
            handle_result(result);
          }
        void finish(BuildInfoJSON *result)
          {
            if (fieldGeneratorUser.have_value)
              {
                result->setUser(fieldGeneratorUser.value);
                fieldGeneratorUser.have_value = false;
              }
            if (fieldGeneratorDate.have_value)
              {
                result->setDate(fieldGeneratorDate.value);
                fieldGeneratorDate.have_value = false;
              }
            if (fieldGeneratorMachine.have_value)
              {
                result->setMachine(fieldGeneratorMachine.value);
                fieldGeneratorMachine.have_value = false;
              }
            if (fieldGeneratorSVNRevision.have_value)
              {
                result->setSVNRevision(fieldGeneratorSVNRevision.value);
                fieldGeneratorSVNRevision.have_value = false;
              }
            if (fieldGeneratorSVNBranch.have_value)
              {
                result->setSVNBranch(fieldGeneratorSVNBranch.value);
                fieldGeneratorSVNBranch.have_value = false;
              }
            if (fieldGeneratorBuildNumber.have_value)
              {
                result->setBuildNumber(fieldGeneratorBuildNumber.value);
                fieldGeneratorBuildNumber.have_value = false;
              }
            if (fieldGeneratorKind.have_value)
              {
                result->setKind(fieldGeneratorKind.value);
                fieldGeneratorKind.have_value = false;
              }
            if (fieldGeneratorVariant.have_value)
              {
                result->setVariant(fieldGeneratorVariant.value);
                fieldGeneratorVariant.have_value = false;
              }
          }
        virtual void handle_result(BuildInfoJSON *new_result) = 0;
        virtual JSONHandler *start_known_field(const char *field_name)
          {
            switch (field_name[0])
              {
                case 'B':
                    if (strcmp(&(field_name[1]), "uildNumber") == 0)
                        return &fieldGeneratorBuildNumber;
                    break;
                case 'D':
                    if (strcmp(&(field_name[1]), "ate") == 0)
                        return &fieldGeneratorDate;
                    break;
                case 'K':
                    if (strcmp(&(field_name[1]), "ind") == 0)
                        return &fieldGeneratorKind;
                    break;
                case 'M':
                    if (strcmp(&(field_name[1]), "achine") == 0)
                        return &fieldGeneratorMachine;
                    break;
                case 'S':
                    if (strncmp(&(field_name[1]), "VN", 2) == 0)
                      {
                        switch (field_name[3])
                          {
                            case 'B':
                                if (strcmp(&(field_name[4]), "ranch") == 0)
                                    return &fieldGeneratorSVNBranch;
                                break;
                            case 'R':
                                if (strcmp(&(field_name[4]), "evision") == 0)
                                    return &fieldGeneratorSVNRevision;
                                break;
                            default:
                                break;
                          }
                      }
                    break;
                case 'U':
                    if (strcmp(&(field_name[1]), "ser") == 0)
                        return &fieldGeneratorUser;
                    break;
                case 'V':
                    if (strcmp(&(field_name[1]), "ariant") == 0)
                        return &fieldGeneratorVariant;
                    break;
                default:
                    break;
              }
            return NULL;
          }

      public:
        Generator(bool ignore_extras = false) : fieldGeneratorUser("field \"User\" of the BuildInfo class"), fieldGeneratorDate("field \"Date\" of the BuildInfo class"), fieldGeneratorMachine("field \"Machine\" of the BuildInfo class"), fieldGeneratorSVNRevision("field \"SVNRevision\" of the BuildInfo class"), fieldGeneratorSVNBranch("field \"SVNBranch\" of the BuildInfo class"), fieldGeneratorBuildNumber("field \"BuildNumber\" of the BuildInfo class"), fieldGeneratorKind("field \"Kind\" of the BuildInfo class"), fieldGeneratorVariant("field \"Variant\" of the BuildInfo class")
          {
            set_what("the BuildInfo class");
          }
        ~Generator(void)
          {
          }

        void reset(void)
          {
            fieldGeneratorUser.reset();
            fieldGeneratorDate.reset();
            fieldGeneratorMachine.reset();
            fieldGeneratorSVNRevision.reset();
            fieldGeneratorSVNBranch.reset();
            fieldGeneratorBuildNumber.reset();
            fieldGeneratorKind.reset();
            fieldGeneratorVariant.reset();
            JSONObjectGenerator::reset();
            unknownFieldGenerator.reset();
          }
      };
  };

#endif /* BUILDINFOJSON_H */
