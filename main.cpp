#include <cstdio>
#include <cstring>

using namespace std;

class BOARDFILE{
    FILE* file;

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
}boardFile;

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

    printf("Regular execution\n");
    return 0;
}