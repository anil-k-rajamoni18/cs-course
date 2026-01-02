#include <stdio.h>
#include "employee.h"

int main() {
    int choice;

    do {
        printf("\n=== Employee Payroll System ===\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Generate Payslip\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: generatePayslip(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
