#include <stdio.h>
int main() {
    int a = 10, b = -10;
    printf("%d %d\n", a, b);
    printf("%+d %+d\n", a, b);
    printf("%-5d % d\n", a, b);
    return 0;
}