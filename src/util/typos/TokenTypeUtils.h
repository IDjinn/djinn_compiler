//
// Created by Lucas on 17/06/2022.
//

#ifndef DJINN_COMPILER_TOKENTYPEUTILS_H
#define DJINN_COMPILER_TOKENTYPEUTILS_H


#include "TokenType.h"
#include <string>
#include <map>

static const std::map<std::string, TokenType> KEYWORD_TO_TOKEN_TYPE = {
        {"import",   TokenType::IMPORT},
        {"public",   TokenType::PUBLIC},
        {"f",        TokenType::FUNCTION},
        {"void",     TokenType::VOID},
        {"int16",    TokenType::INT16},
        {"int32",    TokenType::INT32},
        {"int64",    TokenType::INT64},
        {"int128",   TokenType::INT128},
        {"f32",      TokenType::FLOAT32},
        {"f64",      TokenType::FLOAT64},
        {"bool",     TokenType::BOOL},
        {"string",   TokenType::STRING},
        {"char",     TokenType::CHAR},
        {"uint16",   TokenType::UINT16},
        {"uint32",   TokenType::UINT32},
        {"uint64",   TokenType::UINT64},
        {"uint128",  TokenType::UINT128},
        {"byte",     TokenType::BYTE},
        {"static",   TokenType::STATIC},
        {"abstract", TokenType::ABSTRACT},
        {"return",   TokenType::RETURN},

};

static const std::map<TokenType, std::string> TOKEN_TYPE_TO_KEYWORD = {
        {TokenType::IMPORT,   "import"},
        {TokenType::FUNCTION, "f"},
        {TokenType::PUBLIC,   "public"},
        {TokenType::VOID,     "void"},
        {TokenType::INT16,    "int16"},
        {TokenType::INT32,    "int32"},
        {TokenType::INT64,    "int64"},
        {TokenType::INT128,   "int128"},
        {TokenType::FLOAT32,  "f32"},
        {TokenType::FLOAT64,  "f64"},
        {TokenType::BOOL,     "bool"},
        {TokenType::STRING,   "string"},
        {TokenType::CHAR,     "char"},
        {TokenType::UINT16,   "uint16"},
        {TokenType::UINT32,   "uint32"},
        {TokenType::UINT64,   "uint64"},
        {TokenType::UINT128,  "uint128"},
        {TokenType::BYTE,     "byte"},
        {TokenType::RETURN,   "return"},


};


inline TokenType parse_token_type_from_value(std::string &value, bool ignore_case = true) {
    /*if (ignore_case) {
        std::transform(value.begin(), value.end(), value.begin(), ::tolower);
    }*/

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


inline bool is_semicolon(TokenType type) {
    return type == TokenType::SEMICOLON;
}


#endif //DJINN_COMPILER_TOKENTYPEUTILS_H
