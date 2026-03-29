
## 1. What Do You Mean by Python Memory Model?

**Python Memory Model** is the study of how the Python interpreter manages memory while executing a program.

It explains:
- How variables are stored
- How objects are created and destroyed
- How memory is allocated and deallocated
- How function calls are handled internally

### Simple Definition
> The Python memory model describes how Python stores data, manages objects, and allocates memory during program execution.

---

## 2. Why Is Learning the Python Memory Model Important?

1. Helps in writing **efficient and optimized code**
2. Prevents **unexpected bugs** caused by mutability
3. Improves understanding of **how Python works internally**
4. Helps in **interviews and competitive exams**
5. Enables better use of memory-intensive data structures

---

## 3. Python Memory Layout (Comparison with C)

### C Language Memory Segments
In C, memory is divided into multiple segments:
- Code Segment
- Data Segment
- BSS Segment
- Heap
- Stack

### Python Memory Segments
Python simplifies this model and mainly divides memory into **two segments**:

1. **Stack Memory**
2. **Heap Memory**

---

## 4. Stack Memory

### Characteristics
- Used for **static memory allocation**
- Stores:
  - Function calls
  - Local variables
  - References (names pointing to objects)
- Each function call creates a **stack frame**
- Stack frame is destroyed when the function returns

### Example
```python
def func():
    x = 10
```

Here:
- `x` (reference) is stored in the **stack**
- The actual object `10` is stored in the **heap**

---

## 5. Heap Memory

### Characteristics
- Used for **dynamic memory allocation**
- Stores **all Python objects**
- Objects remain in memory as long as they are referenced

### Objects Stored in Heap
- Integers
- Strings
- Lists
- Tuples
- Dictionaries
- Sets
- Custom class objects

### Example
```python
x = 10
```

- `x` → reference stored in stack
- `10` → object stored in heap with:
  - Type information
  - Actual value
  - Reference count

---

## 6. What Do You Mean by an Object?

An **object** is a block of memory allocated in the heap.

Each Python object contains:
- **Type information** (int, list, str, etc.)
- **Actual data**
- **Reference count**

> In Python, everything is an object.

---

## 7. Reference Counting

### Definition
**Reference counting** is Python’s primary memory management technique.

It keeps track of:
- How many references point to an object

### How It Works
- Reference count increases when:
  - A new variable points to the object
- Reference count decreases when:
  - A variable is deleted
  - A reference goes out of scope

### Example
```python
a = 10
b = a
```

- Object `10` has reference count = 2

```python
del a
```

- Reference count decreases to 1

When reference count becomes **zero**, the object is **automatically destroyed**.

---

## 8. Garbage Collection (GC)

Reference counting alone cannot handle **circular references**.

Python uses a **Garbage Collector** to:
- Detect cyclic references
- Free unused memory automatically

Example:
```python
a = []
a.append(a)
```

Garbage Collector handles this situation.

---

## 9. Memory Allocation in Python

Python uses a **private heap space** managed by the interpreter.

### Memory Management Layers
1. **Python Memory Manager**
2. **Object-specific allocators**
3. **OS-level memory allocation**

Small objects are managed efficiently using:
- **Pymalloc** (Python’s internal allocator)

---

## 10. Mutability vs Immutability

Mutability determines whether an object’s value can be changed after creation.

---

## 11. Immutable Objects

### Definition
Immutable objects **cannot be changed** after creation.

Any modification:
- Creates a **new object**
- Changes the memory address

### Examples
- `int`
- `float`
- `bool`
- `str`
- `tuple`
- `frozenset`

### Example
```python
x = 10
x = x + 1
```

- A new object `11` is created
- `x` now points to the new object

---

## 12. Mutable Objects

### Definition
Mutable objects can be **modified in place**.

### Examples
- `list`
- `dict`
- `set`
- `bytearray`

### Example
```python
lst = [1, 2]
lst.append(3)
```

- Same object is modified
- Memory address remains the same

---

## 13. Mutable vs Immutable Comparison

| Feature | Immutable | Mutable |
|------|----------|---------|
| Value change | ❌ Not allowed | ✅ Allowed |
| Memory behavior | New object created | Same object modified |
| Examples | int, str, tuple | list, dict, set |
| Dictionary key | ✅ Allowed | ❌ Not allowed |

---

## 14. Key Takeaways

- Variables store **references**, not actual data
- Objects live in the **heap**
- Stack stores **references and function calls**
- Reference counting + garbage collection manage memory
- Understanding mutability prevents logical errors

---

## 15. Exam-Oriented Conclusion

> The Python memory model explains how Python allocates memory, manages objects using reference counting and garbage collection, and differentiates between mutable and immutable objects.

---

*Prepared, verified, and enhanced for academic submission.*
