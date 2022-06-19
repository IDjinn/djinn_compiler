//
// Created by Lucas on 18/06/2022.
//

#ifndef DJINN_COMPILER_BODYEXPRESSION_H
#define DJINN_COMPILER_BODYEXPRESSION_H


#include "../../AST.h"
#include <set>
#include <vector>

struct BodyExpression : public AST {
    std::vector<AST *> statements;

public:
    explicit BodyExpression(std::vector<AST *> statements) : statements(std::move(statements)) {}

    /*
    void accept(Visitor *visitor) override {
        visitor->visit(this);
    }*/
    BodyExpression() {
        statements = *new std::vector<AST *>();
    }
};


#endif //DJINN_COMPILER_BODYEXPRESSION_H
