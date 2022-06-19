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
#include "../util/ast/program/Program.h"

class Parser {
    TokenWalker *walker;
    Program *program;

    std::map<TokenType, std::function<AST *(Token *)>> *parse_table;

    AST *parse_identifier(Token *token = nullptr);

    AST *parse_import(Token *token = nullptr);

    AST *parse_method(Token *token = nullptr);

public:
    explicit Parser(TokenWalker *walker);

    void parse();
};


#endif //DJINN_COMPILER_PARSER_H
