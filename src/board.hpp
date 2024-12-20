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

        uint8_t count(uint8_t, uint8_t);
        void test(uint8_t, uint8_t);

};

extern Board board;

#endif