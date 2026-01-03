#ifndef TRANSACTION_H
#define TRANSACTION_H

struct Transaction {
    int accNo;
    char type[10];
    float amount;
    char timestamp[30];
};

void addTransaction(int accNo, char type[], float amount);
void showTransactions(int accNo);

#endif

