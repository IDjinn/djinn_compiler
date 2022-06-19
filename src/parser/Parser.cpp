//
// Created by Lucas on 17/06/2022.
//

#include "Parser.h"

Parser::Parser(TokenWalker *walker) {
    this->walker = walker;
    this->program = new Program();

    this->parse_table = new std::map<TokenType, std::function<AST *(Token *)>>();
    this->parse_table->insert({TokenType::IDENTIFIER, [&](Token *token) { return this->parse_identifier(token); }});
    this->parse_table->insert({TokenType::PUBLIC, [&](Token *token) { return this->parse_method(token); }});
}

void Parser::parse() {
    do {
        auto token = this->walker->peek();
        if (token == nullptr) {
            break; // never should happen
        }

        auto parsed_type = parse_token_type_from_value(token->get_value());
        auto it = this->parse_table->find(parsed_type);
        if (it != this->parse_table->end()) {
            auto parse_function = it->second;
            auto ast = parse_function(token);
            if (parsed_type == TokenType::IMPORT) {
                this->program->add_import(ast);
            } else {
                this->program->add_method(ast);
            }
        }

        this->walker->advance();
    } while (!this->walker->is_end_of_file());
}

AST *Parser::parse_identifier(Token *token) {
    return nullptr;
}

AST *Parser::parse_method(Token *token) {
    auto callable = new CallableExpression();
    callable->modifiers = new AccessModifiersExpression();

    Token *fx = nullptr, *return_type = nullptr, *identifier = nullptr;
    do {
        token = this->walker->peek(); // TODO: continue consuming from token position, do not peek from walker
        auto parsed_type = parse_token_type_from_value(token->get_value());
        auto type = parsed_type == TokenType::UNKNOWN ? token->get_type() : parsed_type;
        switch (type) {
            case TokenType::PUBLIC: // TODO: move-me to my own method
            case TokenType::PRIVATE:
            case TokenType::PROTECTED:
            case TokenType::STATIC:
            case TokenType::ABSTRACT: {
                auto modifier = new ModifierExpression();
                modifier->modifier = token;
                modifier->type = Modifier::token_type_to_modifier_type(parsed_type);
                callable->modifiers->add_modifier(modifier);
                this->walker->advance();
                continue;
            }

            case TokenType::FUNCTION: {// TODO: move-me to my own method
                fx = token;
                this->walker->advance();
                continue; // uselless token
            }

                // built-in types
            case TokenType::VOID:// TODO: move-me to my own method
            case TokenType::INT16:
            case TokenType::INT32:
            case TokenType::INT64:
            case TokenType::INT128:
            case TokenType::FLOAT32:
            case TokenType::FLOAT64:
            case TokenType::FLOAT128:
            case TokenType::STRING:
            case TokenType::CHAR:
            case TokenType::BOOL:
            case TokenType::BYTE: {
                assert(fx != nullptr); // built-in types must be preceded by a function (f)
                auto signature = new SignatureExpression();
                signature->return_type = token;
                callable->signature = signature;
                return_type = token;
                this->walker->advance();
                continue;
            }


            case TokenType::OPEN_BRACE: { // TODO: move-me to my own method
                assert(fx != nullptr); //first function flag
                assert(return_type != nullptr);  // then return type
                assert(identifier != nullptr); // then identifier

                // TODO: function params
                this->walker->advance();
                this->parse_body(nullptr, 0);
                continue;
            }

            case TokenType::CLOSE_BRACE: {
                this->walker->advance();
                continue;
            }

            case TokenType::OPEN_BRACKET: { // TODO: move-me to my own method
                assert(fx != nullptr); //first function flag
                assert(return_type != nullptr);  // then return type
                assert(identifier != nullptr); // then identifier

                this->parse_body(nullptr, 0);
                // TODO: function params
                this->walker->advance();
                assert(this->walker->peek()->get_type() == TokenType::CLOSE_BRACKET);
                this->walker->advance();
                continue;
            }


            case TokenType::IDENTIFIER: {
                identifier = token;
                callable->signature->name = token;
                this->walker->advance();
                continue;
            }

            default:
                return callable;
        }
    } while (true); // TODO: infinite loop protection


    return nullptr;
}

AST *Parser::parse_import(Token *token) {
    return nullptr;
}

AST *Parser::parse_body(Token *token, uint32_t deep) {
    auto body = new BodyExpression();
    if (deep++ > MAX_BODY_RECURSION_DEPTH) {
        return body;
    }

    do {
        token = this->walker->peek();
        auto parsed_type = parse_token_type_from_value(token->get_value());
        auto type = parsed_type == TokenType::UNKNOWN ? token->get_type() : parsed_type;
        switch (type) {
            case STATIC: // TODO: static, const local variables
            case CONST:
            default:
                break;

            case TokenType::RETURN: {
                auto return_expression = new ReturnExpression();
                body->statements.push_back(return_expression);
                this->walker->advance();
                continue;
            }

            case TokenType::IDENTIFIER: { // TODO: this is a variable or type.

            }

            case TokenType::OPEN_BRACE: {
                this->walker->advance();
                body->statements.push_back(this->parse_body(nullptr, deep + 1));
                continue;
            }

            case TokenType::CLOSE_BRACE: {
                this->walker->advance();
                return body; // return recursive body. This is the one way to leave this method. check to do below
            }
        }

        // TODO: infinite loop protection
    } while (true);

    return nullptr;
}
