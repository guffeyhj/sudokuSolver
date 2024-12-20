#ifndef BOARD_HPP
#define BOARD_HPP

#include <cstdint>

using namespace std;

class Board{
    public:
        uint8_t grid[9][9];
        bool possibilities[9][9][9];
        uint8_t numPossibilities[9][9];

        Board(void);
};

extern Board board;

#endif