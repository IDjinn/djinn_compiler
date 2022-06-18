//
// Created by Lucas on 16/06/2022.
//

#ifndef DJINN_COMPILER_UTIL_H
#define DJINN_COMPILER_UTIL_H


#include <cstdint>
#include <cctype>

inline bool is_valid_identifier_char(char c, uint32_t offset) {
    return std::isalpha(c) || offset > 0 && (isdigit(c) || c == '_');
}

// allow [+-] followed by [0-9_.eE]
inline bool is_valid_number_char(char c, uint32_t offset) {
    if (offset == 0)
        return isdigit(c) || c == '-' || c == '+';

    return isdigit(c) || c == '.' || c == 'e' || c == 'E' || c == '_';
}

inline bool is_whitespace(char c) {
    return c == ' ';
}

inline bool is_control_char(char c) {
    return c == '\n' || c == '\r' || c == '\t';
}

inline bool is_valid_string(char c, uint32_t offset) {
    return c != '"';
}


#endif //DJINN_COMPILER_UTIL_H
