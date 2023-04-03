//
// Created by Lucas on 18/06/2022.
//

#ifndef DJINN_COMPILER_RETURNEXPRESSION_H
#define DJINN_COMPILER_RETURNEXPRESSION_H


#include "../../AST.h"

struct ReturnExpression : public AST {
    AST *left;
    AST *right;
};


#endif //DJINN_COMPILER_RETURNEXPRESSION_H
