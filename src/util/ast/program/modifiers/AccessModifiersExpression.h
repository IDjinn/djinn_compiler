//
// Created by Lucas on 18/06/2022.
//

#ifndef DJINN_COMPILER_ACCESSMODIFIERSEXPRESSION_H
#define DJINN_COMPILER_ACCESSMODIFIERSEXPRESSION_H


#include <vector>
#include "../../AST.h"
#include "ModifierExpression.h"

struct AccessModifiersExpression : public AST {
    std::vector<ModifierExpression *> modifiers;

public:
    explicit AccessModifiersExpression(std::vector<ModifierExpression *> modifiers) : modifiers(std::move(modifiers)) {}

    AccessModifiersExpression() {
        modifiers = std::vector<ModifierExpression *>();
    }

    void add_modifier(ModifierExpression *modifier) {
        modifiers.push_back(modifier);
    }
};


#endif //DJINN_COMPILER_ACCESSMODIFIERSEXPRESSION_H
