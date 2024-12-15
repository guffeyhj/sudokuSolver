#ifndef TEST_HPP
#define TEST_HPP

#include <cstdio>
#include "board.hpp"

void WRITEGRID(void){
    FILE* file;
    file = fopen("test.ssolv","w");
    
    for (uint8_t y = 0; y < 9; y++){
        for (uint8_t x = 0; x < 9; x++){
            fprintf(file, "%c", board.grid[x][y]+48);
            if (x == 2 || x == 5){
                fprintf(file, "|");
            }
            if (x == 8 && y != 8){
                fprintf(file, "\n");
            }
        }
        if (y == 2 || y == 5){
            fprintf(file, "---+---+---\n");
        }
    }

    fclose(file);
}

#endif