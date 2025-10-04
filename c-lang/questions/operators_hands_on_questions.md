# Operators — Hands-On Practice

1️⃣ Basic arithmetic operators
```c
#include <stdio.h>
int main() {
    int a = 10, b = 3;
    printf("%d %d %d %d %d\n", a + b, a - b, a * b, a / b, a % b);
    return 0;
}
```
Q: What are the outputs? Why is division result truncated?

---

2️⃣ Integer division and promotion
```c
#include <stdio.h>
int main() {
    int a = 5, b = 2;
    float result = a / b;
    printf("%f\n", result);
    return 0;
}
```
Q: Why doesn’t this show 2.5?

---

3️⃣ Pre-increment vs post-increment
```c
#include <stdio.h>
int main() {
    int x = 5;
    printf("%d %d\n", ++x, x++);
    printf("%d\n", x);
    return 0;
}
```
Q: What’s printed and why?

---

4️⃣ Compound assignment
```c
#include <stdio.h>
int main() {
    int a = 5;
    a += 10;
    a *= 2;
    printf("%d\n", a);
    return 0;
}
```
Q: What is the final value of `a`?

---

5️⃣ Relational operators
```c
#include <stdio.h>
int main() {
    int x = 10, y = 20;
    printf("%d %d %d %d %d %d\n",
           x < y, x > y, x <= y, x >= y, x == y, x != y);
    return 0;
}
```
Q: Which expressions evaluate to true (1) and which to false (0)?

---

6️⃣ Logical operators
```c
#include <stdio.h>
int main() {
    int a = 5, b = 0;
    printf("%d %d %d\n", a && b, a || b, !a);
    return 0;
}
```
Q: What does each logical expression evaluate to?

---

7️⃣ Short-circuit logic
```c
#include <stdio.h>
int main() {
    int a = 0, b = 10;
    if (a && ++b)
        printf("Inside if\n");
    printf("b = %d\n", b);
    return 0;
}
```
Q: Why doesn’t `b` increment even though it’s in the condition?

---

8️⃣ Bitwise AND, OR, XOR
```c
#include <stdio.h>
int main() {
    int a = 5, b = 3;
    printf("%d %d %d\n", a & b, a | b, a ^ b);
    return 0;
}
```
Q: What are the bitwise results in binary form?

---

9️⃣ Bitwise NOT
```c
#include <stdio.h>
int main() {
    int x = 5;
    printf("%d\n", ~x);
    return 0;
}
```
Q: What does `~x` do to the bits of `x`?

---

🔟 Left and right shifts
```c
#include <stdio.h>
int main() {
    int a = 5;
    printf("%d %d\n", a << 1, a >> 1);
    return 0;
}
```
Q: What is the effect of shifting bits left and right?

---

11️⃣ Ternary operator
```c
#include <stdio.h>
int main() {
    int x = 10, y = 20;
    int max = (x > y) ? x : y;
    printf("Max = %d\n", max);
    return 0;
}
```
Q: How does the ternary operator replace an `if` statement here?

---

12️⃣ Nested ternary
```c
#include <stdio.h>
int main() {
    int a = 5, b = 7, c = 3;
    int max = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
    printf("%d\n", max);
    return 0;
}
```
Q: How is nesting used to find the largest of three numbers?

---

13️⃣ Operator precedence test
```c
#include <stdio.h>
int main() {
    int x = 10, y = 5;
    int result = x + y * 2;
    printf("%d\n", result);
    return 0;
}
```
Q: Why is multiplication done before addition?

---

14️⃣ Parentheses and precedence
```c
#include <stdio.h>
int main() {
    int x = 10, y = 5;
    int result = (x + y) * 2;
    printf("%d\n", result);
    return 0;
}
```
Q: How does adding parentheses change the output?

---

15️⃣ Assignment chaining
```c
#include <stdio.h>
int main() {
    int a, b, c;
    a = b = c = 10;
    printf("%d %d %d\n", a, b, c);
    return 0;
}
```
Q: How does assignment chaining work internally?

---

16️⃣ Comma operator
```c
#include <stdio.h>
int main() {
    int x = (1, 2, 3);
    printf("%d\n", x);
    return 0;
}
```
Q: Why is only one value assigned to `x` even though there are multiple?

---

17️⃣ Logical vs Bitwise confusion
```c
#include <stdio.h>
int main() {
    int a = 2, b = 0;
    printf("%d %d\n", a && b, a & b);
    return 0;
}
```
Q: How do `&&` and `&` differ in evaluation?

---

18️⃣ Compound expressions
```c
#include <stdio.h>
int main() {
    int a = 2, b = 3, c = 4;
    int result = a + b * c - a / b;
    printf("%d\n", result);
    return 0;
}
```
Q: Which operator executes first?

---

19️⃣ Increment and assignment order
```c
#include <stdio.h>
int main() {
    int x = 5;
    int y = x++ + ++x;
    printf("x=%d y=%d\n", x, y);
    return 0;
}
```
Q: What is printed and why? (Think about sequence points.)

---

20️⃣ Mixed operator challenge
```c
#include <stdio.h>
int main() {
    int a = 10, b = 5, c = 2;
    int result = a > b && b > c ? a + b * c : a - b / c;
    printf("%d\n", result);
    return 0;
}
```
Q: How are precedence and short-circuiting combined here?
