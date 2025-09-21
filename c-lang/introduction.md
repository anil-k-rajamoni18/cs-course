# 🖥️  Introduction to C Programming Language

---

## 1. Introduction to C Programming Language

C is a powerful **general-purpose programming language** developed in the early 1970s.  
It is widely used for system programming, developing operating systems, embedded systems, and applications where performance is critical.

💡 **Key Features of C:**
- Procedural programming language  
- Close to hardware, providing fine control  
- Fast and efficient  
- Portable across platforms

---

## 2. 📜 History of C Language

- **Early 1970s** – Developed by **Dennis Ritchie** at Bell Labs.  
- Originally designed to develop the **Unix operating system**.  
- Based on earlier languages like **B and BCPL**.

🚀 **Why C became popular:**
- Combines efficiency of assembly with higher-level programming ease.  
- Helps in building system-level software and embedded applications.  
- Became the foundation for many other languages like C++, C#, Java.

---

## 3. 💡 What, Why & Where of C Programming

### ❓ What is C Programming?
C is a **procedural language** designed to write efficient and fast programs with a structured approach.

### Why Learn C?
- Provides a deep understanding of computer hardware.  
- Excellent for learning programming fundamentals.  
- Widely used in operating systems, embedded systems, and critical performance applications.

### 🌍 Where is C Used?
- Operating Systems (e.g., Unix, Linux)  
- Embedded Systems (e.g., Arduino programming)  
- System Tools and Compilers  
- Game Development  
- Real-time systems

---

## 4. 🏗️ Structure of a C Program

```c
## 1. Basic Skeleton of a C Program

```c
#include <stdio.h>    // Preprocessor directive

// Global Declarations (optional)
int globalVar = 10;

// Function Prototypes (optional)
void greet();

// User-Defined Structures and Unions (optional)
struct Person {
    char name[50];
    int age;
};

union Data {
    int i;
    float f;
    char str[20];
};

// Main Function - Entry Point
int main() {
    printf("Hello, World!\n");

    // Call user-defined function
    greet();

    return 0;  // Exit status
}
```
**Key Components:**
1. Preprocessor Directive (#include)
    - Tells the compiler to include the standard input-output library.

2. main() Function
    - Entry point of every C program.

3. printf() Function
    - Displays output on the screen.

4. return 0;
    - Signals successful execution.


**Example Program:**
```c
#include <stdio.h>

int main() {
    int age = 19;  // Declare an integer variable
    printf("I am %d years old.\n", age);  // Display message with variable
    return 0;
}
```

1. #include <stdio.h> → Includes standard I/O library needed for printf.

2. int main() → The main function where execution starts.

3. int age = 19; → Declares an integer variable age and assigns the value 19.

4. printf("I am %d years old.\n", age);
    - %d is a format specifier for integers.
    - Displays: I am 19 years old.

5. return 0; → Program ends successfully.

---
## 5. ⚡ How C Code is Understood by the CPU
*💡 Steps from Source Code to Execution:*
- Write Source Code → File: program.c
- Preprocessing → Expands #include and macros → Output: .i file
- Compilation → Converts code into Assembly → Output: .s file
- Assembly → Converts to Machine Code → Output: .o file (object file)
- Linking → Combines object code and libraries → Output: Executable file (a.out or program.exe)
- Execution by CPU → CPU executes machine code (binary instructions).

*⚡ Simplified Analogy:*
```text
Writing C code → Translator (Compiler & Linker) → Machine understands binary → CPU performs actions.
```

---
## 🚀 What Happens During Execution of a C Program?

When you run a C program, several important steps happen behind the scenes before your program actually works and shows results.


![](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/images/C_DevelopmentProcesses.png)


---

## 1. ✍️ You Write the C Code
- You write human-readable instructions in a text file, for example `program.c`  
- Example:
    ```c
    #include <stdio.h>

    int main() {
        printf("Hello, World!\n");
        return 0;
    }
    ```

---

## 2. ⚡ Compilation Process
Before the computer understands your code, it goes through several stages:

### 🛠️ Step 1: Preprocessing
- Handles `#include`, `#define`, etc.
- Includes necessary files (like `<stdio.h>`)  
- The result is an expanded code version.

### 🛠️ Step 2: Compilation
- Converts your C code into **Assembly code** (lower-level, human-readable machine instructions).

### 🛠️ Step 3: Assembling
- Converts Assembly code into **Machine Code (binary)** (0s and 1s).

### 🛠️ Step 4: Linking
- Links your code with standard libraries (like printf)  
- Produces an executable file (e.g., `a.exe` or `program.out`).

---

## 3. ▶️ Program Execution
When you run the executable:
1. The **Operating System (OS)** loads the program into memory.
2. The CPU executes machine code instructions, step by step.
3. The program performs tasks (like printing "Hello, World!") by interacting with memory and I/O devices.
4. Once finished, the program returns a status code (e.g., `return 0;`) and exits.

---

## 4. 🧱 Simplified Analogy
👉 Think of writing a C program like writing a recipe (human-friendly).  
👉 Compilation is like translating the recipe into a language only a chef (computer) understands.  
👉 Execution is the chef (CPU) following the exact steps to cook the dish (run the program).

---

## 🎯 Final Thought
Even though you write readable C code, the computer only understands 0s and 1s!  
The compiler and assembler do all the heavy lifting to translate your code into something the CPU can understand.

🌟 **Pro Tip**:  
Always check for compilation errors before running your program – they happen when the computer doesn’t understand your instructions!

