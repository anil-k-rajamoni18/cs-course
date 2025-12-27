#include<stdio.h>
#include"operation.h"

int main(){
      // To display menu..

      int choice;
      do{
          printf("____Welcome to our company____\n");
          printf("Select one option below.\n");
          printf("1.Adding details of new employee.\n");
          printf("2.Calculate your salary.\n");
          printf("3.Generate pay slip.\n");
          printf("4.To exit.\n");
          scanf("%d",&choice);

          // Directing to related operation..
          switch(choice){
                  
                case 1 : add_employee();
                         break;
                case 2 : login(choice);
                         break;        
                case 3 : login(choice);
                         break;
                case 4 : printf("Thank you..\n");
                         break;
                default : printf("Invalid choice.Try again.\n");
                          break;
          } 
      }while(choice != 4);
  return 0;
}
