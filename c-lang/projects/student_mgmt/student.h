#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void sortByMarks();

#endif
