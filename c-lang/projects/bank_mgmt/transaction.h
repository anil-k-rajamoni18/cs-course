#ifndef TRANSACTION_H
#define TRANSACTION_H

struct Transaction {
    int accNo;
    char type[10];   // Deposit / Withdraw / Interest
    float amount;
};

void addTransaction(int accNo, char type[], float amount);
void showTransactions(int accNo);

#endif
