/* file "ReGex.h" */

/* Copyright 2013 SoundHound, Incorporated.  All rights reserved. */

#ifndef REGEX_H
#define REGEX_H

#include <vector>
#include <string>

extern "C"
{
    #include "regular_expression.h"
}


class RegEx
{
    private:

    regular_expression *re;

    public:

    /* Constructs a regular expression
     */
    RegEx(std::string expression){
        const char* expressionChars = expression.c_str();
        regular_expression_error regex_err;
        re = create_regular_expression_from_pattern(expressionChars, expression.length(), &regex_err);
    }

    ~RegEx(){
        regular_expression_remove_reference(re);
    }

    /* Retruns true if text matches regular expression, false if 
     * it does not, or there is an error
     */
    boolean match(std::string text){
        boolean err;
        boolean match = matches(re, text.c_str(), true, &err);
        return (match && !err);
    }

    /* Replaces the first appearance of a regular expression with 
     * the provided string. Replace is done on a pointer to the
     * text string
     */
    void replaceFirst(std::string* text, std::string replace){
        boolean err;
        size_t start;
        size_t leng;
        boolean match = longest_match(re, text->c_str(), true, &start, &leng, &err);
        if(match && !err){
            text->replace(start, leng, replace);
        }
    }

    /* Replaces all matches for a regular expression within the string text.
     */
    void replaceAll(std::string* text, std::string replace){
        int position = 0;
        boolean err;
        size_t start;
        size_t leng;
        std::string subText = text->substr(position);
        boolean match = longest_match(re, subText.c_str(), true, &start, &leng, &err);
        int count = 0;
        while(match && !err){
            position += start;
            text->replace(position, leng, replace);
            position += replace.length();
            subText = text->substr(position);
            match = longest_match(re, subText.c_str(), true, &start, &leng, &err);
            count++;
        }
    }

    /* Tokenizes a text and returns a vector of strings. 
     */
    std::vector<std::string> tokenize(std::string text){
        std::vector<std::string> toReturn;
        boolean err;
        size_t start;
        size_t leng;
        boolean match = longest_match(re, text.c_str(), true, &start, &leng, &err);
        while(match && !err){
            std::string sub = text.substr(0,start);
            toReturn.push_back(sub);
            text = text.substr(start+leng);
            match = longest_match(re, text.c_str(), true, &start, &leng, &err);
        }
        toReturn.push_back(text);
        return toReturn;
    }

};


#endif /* REGEX_H */
