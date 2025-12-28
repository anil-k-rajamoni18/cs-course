#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee {
       char name[100];
       int id;
       float basic_salary;
       float hra;
       float da;
       float tax;
       float gross_salary;
       float net_salary;
};

void add_employee();
int calculate_salary(int);
int generate_payslip(int);
int  login(int);

#endif