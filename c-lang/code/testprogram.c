#include <stdio.h>
#include <stdlib.h>
int main() {
    int *p; // Pointer to hold the address of allocated memory
    p = (int*) malloc(3 * sizeof(int)); // Allocate memory for 3 integers
    for (int i = 0; i < 3; i++)
        scanf("%d", &p[i]);

    printf("You entered:\n");
    for (int i = 0; i < 3; i++)
        printf("%d\n", p[i]);

    free(p); // Free the allocated memory
    p = NULL; // Avoid dangling pointer
    printf("Memory freed successfully.\n");
    for (int i = 0; i < 3; i++)
        printf("Test %d\n", p[i]); // Undefined behavior: accessing freed memory
    return 0;
}
