#include<stdio.h>


// define
void greet() {
    printf("Good Moring !!!\n");
}

void printSum(float a, float b) {
    printf("Sum = %f\n", a + b);
}


int getInput() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    return num;
}

int multiply(int a, int b) {
    return a * b;
}


int main() {
    printf("Welcome to Functions..\n");
    greet(); // call
    printSum(10.5,20.6);

    printf("res: %d\n", getInput());
    printf("Multiply Result: %d\n", multiply(10,7));

    printf("Main Function Completed Successfully..\n");
    return 0;
}


