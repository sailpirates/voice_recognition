/* file "JSONWriter.cpp" */

/* Copyright 2012 SoundHound, Incorporated.  All rights reserved. */


#include "JSONWriter.h"
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
extern "C"
  {
#include "unicode.h"
  }


void JSONWriter::start_value(const char *separator)
  {
    if (compound_stack.size() > 0)
      {
        switch (compound_stack[compound_stack.size() - 1])
          {
            case OBJECT:
                assert(in_pair);
                in_pair = false;
                switch (style)
                  {
                    case WHITESPACE_NONE:
                        break;
                    case WHITESPACE_VERBOSE_4:
                        send_raw_text(separator);
                        break;
                    default:
                        assert(false);
                        break;
                  }
                break;
            case ARRAY:
                if (!first)
                    send_raw_text(",");
                else
                    first = false;
                switch (style)
                  {
                    case WHITESPACE_NONE:
                        break;
                    case WHITESPACE_VERBOSE_4:
                        send_raw_text("\n");
                        for (size_t item_num = 0;
                             item_num < compound_stack.size(); ++item_num)
                          {
                            send_raw_text("    ");
                          }
                        break;
                    default:
                        assert(false);
                        break;
                  }
                break;
            default:
                assert(false);
                break;
          }
      }
  }

void JSONWriter::send_quoted_string(const char *data)
  {
    send_raw_text("\"");
    const char *follow = data;
    while (*follow != 0)
      {
        switch (*follow)
          {
            case '\"':
              {
                send_raw_text("\\\"");
                ++follow;
                break;
              }
            case '\\':
              {
                send_raw_text("\\\\");
                ++follow;
                break;
              }
            case '\b':
              {
                send_raw_text("\\b");
                ++follow;
                break;
              }
            case '\f':
              {
                send_raw_text("\\f");
                ++follow;
                break;
              }
            case '\n':
              {
                send_raw_text("\\n");
                ++follow;
                break;
              }
            case '\r':
              {
                send_raw_text("\\r");
                ++follow;
                break;
              }
            case '\t':
              {
                send_raw_text("\\t");
                ++follow;
                break;
              }
            default:
              {
                if ((*follow >= ' ') && (*follow <= '~'))
                  {
                    char buffer[2] = {0x0, 0x0};
                    buffer[0] = *follow;
                    send_raw_text(buffer);
                    ++follow;
                  }
                else
                  {
                    int length = validate_utf8_character(follow);
                    if (length < 0)
                      {
                        send_raw_text("\"");
                        return;
                      }
                    unsigned long code_point = utf8_to_code_point(follow);
                    follow += length;
                    unsigned buffer[2];
                    size_t out_count =
                            code_point_to_utf16(code_point, &(buffer[0]));
                    assert((out_count >= 1) && (out_count <= 2));
                    for (size_t out_num = 0; out_num < out_count; ++out_num)
                      {
                        char char_buffer[7];
                        sprintf(&(char_buffer[0]), "\\u%04x", buffer[out_num]);
                        send_raw_text(char_buffer);
                      }
                  }
                break;
              }
          }
      }
    send_raw_text("\"");
  }

void JSONWriter::true_value(void)
  {
    start_value();
    send_raw_text("true");
  }

void JSONWriter::false_value(void)
  {
    start_value();
    send_raw_text("false");
  }

void JSONWriter::boolean_value(bool to_write)
  {
    if (to_write)
        true_value();
    else
        false_value();
  }

void JSONWriter::null_value(void)
  {
    start_value();
    send_raw_text("null");
  }

void JSONWriter::string_value(const char *to_write)
  {
    if (to_write == NULL)
      {
        null_value();
      }
    else
      {
        start_value();
        send_quoted_string(to_write);
      }
  }

void JSONWriter::string_value(const std::string &to_write)
  {
    start_value();
    send_quoted_string(to_write.c_str());
  }

void JSONWriter::number_value(int to_write)
  {
    start_value();
    std::stringstream buffer;
    buffer << to_write;
    send_raw_text(buffer.str().c_str());
  }

void JSONWriter::number_value(unsigned int to_write)
  {
    start_value();
    std::stringstream buffer;
    buffer << to_write;
    send_raw_text(buffer.str().c_str());
  }

void JSONWriter::number_value(long to_write)
  {
    start_value();
    std::stringstream buffer;
    buffer << to_write;
    send_raw_text(buffer.str().c_str());
  }

void JSONWriter::number_value(unsigned long to_write)
  {
    start_value();
    std::stringstream buffer;
    buffer << to_write;
    send_raw_text(buffer.str().c_str());
  }

