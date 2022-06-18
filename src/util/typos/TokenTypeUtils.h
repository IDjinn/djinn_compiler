//
// Created by Lucas on 17/06/2022.
//

#ifndef DJINN_COMPILER_TOKENTYPEUTILS_H
#define DJINN_COMPILER_TOKENTYPEUTILS_H


#include "TokenType.h"
#include <string>
#include <map>

static const std::map<std::string, TokenType> KEYWORD_TO_TOKEN_TYPE = {
        {"import", TokenType::IMPORT},
        {"f",      TokenType::FUNCTION},
        {"public", TokenType::PUBLIC},
};

static const std::map<TokenType, std::string> TOKEN_TYPE_TO_KEYWORD = {
        {TokenType::IMPORT,   "import"},
        {TokenType::FUNCTION, "f"},
        {TokenType::PUBLIC,   "public"},
};


inline TokenType parse_token_type_from_value(const std::string &value, bool ignore_case = true) {
    //TODO: to lower
    auto it = KEYWORD_TO_TOKEN_TYPE.find(value);
    if (it != KEYWORD_TO_TOKEN_TYPE.end()) {
        return it->second;
    }

    return TokenType::UNKNOWN;
}

inline std::string parse_value_from_token_type(TokenType type) {
    auto it = TOKEN_TYPE_TO_KEYWORD.find(type);
    if (it != TOKEN_TYPE_TO_KEYWORD.end()) {
        return it->second;
    }

    return "";
}


#endif //DJINN_COMPILER_TOKENTYPEUTILS_H
