#ifndef FILEIO_HPP
#define FILEIO_HPP

#include <cstdio>

class FileIO{
    FILE* file;
    char temp[11];

    void writeData(void);
    void writeBreak(void);
    void writeEnd(void);

    public:
        void writeTemplate(void);
        void write(void);
        void read(void);
        void dumpMem(void);
};

extern FileIO fileIO;

#endif