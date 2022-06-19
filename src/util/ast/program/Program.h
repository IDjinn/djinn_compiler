//
// Created by Lucas on 18/06/2022.
//

#ifndef DJINN_COMPILER_PROGRAM_H
#define DJINN_COMPILER_PROGRAM_H


#include <utility>
#include <vector>
#include "../AST.h"

class Program : public AST {
    std::vector<AST *> imports;
    std::vector<AST *> methods;

public:
    Program(std::vector<AST *> imports, std::vector<AST *> methods) : imports(std::move(imports)),
                                                                      methods(std::move(methods)) {}

    Program() {
        this->imports = std::vector<AST *>();
        this->methods = std::vector<AST *>();
    }

    void add_import(AST *import) {
        this->imports.push_back(import);
    }

    void add_method(AST *function) {
        this->methods.push_back(function);
    }
};


#endif //DJINN_COMPILER_PROGRAM_H
