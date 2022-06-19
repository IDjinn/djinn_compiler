//
// Created by Lucas on 18/06/2022.
//

#ifndef DJINN_COMPILER_MODIFIEREXPRESSION_H
#define DJINN_COMPILER_MODIFIEREXPRESSION_H


#include "../../AST.h"
#include "ModifierType.h"


struct ModifierExpression : public AST {
    AST *modifier;
    Modifier::Type type;

public:

};


#endif //DJINN_COMPILER_MODIFIEREXPRESSION_H
