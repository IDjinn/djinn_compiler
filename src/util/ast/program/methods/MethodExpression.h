//
// Created by Lucas on 18/06/2022.
//

#ifndef DJINN_COMPILER_METHODEXPRESSION_H
#define DJINN_COMPILER_METHODEXPRESSION_H


#include <string>
#include <utility>
#include <vector>
#include "../../AST.h"

class MethodExpression : public AST {
private:
    AST *callable;
    AST *parent;

public:
    explicit MethodExpression(AST *callable, AST *parent) : callable(callable), parent(parent) {}
};


#endif //DJINN_COMPILER_METHODEXPRESSION_H
