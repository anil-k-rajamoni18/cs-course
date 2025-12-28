#ifndef BANK_OPERATIONS_H
#define BANK_OPERATIONS_H

struct Account {
       char name[100];
       char user_name[100];
       char password[100];
       int balance;
};


struct Transaction {
       char user_name[100];
       char type[20];
       int amount;
       char date[50];
};
// Transaction: kumar18, Deposit, 5000, 2023-10-05 14:30:00
void create_new_account();
void transaction(char *);
void current_balance(char *);
void account_deletion(char *);
void login(int);

#endif