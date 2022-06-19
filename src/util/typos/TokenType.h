//
// Created by Lucas on 16/06/2022.
//

#ifndef DJINN_COMPILER_TOKENTYPE_H
#define DJINN_COMPILER_TOKENTYPE_H


enum TokenType {
    UNKNOWN, // this is our default value

    IDENTIFIER,

    PLUS, // +
    MINUS, // -
    MULTIPLY, // *
    DIVIDE, // /
    MODULO, // %
    POWER, // ** or ^
    ASSIGNMENT, // =
    EQUAL, // ==
    NOT_EQUAL, // !=
    GREATER_THAN, // >
    GREATER_THAN_OR_EQUAL, // >=
    LESS_THAN, // <
    LESS_THAN_OR_EQUAL, // <=
    QUESTION, // ?
    QUESTION_EQUAL, // ?=
    AND, // &&
    OR, // ||
    NOT, // !
    DOT_DOT, // ..
    INCREMENT, // ++
    DECREMENT, // --
    PLUS_EQUAL, // +=
    MINUS_EQUAL, // -=
    MULTIPLY_EQUAL, // *=
    DIVIDE_EQUAL, // /=
    MODULO_EQUAL, // %=
    POWER_EQUAL, // **=


    // MEMBER ACCESSING
    DOT, // .
    POINTER_ACCESS, // ->
    COMMA, // ,
    COLON, // :
    COLON_COLON, // ::
    SEMICOLON, // ;


    //BLOCKS
    OPEN_BRACKET, // (
    CLOSE_BRACKET, // )
    OPEN_BRACE, // {
    CLOSE_BRACE, // }
    OPEN_SQUARE_BRACKET, // [
    CLOSE_SQUARE_BRACKET, // ]

    //KEYWORDS
    IF, //
    ELSE, //
    WHILE, //
    RETURN, //
    DO, //
    FOR, //
    BREAK, //
    CONTINUE, //
    FOR_EACH, //
    IMPORT, //
    CLASS, //
    FUNCTION, //
    STRUCT,
    ENUM,
    CONST,
    STATIC,
    VIRTUAL,
    OVERRIDE,
    PUBLIC,
    PRIVATE,
    PROTECTED,
    INTERNAL,
    EXTERNAL,
    ABSTRACT,


    NUMBER_LITERAL,
    STRING_LITERAL,
    CHAR_LITERAL,


    //BITWISE OPERATORS
    BITWISE_AND, // &
    BITWISE_OR, // |
    BITWISE_XOR, // ^
    BITWISE_NOT, // ~
    SHIFT_RIGHT, // >>
    SHIFT_LEFT, // <<
    BITWISE_AND_EQUAL, // &=
    BITWISE_OR_EQUAL, // |=
    BITWISE_XOR_EQUAL, // ^=
    SHIFT_RIGHT_EQUAL, // >>=
    SHIFT_LEFT_EQUAL, // <<=


    // built-in types
    VOID,
    BOOL,
    BYTE,
    CHAR,
    INT16,
    INT32,
    INT64,
    INT128,
    UINT16,
    UINT32,
    UINT64,
    UINT128,
    FLOAT32,
    FLOAT64,
    FLOAT128,
    STRING,


    INVALID,
    END_OF_FILE,
};

#endif //DJINN_COMPILER_TOKENTYPE_H
