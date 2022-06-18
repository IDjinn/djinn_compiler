//
// Created by Lucas on 18/06/2022.
//

#ifndef DJINN_COMPILER_ACCESSMODIFIERSEXPRESSION_H
#define DJINN_COMPILER_ACCESSMODIFIERSEXPRESSION_H


#include "../AST.h"
#include "ModifierType.h"


class AccessModifiersExpression : public AST {
private:
    AST *modifier;
    ModifierType type;

public:

};


#endif //DJINN_COMPILER_ACCESSMODIFIERSEXPRESSION_H
