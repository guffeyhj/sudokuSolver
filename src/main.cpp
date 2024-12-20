#include <cstdio>
#include <cstring>
#include <cstdint>
#include "fileIO.hpp"
#include "board.hpp"

int main(void){
    board.outstandingItems = 1;

    fileIO.read();

    while (board.outstandingItems > 0){
        for (uint8_t i = 0; i < 9; i++){
            for (uint8_t j = 0; j < 9; j++){
                board.test(j,i);
                board.numPossibilities[j][i] = board.count(j, i);
            }
        }

        for (uint8_t i = 0; i < 9; i++){
            for (uint8_t j = 0; j < 9; j++){
                if (board.numPossibilities[j][i] == 1){
                    for (uint8_t k = 0; k < 9; k++){
                        if (board.possibilities[j][i][k] == true){
                            board.grid[j][i] = k+1;
                        }
                    }
                }
            }
        }

        board.outstandingItems = 0;
        for (uint8_t i = 0; i < 9; i++){
            for (uint8_t j = 0; j < 9; j++){
                board.outstandingItems += board.numPossibilities[j][i];
            }
        }
    }

    fileIO.write();
    return 0;
}