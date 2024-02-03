#pragma once

#include <string>
#include <optional>
#include <vector>
#include <map>
#include "keywords.hpp"




class token {
public:
    tokenType type;
    std::optional<std::string> value;

    token(tokenType type) : type(type) {}
    token(tokenType type, std::string value) : type(type), value(value) {}

    std::string toStr() {
        if(value.has_value())
            return("[ " + std::to_string(as_int(type)) + " : " +  value.value() + " ]");
        return("[ " + std::to_string(as_int(type)) + " ]");
    }
};

token getWord(std::string text, int* pos) {
    std::string word = "";

    char currentChar = text[*pos];

    do {
        word.push_back(currentChar);
        (*pos)++;

        if(*pos < text.length())
            currentChar = text[*pos];
        else
            break;
    } while(isalpha(currentChar));

    if(keywords.contains(word))
        return token(keywords.at(word));
    return token(tokenType::_invalid_key_word, word);
}

token getNum(std::string text, int* pos) {
    std::string num = "";

    char currentChar = text[*pos];

    bool isFloat = false;

    do {
        if(currentChar == '.')
            isFloat = true;

        num.push_back(currentChar);
        (*pos)++;

        if(*pos < text.length())
            currentChar = text[*pos];
        else
            break;
    } while(isdigit(currentChar) || currentChar == '.');

    if(isFloat)
        return token(tokenType::_float, num);
    return token(tokenType::_int, num);
}

std::vector<token> tokenize(std::string str) {
    std::vector<token> tokens = {};

    char currentChar;


    for(int i = 0; i < str.length(); i++) {
        currentChar = str[i];

        if(isspace(currentChar))
            continue;

        if(isalpha(currentChar)) {
            tokens.push_back(getWord(str, &i));
        }

        if(isdigit(currentChar) || currentChar == '.')  {
            tokens.push_back(getNum(str, &i));
        }

        if(currentChar == '/' && str[i+1] == '/') {
            // Make the line a comment, not reading anything until the next line
            while (i < str.length() && (currentChar != '\n' && currentChar != '\r' && currentChar != '\0')) {
                currentChar = str[i];
                i++;
                std::cout << "\"" << currentChar << "\"";
                std::cout << " : " << i << std::endl;
            }
        }
    }


    return tokens;
}