//
// Created by Lucas on 18/06/2022.
//

#ifndef DJINN_COMPILER_SIGNATUREEXPRESSION_H
#define DJINN_COMPILER_SIGNATUREEXPRESSION_H


#include <set>
#include "../../AST.h"

struct SignatureExpression {
    AST *return_type;
    AST *name;
    std::vector<AST *> parameters;
};


#endif //DJINN_COMPILER_SIGNATUREEXPRESSION_H
