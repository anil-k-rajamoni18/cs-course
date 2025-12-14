# Functions Practice & Assessment

## Part A: Hands-On Coding Questions 
*(Write C programs for the following tasks involving functions)*

1. Write a program to create a function that adds two numbers and returns the result.
2. Write a function to find the factorial of a number.
3. Write a function to check whether a number is prime or not.
4. Write a function to find the greatest of three numbers using return statements.
5. Write a function to swap two numbers using call by value.
6. Write a function to swap two numbers using call by reference (pointers).
7. Write a function to calculate the area of a circle using radius as input.
8. Write a function to find the sum of digits of a given number.
9. Write a function to reverse a number.
10. Write a function to check whether a number is palindrome or not.
11. Write a function to count vowels and consonants in a string.
12. Write a function to convert Celsius to Fahrenheit.
13. Write a function to return the square of a number using return type.
14. Write a function to find the power of a number using recursion.
15. Write a recursive function to find the factorial of a number.
16. Write a recursive function to print the Fibonacci series up to n terms.
17. Write a program using a function to check whether a number is even or odd.
18. Write a function that takes an array and returns the sum of its elements.
19. Write a program using user-defined functions to perform basic arithmetic operations (add, subtract, multiply, divide).
20. Write a menu-driven program using functions for performing different mathematical operations.

---

## Part B: Multiple-Choice Questions 

**1.** Which of the following is the correct syntax to declare a function in C?
- A) `int function;`
- B) `int function();`
- C) `function int();`
- D) `declare function();`

**2.** A function that calls itself is known as:
- A) Inline function
- B) Recursive function
- C) User-defined function
- D) Library function

**3.** What is the default return type of a function in C if not specified?
- A) void
- B) int
- C) float
- D) char

**4.** Which keyword is used to return a value from a function?
- A) return
- B) break
- C) exit
- D) continue

**5.** What is the output of the following code?
```c
void main() {
    printf("%d", sum(2,3));
}
int sum(int a, int b) {
    return a + b;
}
```
- A) 5
- B) 0
- C) Error: function not declared
- D) Undefined behavior

**6.** Which of the following must match when calling a function?
- A) Function name only
- B) Number and type of arguments
- C) Function name and return type
- D) None of these

**7.** A function that does not return any value must be declared as:
- A) void
- B) null
- C) empty
- D) none

**8.** Which of the following is a library function in C?
- A) `main()`
- B) `printf()`
- C) `add()`
- D) `sum()`

**9.** Which of the following correctly passes an array to a function?
- A) `function(int arr);`
- B) `function(int *arr);`
- C) Both A and B
- D) None

**10.** Which of the following is not true about functions in C?
- A) A function can call another function.
- B) Functions help in code reuse.
- C) Every program must have more than one function.
- D) Functions can have no parameters.

**11.** What is the output?
```c
int func() {
    return 10;
}
void main() {
    printf("%d", func());
}
```
- A) 0
- B) 10
- C) Garbage
- D) Error

**12.** Which of these can be used to stop a recursive function?
- A) break
- B) continue
- C) Base condition
- D) goto

**13.** Which statement is true?
- A) A function can return more than one value.
- B) A function cannot return a value.
- C) A function can return only one value at a time.
- D) A function must return an integer.

**14.** Functions that are predefined in C language are called:
- A) User-defined functions
- B) Library functions
- C) Recursive functions
- D) Inline functions

**15.** Which header file is needed for using `pow()` function?
- A) `<math.h>`
- B) `<stdio.h>`
- C) `<conio.h>`
- D) `<stdlib.h>`

**16.** What is the output of this code?
```c
int add(int a, int b) { return a + b; }
void main() {
    printf("%d", add(5, 10));
}
```
- A) 5
- B) 10
- C) 15
- D) Error

**17.** What will happen if a function is called before its declaration?
- A) Compiler error
- B) Works fine always
- C) Depends on compiler
- D) Undefined behavior

**18.** Which of the following is true for call by reference?
- A) Actual values are passed.
- B) Copies of variables are passed.
- C) Addresses of variables are passed.
- D) None of these.

**19.** What is the scope of a function's local variable?
- A) Throughout the program
- B) Inside the function only
- C) Inside all functions
- D) Global scope

**20.** What will the following code output?
```c
void display() {
    printf("Hello");
}
void main() {
    display();
    display();
}
```
- A) Hello
- B) HelloHello
- C) Compile error
- D) Nothing