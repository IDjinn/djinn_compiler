//
// Created by Lucas on 16/06/2022.
//

#ifndef DJINN_COMPILER_TOKEN_H
#define DJINN_COMPILER_TOKEN_H


#include <string>
#include <utility>
#include "TokenType.h"
#include "../Location.h"
#include "../ast/AST.h"

class Token : public AST {
private:
    TokenType type;
    std::string value;
    Location location;

public:
    Token(TokenType type, Location location) {
        this->type = type;
        this->value = "";
        this->location = location;
    }

    Token(TokenType type, std::string value, Location location) {
        this->type = type;
        this->value = std::move(value);
        this->location = location;
    }

    std::string &get_value() {
        return this->value;
    }

    TokenType get_type() {
        return this->type;
    }
};


#endif //DJINN_COMPILER_TOKEN_H
