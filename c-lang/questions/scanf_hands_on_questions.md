# scanf() Hands-On Practice Questions

1️⃣ Basic integer input
```c
#include <stdio.h>
int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    printf("You entered: %d\n", x);
    return 0;
}
```
Q: What happens if you enter a decimal value like `12.5`?

---

2️⃣ Reading multiple integers
```c
#include <stdio.h>
int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
```
Q: What if you input values separated by commas instead of spaces?

---

3️⃣ Float input
```c
#include <stdio.h>
int main() {
    float f;
    printf("Enter a float: ");
    scanf("%f", &f);
    printf("You entered: %.2f\n", f);
    return 0;
}
```
Q: What if you input `123` (no decimal point)?

---

4️⃣ Double input
```c
#include <stdio.h>
int main() {
    double d;
    printf("Enter a double: ");
    scanf("%lf", &d);
    printf("Value: %lf\n", d);
    return 0;
}
```
Q: What happens if you mistakenly use `%f` instead of `%lf` for a double?

---

5️⃣ Character input
```c
#include <stdio.h>
int main() {
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    printf("You typed: %c\n", c);
    return 0;
}
```
Q: What happens if you input multiple characters (like `ABC`)?

---

6️⃣ Character input with whitespace handling
```c
#include <stdio.h>
int main() {
    char c1, c2;
    printf("Enter two characters: ");
    scanf("%c %c", &c1, &c2);
    printf("Chars: %c and %c\n", c1, c2);
    return 0;
}
```
Q: What happens if you press Enter between characters?

---

7️⃣ Using space before %c
```c
#include <stdio.h>
int main() {
    char c1, c2;
    printf("Enter two characters: ");
    scanf("%c %c", &c1, &c2);
    printf("Without leading space: %c %c\n", c1, c2);

    printf("Enter two characters again: ");
    scanf(" %c %c", &c1, &c2);
    printf("With leading space: %c %c\n", c1, c2);
    return 0;
}
```
Q: Why does adding a space before `%c` change behavior?

---

8️⃣ String input without width limit
```c
#include <stdio.h>
int main() {
    char name[10];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    return 0;
}
```
Q: What happens if you enter a very long name (e.g., “Christopher”)?

---

9️⃣ String with width limit
```c
#include <stdio.h>
int main() {
    char name[10];
    printf("Enter your name: ");
    scanf("%9s", name);
    printf("Hello, %s!\n", name);
    return 0;
}
```
Q: What does the `9` in `%9s` do?

---

🔟 Multiple data types
```c
#include <stdio.h>
int main() {
    int id;
    float score;
    char grade;
    printf("Enter ID, Score, Grade: ");
    scanf("%d %f %c", &id, &score, &grade);
    printf("ID=%d Score=%.2f Grade=%c\n", id, score, grade);
    return 0;
}
```
Q: What happens if you input `101 87.5 A`? What if you press Enter after each?

---

11️⃣ Scanset basics
```c
#include <stdio.h>
int main() {
    char word[20];
    printf("Enter a word (stop at x): ");
    scanf("%[^x]", word);
    printf("You typed: %s\n", word);
    return 0;
}
```
Q: What does `%[^x]` mean in scanf?

---

12️⃣ Scanset including spaces
```c
#include <stdio.h>
int main() {
    char line[30];
    printf("Enter a sentence (stop at !): ");
    scanf("%[^!]", line);
    printf("Captured: %s\n", line);
    return 0;
}
```
Q: What happens when you input “Hello world!”?

---

13️⃣ Suppression operator
```c
#include <stdio.h>
int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%*d %d", &y);
    printf("Only second value stored: %d\n", y);
    return 0;
}
```
Q: What does `%*d` do?

---

14️⃣ Using %n to count input length
```c
#include <stdio.h>
int main() {
    int a, count;
    printf("Enter a number: ");
    scanf("%d%n", &a, &count);
    printf("You typed %d and scanf processed %d characters.\n", a, count);
    return 0;
}
```
Q: What does `%n` store into `count`?

---

15️⃣ Mixing scanf and gets (unsafe example)
```c
#include <stdio.h>
int main() {
    char str[20];
    int x;
    printf("Enter number: ");
    scanf("%d", &x);
    printf("Enter string: ");
    gets(str); // unsafe, do not use in real code
    printf("x=%d str=%s\n", x, str);
    return 0;
}
```
Q: What happens to `gets()` after using `scanf()`?

---

16️⃣ Mixing scanf and fgets (safe example)
```c
#include <stdio.h>
int main() {
    char str[20];
    int x;
    printf("Enter number: ");
    scanf("%d", &x);
    getchar(); // consume newline
    printf("Enter string: ");
    fgets(str, 20, stdin);
    printf("x=%d str=%s\n", x, str);
    return 0;
}
```
Q: Why is `getchar()` used here?

---

17️⃣ Wrong format specifier test
```c
#include <stdio.h>
int main() {
    int i;
    printf("Enter a number: ");
    scanf("%f", &i);
    printf("i = %d\n", i);
    return 0;
}
```
Q: What happens if you enter a number here?

---

18️⃣ Input overflow with scanf
```c
#include <stdio.h>
int main() {
    char str[5];
    printf("Enter text: ");
    scanf("%s", str);
    printf("You entered: %s\n", str);
    return 0;
}
```
Q: What happens if you input more than 4 characters?

---

19️⃣ Reading until newline
```c
#include <stdio.h>
int main() {
    char text[50];
    printf("Enter a sentence: ");
    scanf("%[^
]", text);
    printf("You typed: %s\n", text);
    return 0;
}
```
Q: What does `%[^
]` do in scanf()?

---

20️⃣ Combination challenge
```c
#include <stdio.h>
int main() {
    int id;
    char name[20];
    float marks;
    printf("Enter ID Name Marks: ");
    scanf("%d %19s %f", &id, name, &marks);
    printf("ID=%d, Name=%s, Marks=%.2f\n", id, name, marks);
    return 0;
}
```
Q: What happens if name contains a space (e.g., "John Doe")?
