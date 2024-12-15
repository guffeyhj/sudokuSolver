#include <cstdio>
#include <cstdint>
#include "fileIO.hpp"

using namespace std;

void FILEIO::writeData(void){
    fprintf(file, "000|000|000\n");
}

void FILEIO::writeBreak(void){
    fprintf(file, "---+---+---\n");
}

void FILEIO::writeEnd(void){
    fprintf(file, "000|000|000");
}

void FILEIO::write(void){
    file = fopen("template.ssolv","w");

    this->writeData();
    this->writeData();
    this->writeData();
    this->writeBreak();
    this->writeData();
    this->writeData();
    this->writeData();
    this->writeBreak();
    this->writeData();
    this->writeData();
    this->writeEnd();

    fclose(file);
}

        void read(void){
            file = fopen("template.sol","r");
            if (file == NULL){
                this->write();
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
}fileIO;
