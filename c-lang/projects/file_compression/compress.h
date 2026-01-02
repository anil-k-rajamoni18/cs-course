#ifndef COMPRESS_H
#define COMPRESS_H

struct CharFreq {
    char ch;
    int freq;
};

void compressFile(char *inputFile, char *compressedFile);
void decompressFile(char *compressedFile, char *outputFile);

#endif
