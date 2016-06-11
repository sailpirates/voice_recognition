/* file "JSONWriter.h" */

/* Copyright 2012 SoundHound, Incorporated.  All rights reserved. */

#ifndef JSONWRITER_H
#define JSONWRITER_H

#include <string>
#include <ostream>
#include <vector>
#include <stddef.h>
#include <stdio.h>
#include <float.h>
#include "JSONHandler.h"


class JSONWriter : public JSONHandler
  {
  public:
    enum whitespace_style { WHITESPACE_NONE, WHITESPACE_VERBOSE_4 };

  private:
    enum which_compound { OBJECT, ARRAY };
    std::vector<which_compound> compound_stack;
    bool first;
    bool in_pair;
    whitespace_style style;

    void start_value(const char *separator = " ");
    void send_quoted_string(const char *data);

  protected:
    ~JSONWriter(void)  { }

  public:
    void true_value(void);
    void false_value(void);
    void boolean_value(bool to_write);
    void null_value(void);
    void string_value(const char *to_write);
    void string_value(const std::string &to_write);
    void number_value(int to_write);
    void number_value(unsigned int to_write);
    void number_value(long to_write);
    void number_value(unsigned long to_write);
    void number_value(o_integer to_write);
    void number_value(double to_write, int precision = DBL_DIG);
    void number_value(o_integer mantissa_whole_part,
            o_integer mantissa_fraction_numerator,
            size_t mantissa_fraction_digit_count, o_integer exponent);
    void number_value(const char *number_text);
    void start_object(void);
    void start_pair(const char *name);
    void pair(const char *name, const char *string_value);
    void pair(const char *name, const std::string &string_value);
    void pair(const char *name, bool value);
    void pair(const char *name, int value);
    void pair(const char *name, unsigned int value);
    void pair(const char *name, long value);
    void pair(const char *name, unsigned long value);
    void pair(const char *name, double value, int precision = DBL_DIG);
    void finish_object(void);
    void start_array(void);
    void finish_array(void);

  protected:
    JSONWriter(whitespace_style style = WHITESPACE_VERBOSE_4) : style(style)
      { }

    virtual void send_raw_text(const char *text) = 0;
  };

class JSONStreamWriter : public JSONWriter
  {
  private:
    std::ostream &stream;

  public:
    JSONStreamWriter(std::ostream &stream,
            whitespace_style style = WHITESPACE_VERBOSE_4) : JSONWriter(style),
                    stream(stream)  { }
    ~JSONStreamWriter(void)  { }

  protected:
    void send_raw_text(const char *text)
      {
        stream << text;
      }
  };

class JSONFileWriter : public JSONWriter
  {
  private:
    FILE *fp;

  public:
    JSONFileWriter(FILE *fp, whitespace_style style = WHITESPACE_VERBOSE_4) :
            JSONWriter(style), fp(fp)  { }
    ~JSONFileWriter(void)  { }

  protected:
    void send_raw_text(const char *text)
      {
        fputs(text, fp);
      }
  };

class JSONFileDescriptorWriter : public JSONWriter
  {
  private:
    int fd;

  public:
    JSONFileDescriptorWriter(int fd,
            whitespace_style style = WHITESPACE_VERBOSE_4) : JSONWriter(style),
                    fd(fd)  { }
    ~JSONFileDescriptorWriter(void)  { }

  protected:
    void send_raw_text(const char *text);
  };


#endif /* JSONWRITER_H */
