#include <stdio.h>
#include "employee.h"

void addEmployee() {
    struct Employee e;
    FILE *fp = fopen("employees.dat", "ab");

    printf("Enter Employee ID: ");
    scanf("%d", &e.empId);
    printf("Enter Name: ");
    scanf(" %[^\n]", e.name);
    printf("Enter Basic Salary: ");
    scanf("%f", &e.basic);

    /* Salary Calculation */
    e.hra = e.basic * 0.20;   // 20% HRA
    e.da  = e.basic * 0.10;   // 10% DA
    e.gross = e.basic + e.hra + e.da;

    /* Tax Logic */
    if (e.gross > 50000)
        e.tax = e.gross * 0.10;
    else
        e.tax = e.gross * 0.05;

    e.net = e.gross - e.tax;

    fwrite(&e, sizeof(e), 1, fp);
    fclose(fp);

    printf("Employee added successfully!\n");
}

void viewEmployees() {
    struct Employee e;
    FILE *fp = fopen("employees.dat", "rb");

    if (!fp) {
        printf("No records found!\n");
        return;
    }

    printf("\nID\tName\t\tNet Salary\n");
    printf("----------------------------------\n");

    while (fread(&e, sizeof(e), 1, fp)) {
        printf("%d\t%-15s\t%.2f\n", e.empId, e.name, e.net);
    }

    fclose(fp);
}

void generatePayslip() {
    struct Employee e;
    int id, found = 0;
    FILE *fp = fopen("employees.dat", "rb");
    FILE *txt = fopen("payslip.txt", "w");

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(e), 1, fp)) {
        if (e.empId == id) {
            fprintf(txt, "===== PAY SLIP =====\n");
            fprintf(txt, "Employee ID : %d\n", e.empId);
            fprintf(txt, "Name        : %s\n", e.name);
            fprintf(txt, "Basic Salary: %.2f\n", e.basic);
            fprintf(txt, "HRA         : %.2f\n", e.hra);
            fprintf(txt, "DA          : %.2f\n", e.da);
            fprintf(txt, "Gross Salary: %.2f\n", e.gross);
            fprintf(txt, "Tax         : %.2f\n", e.tax);
            fprintf(txt, "Net Salary  : %.2f\n", e.net);

            printf("Payslip generated successfully!\n");
            found = 1;
            break;
        }
    }

    fclose(fp);
    fclose(txt);

    if (!found)
        printf("Employee not found!\n");
}
