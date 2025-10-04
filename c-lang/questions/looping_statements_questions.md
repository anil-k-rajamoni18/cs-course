# Looping Statements — Hands-On Practice

## 1️⃣ Basic for loop

```c
#include <stdio.h>
int main() {
    for(int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    return 0;
}
```

**Q:** What is printed?

---

## 2️⃣ For loop with decrement

```c
#include <stdio.h>
int main() {
    for(int i = 5; i > 0; i--) {
        printf("%d ", i);
    }
    return 0;
}
```

**Q:** Predict the output.

---

## 3️⃣ For loop with step > 1

```c
#include <stdio.h>
int main() {
    for(int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    return 0;
}
```

**Q:** What is printed?

---

## 4️⃣ Nested for loop

```c
#include <stdio.h>
int main() {
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 2; j++) {
            printf("%d%d ", i, j);
        }
    }
    return 0;
}
```

**Q:** Predict the output.

---

## 5️⃣ For loop with multiple variables

```c
#include <stdio.h>
int main() {
    for(int i = 0, j = 5; i <= 5; i++, j--) {
        printf("%d-%d ", i, j);
    }
    return 0;
}
```

**Q:** What is printed?

---

## 6️⃣ While loop basic

```c
#include <stdio.h>
int main() {
    int i = 0;
    while(i < 5) {
        printf("%d ", i);
        i++;
    }
    return 0;
}
```

**Q:** Predict output.

---

## 7️⃣ While loop with missing increment

```c
#include <stdio.h>
int main() {
    int i = 0;
    while(i < 3) {
        printf("%d ", i);
    }
    return 0;
}
```

**Q:** What happens? Why?

---

## 8️⃣ Do-while loop basic

```c
#include <stdio.h>
int main() {
    int i = 0;
    do {
        printf("%d ", i);
        i++;
    } while(i < 5);
    return 0;
}
```

**Q:** Predict output.

---

## 9️⃣ Do-while executes at least once

```c
#include <stdio.h>
int main() {
    int i = 5;
    do {
        printf("%d ", i);
        i++;
    } while(i < 5);
    return 0;
}
```

**Q:** What is printed?

---

## 🔟 Infinite loop using for

```c
#include <stdio.h>
int main() {
    for(;;) {
        printf("Loop ");
        break;
    }
    return 0;
}
```

**Q:** What happens and why?

---

## 1️⃣1️⃣ Break in for loop

```c
#include <stdio.h>
int main() {
    for(int i = 0; i < 5; i++) {
        if(i == 3) break;
        printf("%d ", i);
    }
    return 0;
}
```

**Q:** Predict the output.

---

## 1️⃣2️⃣ Continue in for loop

```c
#include <stdio.h>
int main() {
    for(int i = 0; i < 5; i++) {
        if(i == 2) continue;
        printf("%d ", i);
    }
    return 0;
}
```

**Q:** What is printed?

---

## 1️⃣3️⃣ Nested loops with break

```c
#include <stdio.h>
int main() {
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            if(j == 2) break;
            printf("%d%d ", i, j);
        }
    }
    return 0;
}
```

**Q:** Predict output.

---

## 1️⃣4️⃣ Nested loops with continue

```c
#include <stdio.h>
int main() {
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= 3; j++) {
            if(j == 2) continue;
            printf("%d%d ", i, j);
        }
    }
    return 0;
}
```

**Q:** Predict output.

---

## 1️⃣5️⃣ Sum of first N numbers using for

```c
#include <stdio.h>
int main() {
    int sum = 0;
    for(int i = 1; i <= 5; i++) {
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
```

**Q:** What is printed?

---

## 1️⃣6️⃣ Multiplication table using nested for

```c
#include <stdio.h>
int main() {
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            printf("%d ", i*j);
        }
        printf("\n");
    }
    return 0;
}
```

**Q:** Predict the output.

---

## 1️⃣7️⃣ While loop with logical condition

```c
#include <stdio.h>
int main() {
    int x = 1, y = 5;
    while(x < y && y > 0) {
        printf("%d-%d ", x, y);
        x++; y--;
    }
    return 0;
}
```

**Q:** What is printed?

---

## 1️⃣8️⃣ Do-while with decrement

```c
#include <stdio.h>
int main() {
    int i = 3;
    do {
        printf("%d ", i);
        i--;
    } while(i > 0);
    return 0;
}
```

**Q:** Predict output.

---

## 1️⃣9️⃣ Break with while

```c
#include <stdio.h>
int main() {
    int i = 0;
    while(i < 5) {
        if(i == 3) break;
        printf("%d ", i);
        i++;
    }
    return 0;
}
```

**Q:** Predict output.

---

## 2️⃣0️⃣ Continue with while

```c
#include <stdio.h>
int main() {
    int i = 0;
    while(i < 5) {
        i++;
        if(i == 2) continue;
        printf("%d ", i);
    }
    return 0;
}
```

**Q:** What is printed?