# DAY - 1 ASSIGNMENT

## BEGINNER

### 1. Create variables using all basic types (int, float, str, bool, None)

**Code:**
```python
age = 10
money = 12.5
name = "surya"
is_check = True
new = None

# Printing values, type, address
print(age, type(age), id(age))
print(money, type(money), id(money))
print(name, type(name), id(name))
print(is_check, type(is_check), id(is_check))
print(new, type(new), id(new))
```

**Key Concepts:** The `type()` function returns the data type of a variable, while `id()` returns the memory address where the object is stored.

---

### 2. Write a script that takes name and age from input and prints: Hello John, you are 20 years old

**Code:**
```python
name = input("Enter your name : ")
age = int(input("Enter your age : "))  # we need to type cast string to integer since age is integer
print(f"Hello {name}, You are {age} old.")  # Printing required statement using f-string
print("Hello", name, ", you are", age, "old.")  # without f-string
print("Hello {}, you are {} years old".format(name, age))  # str.format
print("Hello %s, you are %d years old" % (name, age))
```

**Key Concepts:** The `input()` function always returns a string, so type casting with `int()` is necessary for numeric operations. F-strings (f"...") provide the most readable string formatting.

---

### 3. Write a script that asks for two numbers and prints the sum

**Code:**
```python
num1 = int(input("Enter first integer : "))
num2 = int(input("Enter second integer : "))
# num1, num2 = map(int, input("Enter the integers").split()) another way to take input
print(f"Sum of {num1} and {num2} is {num1 + num2}")
print("Sum of {} and {} is {}".format(num1, num2, num1 + num2))
print("Sum of %d and %d is %d" % (num1, num2, num1 + num2))
```

**Key Concepts:** The `map()` function applies a function (like `int()`) to each item in an iterable, useful for converting multiple inputs at once.

---

### 4. Store your city name in a variable and print it in uppercase

**Code:**
```python
city = " gwalior "
print(city.upper())  # converts every letter into upper case
print(city.title())  # converts first letter into upper case
print(city.strip())  # removes whitespaces
print(city.replace("g", "G"))
```

**Key Concepts:** String methods like `upper()`, `title()`, `strip()`, and `replace()` are powerful for text manipulation. `strip()` removes leading/trailing whitespace, while `replace()` substitutes characters.

---

### 5. Convert a string number "45" to an integer and multiply by 2

**Code:**
```python
string = "45"
num = int(string)
result = num * 2
print(result)
```

**Key Concepts:** Type conversion using `int()` transforms string representations of numbers into actual integers for mathematical operations.

---

### 6. Ask user for years of experience and print: "Junior" if <2 years else "Senior"

**Code:**
```python
experience = int(input("Enter your experience ; "))
if experience > 2:
    print("You are senior.")
else:
    print("You are junior")
```

**Key Concepts:** Conditional statements (`if-else`) allow programs to make decisions based on conditions, executing different code blocks accordingly.

---

### 7. Calculate the area of a circle (radius from user)

**Code:**
```python
PI = 3.14
radius = float(input("Enter radius of circle : "))
area = PI * radius**2
print(f"Area of circle is {area} sq.units.")
```

**Key Concepts:** The `**` operator performs exponentiation (power operation). `float()` is used for decimal number inputs.

---

### 8. Convert Celsius to Fahrenheit using formula

**Code:**
```python
temp_c = int(input("Enter the temperature in celsius : "))
temp_f = (9/5) * temp_c + 32
print(f"Temperature in fahrenheit is {temp_f}")
```

**Key Concepts:** Mathematical formulas can be directly implemented in Python. Division (`/`) in Python 3 always returns a float.

---

### 9. Print remainder when a user enters a number divided by 7

**Code:**
```python
num = int(input("Enter a integer ; "))
print("Remainder :", num % 7)
```

**Key Concepts:** The modulo operator (`%`) returns the remainder of a division operation, useful for checking divisibility and cyclic patterns.

---

### 10. Ask user for age and check if they are eligible to vote (>18)

**Code:**
```python
age = int(input("Enter your age : "))
if age >= 18:
    print("You are eligible to vote.")
else:
    print("You are not eligible to vote.")
```

**Key Concepts:** Comparison operators (`>=`, `>`, `<`, `<=`, `==`, `!=`) are used in conditional statements to evaluate conditions.

---

### 11. Evaluate and print result of: 3 + 4 * 2 - 5 / 2

**Code:**
```python
print("3 + 4 * 2 - 5 / 2 =", 3 + 4 * 2 - 5 / 2)
```

