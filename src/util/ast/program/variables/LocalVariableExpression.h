//
// Created by Lucas on 19/06/2022.
//

#ifndef DJINN_COMPILER_LOCALVARIABLEEXPRESSION_H
#define DJINN_COMPILER_LOCALVARIABLEEXPRESSION_H


#include "VariableExpression.h"

/**
 * Scope local variable.
 */
struct LocalVariableExpression : public VariableExpression {
    AST *parent;

};


#endif //DJINN_COMPILER_LOCALVARIABLEEXPRESSION_H
