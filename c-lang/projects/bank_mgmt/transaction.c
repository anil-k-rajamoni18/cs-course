#include <stdio.h>
#include <string.h>
#include "transaction.h"

void addTransaction(int accNo, char type[], float amount) {
    struct Transaction t;
    FILE *fp = fopen("transactions.dat", "ab");

    t.accNo = accNo;
    strcpy(t.type, type);
    t.amount = amount;

    fwrite(&t, sizeof(t), 1, fp);
    fclose(fp);
}

void showTransactions(int accNo) {
    struct Transaction t;
    FILE *fp = fopen("transactions.dat", "rb");

    printf("\nTransaction History:\n");
    while (fread(&t, sizeof(t), 1, fp)) {
        if (t.accNo == accNo) {
            printf("%s : %.2f\n", t.type, t.amount);
        }
    }

    fclose(fp);
}
