#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"
#include "bankoperations.h"

char* login() {
    char username[100];
    char password[100];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // load the account_details.dat file and verify credentials
    FILE *fp;
    struct Account account;
    fp = fopen("account_details.dat", "rb");
    if (fp == NULL) {
        printf("Something went wrong, try again.\n");
        return 0;
    }

    while (fread(&account, sizeof(account), 1, fp)) {
        if (strcmp(username, account.user_name) == 0 && strcmp(password, account.password) == 0) {
            printf("Login successful!\n");
            fclose(fp);
            return strdup(account.user_name);
        }
    }

    printf("Login failed. Please try again.\n");
    fclose(fp);
    return NULL;
}
