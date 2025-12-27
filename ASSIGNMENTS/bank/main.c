#include <stdio.h>
#include "operation.h"

int main(){
     // To display menu..

      int choice;
      do{
          printf("____Welcome to Bank management system____\n");
          printf("Select one option below.\n");
          printf("1.Create new account.\n");
          printf("2.Deposite or withdraw money.\n");
          printf("3.Check current balance.\n");
          printf("4.To delete account.\n");
          printf("5.To exit.\n");
          scanf("%d",&choice);

          // Directing to related operation..
          switch(choice){
                  
                case 1 : create_new_account();
                         break;
                case 2 : login(choice);
                         break;        
                case 3 : login(choice);
                         break;
                case 4 : login(choice);
                         break;
                case 5 : printf("Thank you..\n");
                         break;         
                default : printf("Invalid choice.Try again.\n\n");
                          break;
          } 
      }while(choice != 5);
  return 0;
}