void JSONWriter::number_value(o_integer to_write)
  {
    start_value();
    if (oi_is_negative(to_write))
        send_raw_text("-");
    size_t digit_count;
    oi_decimal_digit_count(to_write, &digit_count);
    if (digit_count == 0)
      {
        send_raw_text("0");
        return;
      }
    char *buffer = new char[digit_count + 1];
    oi_write_decimal_digits(to_write, buffer);
    buffer[digit_count] = 0;
    send_raw_text(buffer);
    delete[] buffer;
  }

void JSONWriter::number_value(double to_write, int precision)
  {
    start_value();

    if (precision + 6 + (sizeof(double) * 3) <= 100)
      {
        char buffer[100];
        sprintf(buffer, "%.*e", precision, to_write);
        char *follow = &(buffer[0]);
        while (*follow != 0)
            ++follow;
        if ((follow - &(buffer[0]) >= 4) && (strcmp(follow - 4, "e+00") == 0))
            *(follow - 4) = 0;
        send_raw_text(&(buffer[0]));
      }
    else
      {
        char *buffer = (char *)(malloc(precision + 6 + (sizeof(double) * 3)));
        sprintf(buffer, "%.*e", precision, to_write);
        char *follow = buffer;
        while (*follow != 0)
            ++follow;
        if ((follow - buffer >= 4) && (strcmp(follow - 4, "e+00") == 0))
            *(follow - 4) = 0;
        send_raw_text(buffer);
        free(buffer);
      }
  }

void JSONWriter::number_value(o_integer mantissa_whole_part,
        o_integer mantissa_fraction_numerator,
        size_t mantissa_fraction_digit_count, o_integer exponent)
  {
    start_value();

    size_t mantissa_whole_digit_count;
    oi_decimal_digit_count(mantissa_whole_part,
                           &mantissa_whole_digit_count);
    if (mantissa_whole_digit_count == 0)
      {
        if (oi_is_negative(mantissa_fraction_numerator))
            send_raw_text("-");
        send_raw_text("0");
      }
    else
      {
        if (oi_is_negative(mantissa_whole_part))
            send_raw_text("-");
        char *buffer = (char *)(malloc(mantissa_whole_digit_count + 1));
        oi_write_decimal_digits(mantissa_whole_part, buffer);
        buffer[mantissa_whole_digit_count] = 0;
        send_raw_text(buffer);
        free(buffer);
      }
    if (mantissa_fraction_digit_count > 0)
      {
        send_raw_text(".");
        size_t non_zero_count;
        oi_decimal_digit_count(mantissa_fraction_numerator,
                               &non_zero_count);
        assert(non_zero_count <= mantissa_fraction_digit_count);
        for (size_t pad = non_zero_count;
             pad < mantissa_fraction_digit_count; ++pad)
          {
            send_raw_text("0");
          }
        char *buffer = (char *)(malloc(non_zero_count + 1));
        oi_write_decimal_digits(mantissa_fraction_numerator, buffer);
        buffer[non_zero_count] = 0;
        send_raw_text(buffer);
        free(buffer);
      }
    if (!(oi_equal(exponent, oi_zero)))
      {
        send_raw_text("e");
        if (oi_is_negative(exponent))
            send_raw_text("-");
        else
            send_raw_text("+");
        size_t exponent_space;
        oi_decimal_digit_count(exponent, &exponent_space);
        if (exponent_space == 0)
          {
            send_raw_text("0");
          }
        else
          {
            if (exponent_space < 2)
                send_raw_text("0");
            char *buffer = (char *)(malloc(exponent_space + 1));
            oi_write_decimal_digits(exponent, buffer);
            buffer[exponent_space] = 0;
            send_raw_text(buffer);
            free(buffer);
          }
      }
  }

void JSONWriter::number_value(const char *number_text)
  {
    const char *follow = number_text;

    start_value();

    if (*follow == '-')
        ++follow;

    if (*follow == '0')
      {
        ++follow;
      }
    else if ((*follow >= '1') && (*follow <= '9'))
      {
        ++follow;
        while ((*follow >= '0') && (*follow <= '9'))
            ++follow;
      }
    else
      {
        throw "JSONWriter: illegal number format";
      }

    if (*follow == '.')
      {
        ++follow;
        if ((*follow < '0') || (*follow > '9'))
            throw "JSONWriter: illegal number format";
        ++follow;
        while ((*follow >= '0') && (*follow <= '9'))
            ++follow;
      }

    if ((*follow == 'e') || (*follow == 'E'))
      {
        ++follow;
        if ((*follow == '+') || (*follow == '-'))
            ++follow;
        if ((*follow < '0') || (*follow > '9'))
            throw "JSONWriter: illegal number format";
        ++follow;
        while ((*follow >= '0') && (*follow <= '9'))
            ++follow;
      }

    if (*follow != 0)
        throw "JSONWriter: illegal number format";

    send_raw_text(number_text);
  }

