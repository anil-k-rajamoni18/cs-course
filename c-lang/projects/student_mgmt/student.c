#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.dat", "ab");

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student added successfully!\n");
}

void viewStudents() {
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");

    if (!fp) {
        printf("No records found!\n");
        return;
    }

    printf("\nRoll\tName\t\tMarks\n");
    printf("--------------------------------\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("%d\t%-15s\t%.2f\n", s.roll, s.name, s.marks);
    }
    fclose(fp);
}

void searchStudent() {
    struct Student s;
    int roll, found = 0;
    FILE *fp = fopen("students.dat", "rb");

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("Found: %d %s %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");

    fclose(fp);
}

void updateStudent() {
    struct Student s;
    int roll, found = 0;
    FILE *fp = fopen("students.dat", "rb+");

    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("New Name: ");
            scanf(" %[^\n]", s.name);
            printf("New Marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found)
        printf("Record updated successfully!\n");
    else
        printf("Student not found!\n");
}

void deleteStudent() {
    struct Student s;
    int roll, found = 0;
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll != roll)
            fwrite(&s, sizeof(s), 1, temp);
        else
            found = 1;
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Record deleted successfully!\n");
    else
        printf("Student not found!\n");
}

void sortByMarks() {
    struct Student s[100], temp;
    int count = 0, i, j;

    FILE *fp = fopen("students.dat", "rb");

    while (fread(&s[count], sizeof(struct Student), 1, fp))
        count++;

    fclose(fp);

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (s[i].marks < s[j].marks) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    fp = fopen("students.dat", "wb");
    fwrite(s, sizeof(struct Student), count, fp);
    fclose(fp);

    printf("Students sorted by marks!\n");
}
