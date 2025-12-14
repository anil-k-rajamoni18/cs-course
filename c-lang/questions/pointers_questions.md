# Pointers Practice & Assessment

##  Part A: Hands-On Coding Questions 
*(Write C programs for the following pointer-based problems)*

1. Write a program to declare and initialize a pointer and display its value and address.
2. Write a program to swap two numbers using pointers.
3. Write a program to find the sum of two numbers using pointers.
4. Write a program to find the length of a string using a pointer.
5. Write a program to reverse a string using pointers.
6. Write a program to copy one string to another using pointers.
7. Write a program to count vowels and consonants in a string using pointers.
8. Write a program to find the largest element in an array using pointers.
9. Write a program to calculate the sum of array elements using pointers.
10. Write a program to print all elements of an array using pointer notation.
11. Write a program to demonstrate pointer arithmetic (++, --, +, -).
12. Write a program to access array elements using pointer and subscript notation.
13. Write a program to compare two strings using pointers (no library functions).
14. Write a program to swap two numbers using call by reference.
15. Write a program to show the relationship between arrays and pointers.
16. Write a program using a pointer to pointer (double pointer) to access a variable.
17. Write a program to find factorial of a number using pointer and function.
18. Write a program to allocate memory dynamically using `malloc()` and find the sum of n integers.
19. Write a program to free dynamically allocated memory and verify its release.
20. Write a program using pointer arrays to store and display names of students.

---

## Multiple-Choice Questions

**1.** Which operator is used to get the address of a variable in C?
- A) *
- B) &
- C) @
- D) #

**2.** Which operator is used to access the value at the address stored in a pointer?
- A) *
- B) &
- C) ->
- D) .

**3.** What is the output?
```c
int a = 10;
int *p = &a;
printf("%d", *p);
```
- A) 10
- B) Address of a
- C) Garbage
- D) Error

**4.** What will happen if you print a pointer without *?
```c
int a = 5;
int *p = &a;
printf("%d", p);
```
- A) Prints 5
- B) Prints address of a
- C) Error
- D) Undefined

**5.** A pointer that does not point to any valid memory location is called:
- A) Null pointer
- B) Dangling pointer
- C) Wild pointer
- D) Void pointer

**6.** The size of a pointer variable in C is:
- A) 2 bytes
- B) 4 or 8 bytes (depends on system)
- C) Same as data type
- D) None

**7.** Which of the following declares a pointer correctly?
- A) `int p;`
- B) `int *p;`
- C) `int &p;`
- D) `pointer int;`

**8.** Which of the following is a void pointer declaration?
- A) `int *ptr;`
- B) `void *ptr;`
- C) `char *ptr;`
- D) `float *ptr;`

**9.** What does the following code print?
```c
int a = 5, b = 10;
int *p = &a;
int *q = &b;
printf("%d", *p + *q);
```
- A) 15
- B) 10
- C) 5
- D) Error

**10.** What is the output?
```c
int a = 100;
int *p = &a;
int **q = &p;
printf("%d", **q);
```
- A) 100
- B) Address of p
- C) Address of a
- D) Error

**11.** Which of the following statements is true?
- A) Pointer stores a value.
- B) Pointer stores the address of a variable.
- C) Pointer stores both value and address.
- D) None.

**12.** What is a dangling pointer?
- A) Pointer not initialized
- B) Pointer pointing to freed memory
- C) Pointer assigned to null
- D) Pointer pointing to itself

**13.** Which function is used to allocate memory dynamically?
- A) `alloc()`
- B) `malloc()`
- C) `calloc()`
- D) Both B and C

**14.** What does `free()` function do?
- A) Resets a pointer
- B) Deallocates previously allocated memory
- C) Prints memory details
- D) Initializes memory to zero

**15.** What is the output?
```c
int x=5, *p;
p = &x;
*p = *p + 2;
printf("%d", x);
```
- A) 5
- B) 7
- C) 2
- D) Error

**16.** Pointer arithmetic is allowed on:
- A) Integer pointers only
- B) Pointers to any data type
- C) Void pointers
- D) None

**17.** What is a wild pointer?
- A) Pointer initialized to null
- B) Pointer pointing to freed memory
- C) Pointer not initialized
- D) Constant pointer

**18.** Which of the following statements is incorrect?
- A) Array name can act as a pointer.
- B) Pointer can be incremented.
- C) Pointer subtraction is allowed.
- D) You can add two pointers.

**19.** What does this code print?
```c
int arr[3]={1,2,3};
int *p=arr;
printf("%d", *(p+1));
```
- A) 1
- B) 2
- C) 3
- D) Error

**20.** What will be the output?
```c
int x = 5;
int *ptr = &x;
printf("%u", ptr);
```
- A) Address of x
- B) 5
- C) Error
- D) Garbage