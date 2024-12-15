#ifndef TEST_HPP
#define TEST_HPP

#include <cstdio>
#include "board.hpp"

void PRINTGRID(void){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf("%u", board.grid[j][i]);
            if (j == 2 || j == 5){
                printf("|");
            }
        }
        printf("\n");
        if (i == 2 || i == 5){
            printf("---+---+---\n");
        }
    }
}

void MODSOMETHING(void){
    board.grid[0][0] = 4;
    board.grid[8][8] = 2;
}

#endif