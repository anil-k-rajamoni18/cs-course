# C Programming: Looping Statements Q&A

## Q1: Basic For Loop
**Question:** What is printed?
```c
#include <stdio.h>
int main() {
    for(int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    return 0;
}
```

**Answer:** The given loop runs for 5 iterations (for i=0,1,2,3,4). For each iteration it is going to print i value with space and final output is `0 1 2 3 4`. Here we used increment of i.

---

## Q2: For Loop with Decrement
**Question:** Predict the output?
```c
#include <stdio.h>
int main() {
    for(int i = 5; i > 0; i--) {
        printf("%d ", i);
    }
    return 0;
}
```

**Answer:** The given loop runs for 5 iterations (for i=5,4,3,2,1). For each iteration it is going to print i value with space and final output is `5 4 3 2 1`. Here we used decrement of i.

---

## Q3: For Loop with Custom Increment
**Question:** What is printed?
```c
#include <stdio.h>
int main() {
    for(int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    return 0;
}
```

**Answer:** By seeing initialisation and condition we think that loop might run for 11 iteration but loop will run for 6 iterations only (for i=0,2,4,6,8,10) because we are incrementing i with 2. For each iterations it prints i value with space finally output is `0 2 4 6 8 10`.

---

## Q4: Nested For Loops
**Question:** Predict the output?
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

**Answer:** The aim given program is to print two digit numbers, for this we used nested loops concept. Here outer loop is used for printing 10s place digit (For i= 1,2,3). Inner loop is used for printing units place (for j=1,2). Inner loop runs completely for each iteration of first loop. That is for i=1,2 and 3 second loop runs two times (j=1,2). Finally output is `11 12 21 22 31 32`.

---

## Q5: Multiple Variables in For Loop
**Question:** What is printed?
```c
#include <stdio.h>
int main() {
    for(int i = 0, j = 5; i <= 5; i++, j--) {
        printf("%d-%d ", i, j);
    }
    return 0;
}
```

**Answer:** In this program we initialised i=0, j=5 and loop runs 6 iterations. After each iteration we simultaneously incrementing i and decrementing j by 1 value. Finally output is `0-5 1-4 2-3 3-2 4-1 5-0`.

**Note:** In printf statement if add newline(\n) it seems to good and output will be:
```
0-5
1-4
2-3
3-2
4-1
5-0
```

---

## Q6: Basic While Loop
**Question:** Predict output?
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

**Answer:** This loop will run if i<5 only and it runs for 5 iterations. In iteration we printing i value and simultaneously incrementing i with 1. Finally output is `0 1 2 3 4`.

**Note:** 
- Before using while loop first initializes all variables.
- Do not forget to increment or decrement variable used in condition.

---

## Q7: Infinite While Loop (Bug)
**Question:** What happens and why?
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

**Answer:** Here we can observe that loop will run for infinite times because we forgot increment i value so for each iteration i value remains i.e 0 and i<3 condition is always true so loop runs for infinite times and prints 0 for each iteration.

**Note:** Following is corrected code:
```c
#include <stdio.h>
int main() {
    int i = 0;
    while(i < 3) {
        printf("%d ", i);
        i++;
    }
    return 0;
}
```

---

## Q8: Do-While Loop
**Question:** Predict output?
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

**Answer:** Here we using another type of loop i.e do-while. This loop is going to run at least one time in code execution. Comparing to remaining loop it is some what different because other loops before code executed checks the condition but this loop checks after each iteration. Finally output is `0 1 2 3 4`.

---

## Q9: Do-While Loop (Single Execution)
**Question:** What is printed?
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

**Answer:** As we know that this loop is going to run for at least one time i.e printing 5 after that i is incremented to 6 since condition is false loop will be terminated.

---

## Q10: Infinite For Loop with Break
**Question:** What happens and why?
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

**Answer:** The given loop will run for infinite times since there is no condition for loop termination. However, the break statement terminates the loop after the first iteration, so it prints `Loop ` only once.

---

## Q11: Break Statement in For Loop
**Question:** Predict the output?
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

**Answer:** 

**Keywords Overview:**
- **break:** Can be used in both loops and switch. Skips all remaining iterations and terminates the loop.
- **continue:** Can be used only in loops, not in switch. Moves to next iteration directly.

Just by looking at condition in for loop we might think that loop runs for 5 iterations but actually it runs only for 3 times (for i=0,1,2). You may confuse why it not for i=3,4 because in code it is given that when i=3 break so after reaching i=3 loop will be terminated and finally output is `0 1 2`.

---

## Q12: Continue Statement in For Loop
**Question:** What is printed?
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

**Answer:** 

**Keywords Overview:**
- **break:** Can be used in both loops and switch. Skips all remaining iterations and terminates the loop.
- **continue:** Can be used only in loops, not in switch. Moves to next iteration directly.

Here actually loop should run for 5 iterations but it runs only four iterations because of usage continue when i==2 so it skips that iteration and moves i=3 and so on. Finally output is `0 1 3 4`.

---

## Q13: Break in Nested Loops
**Question:** Predict output?
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

**Answer:** We might output as `11 12 13 21 22 23 31 32 33` but output is `11 21 31`. This is because of usage of break statement when j=2 so it skips second loop for iteration j=2,3. Outer loop runs for 3 iterations and inner loop runs only one time for each iteration of outer loop.

Instead of break if we use continue then second loop will be skipped only for j=2 and runs 2 times output is `11 13 21 23 31 33`.

---

## Q14: Continue in Nested Loops
**Question:** Predict output?
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

**Answer:** Here output is `11 13 21 23`. When j=2 we used continue statement so compiler will skip iteration when j==2 and moves j=3.

---

## Q15: Sum Using For Loop
**Question:** What is printed?
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

**Answer:** The given loop runs for 5 iterations (for i=1,2,3,4,5). Initially we initialised sum =0 and for each iteration of loop sum going to added with i value and resulted value again assigned to sum i.e sum=sum+i. Finally output will be sum of first 5 natural numbers i.e `15`.

---

## Q16: Multiplication Table
**Question:** Predict the output?
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

**Answer:** By seeing code we can say that output will be value resulted when i*j. Here outer and inner loop runs for 3 iterations. Inner loop runs 3 times for each iteration of outer loop ex: for i=1 j will be 1,2,3 and similar for i=2,3. Here we can observe that there is printf("\n"); its role is move to new line after each iteration of outer loop. Finally output is:
```
1 2 3 
2 4 6 
3 6 9
```

---

## Q17: While Loop with Logical Operator
**Question:** What is printed?
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

**Answer:** Here output is `1-5 2-4`. In loop we have used logical operator i.e && it returns boolean value only. It returns 1 when both its operands are 1 otherwise 0.

---

## Q18: Do-While with Decrement
**Question:** Predict output?
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

**Answer:** Here output will be `3 2 1`.

---

## Q19: While Loop with Break
**Question:** Predict output?
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

**Answer:** Here output is `0 1 2`.

---

## Q20: While Loop with Continue
**Question:** What is printed?
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

**Answer:** Here output is `1 3 4 5`. Here it skips printing 2 because when i=2 we used continue.