#include <stdio.h>

struct student {
    int id;
    char name[20];
};

int main() {
    FILE *fp;
    struct student s = {1, "Amit"};
    
    fp = fopen("stud.dat", "wb");
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    
    return 0;
}