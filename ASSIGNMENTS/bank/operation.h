#ifndef OPERATION_H
#define OPERATION_H

struct account {
       char name[100];
       char user_name[100];
       char password[100];
       int balance;
} A;

void create_new_account();
void transaction(char *);
void current_balance(char *);
void account_deletion(char *);
void login(int);

#endif