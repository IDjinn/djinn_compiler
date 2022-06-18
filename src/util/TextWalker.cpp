//
// Created by Lucas on 16/06/2022.
//

#include <memory>
#include "TextWalker.h"

char TextWalker::peek(uint32_t offset) {
    assert(this->source.length() > this->current_position + offset);
    return this->source.at(this->current_position + offset);
}

char TextWalker::peekAdvance(uint32_t offset, uint32_t count) {
    char peek = this->peek(offset);
    this->current_position += count;
    this->current_location.index += count;
    this->current_location.column += count;
    return peek;
}

std::vector<char> TextWalker::peek_while(const std::function<bool(char, uint32_t)> &predicate, uint32_t offset) {
    std::vector<char> result;
    while (!this->is_end_of_file() && predicate(this->peek(), offset++)) {
        result.push_back(this->peekAdvance());
    }
    return result;
}

bool TextWalker::is_end_of_file() {
    return this->current_position >= this->source.length();
}

TextWalker::TextWalker(const std::string &source) {
    this->source = source;
}

void TextWalker::advance(uint32_t count) {
    this->current_position += count;
    this->current_location.index += count;
    this->current_location.column += count;
}

void TextWalker::break_line(uint32_t count) {
    this->current_location.line += count;
    this->current_location.index += count;
    this->current_location.column = 0;
}

Location TextWalker::get_location() {
    return Location{this->current_location.line, this->current_location.column, this->current_location.index};
}

