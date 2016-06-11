/* file "JSONRep.h" */

/* Copyright 2012 SoundHound, Incorporated.  All rights reserved. */


#ifndef JSONREP_H
#define JSONREP_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <sstream>
#include "JSONWriter.h"
#include "JSONParse.h"
extern "C"
  {
#include "o_integer.h"
#include "rational.h"
#include "string_index.h"
  };


class JSONStringValue;
class JSONIntegerValue;
class JSONRationalValue;
class JSONTrueValue;
class JSONFalseValue;
class JSONNullValue;
class JSONObjectValue;
class JSONArrayValue;

class JSONValue
  {
  private:
    size_t reference_count;

  protected:
    JSONValue(void) : reference_count(1)  { }

  public:
    virtual ~JSONValue(void)  { }

    enum Kind
      {
        JVK_STRING,
        JVK_INTEGER,
        JVK_RATIONAL,
        JVK_TRUE,
        JVK_FALSE,
        JVK_NULL,
        JVK_OBJECT,
        JVK_ARRAY
      };

    virtual Kind kind(void) const = 0;
    virtual void write(JSONHandler *handler) const = 0;
    virtual JSONStringValue *string_value(void)  { return NULL; }
    virtual const JSONStringValue *string_value(void) const  { return NULL; }
    virtual JSONIntegerValue *integer_value(void)  { return NULL; }
    virtual const JSONIntegerValue *integer_value(void) const  { return NULL; }
    virtual JSONRationalValue *rational_value(void)  { return NULL; }
    virtual const JSONRationalValue *rational_value(void) const
      { return NULL; }
    virtual JSONTrueValue *true_value(void)  { return NULL; }
    virtual const JSONTrueValue *true_value(void) const  { return NULL; }
    virtual JSONFalseValue *false_value(void)  { return NULL; }
    virtual const JSONFalseValue *false_value(void) const  { return NULL; }
    virtual JSONNullValue *null_value(void)  { return NULL; }
    virtual const JSONNullValue *null_value(void) const  { return NULL; }
    virtual JSONObjectValue *object_value(void)  { return NULL; }
    virtual const JSONObjectValue *object_value(void) const  { return NULL; }
    virtual JSONArrayValue *array_value(void)  { return NULL; }
    virtual const JSONArrayValue *array_value(void) const  { return NULL; }

    virtual JSONValue *clone(void) const = 0;
    virtual bool is_equal_to(const JSONValue *other) const = 0;

    inline void add_reference(void)
      {
        assert(reference_count > 0);
        ++reference_count;
      }
    inline void remove_reference(void)
      {
        assert(reference_count > 0);
        --reference_count;
        if (reference_count == 0)
            delete this;
      }
  };

class JSONStringValue : public JSONValue
  {
  private:
    char *data;

  public:
    JSONStringValue(const char *init_data)
      {
        assert(init_data != NULL);
        data = (char *)(malloc(strlen(init_data) + 1));
        strcpy(data, init_data);
      }
    ~JSONStringValue(void)
      {
        free(data);
      }

    Kind kind(void) const  { return JVK_STRING; }
    const char *getData(void) const  { return data; }
    void write(JSONHandler *handler) const  { handler->string_value(data); }
    JSONStringValue *string_value(void)  { return this; }
    const JSONStringValue *string_value(void) const  { return this; }
    JSONValue *clone(void) const  { return new JSONStringValue(data); }
    bool is_equal_to(const JSONValue *other) const
      {
        const JSONStringValue *other_string_value = other->string_value();
        if (other_string_value == NULL)
            return false;
        return (strcmp(getData(), other_string_value->getData()) == 0);
      }
  };

