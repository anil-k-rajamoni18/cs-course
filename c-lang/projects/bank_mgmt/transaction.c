#include <stdio.h>
#include <string.h>
#include <time.h>
#include "transaction.h"

void getCurrentTimestamp(char *buffer);

void addTransaction(int accNo, char type[], float amount) {
    struct Transaction t;
    FILE *fp = fopen("transactions.dat", "ab");

    t.accNo = accNo;
    strcpy(t.type, type);
    t.amount = amount;
    getCurrentTimestamp(t.timestamp);

    fwrite(&t, sizeof(t), 1, fp);
    fclose(fp);
}

void showTransactions(int accNo) {
    struct Transaction t;
    FILE *fp = fopen("transactions.dat", "rb");

    printf("\nTransaction History:\n");
    printf("Date & Time           Type        Amount\n");
    printf("-----------------------------------------\n");

    while (fread(&t, sizeof(t), 1, fp)) {
        if (t.accNo == accNo) {
            printf("%-20s %-10s %.2f\n",
                   t.timestamp, t.type, t.amount);
        }
    }

    fclose(fp);
}


void getCurrentTimestamp(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(buffer, 30, "%Y-%m-%d %H:%M:%S", t);
}
