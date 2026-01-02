#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee {
    int empId;
    char name[50];
    float basic;
    float hra;
    float da;
    float gross;
    float tax;
    float net;
};

void addEmployee();
void viewEmployees();
void generatePayslip();

#endif
