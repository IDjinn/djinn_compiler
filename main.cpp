#include <fstream>
#include <sstream>
#include "src/lexer/Lexer.h"
#include "src/util/ast/AST.h"
#include "src/parser/Parser.h"

int main() {
    std::ifstream file_reader("helloWorld.djinn");
    std::stringstream buffer;
    buffer << file_reader.rdbuf();
    std::string code = buffer.str();
    auto lexer = new Lexer(new TextWalker(code));
    Parser parser(new TokenWalker(lexer));
    parser.parse();
    return 0;
}
