//
// Created by Lucas on 18/06/2022.
//

#ifndef DJINN_COMPILER_IMPORTEXPRESSION_H
#define DJINN_COMPILER_IMPORTEXPRESSION_H

#include <string>
#include <utility>
#include "../../AST.h"

class ImportExpression : public AST {
    std::string link;

public:
    explicit ImportExpression(std::string link) : link(std::move(link)) {}

};

#endif //DJINN_COMPILER_IMPORTEXPRESSION_H
