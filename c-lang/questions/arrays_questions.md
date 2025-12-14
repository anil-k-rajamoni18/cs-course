# Arrays Practice & Assessment

## Part A: Hands-On Coding Questions
*(Write C programs for the following)*

1. Input 10 integers into an array and display them.
2. Calculate and print the sum and average of array elements.
3. Find the maximum and minimum element in an array.
4. Reverse the elements of an array (without using another array).
5. Count how many numbers are even and how many are odd in an array.
6. Copy all elements from one array to another.
7. Search for a specific element using linear search.
8. Find the frequency of each element in an array.
9. Sort elements of an array in ascending and descending order.
10. Find the second largest element in an array (without sorting).
11. Insert a new element at a specific position.
12. Delete an element from a specific position.
13. Merge two arrays into a third array.
14. Remove duplicate elements from an array.
15. Rotate an array by `k` positions (left or right).
16. Find the missing number from an array of `1` to `n`.
17. Find the sum of diagonal elements of a 2D square matrix.
18. Find the transpose of a matrix.
19. Add two matrices.
20. Multiply two matrices.

---

## Part B: Multiple-Choice Questions (20 Questions)

**1.** Correct way to declare an array in C is:
- A) `int array;`
- B) `array int[10];`
- C) `int array[10];`
- D) `int[10] array;`

**2.** The index of the first array element in C is:
- A) 0
- B) 1
- C) -1
- D) Depends on compiler

**3.** Output?
```c
int a[5]={1,2,3,4,5};
printf("%d",a[2]);
```
- A) 1
- B) 2
- C) 3
- D) 4

**4.** Which initializes all elements to 0?
- A) `int a[5]={0};`
- B) `int a[5]={0,0,0,0,0};`
- C) Both
- D) None

**5.** Accessing array out of bounds in C causes:
- A) Compile error
- B) Runtime error
- C) Undefined behavior
- D) Wraparound

**6.** How to find number of elements in array `arr`?
- A) `sizeof(arr)`
- B) `sizeof(arr)/sizeof(arr[0])`
- C) `length(arr)`
- D) `count(arr)`

**7.** Output?
```c
int a[5]={10,20,30,40,50};
printf("%d",*(a+3));
```
- A) 10
- B) 20
- C) 30
- D) 40

**8.** Which is incorrect?
- A) Arrays are contiguous.
- B) Array name = address of first element.
- C) Array elements can have different types.
- D) Array size must be constant.

**9.** Output?
```c
int arr[3]={1,2};
printf("%d",arr[2]);
```
- A) 0
- B) Garbage
- C) 2
- D) Error

**10.** For `int arr[5]={1,2,3,4,5};`, which is true?
- A) `arr` = `&arr[0]`
- B) `arr` stores first value
- C) Cannot be passed to function
- D) Reassignable

**11.** Access last element of `arr` of size n:
- A) `arr[5]`
- B) `arr[n]`
- C) `arr[n-1]`
- D) `arr[-1]`

**12.** Size of `char str[10];` is:
- A) 9
- B) 10
- C) 11
- D) Depends on compiler

**13.** Output?
```c
int a[2][3]={{1,2,3},{4,5,6}};
printf("%d",a[1][2]);
```
- A) 3
- B) 4
- C) 5
- D) 6

**14.** How many elements?
```c
int a[][3]={{1,2,3},{4,5,6}};
```
- A) 3
- B) 6
- C) 9
- D) Error

**15.** Function to copy arrays?
- A) `copy()`
- B) `strcpy()`
- C) Manual loop
- D) `memcopy()`

**16.** Correct syntax to pass array to function?
- A) `function(int arr[])`
- B) `function(int *arr)`
- C) Both
- D) None

**17.** Which is invalid?
- A) `int arr[5]={0};`
- B) `int arr[]={1,2,3};`
- C) `int arr[3]={1,2,3,4};`
- D) `int arr[3];`

**18.** Output?
```c
int arr[4]={10,20,30,40};
printf("%d",*arr+2);
```
- A) 10
- B) 12
- C) 20
- D) 30

**19.** Which is false?
- A) Arrays can be multidimensional.
- B) Array elements accessed by subscripts.
- C) Array name assignable to another array.
- D) Indexing starts from 1.

**20.** Output?
```c
int arr[5]={1,2,3,4,5};
printf("%d",*(arr+4));
```
- A) 1
- B) 4
- C) 5
- D) Error