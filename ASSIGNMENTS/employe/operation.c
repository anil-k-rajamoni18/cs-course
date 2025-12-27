#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"operation.h"

// Defining addEmployee function..
void add_employee(){
    struct employee E;

     printf("To add your details , answer below questions.\n");
     printf("Please enter your name : ");
     scanf(" %[^\n]",E.name);
     printf("Please enter your Employee id : ");
     scanf("%d",&E.id);
     printf("Please enter your basic salary which was given by manager : ");
     scanf("%f",&E.basic_salary);

     // Finding remaing details..
     
    E.hra =  E.basic_salary/5;
    E.da = E.basic_salary/10;
    E.gross_salary = E.basic_salary + E.hra + E.da;

    if(E.gross_salary >= 100000){
        E.tax = E.gross_salary/10;
    }
    else {
        E.tax = E.gross_salary/20;
    }
     
    E.net_salary = E.gross_salary - E.tax; 

    // Entering details into file..

    FILE *fp;
    fp = fopen("Employee_records.dat","ab");
    fwrite(&E,sizeof(E),1,fp);
    fclose(fp);
    printf("Your details are sucessfully added.\n");
    printf("\n");
}

// Login function..
int  login(int choice){
     struct employee E;
     char name[100];
     int id;
     int flag = 0;

     printf("Enter your name : ");
     scanf(" %[^\n]",name);
     printf("Enter your Employee id : ");
     scanf("%d",&id);

     FILE *fp;
     fp = fopen("Employee_records.dat","rb");
    
     if(fp == NULL){
        printf("Something went wrong.Try again.\n");
        return 0;
     }

     while(fread(&E,sizeof(E),1,fp)){
            if(strcmp(name,E.name) == 0 && id == E.id){
                printf("You logged in successfully.\n");
                flag++;
                break;
            }
     }

     fclose(fp);

     if(flag == 0){
        printf("You entered wrong information.\n");
     }
     else{
        switch(choice){  
            case 2 : calculate_salary(id);
                     break;
            case 3 : generate_payslip(id);         
                     break;
        }
     }  
   printf("\n");
return 0;
}

// calculating salary..
int calculate_salary(int id){
     struct employee E;
     FILE *fp;
     fp = fopen("Employee_records.dat","rb");
    
     if(fp == NULL){
        printf("Something went wrong.Try again.\n");
        return 0;
     }

     while(fread(&E,sizeof(E),1,fp)){
            if(id == E.id){
                printf("Your net salary is %.2f\n",E.net_salary);
                break;
            }
     }
     printf("\n");
     fclose(fp);

return 0;
}

// Generating pay slip..
int generate_payslip(int id){
     struct employee E;
     FILE *fp;
     fp = fopen("Employee_records.dat","rb");
    
     if(fp == NULL){
        printf("Something went wrong.Try again.\n");
        return 0;
     }

     while(fread(&E,sizeof(E),1,fp)){
            if(id == E.id){
                printf("-------------------------------------\n");
                printf("              PAY SLIP               \n");
                printf("-------------------------------------\n");
                printf("\n");
                printf("1.Employee name   : %s\n",E.name);
                printf("2.Employee id     : %d\n",E.id);
                printf("3.Basic salary    : %.2f\n",E.basic_salary);
                printf("4.HRA             : %.2f\n",E.hra);
                printf("5.DA              : %.2f\n",E.da);
                printf("6.Gross salary    : %.2f\n",E.gross_salary);
                printf("7.Tax amount      : %.2f\n",E.tax);
                printf("8.Net salary      : %.2f\n",E.net_salary);
                break;
            }
     }
     printf("\n");
     fclose(fp);

return 0;
}