**Key Concepts:** Python follows PEMDAS order of operations: Parentheses, Exponents, Multiplication/Division, Addition/Subtraction.

---

### 12. Ask for a name and print the first & last character

**Code:**
```python
name = input("Enter your name : ")
length = len(name)
print(f"first letter : {name[0]}, last letter : {name[length-1]}")
```

**Key Concepts:** String indexing uses `[0]` for the first character and `[length-1]` for the last. The `len()` function returns the length of a string.

---

### 13. Slice a string "PYTHONPROGRAMMING" to print "PROGRAM"

**Code:**
```python
data = "PYTHONPROGRAMMING"
print(data[6:13])
```

**Key Concepts:** String slicing `[start:end]` extracts a substring from index `start` to `end-1`. Indices start at 0 in Python.

---

### 14. Ask for a sentence and print number of characters

**Code:**
```python
sentence = input("Enter one sentence : ")
no_of_characters = len(sentence)
print(f"No of characters in your is {no_of_characters}")
```

**Key Concepts:** The `len()` function counts all characters including spaces and punctuation in a string.

---

### 15. Replace all spaces in a sentence with hyphens

**Code:**
```python
sentence = input("Enter one sentence : ")
new_sentence = sentence.replace(" ", "-")
print(f"Your sentence without replacing is {sentence}")
print(f"Your sentence after replacing is {new_sentence}")
```

**Key Concepts:** The `replace(old, new)` method creates a new string with all occurrences of `old` replaced by `new`. Strings are immutable in Python.

---

### 16. Ask for a filename (e.g., "data.csv") → print the extension

**Code:**
```python
file_name = input("Enter the file name(with extension) : ")
name, extension = file_name.split(".")  # Providing a parameter where to split
print(f"Your file extension is {extension}")
```

**Key Concepts:** The `split(separator)` method divides a string into a list of substrings based on the separator. Multiple variables can capture the split results.

---

## INTERMEDIATE

### 1. Build a script that asks for name, department, employee id and prints formatted ID card-style output

**Code:**
```python
name = input("Please enter your name: ").strip().title()
department = input("Please enter your department: ").strip().title()
em_id = int(input("Please enter your employee id : "))
id_card = f"""
-------------------------------------
ID CARD
-------------------------------------
1. Name         : {name}
2. Department   : {department}
3. Employee id  : {em_id}
-------------------------------------
"""
print(id_card)
```

**Key Concepts:** Method chaining like `.strip().title()` applies multiple string methods sequentially. Triple quotes (`"""`) create multi-line strings preserving formatting.

---

### 2. Accept 3 numbers and print the largest (without using max())

**Code:**
```python
num1, num2, num3 = map(int, input("Please enter three integers : ").split())
if num1 > num2:
    if num1 > num3:
        print("Greatest number is", num1)
    else:
        print("Greatest number is", num3)
elif num2 > num3:
    print("Greatest number is", num2)
else:
    print("Greatest number is", num3)
```

**Key Concepts:** Nested `if-elif-else` statements allow complex decision-making. The `map()` function combined with `split()` efficiently processes multiple inputs.

---

### 3. Create 3 variables and swap their values (a→b, b→c, c→a)

**Code:**
```python
num1, num2, num3 = map(int, input("Please enter three integers : ").split())
# Trying swap their values
num_1, num_2, num_3 = num1, num2, num3
num1, num2, num3 = num_2, num_3, num_1
print("Before swaping numbers :", num_1, num_2, num_3)
print("After swaping numbers :", num1, num2, num3)
```

**Key Concepts:** Python allows simultaneous assignment, enabling elegant variable swapping without temporary variables: `a, b, c = b, c, a`.

---

### 4. Create a BMI calculator: BMI = weight / (height * height)

**Code:**
```python
weight = float(input("Enter your weight(kg) : "))
height = float(input("Enter your height(m) : "))
bmi = weight / (height * height)
print("Your BMI is %.2f kg/m2" % (bmi))
```

**Key Concepts:** The `%.2f` format specifier rounds floating-point numbers to 2 decimal places for cleaner output in percentage-style formatting.

---

### 5. Given an amount & tax rate, calculate final bill

**Code:**
```python
amo = float(input("Enter the amount : "))
tax_rate = float(input("Enter the tax rate : "))
tax_amo = (tax_rate * amo) / 100
final_bill = amo - tax_amo
print("Your bill is %.2f" % (final_bill))
```

**Key Concepts:** Mathematical calculations can be broken into steps for clarity. Percentage calculations involve division by 100.

---

