//
// Created by Lucas on 17/06/2022.
//

#ifndef DJINN_COMPILER_TOKENWALKER_H
#define DJINN_COMPILER_TOKENWALKER_H


#include <vector>
#include "typos/Token.h"
#include "../lexer/Lexer.h"

class TokenWalker {
private:
    std::vector<Token *> *tokens = new std::vector<Token *>();
    uint32_t current_position = 0;

public:
    explicit TokenWalker(Lexer *lexer);

    Token *peek(uint32_t offset = 0);

    void advance(uint32_t count = 1);

    bool is_end_of_file();
};


#endif //DJINN_COMPILER_TOKENWALKER_H
