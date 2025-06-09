//
// Created by Lucas on 16/06/2022.
//

#ifndef DJINN_COMPILER_TEXTWALKER_H
#define DJINN_COMPILER_TEXTWALKER_H

#include "cassert"
#include "Location.h"
#include <string>
#include <array>
#include <functional>

class TextWalker {
private:
    std::string source;
    uint32_t current_position = 0;
    uint32_t previous_position = 0;
    Location current_location = Location(0, 0, 0);

public:
    explicit TextWalker(const std::string &source);

    uint32_t get_remaining_length() {
        return this->source.length() - this->current_position;
    }

    void advance(uint32_t count = 1);

    void break_line(uint32_t count = 1);

    char peek(uint32_t offset = 0);

    char peekAdvance(uint32_t offset = 0, uint32_t count = 1);

    bool is_end_of_file();

    std::string peek_while(const std::function<bool(char, uint32_t)> &predicate, uint32_t offset = 0);

    Location get_location();
};


#endif //DJINN_COMPILER_TEXTWALKER_H
