#ifndef BOARD_HPP
#define BOARD_HPP

#include <cstdint>

class Board{
    public:
        uint8_t grid[9][9];
};

extern Board board;

#endif