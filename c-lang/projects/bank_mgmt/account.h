#ifndef ACCOUNT_H
#define ACCOUNT_H

struct Account {
    int accNo;
    char name[50];
    char password[20];
    float balance;
};

void createAccount();
int loginAccount(struct Account *loggedIn);
void checkBalance(struct Account acc);
void deposit(struct Account *acc);
void withdraw(struct Account *acc);
void calculateInterest(struct Account *acc);
void deleteAccount(int accNo);

#endif