class JSONIntegerValue : public JSONValue
  {
  private:
    o_integer data;

  public:
    JSONIntegerValue(o_integer init_data)
      {
        data = init_data;
        oi_add_reference(data);
      }
    JSONIntegerValue(char init_data)
      {
        oi_create_from_long_int(data, (long)init_data);
      }
    JSONIntegerValue(signed char init_data)
      {
        oi_create_from_long_int(data, (long)init_data);
      }
    JSONIntegerValue(short init_data)
      {
        oi_create_from_long_int(data, (long)init_data);
      }
    JSONIntegerValue(int init_data)
      {
        oi_create_from_long_int(data, (long)init_data);
      }
    JSONIntegerValue(long init_data)
      {
        oi_create_from_long_int(data, (long)init_data);
      }
    JSONIntegerValue(unsigned char init_data)
      {
        oi_create_from_unsigned_long_int(data, (unsigned long)init_data);
      }
    JSONIntegerValue(unsigned short init_data)
      {
        oi_create_from_unsigned_long_int(data, (unsigned long)init_data);
      }
    JSONIntegerValue(unsigned int init_data)
      {
        oi_create_from_unsigned_long_int(data, (unsigned long)init_data);
      }
    JSONIntegerValue(unsigned long init_data)
      {
        oi_create_from_unsigned_long_int(data, (unsigned long)init_data);
      }
    ~JSONIntegerValue(void)
      {
        oi_remove_reference(data);
      }

    Kind kind(void) const  { return JVK_INTEGER; }
    o_integer getData(void) const  { return data; }
    int getInt(void) const
      {
        long int result;
        verdict the_verdict = oi_to_long_int(data, &result);
        if (the_verdict != MISSION_ACCOMPLISHED)
            throw("Overflow in JSONIntegerValue::getInt().");
        if ((result >= (long int)INT_MAX) || (result < (long int)INT_MIN))
            throw("Overflow in JSONIntegerValue::getInt().");
        return (int)result;
      }
    long int getLongInt(void) const
      {
        long int result;
        verdict the_verdict = oi_to_long_int(data, &result);
        if (the_verdict != MISSION_ACCOMPLISHED)
            throw("Overflow in JSONIntegerValue::getLongInt().");
        return result;
      }
    unsigned long int getUnsignedLongInt(void) const
      {
        unsigned long int result;
        verdict the_verdict = oi_to_unsigned_long_int(data, &result);
        if (the_verdict != MISSION_ACCOMPLISHED)
            throw("Overflow in JSONIntegerValue::getUnsignedLongInt().");
        return result;
      }
    void write(JSONHandler *handler) const
      {
        size_t digit_count;
        oi_decimal_digit_count(data, &digit_count);
        if (digit_count == 0)
          {
            handler->number_value("0");
            return;
          }
        bool is_negative = oi_is_negative(data);
        char *buffer =
                (char *)(malloc(digit_count + 1 + (is_negative ? 1 : 0)));
        char *digit_start = buffer;
        if (is_negative)
          {
            digit_start[0] = '-';
            ++digit_start;
          }
        oi_write_decimal_digits(data, digit_start);
        digit_start[digit_count] = 0;
        handler->number_value(buffer);
        free(buffer);
      }
    JSONIntegerValue *integer_value(void)  { return this; }
    const JSONIntegerValue *integer_value(void) const  { return this; }
    JSONValue *clone(void) const  { return new JSONIntegerValue(data); }
    bool is_equal_to(const JSONValue *other) const
      {
        const JSONIntegerValue *other_integer_value = other->integer_value();
        if (other_integer_value == NULL)
            return false;
        return oi_equal(getData(), other_integer_value->getData());
      }
  };

