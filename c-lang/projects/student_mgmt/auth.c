#include <stdio.h>
#include <string.h>
#include "auth.h"

int login() {
    char username[20];
    char password[20];

    printf("===== Admin Login =====\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "admin123") == 0) {
        printf("Login successful!\n");
        return 1;
    } else {
        printf("Invalid credentials!\n");
        return 0;
    }
}
