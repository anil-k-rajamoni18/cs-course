#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    fp = fopen("sample.txt", "r");

    if (fp == NULL) {
        printf("File not found or cannot be opened.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        printf("%c\n", ch);   
    }

    fclose(fp);
    return 0;
}