class JSONRationalValue : public JSONValue
  {
  private:
    o_integer mantissa_whole_part;
    o_integer mantissa_fraction_numerator;
    size_t mantissa_fraction_digit_count;
    o_integer exponent;

  public:
    JSONRationalValue(o_integer init_mantissa_whole_part,
            o_integer init_mantissa_fraction_numerator,
            size_t init_mantissa_fraction_digit_count, o_integer init_exponent)
      {
        mantissa_whole_part = init_mantissa_whole_part;
        mantissa_fraction_numerator = init_mantissa_fraction_numerator;
        mantissa_fraction_digit_count = init_mantissa_fraction_digit_count;
        exponent = init_exponent;
        oi_add_reference(mantissa_whole_part);
        oi_add_reference(mantissa_fraction_numerator);
        oi_add_reference(exponent);
      }
    JSONRationalValue(double init_double, int precision)
      {
        char buffer[200];
        sprintf(buffer, "%.*e", precision, init_double);

        const char *start_mantissa_whole = &(buffer[0]);
        if (*start_mantissa_whole == '-')
            ++start_mantissa_whole;
        const char *decimal_point = start_mantissa_whole;
        do
          {
            assert((*decimal_point >= '0') && (*decimal_point <= '9'));
            ++decimal_point;
          } while (*decimal_point != '.');
        oi_create_from_decimal_ascii(mantissa_whole_part,
                decimal_point - start_mantissa_whole, start_mantissa_whole,
                (buffer[0] == '-'));
        assert(!oi_out_of_memory(mantissa_whole_part));

        const char *exponent_marker = decimal_point + 1;
        while (*exponent_marker != 'e')
          {
            assert((*exponent_marker >= '0') && (*exponent_marker <= '9'));
            ++exponent_marker;
          }
        oi_create_from_decimal_ascii(mantissa_fraction_numerator,
                exponent_marker - (decimal_point + 1), (decimal_point + 1),
                false);
        assert(!oi_out_of_memory(mantissa_fraction_numerator));
        mantissa_fraction_digit_count = exponent_marker - (decimal_point + 1);

        const char *exponent_start = exponent_marker + 1;
        assert((*exponent_start == '-') || (*exponent_start == '+'));
        ++exponent_start;
        oi_create_from_decimal_ascii(exponent, strlen(exponent_start),
                exponent_start, (exponent_marker[1] == '-'));
        assert(!oi_out_of_memory(exponent));
      }
    ~JSONRationalValue(void)
      {
        oi_remove_reference(mantissa_whole_part);
        oi_remove_reference(mantissa_fraction_numerator);
        oi_remove_reference(exponent);
      }

    Kind kind(void) const  { return JVK_RATIONAL; }
    o_integer getMantissaWholePart(void) const  { return mantissa_whole_part; }
    o_integer getMantissaFractionNumerator(void) const
      { return mantissa_fraction_numerator; }
    size_t getMantissaFractionDigitCount(void) const
      { return mantissa_fraction_digit_count; }
    o_integer getExponent(void) const  { return exponent; }
    double getDouble(void) const
      {
        std::stringstream stream;
        JSONStreamWriter writer(stream);
        write(&writer);
        return strtod(stream.str().c_str(), NULL);
      }
    float getFloat(void) const
      {
        return (float)(getDouble());
      }
    void write(JSONHandler *handler) const
      {
        handler->number_value(mantissa_whole_part, mantissa_fraction_numerator,
                              mantissa_fraction_digit_count, exponent);
      }
    JSONRationalValue *rational_value(void)  { return this; }
    const JSONRationalValue *rational_value(void) const  { return this; }
    JSONValue *clone(void) const
      {
        return new JSONRationalValue(mantissa_whole_part,
                mantissa_fraction_numerator, mantissa_fraction_digit_count,
                exponent);
      }
    bool is_equal_to(const JSONValue *other) const
      {
        const JSONRationalValue *other_rational_value = other->rational_value();
        if (other_rational_value == NULL)
            return false;
        if (!(oi_equal(getExponent(), other_rational_value->getExponent())))
            return false;
        if (!(oi_equal(getMantissaWholePart(),
                       other_rational_value->getMantissaWholePart())))
          {
            return false;
          }
        if (getMantissaFractionDigitCount() !=
            other_rational_value->getMantissaFractionDigitCount())
          {
            return false;
          }
        return oi_equal(getMantissaFractionNumerator(),
                        other_rational_value->getMantissaFractionNumerator());
      }

    static double getDouble(o_integer mantissa_whole_part,
            o_integer mantissa_fraction_numerator,
            size_t mantissa_fraction_digit_count, o_integer exponent)
      {
        std::stringstream stream;
        JSONStreamWriter writer(stream);
        writer.number_value(mantissa_whole_part, mantissa_fraction_numerator,
                            mantissa_fraction_digit_count, exponent);
        return strtod(stream.str().c_str(), NULL);
      }
  };

class JSONTrueValue : public JSONValue
  {
  public:
    JSONTrueValue(void)  { }
    ~JSONTrueValue(void)  { }

    Kind kind(void) const  { return JVK_TRUE; }
    void write(JSONHandler *handler) const  { handler->true_value(); }
    JSONTrueValue *true_value(void)  { return this; }
    const JSONTrueValue *true_value(void) const  { return this; }
    JSONValue *clone(void) const  { return new JSONTrueValue(); }
    bool is_equal_to(const JSONValue *other) const
      { return (other->true_value() != NULL); }
  };

