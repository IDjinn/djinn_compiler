//
// Created by Lucas on 17/06/2022.
//

#ifndef DJINN_COMPILER_LOCATION_H
#define DJINN_COMPILER_LOCATION_H


#include <cstdint>

class Location {
public:
    uint32_t line = 0;
    uint32_t column = 0;
    uint32_t index = 0;

    Location() = default;;

    Location(uint32_t line, uint32_t column) : line(line), column(column) {}

    Location(uint32_t line, uint32_t column, uint32_t index) : line(line), column(column), index(index) {}
};


#endif //DJINN_COMPILER_LOCATION_H
