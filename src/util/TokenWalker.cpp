//
// Created by Lucas on 17/06/2022.
//

#include "TokenWalker.h"

TokenWalker::TokenWalker(Lexer *lexer) {
    this->current_position = 0;

    while (!lexer->get_walker()->is_end_of_file()) {
        this->tokens->push_back(lexer->next());
    }
}

Token *TokenWalker::peek(uint32_t offset) {
    if (this->current_position + offset >= this->tokens->size()) {
        return nullptr;
    }

    return this->tokens->at(this->current_position + offset);
}

void TokenWalker::advance(uint32_t count) {
    this->current_position += count;
}

bool TokenWalker::is_end_of_file() {
    return this->current_position >= this->tokens->size();
}

