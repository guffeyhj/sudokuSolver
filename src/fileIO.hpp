#ifndef FILEIO
#define FILEIO

#include <cstdio>

class FILEIO{
    FILE* file;
    char temp[11];

    void writeData(void);
    void writeBreak(void);
    void writeEnd(void);

    public:
        void write(void);
        void read(void);
}fileIO;

#endif
