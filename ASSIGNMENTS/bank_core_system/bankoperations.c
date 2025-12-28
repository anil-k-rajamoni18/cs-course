#include <stdio.h>
#include "bankoperations.h"
#include <stdlib.h>
#include <string.h>

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

// Login function..
void login(int choice){
             char user_name[100];
             char password[100];
             int flag = 0;
             struct Account account;
             printf("Enter your username : ");
             scanf(" %[^\n]",user_name);
             printf("Enter your password : ");
             scanf(" %[^\n]",password);
    
             FILE *fp;
             fp = fopen("account_details.dat","rb");
             if(fp == NULL){
                    printf("Something went wrong, try again.\n");
             }
             else{
                  while( fread(&account,sizeof(account),1,fp)){
                       if(strcmp(user_name,account.user_name) == 0 && strcmp(password,account.password) == 0){
                                 printf("You logged in successfully.\n");
                                 flag++;
                                 switch(choice){
                                       case 2 : transaction(user_name);
                                                break;
                                       case 3 : current_balance(user_name);    
                                                break ;
                                       case 4 : account_deletion(user_name);             
                                                break;
                                 }
                       }
                  }
                  fclose(fp);
                  if(flag == 0){
                      printf("You have entered wrong information.\n");
                  }
             }
             printf("\n");
}

// Deposite or withdraw money..
void transaction(char *user_name){
      int option,money;

      printf("Select one option from below.\n");
      printf("1.Deposite money.\n");
      printf("2.Withdraw money.\n");
      scanf("%d",&option);
      printf("Enter the amount : ");
      scanf("%d",&money);

      FILE *fp;
      FILE *temp;
      struct Account account;
      fp = fopen("account_details.dat","rb");
      temp = fopen("temp.dat","wb");

      while(fread(&account,sizeof(account),1,fp)){
            if(strcmp(user_name,account.user_name) != 0){
                fwrite(&account,sizeof(account),1,temp);
            }
            else{
                  if(option == 1){
                    account.balance = account.balance + money;
                    fwrite(&account,sizeof(account),1,temp);
                    printf("Your transaction completed sucessfully.\n");
                  }

                  else if(option == 2 && money <= account.balance){
                           account.balance = account.balance - money;
                           fwrite(&account,sizeof(account),1,temp);
                           printf("Your transaction completed sucessfully.\n");
                  }

                   else if(option == 2 && money >= account.balance){
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

      remove("account_details.dat");
      rename("temp.dat","account_details.dat");
      printf("\n");
}

// To view current balance..
void current_balance(char *user_name){
         
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
void account_deletion(char *user_name){
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
