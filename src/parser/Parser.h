//
// Created by Lucas on 17/06/2022.
//

#ifndef DJINN_COMPILER_PARSER_H
#define DJINN_COMPILER_PARSER_H


#include <map>
#include <memory>

#include "../util/TokenWalker.h"
#include "../util/typos/TokenTypeUtils.h"
#include "../util/ast/AST.h"
#include "../util/ast/program/Program.h"
#include "../util/ast/program/methods/MethodExpression.h"
#include "../util/ast/program/methods/CallableExpression.h"
#include "../util/ast/program/modifiers/AccessModifiersExpression.h"
#include "../util/ast/program/methods/ReturnExpression.h"
#include "../util/Constants.h"

class Parser {
    TokenWalker *walker;
    Program *program;

    std::map<TokenType, std::function<AST *(Token *)>> *parse_table;

    AST *parse_identifier(Token *token = nullptr);

    AST *parse_import(Token *token = nullptr);

    AST *parse_method(Token *token = nullptr);

    BodyExpression *parse_body(Token *token = nullptr, uint32_t deep = 0);

    AST *parse_expression(Token *token = nullptr);

public:
    explicit Parser(TokenWalker *walker);

    Program *parse();
};


#endif //DJINN_COMPILER_PARSER_H
