# Conditional Statements — Hands-On Practice

## 1️⃣ Basic if

```c
#include <stdio.h>
int main() {
    int a = 10;
    if(a > 5) {
        printf("Greater than 5\n");
    }
    return 0;
}
```

**Q:** What will be printed if a is 3?

---

## 2️⃣ If-else

```c
#include <stdio.h>
int main() {
    int a = 10;
    if(a % 2 == 0) {
        printf("Even\n");
    } else {
        printf("Odd\n");
    }
    return 0;
}
```

**Q:** What is printed when a is 7?

---

## 3️⃣ If-else if-else

```c
#include <stdio.h>
int main() {
    int marks = 85;
    if(marks >= 90) {
        printf("A\n");
    } else if(marks >= 75) {
        printf("B\n");
    } else {
        printf("C\n");
    }
    return 0;
}
```

**Q:** What grade is printed for marks = 70?

---

## 4️⃣ Nested if

```c
#include <stdio.h>
int main() {
    int a = 10, b = 5;
    if(a > 0) {
        if(b > 0) {
            printf("Both positive\n");
        }
    }
    return 0;
}
```

**Q:** What happens if a = -10 and b = 5?

---

## 5️⃣ Comparison of two numbers

```c
#include <stdio.h>
int main() {
    int x = 20, y = 30;
    if(x > y) {
        printf("x is greater\n");
    } else {
        printf("y is greater\n");
    }
    return 0;
}
```

**Q:** Predict the output when x = 30, y = 30.

---

## 6️⃣ Maximum of three numbers

```c
#include <stdio.h>
int main() {
    int a = 10, b = 20, c = 15;
    int max;
    if(a > b) {
        if(a > c) max = a;
        else max = c;
    } else {
        if(b > c) max = b;
        else max = c;
    }
    printf("%d\n", max);
    return 0;
}
```

**Q:** What is printed for a=25, b=25, c=10?

---

## 7️⃣ Switch statement basic

```c
#include <stdio.h>
int main() {
    int day = 3;
    switch(day) {
        case 1: printf("Mon\n"); break;
        case 2: printf("Tue\n"); break;
        case 3: printf("Wed\n"); break;
        default: printf("Other\n");
    }
    return 0;
}
```

**Q:** What is printed if day = 5?

---

## 8️⃣ Switch without break

```c
#include <stdio.h>
int main() {
    int x = 2;
    switch(x) {
        case 1: printf("One "); 
        case 2: printf("Two "); 
        case 3: printf("Three "); 
        default: printf("Default ");
    }
    return 0;
}
```

**Q:** Predict the output. Why?

---

## 9️⃣ Nested switch

```c
#include <stdio.h>
int main() {
    int a = 1, b = 2;
    switch(a) {
        case 1: 
            switch(b) {
                case 2: printf("Inside nested\n"); break;
            }
            break;
        default: printf("Default\n");
    }
    return 0;
}
```

**Q:** What happens if b = 3?

---

## 🔟 Using logical operators in if

```c
#include <stdio.h>
int main() {
    int x = 5, y = 10;
    if(x > 0 && y > 0) {
        printf("Both positive\n");
    }
    return 0;
}
```

**Q:** Predict output when x=-5, y=10.

---

## 1️⃣1️⃣ If with OR operator

```c
#include <stdio.h>
int main() {
    int x = 0, y = 1;
    if(x == 0 || y == 0) {
        printf("At least one zero\n");
    }
    return 0;
}
```

**Q:** Predict output when x=2, y=2.

---

## 1️⃣2️⃣ Ternary operator in conditional

```c
#include <stdio.h>
int main() {
    int a = 10, b = 20;
    int max = (a > b) ? a : b;
    printf("%d\n", max);
    return 0;
}
```

**Q:** Predict the output for a=30, b=15.

---

## 1️⃣3️⃣ Nested if with logical operator

```c
#include <stdio.h>
int main() {
    int x = 5, y = -5;
    if(x > 0) {
        if(y > 0) printf("Both positive\n");
        else printf("Only x positive\n");
    }
    return 0;
}
```

**Q:** What is printed?

---

## 1️⃣4️⃣ Switch with character

```c
#include <stdio.h>
int main() {
    char ch = 'B';
    switch(ch) {
        case 'A': printf("Apple\n"); break;
        case 'B': printf("Banana\n"); break;
        default: printf("Other\n");
    }
    return 0;
}
```

**Q:** Predict output when ch='C'.

---

## 1️⃣5️⃣ Multiple case labels

```c
#include <stdio.h>
int main() {
    int grade = 85;
    switch(grade/10) {
        case 10:
        case 9: printf("A\n"); break;
        case 8: printf("B\n"); break;
        default: printf("C\n");
    }
    return 0;
}
```

**Q:** What is printed when grade=95?

---

## 1️⃣6️⃣ If without braces

```c
#include <stdio.h>
int main() {
    int a = 10;
    if(a > 5) 
        printf("Greater "); 
        printf("Check\n");
    return 0;
}
```

**Q:** Predict output. Why does it print both lines?

---

## 1️⃣7️⃣ Switch with fall-through

```c
#include <stdio.h>
int main() {
    int x = 1;
    switch(x) {
        case 1: printf("One "); 
        case 2: printf("Two "); 
        case 3: printf("Three "); break;
    }
    return 0;
}
```

**Q:** Predict output. Explain fall-through behavior.

---

## 1️⃣8️⃣ Conditional assignment with if-else

```c
#include <stdio.h>
int main() {
    int num;
    scanf("%d", &num);
    if(num % 2 == 0) printf("Even\n");
    else printf("Odd\n");
    return 0;
}
```

**Q:** What is printed for input 7? For input 0?

---

## 1️⃣9️⃣ Nested if-else for eligibility

```c
#include <stdio.h>
int main() {
    int age = 20;
    int hasID = 1;
    if(age >= 18) {
        if(hasID) printf("Eligible\n");
        else printf("Need ID\n");
    } else {
        printf("Not eligible\n");
    }
    return 0;
}
```

**Q:** Predict output for age=16, hasID=1 and age=20, hasID=0.

---

## 2️⃣0️⃣ Switch with default only

```c
#include <stdio.h>
int main() {
    int choice = 5;
    switch(choice) {
        default: printf("Invalid option\n");
    }
    return 0;
}
```

**Q:** What is printed? What happens if choice=1?