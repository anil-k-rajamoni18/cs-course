# C Programming: Conditional Statements Examples

## Example 1 – Simple if condition

```c
#include <stdio.h>
int main() {
    int a = 10;
    if (a > 5) {
        printf("Greater than 5\n");
    }
    return 0;
}
```

**Explanation:**
- **Condition:** `a > 5`
- For `a = 10`: True → prints "Greater than 5"
- For `a = 3`: False → nothing is printed (no else block)

---

## Example 2 – if–else condition

```c
#include <stdio.h>
int main() {
    int a = 10;
    if (a % 2 == 0) {
        printf("Even\n");
    } else {
        printf("Odd\n");
    }
    return 0;
}
```

**Explanation:**
- **Condition:** `a % 2 == 0`
- `a = 10`: True → prints "Even"
- `a = 7`: False → prints "Odd"

**Notes:**
- The `else` block executes only if the `if` condition is false.
- If there's no `else`, nothing happens when the condition fails.

**Example:**
- `a = 6` → Even
- `a = 5` → Odd

---

## Example 3 – Grading using else if ladder

```c
#include <stdio.h>
int main() {
    int marks = 85;
    if (marks >= 90) printf("A\n");
    else if (marks >= 75) printf("B\n");
    else printf("C\n");
    return 0;
}
```

**Output:**
- For `marks = 85` → B
- For `marks = 70` → C

---

## Example 4 – Nested if

```c
#include <stdio.h>
int main() {
    int a = 10, b = 5;
    if (a > 0) {
        if (b > 0) {
            printf("Both positive\n");
        }
    }
    return 0;
}
```

**Output:**
- `a = 10, b = 5` → Both positive
- `a = -10, b = 5` → No output (first condition fails)

---

## Example 5 – Comparing two numbers

```c
#include <stdio.h>
int main() {
    int x = 20, y = 30;
    if (x > y) printf("x is greater\n");
    else printf("y is greater\n");
    return 0;
}
```

**Output:**
- `x = 20, y = 30` → y is greater
- `x = 30, y = 30` → y is greater, because no equality condition was checked.

**Improved version:**

```c
if (x == y)
    printf("Both are equal\n");
else if (x > y)
    printf("x is greater\n");
else
    printf("y is greater\n");
```

---

## Example 6 – Find the largest number

```c
#include <stdio.h>
int main() {
    int a = 10, b = 20, c = 15;
    int max;
    if (a > b) {
        if (a > c) max = a;
        else max = c;
    } else {
        if (b > c) max = b;
        else max = c;
    }
    printf("%d\n", max);
    return 0;
}
```

**Output:**
- `a=10, b=20, c=15` → 20
- `a=25, b=25, c=10` → 25

---

## Example 7 – Basic switch case

```c
int day = 3;
switch(day) {
    case 1: printf("Mon\n"); break;
    case 2: printf("Tue\n"); break;
    case 3: printf("Wed\n"); break;
    default: printf("Other\n");
}
```

**Output:**
- `day = 3` → Wed
- `day = 5` → Other

**Notes:**
- `break` prevents fall-through.
- `continue` is used only in loops, not switch.

---

## Example 8 – Missing break

```c
int x = 2;
switch(x) {
    case 1: printf("One ");
    case 2: printf("Two ");
    case 3: printf("Three ");
    default: printf("Default ");
}
```

**Output:** `Two Three Default`

**Reason:** Without `break`, all subsequent cases execute ("fall-through behavior").

---

## Example 9 – Nested switch

```c
int a = 1, b = 2;
switch(a) {
    case 1:
        switch(b) {
            case 2: printf("Inside nested\n"); break;
        }
        break;
    default: printf("Default\n");
}
```

**Output:**
- `a=1, b=2` → Inside nested
- `a=1, b=3` → No output (inner switch has no case 3)

---

## Example 10 – Logical AND (&&)

```c
int x = 5, y = 10;
if (x > 0 && y > 0) {
    printf("Both positive\n");
}
```

**Output:**
- `x=5, y=10` → Both positive
- `x=-5, y=10` → No output (first condition false)

**Notes:**
- `&&` (AND): true if both are true
- `||` (OR): true if at least one is true
- `!` (NOT): reverses condition

**Example:**

```c
int a = 9;
printf("%d", !a); // prints 0 because a is non-zero (true)
```

---

## Example 11 – Logical OR (||)

```c
if (x == 0 || y == 0)
    printf("At least one zero\n");
```

**Output:**
- `x=0, y=1` → prints "At least one zero"
- `x=2, y=2` → no output (both false)

---

## Example 12 – Ternary Operator

```c
int max = (a > b) ? a : b;
printf("%d\n", max);
```

**Output:**
- `a=10, b=20` → 20
- `a=30, b=15` → 30

**Explanation:**
- `E1 ? E2 : E3` means:
  - If E1 is true → execute E2
  - Else → execute E3

---

## Example 13 – Nested if-else

```c
int x = 5, y = -5;
if (x > 0) {
    if (y > 0) printf("Both positive\n");
    else printf("Only x positive\n");
}
```

**Output:** `Only x positive`

---

## Example 14 – Character switch

```c
char ch = 'B';
switch(ch) {
    case 'A': printf("Apple\n"); break;
    case 'B': printf("Banana\n"); break;
    default: printf("Other\n");
}
```

**Output:**
- `ch = 'B'` → Banana
- `ch = 'C'` → Other

---

## Example 15 – Switch with arithmetic

```c
int grade = 85;
switch(grade / 10) {
    case 10:
    case 9: printf("A\n"); break;
    case 8: printf("B\n"); break;
    default: printf("C\n");
}
```

**Output:**
- `grade=85` → B
- `grade=95` → A

**Explanation:**
- `grade/10` uses integer division, so `85/10 = 8`, not 8.5.

---

## Example 16 – Missing braces {}

```c
int a = 10;
if (a > 5)
    printf("Greater ");
printf("Check\n");
```

**Output:** `Greater Check`

**Reason:** Only the first statement belongs to the if.

**Always use braces for clarity:**

```c
if (a > 5) {
    printf("Greater ");
    printf("Check\n");
}
```

---

## Example 17 – Switch fall-through behavior

```c
int x = 1;
switch(x) {
    case 1: printf("One ");
    case 2: printf("Two ");
    case 3: printf("Three "); break;
}
```

**Output:** `One Two Three`

**Reason:** Missing `break` causes fall-through.

---

## Example 18 – Even/Odd using modulus

```c
int num;
scanf("%d", &num);
if (num % 2 == 0) printf("Even\n");
else printf("Odd\n");
```

**Output:**
- Input `7` → Odd
- Input `0` → Even

---

## 💡 Summary Table

| Concept | Example | Key Idea |
|---------|---------|----------|
| Simple if | Example 1 | Executes only when true |
| if–else | Example 2 | Two possible outcomes |
| else if ladder | Example 3 | Multiple conditions |
| Nested if | Example 4 | if inside another if |
| Switch | Example 7 | Case-based selection |
| Logical Operators | Example 10–11 | `&&`, `||` |
| Ternary | Example 12 | Compact if–else |
| Missing braces | Example 16 | Causes logic errors |
| Fall-through | Example 8 & 17 | Occurs without break |