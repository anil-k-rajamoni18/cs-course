#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"employee.h"

// Defining addEmployee function..
void add_employee(){
    struct Employee emp;

     printf("To add your details , answer below questions.\n");
     printf("Please enter your name : ");
     scanf(" %[^\n]",emp.name);
     printf("Please enter your Employee id : ");
     scanf("%d",&emp.id);
     printf("Please enter your basic salary which was given by manager : ");
     scanf("%f",&emp.basic_salary);

     // Finding remaing details..

    emp.hra =  emp.basic_salary/5;
    emp.da = emp.basic_salary/10;
    emp.gross_salary = emp.basic_salary + emp.hra + emp.da;

    if(emp.gross_salary >= 100000){
        emp.tax = emp.gross_salary/10;
    }
    else {
        emp.tax = emp.gross_salary/20;
    }

    emp.net_salary = emp.gross_salary - emp.tax;

    // Entering details into file..

    FILE *fp;
    fp = fopen("Employee_records.dat","ab");
    fwrite(&emp,sizeof(emp),1,fp);
    fclose(fp);
    printf("Your details are sucessfully added.\n");
    printf("\n");
}

// Login function..
int  login(int choice){
     struct Employee emp;
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

     while(fread(&emp,sizeof(emp),1,fp)){
            if(strcmp(name,emp.name) == 0 && id == emp.id){
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
     struct Employee emp;
     FILE *fp;
     fp = fopen("Employee_records.dat","rb");
    
     if(fp == NULL){
        printf("Something went wrong.Try again.\n");
        return 0;
     }

     while(fread(&emp,sizeof(emp),1,fp)){
            if(id == emp.id){
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
     struct Employee emp;
     FILE *fp;
     fp = fopen("Employee_records.dat","rb");
    
     if(fp == NULL){
        printf("Something went wrong.Try again.\n");
        return 0;
     }

     while(fread(&emp,sizeof(emp),1,fp)){
            if(id == emp.id){
                printf("-------------------------------------\n");
                printf("              PAY SLIP               \n");
                printf("-------------------------------------\n");
                printf("\n");
                printf("1.Employee name   : %s\n",emp.name);
                printf("2.Employee id     : %d\n",emp.id);
                printf("3.Basic salary    : %.2f\n",emp.basic_salary);
                printf("4.HRA             : %.2f\n",emp.hra);
                printf("5.DA              : %.2f\n",emp.da);
                printf("6.Gross salary    : %.2f\n",emp.gross_salary);
                printf("7.Tax amount      : %.2f\n",emp.tax);
                printf("8.Net salary      : %.2f\n",emp.net_salary);
                break;
            }
     }
     printf("\n");
     fclose(fp);

return 0;
}