class JSONFalseValue : public JSONValue
  {
  public:
    JSONFalseValue(void)  { }
    ~JSONFalseValue(void)  { }

    Kind kind(void) const  { return JVK_FALSE; }
    void write(JSONHandler *handler) const  { handler->false_value(); }
    JSONFalseValue *false_value(void)  { return this; }
    const JSONFalseValue *false_value(void) const  { return this; }
    JSONValue *clone(void) const  { return new JSONFalseValue(); }
    bool is_equal_to(const JSONValue *other) const
      { return (other->false_value() != NULL); }
  };

class JSONNullValue : public JSONValue
  {
  public:
    JSONNullValue(void)  { }
    ~JSONNullValue(void)  { }

    Kind kind(void) const  { return JVK_NULL; }
    void write(JSONHandler *handler) const  { handler->null_value(); }
    JSONNullValue *null_value(void)  { return this; }
    const JSONNullValue *null_value(void) const  { return this; }
    JSONValue *clone(void) const  { return new JSONNullValue(); }
    bool is_equal_to(const JSONValue *other) const
      { return (other->null_value() != NULL); }
  };

class JSONObjectValue : public JSONValue
  {
  private:
    std::vector<std::string> keys;
    std::vector<JSONValue *> values;
    string_index *index;

  public:
    JSONObjectValue(void)
      {
        index = create_string_index();
      }
    ~JSONObjectValue(void)
      {
        size_t value_count = values.size();
        for (size_t value_num = 0; value_num < value_count; ++value_num)
            values[value_num]->remove_reference();
        destroy_string_index(index);
      }

    Kind kind(void) const  { return JVK_OBJECT; }
    size_t componentCount(void) const  { return values.size(); }
    const char *componentKey(size_t component_num) const
      {
        assert(keys.size() == values.size());
        assert(component_num < values.size());
        return keys[component_num].c_str();
      }
    JSONValue *componentValue(size_t component_num)
      {
        assert(keys.size() == values.size());
        assert(component_num < values.size());
        return values[component_num];
      }
    const JSONValue *componentValue(size_t component_num) const
      {
        assert(keys.size() == values.size());
        assert(component_num < values.size());
        return values[component_num];
      }
    JSONValue *lookup(const char *field_name)
      {
        return (JSONValue *)(lookup_in_string_index(index, field_name));
      }
    const JSONValue *lookup(const char *field_name) const
      {
        return (const JSONValue *)(lookup_in_string_index(index, field_name));
      }

    void write(JSONHandler *handler) const
      {
        handler->start_object();
        size_t count = keys.size();
        assert(count == values.size());
        for (size_t num = 0; num < count; ++num)
          {
            handler->start_pair(keys[num].c_str());
            values[num]->write(handler);
          }
        handler->finish_object();
      }
    JSONObjectValue *object_value(void)  { return this; }
    const JSONObjectValue *object_value(void) const  { return this; }
    JSONValue *clone(void) const
      {
        JSONObjectValue *result = new JSONObjectValue();
        size_t count = keys.size();
        assert(count == values.size());
        for (size_t num = 0; num < count; ++num)
            result->appendPair(keys[num].c_str(), values[num]);
        return result;
      }
    bool is_equal_to(const JSONValue *other) const
      {
        const JSONObjectValue *other_object_value = other->object_value();
        if (other_object_value == NULL)
            return false;

        size_t local_count = componentCount();
        for (size_t local_num = 0; local_num < local_count; ++local_num)
          {
            const char *key = componentKey(local_num);
            const JSONValue *local_value = componentValue(local_num);
            const JSONValue *other_value = other_object_value->lookup(key);
            if ((other_value == NULL) ||
                (!(local_value->is_equal_to(other_value))))
              {
                return false;
              }
          }

        size_t other_count = other_object_value->componentCount();
        for (size_t other_num = 0; other_num < other_count; ++other_num)
          {
            if (lookup(other_object_value->componentKey(other_num)) == NULL)
                return false;
          }
        return true;
      }

    void appendPair(const char *key, JSONValue *new_component)
      {
        assert(key != NULL);
        assert(new_component != NULL);

        assert(keys.size() == values.size());
        keys.push_back(key);
        values.push_back(new_component);
        enter_into_string_index(index, key, new_component);
        new_component->add_reference();
      }
    void setField(const char *key, JSONValue *new_component)
      {
        assert(key != NULL);
        assert(new_component != NULL);

        JSONValue *old_field = lookup(key);
        if (old_field == NULL)
          {
            appendPair(key, new_component);
          }
        else
          {
            size_t count = keys.size();
            assert(count == values.size());
            for (size_t num = 0; num < count; ++num)
              {
                if (strcmp(keys[num].c_str(), key) == 0)
                  {
                    values[num] = new_component;
                    break;
                  }
              }
            enter_into_string_index(index, key, new_component);
            new_component->add_reference();
            old_field->remove_reference();
          }
      }
    void clearField(const char *key)
      {
        assert(key != NULL);

        JSONValue *old_field = lookup(key);
        if (old_field == NULL)
            return;
        size_t count = keys.size();
        assert(count == values.size());
        for (size_t num = 0; num < count; ++num)
          {
            if (strcmp(keys[num].c_str(), key) == 0)
              {
                keys.erase(keys.begin() + num, keys.begin() + num + 1);
                values.erase(values.begin() + num, values.begin() + num + 1);
                break;
              }
          }
        remove_from_string_index(index, key);
        old_field->remove_reference();
      }
    void clearField(size_t field_num)
      {
        assert(field_num < keys.size());
        assert(field_num < values.size());
        remove_from_string_index(index, keys[field_num].c_str());
        values[field_num]->remove_reference();
        keys.erase(keys.begin() + field_num, keys.begin() + field_num + 1);
        values.erase(values.begin() + field_num,
                     values.begin() + field_num + 1);
      }
  };

