cmake_minimum_required(VERSION 3.22)
project(djinn_compiler)

set(CMAKE_CXX_STANDARD 23)


add_executable(djinn_compiler main.cpp src/util/typos/Token.h src/lexer/Lexer.cpp src/lexer/Lexer.h src/util/TextWalker.cpp src/util/TextWalker.h src/util/typos/TokenType.h src/util/Util.h src/util/TokenWalker.cpp src/util/TokenWalker.h src/util/Location.h src/parser/Parser.cpp src/parser/Parser.h src/util/typos/TokenTypeUtils.h src/util/ast/AST.cpp src/util/ast/AST.h src/util/ast/variables/VariableExpression.h src/util/ast/method/MethodExpression.h src/util/ast/modifiers/AccessModifiersExpression.h src/util/ast/modifiers/ModifierType.h)