### 6. Ask for a full name and generate initials (e.g., "John A Doe" → "J.A.D.")

**Code:**
```python
name = input("Enter your full name : ").strip().title().split()
length = len(name)
short = ""
# extracting single words
for i in range(length):
    first_letter = name[i]
    if i != length - 1:
        short = short + first_letter[0] + "."
    else:
        short = short + first_letter[0]
print(short)
```

**Key Concepts:** The `split()` without arguments splits on whitespace, creating a list of words. `range(length)` generates indices for iteration through the list.

---

### 7. Reverse a string using slicing

**Code:**
```python
word = input("Enter a word : ")
print(word[::-1])
```

**Key Concepts:** Advanced slicing `[::step]` with a negative step (`-1`) reverses sequences. This is the most Pythonic way to reverse strings.

---

### 8. Extract domain from email ("user@gmail.com" → "gmail.com")

**Code:**
```python
name, domain = input("Please enter your email : ").split("@")
print(f"Domain is {domain}")
```

**Key Concepts:** The `split("@")` method divides email addresses at the @ symbol, and unpacking assigns parts to separate variables.

---

### 9. Create a simple salary increment calculator

**Code:**
```python
salary = int(input("Enter your salary : "))
increment = int(input("Enter the increment percentage : "))
incre_amo = (salary * increment) / 100
salary_new = salary + incre_amo
print("Your new salary is", salary_new)
```

**Key Concepts:** Percentage increase calculations involve finding the increment amount and adding it to the original value.

---

### 10. Ask a user for test scores (3 numbers) and print average

**Code:**
```python
score1, score2, score3 = input("Enter your scores in three tests : ").split()
score1 = float(score1)
score2 = float(score2)
score3 = float(score3)
avg = (score1 + score2 + score3) / 3
print("Your Average score is %.2f" % (avg))
```

**Key Concepts:** Average calculation requires summing all values and dividing by the count. Individual type conversion ensures accurate floating-point arithmetic.

---

### 11. Given distance (km) & fuel consumption, print mileage

**Code:**
```python
distance, fuel = input("Enter the distance travelled(km) and fuel consumed(lit) : ").split()
distance = int(distance)
fuel = int(fuel)
mile_age = distance // fuel
print("Your vehicle mileage is", mile_age)
```

**Key Concepts:** The floor division operator (`//`) performs integer division, discarding the decimal part and returning only the whole number quotient.

---

### 12. Evaluate: (a**2 + b**2) / (a+b) using user inputs

**Code:**
```python
a, b = map(int, input("Enter the two integers : ").split())
result = (a**2 + b**2) / (a + b)
print("Result : %.2f" % (result))
```

**Key Concepts:** Complex mathematical expressions can be directly written in Python. Parentheses control the order of operations.

---

## ADVANCE

### 1. Create a script that takes a date in format "DD-MM-YYYY" and prints Day, Month, Year using slicing

**Code:**
```python
date = input("Enter the date in correct format : ")
day = date[0:2]
month = date[3:5]
year = date[6:]
print(f"Day : {day}")
print(f"Month : {month}")
print(f"Year : {year}")
```

**Key Concepts:** String slicing `[start:end]` extracts specific portions. Omitting the end index `[6:]` slices from index 6 to the end of the string.

---

### 2. Create an electricity bill calculator

**Rules:**
- 0-100 units → ₹5/unit
- 101-200 units → ₹7/unit
- 200+ units → ₹10/unit

**Code:**
```python
units = int(input("Enter the no of units : "))
uni_amo = 0
if units >= 0 and units <= 100:
    uni_amo = 5
elif units <= 200:
    uni_amo = 7
else:
    uni_amo = 10
total_amount = units * uni_amo
print("Your electricity bill is", total_amount)
```

**Key Concepts:** Logical operators (`and`, `or`, `not`) combine multiple conditions. Tiered pricing systems use `if-elif-else` chains to determine rates based on ranges.

---

## Summary

This assignment covers fundamental Python concepts including:
- **Variables and Data Types**: int, float, str, bool, None
- **Input/Output**: `input()`, `print()`, formatting methods
- **String Operations**: slicing, `split()`, `replace()`, `strip()`, `upper()`, `title()`
- **Type Conversion**: `int()`, `float()`, `str()`
- **Operators**: Arithmetic, comparison, logical, modulo (`%`), floor division (`//`), exponentiation (`**`)
- **Control Flow**: `if-elif-else` statements
- **Functions**: `len()`, `type()`, `id()`, `range()`, `map()`

These building blocks form the foundation for more advanced Python programming.
