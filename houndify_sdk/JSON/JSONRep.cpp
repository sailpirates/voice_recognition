/* file "JSONRep.cpp" */

/* Copyright 2012 SoundHound, Incorporated.  All rights reserved. */


#include "JSONRep.h"
#include <assert.h>
#include <vector>


extern JSONValue *parse_json_value(JSONTextSource *source)
  {
    JSONValueHandler my_handler;
    parse_json_value(source, &my_handler);
    return my_handler.getResult();
  }

extern JSONValue *parse_json_value(FILE *fp, const char *file_name)
  {
    JSONValueHandler my_handler;
    parse_json_value(fp, file_name, &my_handler);
    return my_handler.getResult();
  }

extern JSONValue *parse_json_value(const char *text)
  {
    JSONValueHandler my_handler;
    parse_json_value(text, &my_handler);
    return my_handler.getResult();
  }

extern JSONValue *parse_json_value(std::string text)
  {
    JSONValueHandler my_handler;
    parse_json_value(text, &my_handler);
    return my_handler.getResult();
  }
