//
// Created by Lucas on 19/06/2022.
//

#ifndef DJINN_COMPILER_CONSTANTEXPRESSION_H
#define DJINN_COMPILER_CONSTANTEXPRESSION_H

#include <string>
#include "../../AST.h"

/**
 * Represent any kind of constant literal expression. This is abstract class must be
 * implemented by all concrete types.
 */
struct ConstantExpression : public AST {
    std::string value;


    virtual ~ConstantExpression() = default;
};

#endif //DJINN_COMPILER_CONSTANTEXPRESSION_H