class JSONArrayValue : public JSONValue
  {
  private:
    std::vector<JSONValue *> values;

  public:
    JSONArrayValue(void)  { }
    ~JSONArrayValue(void)
      {
        size_t value_count = values.size();
        for (size_t value_num = 0; value_num < value_count; ++value_num)
            values[value_num]->remove_reference();
      }

    Kind kind(void) const  { return JVK_ARRAY; }
    size_t componentCount(void) const  { return values.size(); }
    JSONValue *component(size_t component_num)
      {
        assert(component_num < values.size());
        return values[component_num];
      }
    const JSONValue *component(size_t component_num) const
      {
        assert(component_num < values.size());
        return values[component_num];
      }

    void write(JSONHandler *handler) const
      {
        handler->start_array();
        size_t count = values.size();
        for (size_t num = 0; num < count; ++num)
            values[num]->write(handler);
        handler->finish_array();
      }
    JSONArrayValue *array_value(void)  { return this; }
    const JSONArrayValue *array_value(void) const  { return this; }
    JSONValue *clone(void) const
      {
        JSONArrayValue *result = new JSONArrayValue();
        size_t count = values.size();
        for (size_t num = 0; num < count; ++num)
            result->appendComponent(values[num]);
        return result;
      }
    bool is_equal_to(const JSONValue *other) const
      {
        const JSONArrayValue *other_array_value = other->array_value();
        if (other_array_value == NULL)
            return false;
        size_t count = componentCount();
        if (other_array_value->componentCount() != count)
            return false;
        for (size_t num = 0; num < count; ++num)
          {
            if (!(component(num)->is_equal_to(
                          other_array_value->component(num))))
              {
                return false;
              }
          }
        return true;
      }

    void appendComponent(JSONValue *new_component)
      {
        assert(new_component != NULL);
        values.push_back(new_component);
        new_component->add_reference();
      }
  };


