#include<stdio.h>
#include<string.h>

struct account{
   char user_name[20];
   char password[20];
};

// Declaration of prototype
int display_menu();
void create_new_account();
void transaction(char *);
void current_balance(char *);
void histroy(char *);
void account_deletion(char *);
int login(int);

// main function
int main(){
    display_menu();
}

// Display function
int display_menu(){
     int option;
      
      do{  
        printf("Welcome to Bank management system\n");
        printf("Select one option from below\n");
        printf("1.Create a new account\n");
        printf("2.Deposit (or) withdraw money\n");
        printf("3.Check current balance\n");
        printf("4.See Transaction histroy\n");
        printf("5.Account deletion\n");
        printf("6.To exit\n");
        scanf("%d", &option);
        
        switch(option){
              case 1  : create_new_account();
                        break;
              case 2  : login(option);
                        break;
              case 3  : login(option);
                        break;
              case 4  : login(option);
                        break;
              case 5  : login(option);
                        break;
              case 6  : printf("Thank you\n");
                        return 0;
                        break;
              default : printf("Invalid choice\n");
                        printf("Try again");      
        }        
      } while(option!=6);
 return 0;
}

// Login function
int login(int option){

        char un[20],un1[20];
        char pw[20],pw1[20];
        char line[100];
        int flag = 0;

        // To whether user exist or not
        printf("Enter your username : ");
        scanf(" %[^\n]",un);
        printf("Enter your password : ");
        scanf(" %[^\n]",pw);

        FILE *fp;
        fp = fopen("login_details.txt","r");
        if(fp == NULL){
            printf("create account first");
            return 0;
        }
        while(fgets(line,100,fp)){
            sscanf(line,"%[^|]|%[^\n]",un1,pw1);
            int check1 = strcmp(un,un1);
            int check2 = strcmp(pw,pw1);
            if(check1 == 0 && check2 == 0){
                    printf("You logined succesfully.\n");
                    flag++;
                    switch(option){
                        case 2  : transaction(un);
                                  break;
                        case 3  : current_balance(un);
                                  break;
                        case 4  : histroy(un);
                                  break;
                        case 5  : account_deletion(un);
                                  break;
                    }
                    break;
            }
        }

        if(flag == 0){
            printf("you have entered wrong details\n");
        }

        fclose(fp);
        printf("\n");

return 0;
}

// create new account
void create_new_account(){
   struct account a1; 
   FILE *fp;
   fp = fopen("login_details.txt","a");

   // Taking username and password
   printf("To create New account you need set username and password.\n");
   printf("Please enter new username : ");
   scanf(" %[^\n]",a1.user_name);
   printf("Please enter new password : ");
   scanf(" %[^\n]" , a1.password);

   // Storing login information in login_details file
   fprintf(fp , "%s|%s\n",a1.user_name,a1.password);
   fclose(fp);

   // creating account details
   fp = fopen("account_details.txt","a");
   fprintf(fp , "%s|%d\n",a1.user_name,0);
   fclose(fp);

   printf("Your account is successfully created..\n");
   printf("\n");
 
}

// Deposite or withdraw money
void transaction(char user_name1[20]){
        char user_name2[20];
        FILE *fp;
        FILE *temp;
        char line[100];
        int balance=0;

        printf("Select one option from below\n");
        printf("1.Deposite money\n2.Withdraw money\n");
        int choice,money=0;
        scanf("%d",&choice);
        printf("Enter the amount : ");
        scanf("%d",&money);

        fp = fopen("account_details.txt","r");
        temp = fopen("temparory.txt","w");
        while(fgets(line,100,fp)){
            sscanf(line,"%[^|]|%d",user_name2,&balance);
            if(strcmp(user_name1,user_name2) != 0){
                fprintf(temp,"%s",line);
            }
            else if( choice == 1){
                balance = balance + money;
                fprintf(temp,"%s|%d\n",user_name2,balance);
                printf("your transaction completed sucessfully.\n");
            }
            else if(choice == 2 && money<=balance){
                balance = balance - money;
                fprintf(temp,"%s|%d\n",user_name2,balance);
                printf("your transaction completed sucessfully.\n");
            }
            else if(choice == 2 && money > balance){
                fprintf(temp,"%s|%d\n",user_name2,balance);
                printf("you can't with draw\n");
            }
            else {
                printf("Invalid choice\n");
            }
        }
    
        fclose(fp);
        fclose(temp);

        remove("account_details.txt");
        rename("temparory.txt","account_details.txt");
        printf("\n");
}

// TO check balance
void current_balance(char user_name1[20]){
       char user_name2[20];
       char line[100];
       int balance=0;
       FILE *fp;
       

       fp = fopen("account_details.txt","r");
       while(fgets(line,100,fp)){
            sscanf(line,"%[^|]|%d",user_name2,&balance);
            if(strcmp(user_name1,user_name2) == 0){
                printf("your current balance is %d\n",balance);
                break;
            }
        } 

       fclose(fp);  
       printf("\n");
}

// To delete account
void account_deletion(char user_name1[20]){
       char user_name2[20];
       char line[100];
       int balance=0;
       char password[20];
       FILE *fp;
       FILE *temp;

       fp = fopen("account_details.txt","r");
       temp= fopen("temporary.txt","w");
       while(fgets(line,100,fp)){
            sscanf(line,"%[^|]|%d",user_name2,&balance);
            if(strcmp(user_name1,user_name2) != 0){
                fprintf(temp,"%s\n",line);
            }
       }
       fclose(fp);
       fclose(temp);
       printf("your account is deleted\n");
   
       remove("account_details.txt");
       rename("temporary.txt","account_details.txt");
     
       fp = fopen("login_details.txt","r");
       temp= fopen("temporary.txt","w");
       while(fgets(line,100,fp)){
            sscanf(line,"%[^|]|%[^\n]",user_name2,password);
            if(strcmp(user_name1,user_name2) != 0){
                fprintf(temp,"%s\n",line);
            }
       }
       fclose(fp);
       fclose(temp);
       remove("login_details.txt");
       rename("temporary.txt","login_details.txt");
        
       printf("\n");
}

// To view history
void histroy(char user_name1[20]){
    printf("2");
}