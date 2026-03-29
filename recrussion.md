Recursive Functions in C - Practice Problems
Q1) Write a recursive function to find the sum of digits of a number.
Solution:
c// Sum of digits of number
#include<stdio.h>

int sum(int);

int main(){
  int n;
  printf("Enter the number:");
  scanf("%d",&n);
  int a=sum(n);
  printf("%d",a);
}

int sum(int n){
    int s=0;
    if (n==0) return 0;
    if(n>0){
     s=n%10+sum(n/10);
    }
    return s;
}

Q2) Write a recursive function to find the power of a number (a^b).
Solution:
c// To compute power
#include<stdio.h>

int power(int ,int ,int);

int main(){
  int a,b,y;
  y=0;
  printf("Enter the base and exponent : ");
  scanf("%d %d",&a, &b);
  int c=power(a,b,y);
  printf("%d power %d is %d",a,b,c);
  return 0;
}

int power(int a, int b,int y){
    int x;
    y++;
    if(y<=b){
    x=a*power(a,b,y);
    }
    else return 1;
   return x;
}

Q3) Write a recursive function to count the digits of a number.
Solution:
c// Counting no of digits in a number
#include<stdio.h>

int c=0;
int counting(int);

int main(){
    int num;
    printf("enter the number :");
    scanf("%d",&num);
    int a=counting(num);
    printf("no of digits are %d",a);
    return 0;
}

int counting(int n){
   if (n!=0){
        c=c+1;
        counting(n/10);
   }
   return c;
}

Q4) Write a recursive function to reverse a number.
Solution:
c// To reverse the number
#include<stdio.h>
#include<math.h>

void reverse(int);

int main(){
  int num;
  printf("Enter the number: ");
  scanf("%d",&num);
  reverse(num);
return 0;
}

void reverse(int n){
    int a=0;
    a=a*10 + n%10;
   if(n>0){
    reverse(n/10);
   }
   printf("%d",a);
}

Q5) Write a recursive function to print all elements of an array.
Solution:
c// To print array element
#include<stdio.h>
#include<stdlib.h>

int x=0;
void arr(int *,int);

int main(){
  int n;
  printf("Enter the no of elements : ");
  scanf("%d",&n);
  int *num=(int*)malloc(n*sizeof(int));
  printf("Enter the elements:");
  for(int i=0;i<n;i++){
     scanf("%d",&num[i]);
  }
  printf("you entered below elements \n");
  arr(num,n);
  free(num);
}

void arr(int* a,int n){
    if(x<n){
        printf("%d ",*(a+x));
        x++;
        arr(a,n);
    }
}

Q6) Write a recursive function to print numbers from 1 to n.
Solution:
c// Printing first n terms
#include<stdio.h>

void series(int ,int);

int main(){
    int n,i;
    i=1;
    printf("Enter the number: ");
    scanf("%d",&n);
    series(n,i);
    return 0;
}

void series(int n,int i){
      if(i<=n){
        printf("%d ",i);
        i++;
        series(n,i);
      }
}

Q7) Write a recursive function to print sum of n terms.
Solution:
c// Sum of first n terms
#include<stdio.h>

int sum(int);

int main(){
   int n;
   printf("Enter the number : ");
   scanf("%d",&n);
   int a=sum(n);
   printf("Sum of first %d terms is %d",n,a);
   return 0;
}

int sum(int n){
    int x=0;
    if(n==1) return 1;
    x=n+sum(n-1);
    return x;
}