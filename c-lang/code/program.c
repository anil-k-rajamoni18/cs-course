#include<stdio.h>
#include<time.h>

// defining
void greet() {
    printf("Hello Hi Welcome to C\n");
}

void displayCurrentDate() {
    time_t currentTime;
    struct tm* timeInfo;
    time(&currentTime);
    timeInfo = localtime(&currentTime);
    printf("%04d-%02d-%02dT%02d:%02d:%02d\n", timeInfo->tm_year+1900, timeInfo->tm_mon+1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
}



int addTwoNumbers(int n1, int n2) {
    int result = n1 + n2;
    return result;
}

int main() {
    greet(); // calling
    displayCurrentDate();
    printf("result: %d\n", addTwoNumbers(10,20));
    printf("%d %d", 10,20,30);
    return 0;
}