#include <stdio.h>
#include "bankoperations.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

// To create account..
void create_new_account(){
      
         struct Account account;
         printf("To create a account please enter your details.\n");
         printf("Enter your name : ");
         scanf(" %[^\n]",account.name);
         printf("Please set a new username : ");
         scanf(" %[^\n]",account.user_name);
         printf("Please set a new password : ");
         scanf(" %[^\n]",account.password);

         // for new account, balance will be zero
         account.balance = 0;

         // Entering details into file
         FILE *fp;
         fp = fopen("account_details.dat","ab");
         fwrite(&account,sizeof(account),1,fp);
         fclose(fp);
         printf("Your account is created sucessfully.\n");
         printf("\n");
}


// Deposite or withdraw money..
void deposit_withdraw(char *user_name){
      int option,money;

      // To store time
      time_t now = time(NULL);
      struct tm *t = localtime(&now);

      printf("Select one option from below.\n");
      printf("1.Deposite money.\n");
      printf("2.Withdraw money.\n");
      scanf("%d",&option);
      printf("Enter the amount : ");
      scanf("%d",&money);

      FILE *fp;
      FILE *temp;
      FILE *transaction;
      struct Account account;
      struct Transaction histroy;
      
      fp = fopen("account_details.dat","rb");
      temp = fopen("temp.dat","wb");
      transaction = fopen("histroy.dat","ab");

      while(fread(&account,sizeof(account),1,fp)){
            if(strcmp(user_name,account.user_name) != 0){
                fwrite(&account,sizeof(account),1,temp);
            }
            else{
                  if(option == 1){
                    account.balance = account.balance + money;
                    fwrite(&account,sizeof(account),1,temp);
                    printf("Your transaction completed sucessfully.\n");
                    strcpy(histroy.user_name,account.user_name);
                    strcpy(histroy.type,"Deposite");
                    histroy.amount = money;
                    strftime(histroy.date, sizeof(histroy.date), "%d-%m-%Y %H:%M:%S", t);
                    fwrite(&histroy,sizeof(histroy),1,transaction);
                  }

                  else if(option == 2 && money <= account.balance){
                           account.balance = account.balance - money;
                           fwrite(&account,sizeof(account),1,temp);
                           printf("Your transaction completed sucessfully.\n");
                           strcpy(histroy.user_name,account.user_name);
                           strcpy(histroy.type,"Withdraw");
                           histroy.amount = money;
                           strftime(histroy.date, sizeof(histroy.date), "%d-%m-%Y %H:%M:%S", t);
                           fwrite(&histroy,sizeof(histroy),1,transaction);
                  }

                   else if(option == 2 && money > account.balance){
                           printf("You can't withdraw this amount.\n");
                           fwrite(&account,sizeof(account),1,temp);
                  }

                  else {
                      printf("Invalid option.\n");
                      fwrite(&account,sizeof(account),1,temp);
                  }
            }
      }

      fclose(fp);
      fclose(temp);
      fclose(transaction);

      remove("account_details.dat");
      rename("temp.dat","account_details.dat");
      printf("\n");
}

// To view current balance..
void check_balance(char *user_name){
         
      FILE *fp;
      struct Account account;
      
      fp = fopen("account_details.dat","rb");

      while(fread(&account,sizeof(account),1,fp)){
            if(strcmp(user_name,account.user_name) == 0){
                printf("Your current balance is %d\n",account.balance);
                break;
            }
        }

       fclose(fp);
       printf("\n");
}

// To delete account..
void delete_account(char *user_name){
      FILE *fp;
      FILE *temp;
      struct Account account;
      fp = fopen("account_details.dat","rb");
      temp = fopen("temp.dat","wb");

      while(fread(&account,sizeof(account),1,fp)){
            if(strcmp(user_name,account.user_name) != 0){
                fwrite(&account,sizeof(account),1,temp);
            }
      }

      fclose(fp);
      fclose(temp);

      remove("account_details.dat");
      rename("temp.dat","account_details.dat");
      printf("Your account deteled sucessfully.\n");
      printf("\n");
}

// To view transaction histroy..
void transaction_histroy(char *user_name){
           struct Transaction histroy; 
           FILE *transaction;
           transaction = fopen("histroy.dat","rb");
           
           if (transaction == NULL){
                 printf("something went wrong. Try again.\n");
           }
           else{
               printf("Date                 Username        Type        Amount\n");
               printf("-------------------------------------------------------\n");
  
               while(fread(&histroy,sizeof(histroy),1,transaction)){
                      if(strcmp(user_name,histroy.user_name) == 0){
                         printf("%-20s %-15s %-10s %d\n",
                                    histroy.date,
                                    histroy.user_name,
                                    histroy.type,
                                    histroy.amount);
                      }
               }
           }
           fclose(transaction);
}
