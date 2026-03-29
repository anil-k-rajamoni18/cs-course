# Linear Search – Practice Questions

## Q1) Write a program using linear search to find whether a given number exists in an array of 10 integers.

**Solution:**

```c
#include<stdio.h>
int main(){
   int num[10];
   char ch='F';
   printf("Enter the ten elements :");
   for(int i=0;i<10;i++){
      scanf("%d",&num[i]);
   }
   int key;
   printf("Enter the element to find :");
   scanf("%d",&key);
   for(int j=0;j<10;j++){
      if(key==num[j]){
         ch='T';
         break;  
      }
   }
   if(ch=='T') 
      printf("Given element exist in array..");
   else 
      printf("Given element not exist in array..");
   return 0;
}
```

## Q2) Accept n elements from the user and a key element. Use linear search to display whether the key is found or not.

**Solution:**

```c
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,key;
    char ch='F';
    printf("Enter the no of elements in array :");
    scanf("%d",&n);
    int *num=(int*)malloc(n*sizeof(int));
    printf("Enter the %d elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",(num+i));
    }
    printf("Enter the Element to find:");
    scanf("%d",&key);
    for(int j=0;j<10;j++){
        if(key==num[j]){
            ch='T';
            break;  
        }
    }
    if(ch=='T') 
        printf("Given element exist in array..");
    else 
        printf("Given element not exist in array..");
    free(num);
}
```

## Q3) Write a function int linearSearch(int arr[], int n, int key) that returns the index of the element if found, else -1.

**Solution:**

```c
#include<stdio.h>
#include<stdlib.h>
int Linear_search(int*,int ,int);
int main(){
    int n,key;
    printf("Enter the no of elements in array :");
    scanf("%d",&n);
    int *num=(int*)malloc(n*sizeof(int));
    printf("Enter the %d elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",(num+i));
    }
    printf("Enter the Element to find:");
    scanf("%d",&key);
    int index= Linear_search(num,n,key);
    printf("Given element is at index %d",index);
    free(num);
    return 0;
}
int Linear_search(int*a,int n ,int k){
    int index=-1;
    for(int x=0;x<n;x++){
        if(k==*(a+x)){
            index=x;
            return index;
        }
    }
    return index;
}
```

## Q4) Modify the linear search to count how many times a number occurs in the array.

**Solution:**

```c
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,key,count=0;
    printf("Enter the no of elements in array :");
    scanf("%d",&n);
    int *num=(int*)malloc(n*sizeof(int));
    printf("Enter the %d elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",(num+i));
    }
    printf("Enter the Element to find:");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(key==*(num+i)){
            count+=1;
        }
    }
    if(count ==0){
        printf("Given number not present in array..");
    }
    else 
        printf("%d occurs %d times..",key, count);
    free(num);
    return 0;
}
```

## Q5) Use linear search to find the first and last occurrence of a given element in an array.

**Solution:**

```c
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,key,count=0;
    int first=-1;
    int last =-1;
    printf("Enter the no of elements in array :");
    scanf("%d",&n);
    int *num=(int*)malloc(n*sizeof(int));
    printf("Enter the %d elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",(num+i));
    }
    printf("Enter the Element to find:");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(count==0){
            if(key==num[i]){
                first=i;
                count+=1;
            }
        }
        else if(key==num[i]){
            last=i;
        }
    }
    printf("%d occurs first time at index %d and last time at index %d",key,first,last);
    free(num);
    return 0;
}
```

## Q6) Implement recursive linear search to find an element in an array.

**Solution:**

```c
#include<stdio.h>
#include<stdlib.h>
int call=0;
void Linear_search(int*,int ,int);
int main(){
    int n,key;
    printf("Enter the no of elements in array :");
    scanf("%d",&n);
    int *num=(int*)malloc(n*sizeof(int));
    printf("Enter the %d elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",(num+i));
    }
    printf("Enter the Element to find:");
    scanf("%d",&key);
    Linear_search(num,n,key);
}
void Linear_search(int*p,int n,int k){
    if(call<n){
        if(k==*p){
            printf("number is found");
        }
        else {
            call+=1;
            Linear_search(p+1,n,k);
        }
    }
    else 
        printf("number not found");
}
```