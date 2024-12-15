#include <cstdio>
#include <cstring>
#include <cstdint>
#include "fileIO.hpp"
#include "board.hpp"
#include "test.hpp"

int main(void){
    fileIO.read();

    for (uint8_t y = 0; y < 9; y++){
        for (uint8_t x = 0; x < 9; x++){    
            if (board.grid[x][y] != 0){
                for (uint8_t i = 0; i < 9; i++){
                    if (board.grid[i][y] != 0)
                }
            }
        }
    }

    WRITEGRID();

    return 0;
}