//
// Created by Lucas on 18/06/2022.
//

#ifndef DJINN_COMPILER_CALLABLEEXPRESSION_H
#define DJINN_COMPILER_CALLABLEEXPRESSION_H


#include <string>
#include "../../AST.h"
#include "../modifiers/AccessModifiersExpression.h"
#include "SignatureExpression.h"

struct CallableExpression : public AST {
    AccessModifiersExpression *modifiers;
    SignatureExpression *signature;
    AST *body;

public:
    explicit CallableExpression(AccessModifiersExpression *modifier, SignatureExpression *signature, AST *body)
            : modifiers(modifier), signature(signature), body(body) {}

    CallableExpression() {}

};


#endif //DJINN_COMPILER_CALLABLEEXPRESSION_H
