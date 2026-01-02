#include <stdio.h>
#include "account.h"
#include "transaction.h"

int main() {
    int choice;
    struct Account current;

    while (1) {
        printf("\n=== Bank Management System ===\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            createAccount();
        else if (choice == 2) {
            if (loginAccount(&current)) {
                int ch;
                do {
                    printf("\n--- Account Menu ---\n");
                    printf("1. Check Balance\n");
                    printf("2. Deposit\n");
                    printf("3. Withdraw\n");
                    printf("4. Transaction History\n");
                    printf("5. Add Interest\n");
                    printf("6. Delete Account\n");
                    printf("0. Logout\n");
                    printf("Choice: ");
                    scanf("%d", &ch);

                    switch (ch) {
                        case 1: checkBalance(current); break;
                        case 2: deposit(&current); break;
                        case 3: withdraw(&current); break;
                        case 4: showTransactions(current.accNo); break;
                        case 5: calculateInterest(&current); break;
                        case 6: deleteAccount(current.accNo); ch = 0; break;
                    }
                } while (ch != 0);
            } else {
                printf("Invalid login!\n");
            }
        } else {
            break;
        }
    }

    return 0;
}