class JSONValueHandler : public JSONHandler
  {
  public:
    void handle_value(JSONValue *item)
      {
        if (stack.size() == 0)
          {
            if (result != NULL)
                result->remove_reference();
            result = item;
            new_value(result);
            handle_result(result);
          }
        else
          {
            JSONValue *top = stack[stack.size() - 1];
            if (top->kind() == JSONValue::JVK_ARRAY)
              {
                ((JSONArrayValue *)top)->appendComponent(item);
              }
            else
              {
                assert(top->kind() == JSONValue::JVK_OBJECT);
                ((JSONObjectValue *)top)->appendPair(label.c_str(), item);
              }
            item->remove_reference();
          }
      }

  protected:
    void set_what(const char *what)  { }

  public:
    JSONValueHandler(void) : result(NULL)  { }
    JSONValueHandler(const char *what) : result(NULL)  { }
    ~JSONValueHandler(void)
      {
        if (result != NULL)
            result->remove_reference();
        for (size_t num = 0; num < stack.size(); ++num)
            stack[num]->remove_reference();
      }

    JSONValue *result;
    std::vector<JSONValue *> stack;
    std::vector<std::string> label_stack;
    std::string label;

    virtual void new_value(JSONValue *item)  { }
    virtual void handle_result(JSONValue *item)  { }

    void true_value(void)
      {
        handle_value(new JSONTrueValue());
      }
    void false_value(void)
      {
        handle_value(new JSONFalseValue());
      }
    void boolean_value(bool to_write)
      {
        if (to_write)
            true_value();
        else
            false_value();
      }
    void null_value(void)
      {
        handle_value(new JSONNullValue());
      }
    void string_value(const char *to_write)
      {
        handle_value(new JSONStringValue(to_write));
      }
    void string_value(const std::string &to_write)
      {
        string_value(to_write.c_str());
      }
    void number_value(int to_write)
      {
        o_integer the_oi;
        oi_create_from_long_int(the_oi, to_write);
        number_value(the_oi);
        oi_remove_reference(the_oi);
      }
    void number_value(unsigned int to_write)
      {
        o_integer the_oi;
        oi_create_from_unsigned_long_int(the_oi, to_write);
        number_value(the_oi);
        oi_remove_reference(the_oi);
      }
    void number_value(long to_write)
      {
        o_integer the_oi;
        oi_create_from_long_int(the_oi, to_write);
        number_value(the_oi);
        oi_remove_reference(the_oi);
      }
    void number_value(unsigned long to_write)
      {
        o_integer the_oi;
        oi_create_from_unsigned_long_int(the_oi, to_write);
        number_value(the_oi);
        oi_remove_reference(the_oi);
      }
    void number_value(o_integer to_write)
      {
        handle_value(new JSONIntegerValue(to_write));
      }
    void number_value(double to_write, int precision = DBL_DIG)
      {
        handle_value(new JSONRationalValue(to_write, precision));
      }
    void number_value(o_integer mantissa_whole_part,
            o_integer mantissa_fraction_numerator,
            size_t mantissa_fraction_digit_count, o_integer exponent)
      {
        handle_value(new JSONRationalValue(mantissa_whole_part,
                mantissa_fraction_numerator, mantissa_fraction_digit_count,
                exponent));
      }
    void number_value(const char *number_text)
      {
        parse_json_value(number_text, this);
      }
    void start_object(void)
      {
        stack.push_back(new JSONObjectValue());
        label_stack.push_back(label);
      }
    void start_pair(const char *name)
      {
        label = name;
      }
    void pair(const char *name, const char *value)
      {
        start_pair(name);
        string_value(value);
      }
    void pair(const char *name, const std::string &value)
      {
        start_pair(name);
        string_value(value);
      }
    void pair(const char *name, bool value)
      {
        start_pair(name);
        boolean_value(value);
      }
    void pair(const char *name, int value)
      {
        start_pair(name);
        number_value(value);
      }
    void pair(const char *name, unsigned int value)
      {
        start_pair(name);
        number_value(value);
      }
    void pair(const char *name, long value)
      {
        start_pair(name);
        number_value(value);
      }
    void pair(const char *name, unsigned long value)
      {
        start_pair(name);
        number_value(value);
      }
    void pair(const char *name, double value, int precision = DBL_DIG)
      {
        start_pair(name);
        number_value(value, precision);
      }
    void finish_object(void)
      {
        assert(stack.size() > 0);
        assert(label_stack.size() == stack.size());
        JSONValue *item = stack[stack.size() - 1];
        assert(item->kind() == JSONValue::JVK_OBJECT);
        label = label_stack[label_stack.size() - 1];
        stack.pop_back();
        label_stack.pop_back();
        handle_value(item);
      }
    void start_array(void)
      {
        stack.push_back(new JSONArrayValue());
        label_stack.push_back(label);
      }
    void finish_array(void)
      {
        assert(stack.size() > 0);
        assert(label_stack.size() == stack.size());
        JSONValue *item = stack[stack.size() - 1];
        assert(item->kind() == JSONValue::JVK_ARRAY);
        label = label_stack[label_stack.size() - 1];
        stack.pop_back();
        label_stack.pop_back();
        handle_value(item);
      }

    JSONValue *getResult(void)
      {
        if (result != NULL)
            result->add_reference();
        return result;
      }
  };


extern JSONValue *parse_json_value(JSONTextSource *source);
extern JSONValue *parse_json_value(FILE *fp, const char *file_name);
extern JSONValue *parse_json_value(const char *text);
extern JSONValue *parse_json_value(std::string text);


#endif /* JSONREP_H */
