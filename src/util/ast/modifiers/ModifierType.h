//
// Created by Lucas on 18/06/2022.
//

#ifndef DJINN_COMPILER_MODIFIERTYPE_H
#define DJINN_COMPILER_MODIFIERTYPE_H

enum ModifierType {
    UNDEFINED = 0,
    PUBLIC = 1 << 0,
    PROTECTED = 1 << 1,
    PRIVATE = 1 << 2,
    INTERNAL = 1 << 3,
    STATIC = 1 << 4,
};

static bool hasFlag(ModifierType type, ModifierType flag) {
    return (type & flag) == flag;
}

#endif //DJINN_COMPILER_MODIFIERTYPE_H
