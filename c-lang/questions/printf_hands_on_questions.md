## printf() Hands-On Practice Questions

1️⃣ Simple integer printing
```c
#include <stdio.h>
int main() {
    int x = 25;
    printf("%d\n", x);
    printf("%5d\n", x);
    printf("%05d\n", x);
    printf("%-5dEnd\n", x);
    return 0;
}
```
Q: What does each line print?  


---

2️⃣ Unsigned and hexadecimal
```c
#include <stdio.h>
int main() {
    unsigned int n = 4294967295;
    printf("%u\n", n);
    printf("%x\n", n);
    printf("%X\n", n);
    printf("%#x\n", n);
    return 0;
}
```
Q: What’s the difference between `%x`, `%X`, and `%#x`?

---

3️⃣ Character and ASCII
```c
#include <stdio.h>
int main() {
    char ch = 'A';
    printf("%c\n", ch);
    printf("%d\n", ch);
    printf("%3c\n", ch);
    printf("%-3cEnd\n", ch);
    return 0;
}
```
Q: What happens when you print a char using `%d`?

---

4️⃣ Decimal precision
```c
#include <stdio.h>
int main() {
    float pi = 3.1415926;
    printf("%f\n", pi);
    printf("%.2f\n", pi);
    printf("%8.3f\n", pi);
    printf("%-8.3fEnd\n", pi);
    return 0;
}
```
Q: What do width and precision control?

---

5️⃣ Exponential vs normal
```c
#include <stdio.h>
int main() {
    double x = 12345.6789;
    printf("%e\n", x);
    printf("%E\n", x);
    printf("%g\n", x);
    printf("%G\n", x);
    return 0;
}
```
Q: When does `%g` switch from `%f` to `%e`?

---

6️⃣ String width and truncation
```c
#include <stdio.h>
int main() {
    char str[] = "Hello";
    printf("[%s]\n", str);
    printf("[%10s]\n", str);
    printf("[%-10s]\n", str);
    printf("[%.3s]\n", str);
    printf("[%10.3s]\n", str);
    return 0;
}
```
Q: What happens when you combine width and precision for strings?

---

7️⃣ Pointer addresses
```c
#include <stdio.h>
int main() {
    int a = 10;
    int *p = &a;
    printf("Address of a: %p\n", &a);
    printf("Value of p:   %p\n", p);
    printf("Value via p:  %d\n", *p);
    return 0;
}
```
Q: What does `%p` display?  
Can you use `%x` for a pointer safely?

---

8️⃣ Printing number of characters printed
```c
#include <stdio.h>
int main() {
    int count;
    printf("Hello%nWorld\n", &count);
    printf("Characters before 'World': %d\n", count);
    return 0;
}
```
Q: What does `%n` do, and why should you be cautious with it?

---

9️⃣ Printing different integer sizes
```c
#include <stdio.h>
int main() {
    short s = 32767;
    long l = 1000000;
    long long ll = 1234567890123;
    printf("%hd %ld %lld\n", s, l, ll);
    return 0;
}
```
Q: What happens if you print `short` or `long long` with the wrong specifier?

---

🔟 Dynamic width and precision
```c
#include <stdio.h>
int main() {
    int width = 10, prec = 3;
    double val = 12.34567;
    printf("%*.*f\n", width, prec, val);
    return 0;
}
```
Q: What do the `*` symbols mean in `%*.*f`?

---

🧩 Q11
```c
#include <stdio.h>
int main() {
    printf("%d\n", printf("Hello"));
    return 0;
}
```
Q: What does it print and why?

---

🧩 Q12
```c
#include <stdio.h>
int main() {
    int x = 255;
    printf("%#o %#x %#X\n", x, x, x);
    return 0;
}
```
Q: What does `#` (alternate form) do for octal and hex?

---

1️⃣ Plus (+) flag — always show sign
```c
#include <stdio.h>
int main() {
    int a = 10, b = -10;
    printf("%d %d\n", a, b);
    printf("%+d %+d\n", a, b);
    return 0;
}
```
Q: What does the `+` do? Why might it be helpful in tabular output?

---

2️⃣ Space ( ) flag — reserve sign space
```c
#include <stdio.h>
int main() {
    int a = 10, b = -10;
    printf("% d % d\n", a, b);
    return 0;
}
```
Q: Compare this with the `+` flag. What prints before positive numbers?

---

3️⃣ + vs Space — precedence test
```c
#include <stdio.h>
int main() {
    int a = 15;
    printf("% +d\n", a);
    return 0;
}
```
Q: Which flag wins if both `+` and space are used together?

---

4️⃣ Zero (0) padding
```c
#include <stdio.h>
int main() {
    int a = 42;
    printf("%5d\n", a);
    printf("%05d\n", a);
    printf("%+05d\n", a);
    return 0;
}
```
Q: How does `0` interact with `+`?  
(Hint: the sign always comes first!)

---

5️⃣ Left alignment (-) flag
```c
#include <stdio.h>
int main() {
    int n = 7;
    printf("[%5d]\n", n);
    printf("[%-5d]\n", n);
    printf("[%-05d]\n", n);
    return 0;
}
```
Q: Does `-` override `0`? (What happens in the third line?)

---

6️⃣ Alternate form (#) for octal and hex
```c
#include <stdio.h>
int main() {
    int n = 255;
    printf("%o %x %X\n", n, n, n);
    printf("%#o %#x %#X\n", n, n, n);
    return 0;
}
```
Q: `#` adds prefixes like `0`, `0x`, or `0X`.  
When would this be useful in debugging?

---

7️⃣ # with floating point
```c
#include <stdio.h>
int main() {
    double x = 12.0;
    printf("%g\n", x);
    printf("%#g\n", x);
    return 0;
}
```
Q: What difference does `#` make when printing floats?

---

8️⃣ Combining width, zero, and sign
```c
#include <stdio.h>
int main() {
    int val = -42;
    printf("%08d\n", val);
    printf("%+08d\n", val);
    printf("% 08d\n", val);
    return 0;
}
```
Q: When using width + sign + zero, which comes first — sign or zero padding?

---

9️⃣ Precision and width with floats
```c
#include <stdio.h>
int main() {
    double pi = 3.1415926;
    printf("%8.2f\n", pi);
    printf("%08.2f\n", pi);
    printf("%-8.2fEnd\n", pi);
    return 0;
}
```
Q: What happens when you combine zero-padding and precision?

---

🔟 Flag combo challenge
```c
#include <stdio.h>
int main() {
    int x = 255;
    printf("%#010x\n", x);
    printf("%#-10XEnd\n", x);
    printf("%+10d\n", x);
    return 0;
}
```
Q: Can you explain how each line formats its output differently?
