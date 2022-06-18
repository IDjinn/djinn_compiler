//
// Created by Lucas on 17/06/2022.
//

#ifndef DJINN_COMPILER_PARSER_H
#define DJINN_COMPILER_PARSER_H


#include <map>
#include "../util/TokenWalker.h"
#include "../util/typos/TokenTypeUtils.h"
#include "../util/ast/AST.h"
#include <memory>

class Parser {
    TokenWalker *walker;

    std::map<TokenType, std::function<AST *(Token *)>> *parse_table;

    AST *parse_identifier(Token *token);

    AST *parse_method(Token *token);

public:
    explicit Parser(TokenWalker *walker);

    void parse();
};


#endif //DJINN_COMPILER_PARSER_H
