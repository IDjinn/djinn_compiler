cmake_minimum_required(VERSION 3.22)
project(djinn_compiler)

set(CMAKE_CXX_STANDARD 23)


add_executable(djinn_compiler main.cpp src/util/typos/Token.h src/lexer/Lexer.cpp src/lexer/Lexer.h src/util/TextWalker.cpp src/util/TextWalker.h src/util/typos/TokenType.h src/util/Util.h src/util/TokenWalker.cpp src/util/TokenWalker.h src/util/Location.h src/parser/Parser.cpp src/parser/Parser.h src/util/typos/TokenTypeUtils.h src/util/ast/AST.cpp src/util/ast/AST.h src/util/ast/program/variables/VariableExpression.h src/util/ast/program/methods/MethodExpression.h src/util/ast/program/modifiers/ModifierExpression.h src/util/ast/program/modifiers/ModifierType.h src/util/ast/program/imports/ImportExpression.h src/util/ast/program/methods/CallableExpression.h src/util/ast/program/Program.h src/util/ast/program/modifiers/AccessModifiersExpression.h src/util/ast/program/methods/SignatureExpression.h)

