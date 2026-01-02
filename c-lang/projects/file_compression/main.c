#include <stdio.h>
#include "compress.h"

int main() {
    int choice;

    do {
        printf("\n=== File Compression Tool ===\n");
        printf("1. Compress File\n");
        printf("2. Decompress File\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                compressFile("input.txt", "compressed.txt");
                break;
            case 2:
                decompressFile("compressed.txt", "output.txt");
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
