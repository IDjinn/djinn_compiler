//
// Created by Lucas on 17/06/2022.
//

#include "Parser.h"
#include "../util/ast/program/imports/ImportExpression.h"

Parser::Parser(TokenWalker *walker) {
    this->walker = walker;
    this->program = new Program();

    this->parse_table = new std::map<TokenType, std::function<AST *(Token *)>>();
    this->parse_table->insert({TokenType::IDENTIFIER, [&](Token *token) { return this->parse_identifier(token); }});
    this->parse_table->insert({TokenType::PUBLIC, [&](Token *token) { return this->parse_method(token); }});
    this->parse_table->insert({TokenType::IMPORT, [&](Token *token) { return this->parse_import(token); }});
}

Program *Parser::parse() {
    do {
        auto token = this->walker->peek();
        assert(token != nullptr);
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
            continue;
        }

        this->walker->advance();
    } while (!this->walker->is_end_of_file());
    return this->program;
}

AST *Parser::parse_identifier(Token *token) {
    return nullptr;
}

AST *Parser::parse_method(Token *token) {
    auto callable = new CallableExpression();
    callable->modifiers = new AccessModifiersExpression(); // TODO: do not create if it's invalid?

    Token *fx = nullptr, *return_type = nullptr, *identifier = nullptr; // TODO: instances is unused, should use some bitflags to check declarations?
    do {
        token = this->walker->peek(); // TODO: continue consuming from token position, do not peek from
        if (token == nullptr) { // TODO: this should be there. Should never returns nullptr inside this function.
            return callable;
        }

        auto parsed_type = parse_token_type_from_value(token->get_value());
        auto type = parsed_type == TokenType::UNKNOWN ? token->get_type() : parsed_type;
        switch (type) {
            case TokenType::PUBLIC: // TODO: move-me to my own method
            case TokenType::PRIVATE:
            case TokenType::PROTECTED:
            case TokenType::STATIC:
            case TokenType::ABSTRACT: { // TODO: check modifiers position and if can override
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
            case TokenType::FLOAT128: // TODO: is this useful?
            case TokenType::STRING:
            case TokenType::CHAR:
            case TokenType::BOOL:
            case TokenType::BYTE: {
                assert(fx != nullptr); // built-in types must be preceded by a function (f)
                callable->signature = new SignatureExpression();
                callable->signature->return_type = token;
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
                callable->body = this->parse_body(this->walker->peek(), 0);
                continue;
            }

            case TokenType::CLOSE_BRACE: { // TODO: shouldn't be here?
                this->walker->advance();
                return callable;
            }

            case TokenType::OPEN_BRACKET: { // TODO: move-me to my own method
                assert(fx != nullptr); //first function flag
                assert(return_type != nullptr);  // then return type
                assert(identifier != nullptr); // then identifier

                this->walker->advance();
                assert(this->walker->peek()->get_type() == TokenType::CLOSE_BRACKET); // todo: FUNCTION PARAMS?
                this->walker->advance();
                // TODO: function params
                break;
            }


            case TokenType::IDENTIFIER: {
                assert(fx != nullptr); //first function flag
                assert(return_type != nullptr);  // then return type
                identifier = token;
                callable->signature->name = token; // TODO: properly AST
                this->walker->advance();
                continue;
            }

            default:
                return callable;
        }
    } while (true); // TODO: infinite loop protection

    callable->body = this->parse_body();

    return nullptr;
}

AST *Parser::parse_import(Token *token) {
    assert(token->get_type() == IDENTIFIER && token->get_value() == "import"); // TODO: get import keyword by function
    this->walker->advance();

    assert(this->walker->peek()->get_type() == IDENTIFIER);
    auto import = new ImportExpression(this->walker->peek()->get_value());
    this->walker->advance();
    assert(this->walker->peek()->get_type() == SEMICOLON);
    this->walker->advance();
    return import;
}

BodyExpression *Parser::parse_body(Token *token, uint32_t deep) {
    auto body = new BodyExpression();
    if (deep++ > MAX_BODY_RECURSION_DEPTH) {
        return body;
    }

    do {
        token = this->walker->peek();
        if (token == nullptr) {
            return body;
        }

        auto parsed_type = parse_token_type_from_value(token->get_value());
        auto type = parsed_type == TokenType::UNKNOWN ? token->get_type() : parsed_type;
        switch (type) {
            case STATIC: // TODO: static, const local variables
            case CONST:
            default:
                break;

            case TokenType::RETURN: {
                auto return_expression = new ReturnExpression(); // TODO: return values
                body->statements.push_back(return_expression);
                if (this->walker->peek(1)->get_type() == NUMBER_LITERAL) {
                    return_expression->right = this->walker->peek(1);
                    this->walker->advance(2);
                }
                assert(this->walker->peek()->get_type() == TokenType::SEMICOLON);
                this->walker->advance();
                continue;
            }

            case TokenType::IDENTIFIER: { // TODO: this is a variable or type.

            }

            case TokenType::OPEN_BRACE: {
                this->walker->advance();
                body->statements.push_back(this->parse_body(nullptr, deep + 1)); // TODO: check this recursion deepness
                continue;
            }

            case TokenType::CLOSE_BRACE: {
                this->walker->advance();
                return body; // TODO: return recursive body. This is the one way to leave this method. check to do below
            }
        }

        this->walker->advance(); // TODO: is this invalid token?
        // TODO: infinite loop protection
    } while (true);

    return nullptr;
}

AST *Parser::parse_expression(Token *token) { // TODO: better way than while loop
    AST *ret = nullptr;
    do {
        token = this->walker->peek();
        if (token == nullptr) {
            return ret;
        }

        auto parsed_type = parse_token_type_from_value(token->get_value());
        auto type = parsed_type == TokenType::UNKNOWN ? token->get_type() : parsed_type;
        switch (type) {
            case STATIC: // TODO: static, const local variables
            case CONST:
            default:
                break;

            case TokenType::RETURN: {
                auto return_expression = new ReturnExpression(); // TODO: return values
                ret = return_expression;
                this->walker->advance();
                continue;
            }

            case TokenType::IDENTIFIER: { // TODO: this is a variable or type.

            }
        }

        this->walker->advance();
    } while (true);

    return ret;
}

