#include <stdio.h>

long long fact(int n) {
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    printf("Factorial = %ld", fact(20));
    return 0;
}