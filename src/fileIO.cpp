#include <cstdio>
#include <cstdint>
#include "fileIO.hpp"
#include "board.hpp"

FileIO fileIO;

void FileIO::writeTemplate(void){
    file = fopen("template.ssolv","w");

    for (uint8_t i = 0; i < 11; i++){
        if (i == 3 || i == 7){
            fprintf(file, "---+---+---");
        }
        else{
            fprintf(file, "000|000|000");
        }
        if (i != 10){
            fprintf(file, "\n");
        }
    }

    board.outstandingItems = 0;

    fclose(file);
}

void FileIO::write(void){
    file = fopen("template.ssolv","w");
    
    for (uint8_t i = 0; i < 9; i++){
        for (uint8_t j = 0; j < 9; j++){
            fprintf(file, "%c", board.grid[j][i]+48);
            if (j == 2 || j == 5){
                fprintf(file, "|");
            }
            if (j == 8 && i != 8){
                fprintf(file, "\n");
            }
        }
        if (i == 2 || i == 5){
            fprintf(file, "---+---+---\n");
        }
    }

    fclose(file);
}

void FileIO::read(void){
    file = fopen("template.ssolv","r");
    if (file == NULL){
        this->writeTemplate();
        return;
    }
    
    uint8_t idx = 0;
    uint8_t idy = 0;
    for (uint8_t i = 0; i < 11; i++){
        fscanf(file, "%s", temp);
        if (temp[0] != '-'){
            for (int j = 0; j < 11; j++){
                if (temp[j] >= '0' && temp[j] <= '9'){
                    board.grid[idx][idy] = temp[j]-48;
                    idx++;
                }
            }
            idy++;
            idx = 0;
        }
    }

    fclose(file);
}

void FileIO::dumpMem(void){
    file = fopen("poss.ssolv","w");
    
    for (uint8_t k = 0; k < 9; k++){
        for (uint8_t i = 0; i < 9; i++){
            for (uint8_t j = 0; j < 9; j++){
                if (board.possibilities[j][i][k]){
                    fprintf(file, "T");
                }
                else{
                    fprintf(file, "F");
                }
                if (j == 2 || j == 5){
                    fprintf(file, "|");
                }
                if (j == 8 && i != 8){
                    fprintf(file, "\n");
                }
            }
            if (i == 2 || i == 5){
                fprintf(file, "---+---+---\n");
            }
        }
        fprintf(file, "\n\n- - - - - -\n\n");
    }

    for (uint8_t i = 0; i < 9; i++){
        for (uint8_t j = 0; j < 9; j++){
            fprintf(file, "%c", board.numPossibilities[j][i]+48);
            if (j == 2 || j == 5){
                fprintf(file, "|");
            }
            if (j == 8 && i != 8){
                fprintf(file, "\n");
            }
        }
        if (i == 2 || i == 5){
            fprintf(file, "---+---+---\n");
        }
    }

    fclose(file);
}