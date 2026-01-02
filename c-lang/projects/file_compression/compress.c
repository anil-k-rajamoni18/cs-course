#include <stdio.h>
#include "compress.h"

/* Count frequency and store compressed data */
void compressFile(char *inputFile, char *compressedFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(compressedFile, "w");

    int freq[256] = {0};
    char ch;
    int i;

    if (!in || !out) {
        printf("File error!\n");
        return;
    }

    /* Count character frequency */
    while ((ch = fgetc(in)) != EOF) {
        freq[(unsigned char)ch]++;
    }

    /* Write compressed data */
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            fprintf(out, "%c %d\n", i, freq[i]);
        }
    }

    fclose(in);
    fclose(out);

    printf("File compressed successfully!\n");
}

/* Decompress the file */
void decompressFile(char *compressedFile, char *outputFile) {
    FILE *in = fopen(compressedFile, "r");
    FILE *out = fopen(outputFile, "w");

    char ch;
    int freq, i;

    if (!in || !out) {
        printf("File error!\n");
        return;
    }

    while (fscanf(in, " %c %d", &ch, &freq) != EOF) {
        for (i = 0; i < freq; i++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);

    printf("File decompressed successfully!\n");
}
