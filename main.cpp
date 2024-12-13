#include <cstdio>
#include <cstring>
#include <cstdint>

using namespace std;

class BOARD{
    public:
        uint8_t grid[9][9];
}board;

class BOARDFILE{
    FILE* file;
    char temp[11];

    void writeData(void){
        fprintf(file, "000|000|000\n");
    }

    void writeBreak(void){
        fprintf(file, "---+---+---\n");
    }

    void writeEnd(void){
        fprintf(file, "000|000|000");
    }

    public:
        void writeTemplate(void){
            this->writeTemplate("default.txt");
        }

        void writeTemplate(const char fileName[20]){
            file = fopen(fileName,"w");

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

        void readTemplate(void){
            this->readTemplate("default.txt");
        }

        void readTemplate(const char fileName[20]){
            file = fopen(fileName,"r");
            if (file == NULL){
                printf("File does not exist\n");
                fclose(file);
                this->writeTemplate();
            }
            
            uint8_t idx = 0;
            uint8_t idy = 0;
            for (int i = 0; i < 11; i++){
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
}boardFile;

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

int main(int argc, char* argv[]){
    if (argc > 1){
        if (!strcmp(argv[1], "-t") || !strcmp(argv[1], "--template")){
            if (argc == 2){
                boardFile.writeTemplate();
            }
            else{
                boardFile.writeTemplate(argv[2]);
            }

            return 0;
        }
    }

    boardFile.readTemplate();

    PRINTGRID();

    return 0;
}