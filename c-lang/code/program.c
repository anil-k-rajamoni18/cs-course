#include <stdio.h>

int globalVar = 100;  // Global Variable

void showCounter() {
    static int counter = 0;  // Static Variable
    counter++;
    printf("Counter: %d\n", counter);
}

int main() {
    int localVar = 10;        // Local Variable
    const float PI = 3.1416; // Constant Variable

    showCounter();
    printf("Global: %d\n", globalVar);
    printf("Local: %d\n", localVar);
    printf("Constant PI: %.4f\n", PI);
    showCounter();
    showCounter();

    return 0;
}