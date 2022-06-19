//
// Created by Lucas on 18/06/2022.
//

#ifndef DJINN_COMPILER_MODIFIERTYPE_H
#define DJINN_COMPILER_MODIFIERTYPE_H

#include "../../../typos/TokenType.h"

struct Modifier {
    enum Type : long {
        UNDEFINED = 0,
        PUBLIC = 1 << 0,
        PROTECTED = 1 << 1,
        PRIVATE = 1 << 2,
        INTERNAL = 1 << 3,
        STATIC = 1 << 4,
    };

    static bool hasFlag(Modifier::Type type, Modifier::Type flag) {
        return (type & flag) == flag;
    }


    static Modifier::Type token_type_to_modifier_type(TokenType type) {
        switch (type) {
            case TokenType::PUBLIC:
                return PUBLIC;
            case TokenType::PROTECTED:
                return PROTECTED;
            case TokenType::PRIVATE:
                return PRIVATE;
            case TokenType::INTERNAL:
                return INTERNAL;
            case TokenType::STATIC:
                return STATIC;
            default:
                return UNDEFINED;
        }
    }
};

#endif //DJINN_COMPILER_MODIFIERTYPE_H
