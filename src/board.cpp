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

uint8_t Board::count(uint8_t x, uint8_t y){
    uint8_t count = 0;

    if (board.grid[x][y] == 0){
        for (uint8_t i = 0; i < 9; i++){
            if (board.possibilities[x][y][i]){
                count++;
            }
        }
        return count;
    }
    else{
        return 0;
    }
}

void Board::test(uint8_t x, uint8_t y){
    uint8_t xStart = 0;
    uint8_t yStart = 0;

    if (board.grid[x][y] != 0){
        for (uint8_t i = 0; i < 9; i++){
            board.possibilities[x][y][i] = false;
        }
        board.possibilities[x][y][board.grid[x][y]-1] = true;
    }
    else{
        for (uint8_t i = 0; i < 9; i++){
            if (board.grid[i][y] != 0){
                board.possibilities[x][y][board.grid[i][y]-1] = false;
            }
            if (board.grid[x][i] != 0){
                board.possibilities[x][y][board.grid[x][i]-1] = false;
            }
        }

        if (x >= 0 && x <=2){
            xStart = 0;
        }
        else if (x >= 3 && x <=5){
            xStart = 3;
        }
        else if (x >= 6 && x <=8){
            xStart = 6;
        }

        if (y >= 0 && y <= 2){
            yStart = 0;
        }
        else if (y >= 3 && y <= 5){
            yStart = 3;
        }
        else if (y >= 6 && y <= 8){
            yStart = 6;
        }

        for (uint8_t i = yStart; i < yStart + 3; i++){
            for (uint8_t j = xStart; j < xStart + 3; j++){
                if (board.grid[j][i] != 0){
                board.possibilities[x][y][board.grid[j][i]-1] = false;
                }
            }
        }
    }
}

Board board;