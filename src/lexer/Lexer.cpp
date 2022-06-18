//
// Created by Lucas on 16/06/2022.
//

#include "Lexer.h"


Lexer::Lexer(TextWalker *walker) {
    this->walker = walker;
}


Token *Lexer::next() {
    auto location = this->walker->get_location();
    if (this->walker->is_end_of_file()) {
        return Lexer::make_token(TokenType::END_OF_FILE, location);
    }

    char peek = this->walker->peek();
    switch (peek) {
        case 'a': // TODO: UTF-8 support?
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            return Lexer::make_token(TokenType::IDENTIFIER, this->peek_identifier(), location);

        case '-': {
            this->walker->advance();
            char next = this->walker->peek();
            if (isdigit(next)) {
                this->walker->advance();
                return Lexer::make_token(TokenType::NUMBER_LITERAL, this->peek_number(), location);
            } else if (next == '-') {
                this->walker->advance();
                return Lexer::make_token(TokenType::DECREMENT, location);
            } else if (next == '=') {
                this->walker->advance();
                return Lexer::make_token(TokenType::MINUS_EQUAL, location);
            }

            return Lexer::make_token(TokenType::MINUS, location);
        }

        case '+': {
            this->walker->advance();
            char next = this->walker->peek();
            if (isdigit(next)) {
                this->walker->advance();
                return Lexer::make_token(TokenType::NUMBER_LITERAL, this->peek_number(), location);
            } else if (next == '+') {
                this->walker->advance();
                return Lexer::make_token(TokenType::INCREMENT, location);
            } else if (next == '=') {
                this->walker->advance();
                return Lexer::make_token(TokenType::PLUS_EQUAL, location);
            }

            return Lexer::make_token(TokenType::PLUS, location);
        }

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return Lexer::make_token(TokenType::NUMBER_LITERAL, this->peek_number(), location);

        case '{': {
            this->walker->advance();
            return Lexer::make_token(TokenType::OPEN_BRACE, location);
        }

        case '}': {
            this->walker->advance();
            return Lexer::make_token(TokenType::CLOSE_BRACE, location);
        }

        case '(': {
            this->walker->advance();
            return Lexer::make_token(TokenType::OPEN_BRACKET, location);
        }

        case ')': {
            this->walker->advance();
            return Lexer::make_token(TokenType::CLOSE_BRACKET, location);
        }

        case '[': {
            this->walker->advance();
            return Lexer::make_token(TokenType::OPEN_SQUARE_BRACKET, location);
        }

        case ']': {
            this->walker->advance();
            return Lexer::make_token(TokenType::CLOSE_SQUARE_BRACKET, location);
        }

        case ';': {
            this->walker->advance();
            return Lexer::make_token(TokenType::SEMICOLON, location);
        }

        case ':': {
            this->walker->advance();
            if (this->walker->peek() == ':') {
                this->walker->advance();
                return Lexer::make_token(TokenType::COLON_COLON, location);
            }
            return Lexer::make_token(TokenType::COLON, location);
        }

        case ',': {
            this->walker->advance();
            return Lexer::make_token(TokenType::COMMA, location);
        }

        case '.': {
            this->walker->advance();
            if (this->walker->peek() == '.') {
                this->walker->advance();
                return Lexer::make_token(TokenType::DOT_DOT, location);
            }
            return Lexer::make_token(TokenType::DOT, location);
        }

        case '^':
        case '*': {
            this->walker->advance();
            if (this->walker->peek() == '=') {
                this->walker->advance();
                return Lexer::make_token(TokenType::MULTIPLY_EQUAL, location);
            }
            if (this->walker->peek() == '*') {
                this->walker->advance();
                return Lexer::make_token(TokenType::POWER, location);
            }
            return Lexer::make_token(TokenType::MULTIPLY, location);
        }

        case '=': {
            this->walker->advance();
            if (this->walker->peek() == '=') {
                this->walker->advance();
                return Lexer::make_token(TokenType::EQUAL, location);
            }
            return Lexer::make_token(TokenType::ASSIGNMENT, location);
        }

        case '>': {
            this->walker->advance();
            if (this->walker->peek() == '=') {
                this->walker->advance();
                return Lexer::make_token(TokenType::GREATER_THAN_OR_EQUAL, location);
            }

            if (this->walker->peek() == '>') {
                this->walker->advance();
                return Lexer::make_token(TokenType::SHIFT_RIGHT, location);
            }

            return Lexer::make_token(TokenType::GREATER_THAN, location);
        }

        case '<': {
            this->walker->advance();
            if (this->walker->peek() == '=') {
                this->walker->advance();
                return Lexer::make_token(TokenType::LESS_THAN_OR_EQUAL, location);
            }

            if (this->walker->peek() == '<') {
                this->walker->advance();
                return Lexer::make_token(TokenType::SHIFT_LEFT, location);
            }

            return Lexer::make_token(TokenType::LESS_THAN, location);
        }

        case '!': {
            this->walker->advance();
            if (this->walker->peek() == '=') {
                this->walker->advance();
                return Lexer::make_token(TokenType::NOT_EQUAL, location);
            }

            return Lexer::make_token(TokenType::NOT, location);
        }

        case '?': {
            this->walker->advance();
            if (this->walker->peek() == '?') {
                this->walker->advance();
                return Lexer::make_token(TokenType::QUESTION_EQUAL, location);
            }

            return Lexer::make_token(TokenType::QUESTION, location);
        }

        case '&': {
            this->walker->advance();
            if (this->walker->peek() == '&') {
                this->walker->advance();
                return Lexer::make_token(TokenType::AND, location);
            }
            if (this->walker->peek() == '=') {
                this->walker->advance();
                return Lexer::make_token(TokenType::BITWISE_AND_EQUAL, location);
            }

            return Lexer::make_token(TokenType::BITWISE_AND, location);
        }

        case '|': {
            this->walker->advance();
            if (this->walker->peek() == '|') {
                this->walker->advance();
                return Lexer::make_token(TokenType::OR, location);
            }
            if (this->walker->peek() == '=') {
                this->walker->advance();
                return Lexer::make_token(TokenType::BITWISE_OR_EQUAL, location);
            }

            return Lexer::make_token(TokenType::BITWISE_OR, location);
        }

        case ' ': {
            this->skip_whitespace();
            return this->next();
        }

        case '\'': {
            // ' ' some char literal, must occur after ' character
            if (this->walker->peek() != '\'' && this->walker->peek() == '\'') {
                return Lexer::make_token(TokenType::CHAR_LITERAL, this->peek_char(), location);
            }

            return Lexer::make_token(TokenType::INVALID, location);
        }

        case '"': {
            return Lexer::make_token(TokenType::STRING_LITERAL, this->peek_string(), location);
        }
            /*
            case '$':{
                if(this->walker->peek() == '"'){
                    return Lexer::make_token(TokenType::STRING_LITERAL, this->peek_string());
                }

            }*/

            //TODO: handle control chars
        case '\n':
            /* case '\r':
             case '\t':*/{
            this->walker->break_line();
            this->walker->advance();
            return this->next();
        }

        case '\0': {
            return Lexer::make_token(TokenType::END_OF_FILE, location);
        }

        default: {            // TODO: handle comment and strings
            this->walker->advance();
            return Lexer::make_token(TokenType::UNKNOWN, location);
        }
    }
}

std::string Lexer::peek_identifier() {
    return (std::string) this->walker->peek_while([](char c, uint32_t offset) {
        return is_valid_identifier_char(c, offset);
    });
}

std::string Lexer::peek_number() {
    return (std::string) this->walker->peek_while([](char c, uint32_t offset) {
        return is_valid_number_char(c, offset);
    });
}

void Lexer::skip_whitespace() {
    this->walker->peek_while([](char c, uint32_t offset) {
        return is_whitespace(c);
    });
}

std::string Lexer::peek_string() {
    this->walker->advance(); // skip first "
    return (std::string) this->walker->peek_while([](char c, uint32_t offset) {
        return is_valid_string(c, offset);
    });
    this->walker->advance(); // skip last "
}

std::string Lexer::peek_char() {
    return std::string();
}

TextWalker *Lexer::get_walker() const {
    return this->walker;
}

Token *Lexer::make_token(TokenType type, const std::string &value, Location location) {
    return new Token(type, value, location);
}

Token *Lexer::make_token(TokenType type, Location location) {
    return Lexer::make_token(type, "", location);
}

