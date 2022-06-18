//
// Created by Lucas on 17/06/2022.
//

#ifndef DJINN_COMPILER_VARIABLEEXPRESSION_H
#define DJINN_COMPILER_VARIABLEEXPRESSION_H


#include <string>
#include "../AST.h"

class VariableExpression : public AST {
    std::string name;

    explicit VariableExpression(const std::string &name) {
        this->name = name;
    }
};


#endif //DJINN_COMPILER_VARIABLEEXPRESSION_H
