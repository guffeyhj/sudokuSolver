#include "board.hpp"

Board::Board(void){
    for (uint8_t k = 0; k < 9; k++){
        for (uint8_t i = 0; i < 9; i++){
            for (uint8_t j = 0; j < 9; j++){
                board.possibilities[j][i][k] = true;
            }
        }
    }
}

Board board;