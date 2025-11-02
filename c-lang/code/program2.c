#include <stdio.h>


void display(int[], int);
void displayPassByValue(int);

int main() {
    // int arr[5];
    // for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    //     printf("Enter element %d: ", i + 1);
    //     scanf("%d", &arr[i]);
    // }

    // printf("You entered:\n");
    // for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    //     printf("%d ", arr[i]);
    // }

    // Linear Search
    // int arr[10] = {99,1,3,5,8,22,1,82,26,19};
    // int key;
    // printf("enter the key to search: ");
    // scanf("%d", &key);
    // int isFound=0;
    // for(int i=0; i < 10; i++) {
    //     if (key == arr[i]) {
    //         printf("Key:%d found at index %d\n", key, i);
    //         isFound = 1;
    //         break;
    //     }
    // }
    // if (!isFound)
    //     printf("-1");

    int size = 1, x;
    int dum[size];
    printf("%d %d\n", dum[0], sizeof(dum));
    x = size;
    x = x+1;
    printf("%d %d\n", dum[0], sizeof(dum));
    dum[x] = 0;
    x = x + 2;
    dum[x] = 10;
    printf("%d %d\n", dum[0], sizeof(dum));



    int num = 10;
    int marks[5] = {98, 78,97,77,90};

    displayPassByValue(num);
    printf("num inside main() = %d\n", num);

    printf("Before passing to display() \n ");
    for(int i = 0; i<5; i++) {
        printf("marks[%d] = %d\n", i, marks[i]);
    }

    display(marks, 5);
    
    printf("After passing to display() \n ");
    for(int i = 0; i<5; i++) {
        printf("marks[%d] = %d\n", i, marks[i]);
    }

}

void displayPassByValue(int num) {
    num = num *2;
    printf("num inside display() = %d\n", num);
}

void display(int res[], int size) {
    for(int i = 0; i<size; i++) {
        res[i] *= 2; 
        //printf("res[%d] = %d\n", i, res[i]);
    }

}