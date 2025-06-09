//
// Created by Lucas on 16/06/2022.
//

#ifndef DJINN_COMPILER_LEXER_H
#define DJINN_COMPILER_LEXER_H


#include <memory>
#include "../util/TextWalker.h"
#include "../util/typos/Token.h"
#include "../util/Util.h"
#include <utility>

class Lexer {
private:
    TextWalker *walker;
    Location *current_location;

    std::string peek_identifier();

    std::string peek_number();

    void skip_whitespace();

    std::string peek_string();

    [[nodiscard]] char peek_char() const;

    static Token *make_token(TokenType type, Location location);

    static Token *make_token(TokenType type, const std::string &value, Location location);

public:
    explicit Lexer(TextWalker *walker);

    Token *next();

    [[nodiscard]] TextWalker *get_walker() const;
};


#endif //DJINN_COMPILER_LEXER_H
