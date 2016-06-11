/* file "ClientVerticalStateJSON.cpp" */

/* Generated automatically by Classy JSON. */

#include "ClientVerticalStateJSON.h"


ClientVerticalStateJSON *ClientVerticalStateJSON::createForKey(const char *key, string_index *other_field_index)
  {

    class GenericClientVerticalStateJSON : public ClientVerticalStateJSON
      {
      private:
        std::string key;

      public:
        GenericClientVerticalStateJSON(const char *init_key) : key(init_key)
          {
          }
        ~GenericClientVerticalStateJSON(void)
          {
          }

        const char *getClientVerticalStateKind(void) const  { return key.c_str(); }
        void write_as_json(JSONHandler *handler) const
          {
            handler->start_object();
            write_fields_as_json(handler);
            handler->finish_object();
          }
      };
    return new GenericClientVerticalStateJSON(key);
  }
ClientVerticalStateJSON *ClientVerticalStateJSON::from_json(JSONValue *json_value, bool ignore_extras)
  {
    ClientVerticalStateJSON *result;
      {
        JSONHoldingGenerator<Generator, RCHandle<ClientVerticalStateJSON>, ClientVerticalStateJSON *, bool> generator("Type ClientVerticalState", ignore_extras);
        json_value->write(&generator);
        assert(generator.have_value);
        result = generator.value.referenced();
        result->add_reference();
      };
    result->remove_reference_no_delete();
    return result;
  }
