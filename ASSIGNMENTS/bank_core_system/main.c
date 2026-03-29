#include <stdio.h>
#include "bankoperations.h"
#include "auth.h"
#include <stdlib.h>

void display_menu();
void loged_in_menu(int);

int main(){
     // To display menu..
      int choice;
      int isLoggedIn = 0;
      char* username = NULL;
      do{
          if (!isLoggedIn) {
              display_menu();
          } else {
              loged_in_menu(choice);
          }
          scanf("%d",&choice);
          
          printf("Entered choice is : %d\n",choice);

          if (choice == 1) {
                // Create new account
                create_new_account();
                continue;
          } else {

            if (!isLoggedIn) {
                printf("Please login to continue.\n");
                username = login();
                if (username != NULL) {
                    printf("You are now logged in as %s.\n\n", username);
                    isLoggedIn = 1;
                }
            }
            if (username == NULL) {
                printf("Login required to perform this operation.\n\n");
                continue;
            }
            switch(choice){
                    case 2 : deposit_withdraw(username);
                            break;        
                    case 3 : check_balance(username);
                            break;
                    case 4 : delete_account(username);
                            break;
                    case 5 : transaction_histroy(username);
                             break ;      
                    case 6 : printf("Thank you..\n");
                            break;         
                    default : printf("Invalid choice.Try again.\n\n");
                            break;
            }
        }
      }while(choice != 6);
  return 0;
}


void display_menu(){
      printf("____Welcome to Bank management system____\n");
      printf("Select one option below.\n");
      printf("1.Create new account.\n");
      printf("2.Deposite or withdraw money.\n");
      printf("3.Check current balance.\n");
      printf("4.To delete account.\n");
      printf("5.To check transaction histroy\n");
      printf("6.To exit.\n");
}

void loged_in_menu(int choice){
      printf("Select one option below.\n");
      printf("2.Deposite or withdraw money.\n");
      printf("3.Check current balance.\n");
      printf("4.To delete account.\n");
      printf("5.To check transaction histroy\n");
      printf("6.To exit.\n");  
}