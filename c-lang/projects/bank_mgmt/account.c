#include <stdio.h>
#include <string.h>
#include "account.h"
#include "transaction.h"

void createAccount() {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "ab");

    printf("Enter Account Number: ");
    scanf("%d", &acc.accNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", acc.name);
    printf("Set Password: ");
    scanf("%s", acc.password);

    acc.balance = 0;

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("Account created successfully!\n");
}

int loginAccount(struct Account *loggedIn) {
    int accNo;
    char pass[20];
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");

    printf("Account Number: ");
    scanf("%d", &accNo);
    printf("Password: ");
    scanf("%s", pass);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo && strcmp(acc.password, pass) == 0) {
            *loggedIn = acc;
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void checkBalance(struct Account acc) {
    printf("Current Balance: %.2f\n", acc.balance);
}

void deposit(struct Account *acc) {
    float amount;
    FILE *fp = fopen("accounts.dat", "rb+");

    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    acc->balance += amount;

    struct Account temp;
    while (fread(&temp, sizeof(temp), 1, fp)) {
        if (temp.accNo == acc->accNo) {
            fseek(fp, -sizeof(temp), SEEK_CUR);
            fwrite(acc, sizeof(*acc), 1, fp);
            break;
        }
    }

    fclose(fp);
    addTransaction(acc->accNo, "Deposit", amount);
    printf("Deposit successful!\n");
}

void withdraw(struct Account *acc) {
    float amount;
    FILE *fp = fopen("accounts.dat", "rb+");

    printf("Enter withdraw amount: ");
    scanf("%f", &amount);

    if (amount > acc->balance) {
        printf("Insufficient balance!\n");
        fclose(fp);
        return;
    }

    acc->balance -= amount;

    struct Account temp;
    while (fread(&temp, sizeof(temp), 1, fp)) {
        if (temp.accNo == acc->accNo) {
            fseek(fp, -sizeof(temp), SEEK_CUR);
            fwrite(acc, sizeof(*acc), 1, fp);
            break;
        }
    }

    fclose(fp);
    addTransaction(acc->accNo, "Withdraw", amount);
    printf("Withdrawal successful!\n");
}

void calculateInterest(struct Account *acc) {
    float interest = acc->balance * 0.05; // 5% interest
    acc->balance += interest;

    FILE *fp = fopen("accounts.dat", "rb+");
    struct Account temp;

    while (fread(&temp, sizeof(temp), 1, fp)) {
        if (temp.accNo == acc->accNo) {
            fseek(fp, -sizeof(temp), SEEK_CUR);
            fwrite(acc, sizeof(*acc), 1, fp);
            break;
        }
    }

    fclose(fp);
    addTransaction(acc->accNo, "Interest", interest);
    printf("Interest added: %.2f\n", interest);
}

void deleteAccount(int accNo) {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo != accNo)
            fwrite(&acc, sizeof(acc), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");

    printf("Account deleted successfully!\n");
}
