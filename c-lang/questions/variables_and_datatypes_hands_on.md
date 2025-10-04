# Variables and Data Types — Hands-On Practice

1️⃣ Basic variable declaration
```c
#include <stdio.h>
int main() {
    int x;
    x = 10;
    printf("%d\n", x);
    return 0;
}
```
Q: What happens if you print `x` before assigning it a value?

---

2️⃣ Multiple variable declarations
```c
#include <stdio.h>
int main() {
    int a = 5, b = 10, c = 15;
    printf("%d %d %d\n", a, b, c);
    return 0;
}
```
Q: What if one variable is uninitialized?

---

3️⃣ Implicit type conversion
```c
#include <stdio.h>
int main() {
    int a = 5;
    float b = 2;
    float result = a / b;
    printf("%f\n", result);
    return 0;
}
```
Q: Why does `a / b` not give a decimal result unless one is a float literal?

---

4️⃣ Explicit type casting
```c
#include <stdio.h>
int main() {
    int a = 5, b = 2;
    float result = (float)a / b;
    printf("%f\n", result);
    return 0;
}
```
Q: What changes if you remove `(float)`?

---

5️⃣ Type modifiers
```c
#include <stdio.h>
int main() {
    short s = 32767;
    unsigned short us = 65535;
    printf("s=%d us=%u\n", s, us);
    return 0;
}
```
Q: What happens if you increase `s` or `us` by 1?

---

6️⃣ Sizeof operator
```c
#include <stdio.h>
int main() {
    printf("int=%zu float=%zu double=%zu char=%zu\n",
           sizeof(int), sizeof(float), sizeof(double), sizeof(char));
    return 0;
}
```
Q: Does `sizeof` depend on your compiler or machine?

---

7️⃣ Overflow behavior
```c
#include <stdio.h>
int main() {
    unsigned int x = 4294967295;
    x = x + 1;
    printf("%u\n", x);
    return 0;
}
```
Q: Why does `x` become 0 after incrementing?

---

8️⃣ Character variables
```c
#include <stdio.h>
int main() {
    char ch = 'A';
    printf("%c %d\n", ch, ch);
    return 0;
}
```
Q: Why does printing `ch` with `%d` show a number?

---

9️⃣ ASCII manipulation
```c
#include <stdio.h>
int main() {
    char ch = 'a';
    ch = ch - 32;
    printf("%c\n", ch);
    return 0;
}
```
Q: What is printed, and why does subtracting 32 change case?

---

🔟 Global vs local variables
```c
#include <stdio.h>
int x = 10;
int main() {
    int x = 5;
    printf("%d\n", x);
    return 0;
}
```
Q: Which variable takes precedence — local or global?

---

11️⃣ Shadowing variables
```c
#include <stdio.h>
int main() {
    int a = 10;
    {
        int a = 20;
        printf("%d\n", a);
    }
    printf("%d\n", a);
    return 0;
}
```
Q: What values are printed and why?

---

12️⃣ Static variable behavior
```c
#include <stdio.h>
void counter() {
    static int count = 0;
    count++;
    printf("%d ", count);
}
int main() {
    counter();
    counter();
    counter();
    return 0;
}
```
Q: Why does `count` keep its value between function calls?

---

13️⃣ Automatic (local) variable behavior
```c
#include <stdio.h>
void counter() {
    int count = 0;
    count++;
    printf("%d ", count);
}
int main() {
    counter();
    counter();
    counter();
    return 0;
}
```
Q: How does this differ from the previous static version?

---

14️⃣ External variable use
```c
#include <stdio.h>

int num = 10;
void printNum() {
    printf("%d\n", num);
}

int main() {
    printNum();
    return 0;
}
```
Q: What keyword allows `num` to be used across multiple files?

---

15️⃣ Constant variable
```c
#include <stdio.h>
int main() {
    const int x = 100;
    printf("%d\n", x);
    // x = 200; // Uncomment this line
    return 0;
}
```
Q: What happens if you try to modify a `const` variable?

---

16️⃣ #define constant
```c
#include <stdio.h>
#define PI 3.14
int main() {
    printf("%.2f\n", PI);
    return 0;
}
```
Q: How is `#define` different from `const`?

---

17️⃣ Mixed type arithmetic
```c
#include <stdio.h>
int main() {
    int i = 5;
    float f = 2.5;
    double result = i + f;
    printf("%lf\n", result);
    return 0;
}
```
Q: Which variable type determines the final precision?

---

18️⃣ Type promotion in expressions
```c
#include <stdio.h>
int main() {
    char a = 10, b = 20;
    int c = a + b;
    printf("%d\n", c);
    return 0;
}
```
Q: Why is the result an `int`, not a `char`?

---

19️⃣ Variable scope in loops
```c
#include <stdio.h>
int main() {
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
    }
    // printf("%d", i); // Uncomment
    return 0;
}
```
Q: What happens if you try to access `i` outside the loop?

---

20️⃣ Typecasting challenge
```c
#include <stdio.h>
int main() {
    int x = 5;
    int y = 2;
    double result = x / y;
    printf("%lf\n", result);
    result = (double)x / y;
    printf("%lf\n", result);
    return 0;
}
```
Q: Why do the two results differ?
