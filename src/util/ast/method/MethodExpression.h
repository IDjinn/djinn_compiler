//
// Created by Lucas on 18/06/2022.
//

#ifndef DJINN_COMPILER_METHODEXPRESSION_H
#define DJINN_COMPILER_METHODEXPRESSION_H


#include <string>
#include <vector>
#include "../AST.h"

class MethodExpression : public AST {
private:
    AST *modifier;
    std::string name;
    AST *signature;
    AST *body;

public:
    MethodExpression(AST *modifier, const std::string &name, AST *signature, AST *body) : modifier(modifier),
                                                                                          name(name),
                                                                                          signature(signature),
                                                                                          body(body) {}

};


#endif //DJINN_COMPILER_METHODEXPRESSION_H
