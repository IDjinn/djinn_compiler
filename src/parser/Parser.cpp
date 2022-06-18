//
// Created by Lucas on 17/06/2022.
//

#include "Parser.h"

Parser::Parser(TokenWalker *walker) {
    this->walker = walker;

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
        auto it = this->parse_table->find(parsed_type == TokenType::UNKNOWN ? token->get_type() : parsed_type);
        if (it != this->parse_table->end()) {
            auto parse_function = it->second;
            auto ret = parse_function(token);
        }

        this->walker->advance();
    } while (!this->walker->is_end_of_file());
}

AST *Parser::parse_identifier(Token *token) {
    return nullptr;
}

AST *Parser::parse_method(Token *token) {


    return nullptr;
}