void JSONWriter::start_object(void)
  {
    switch (style)
      {
        case WHITESPACE_NONE:
          {
            start_value("");
            break;
          }
        case WHITESPACE_VERBOSE_4:
          {
            std::string separator("\n");
            for (size_t item_num = 0; item_num < compound_stack.size();
                 ++item_num)
              {
                separator += "    ";
              }
            start_value(separator.c_str());
            send_raw_text("  ");
            break;
          }
        default:
          {
            assert(false);
            break;
          }
      }

    send_raw_text("{");
    first = true;
    in_pair = false;
    compound_stack.push_back(OBJECT);
  }

void JSONWriter::start_pair(const char *name)
  {
    assert(compound_stack.size() > 0);
    assert(compound_stack[compound_stack.size() - 1] == OBJECT);
    assert(!in_pair);

    if (!first)
        send_raw_text(",");
    else
        first = false;

    switch (style)
      {
        case WHITESPACE_NONE:
            break;
        case WHITESPACE_VERBOSE_4:
            send_raw_text("\n");
            for (size_t item_num = 0; item_num < compound_stack.size();
                 ++item_num)
              {
                send_raw_text("    ");
              }
            break;
        default:
            assert(false);
            break;
      }

    send_quoted_string(name);

    send_raw_text(":");

    in_pair = true;
  }

void JSONWriter::pair(const char *name, const char *string_value)
  {
    start_pair(name);
    JSONWriter::string_value(string_value);
  }

void JSONWriter::pair(const char *name, const std::string &string_value)
  {
    start_pair(name);
    JSONWriter::string_value(string_value);
  }

void JSONWriter::pair(const char *name, bool value)
  {
    start_pair(name);
    JSONWriter::boolean_value(value);
  }

void JSONWriter::pair(const char *name, int value)
  {
    start_pair(name);
    JSONWriter::number_value(value);
  }

void JSONWriter::pair(const char *name, unsigned int value)
  {
    start_pair(name);
    JSONWriter::number_value(value);
  }

void JSONWriter::pair(const char *name, long value)
  {
    start_pair(name);
    JSONWriter::number_value(value);
  }

void JSONWriter::pair(const char *name, unsigned long value)
  {
    start_pair(name);
    JSONWriter::number_value(value);
  }

void JSONWriter::pair(const char *name, double value, int precision)
  {
    start_pair(name);
    JSONWriter::number_value(value, precision);
  }

void JSONWriter::finish_object(void)
  {
    assert(compound_stack.size() > 0);
    assert(compound_stack[compound_stack.size() - 1] == OBJECT);
    assert(!in_pair);

    compound_stack.pop_back();

    switch (style)
      {
        case WHITESPACE_NONE:
            break;
        case WHITESPACE_VERBOSE_4:
            send_raw_text("\n");
            for (size_t item_num = 0; item_num < compound_stack.size();
                 ++item_num)
              {
                send_raw_text("    ");
              }
            send_raw_text("  ");
            break;
        default:
            assert(false);
            break;
      }

    send_raw_text("}");

    first = false;
    in_pair = false;
  }

void JSONWriter::start_array(void)
  {
    switch (style)
      {
        case WHITESPACE_NONE:
          {
            start_value("");
            break;
          }
        case WHITESPACE_VERBOSE_4:
          {
            std::string separator("\n");
            for (size_t item_num = 0; item_num < compound_stack.size();
                 ++item_num)
              {
                separator += "    ";
              }
            start_value(separator.c_str());
            send_raw_text("  ");
            break;
          }
        default:
          {
            assert(false);
            break;
          }
      }

    send_raw_text("[");
    first = true;
    compound_stack.push_back(ARRAY);
  }

void JSONWriter::finish_array(void)
  {
    assert(compound_stack.size() > 0);
    assert(compound_stack[compound_stack.size() - 1] == ARRAY);

    compound_stack.pop_back();

    switch (style)
      {
        case WHITESPACE_NONE:
            break;
        case WHITESPACE_VERBOSE_4:
            send_raw_text("\n");
            for (size_t item_num = 0; item_num < compound_stack.size();
                 ++item_num)
              {
                send_raw_text("    ");
              }
            send_raw_text("  ");
            break;
        default:
            assert(false);
            break;
      }

    send_raw_text("]");

    first = false;
    in_pair = false;
  }

void JSONFileDescriptorWriter::send_raw_text(const char *text)
  {
    write(fd, text, strlen(text));
  }
