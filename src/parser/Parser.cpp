//
// Created by Lucas on 17/06/2022.
//

#include "Parser.h"
#include "../util/ast/program/methods/MethodExpression.h"
#include "../util/ast/program/methods/CallableExpression.h"
#include "../util/ast/program/modifiers/AccessModifiersExpression.h"

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
            break;
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

    Token *fx = nullptr;
    Token *return_type = nullptr;
    do {
        token = this->walker->peek(); // TODO: continue consuming from token position, do not peek from walker
        auto parsed_type = parse_token_type_from_value(token->get_value());
        switch (parsed_type) {
            case TokenType::PUBLIC:
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

            case TokenType::FUNCTION: {
                fx = token;
                this->walker->advance();
                continue; // uselless token
            }

                // built-in types
            case TokenType::VOID:
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

            case TokenType::OPEN_BRACE: {
                assert(fx != nullptr); //first function flag
                assert(return_type != nullptr);  // then return type
                auto body = this->parse_body();
            }


            case TokenType::IDENTIFIER: {
                break;
            }

            default:
                return callable;
        }
    } while (true);


    return nullptr;
}

AST *Parser::parse_import(Token *token) {
    return nullptr;
}
