# 🧪 DAY 2 - Python Control Flow Assignment
## Control Flow, Loops, Break/Continue, List Comprehensions

---

## SECTION 1 — Industry-Driven if/elif/else Exercises

### ✅ Question 1: Login System with Lockout

**Problem Statement:**
Simulate a login system where:
- User enters username/password
- If entered incorrectly 3 times → lock the account

**Solution:**
```python
user_name = "surya"
password = "kiran123"

for i in range(3):
    username = input("Enter the username :")
    pass_word = input("Enter the password :")
    
    if username == user_name and pass_word == password:
        print("Login succesful.")
        break

    elif i < 2:
        print("you have entered wrong details, try again.")

    else:
        print("Your account is locked.")
```

---

### ✅ Question 2: Bank Transaction Validator

**Problem Statement:**
- **Input:** withdrawal amount, balance  
- **Output:**
  - "Transaction successful" if amount ≤ balance
  - "Insufficient balance" otherwise

**Solution:**
```python
balance = int(input("Enter your current balance : "))  # taking balance from user
amount = int(input("Enter the amount to withdraw : "))  # taking amount from user

if amount < 0 or balance < 0:
    print("Invalid details.")

elif amount > balance:
    print("Insufficient balance") 

else:
    print("Transaction successful.")
    print("Current balance is", balance - amount, sep=" ")
```

---

### ✅ Question 3: Shipping Cost Calculator

**Problem Statement:**
**Rules:**
- Weight < 1kg → ₹50
- 1–5kg → ₹100
- >5kg → ₹200

**Solution:**
```python
weight = float(input("Enter the weight in kg : "))
amount = 0

if weight < 1.0:
    amount = 50
elif weight <= 5.0:
    amount = 100
else:
    amount = 200

print("You need to pay", amount)
```

---

### ✅ Question 4: Employee Bonus Eligibility

**Problem Statement:**
**Inputs:**
- Years of experience
- Rating (1–5)

**Rules:**
- If experience > 5 AND rating ≥ 4 → 20% bonus
- Else → 10% bonus

**Solution:**
```python
experience = int(input("Enter your experience : "))
rating = int(input("Enter your rating(1-5) : "))
current_salary = float(input("Enter your current salary : "))
bonus = 0

if (experience > 5 and rating >= 4):
    bonus = 20
else:
    bonus = 10

current_salary = current_salary + (current_salary * bonus) / 100
print(f"Now your salary is {current_salary}RS.")
```

---

### ✅ Question 5: Movie Ticket Pricing

**Problem Statement:**
**Rules:**
- Children (<13) → ₹100
- Adults (13–60) → ₹200
- Seniors (>60) → ₹150

**Solution:**
```python
age = int(input("Enter your age : "))
price = 0

if age < 13:
    price = 100
elif age < 60:
    price = 200
else:
    price = 150

print(f"Your ticket price is {price}")
```

---

### ✅ Question 6: Smart Traffic Light Rule Engine

**Problem Statement:**
- **Input:** light color: "red", "yellow", "green"  
- **Output:** corresponding driving instruction

**Solution:**
```python
traffic_light = input("Enter the traffic light : ").strip().lower()

if traffic_light == "red":
    print('This colour indicates "stop immediately before the line".')

elif traffic_light == "yellow":
    print("This colour warns to slow down and prepare to stop, as the light is about to turn red")  

elif traffic_light == "green":  
    print("This colour says you can move.") 

else:
    print("Invalid colour")
```

---

### ✅ Question 7: Fraud Score Classification

**Problem Statement:**
Given fraud probability score (0–1):
- >0.9 → "High risk"
- >0.6 → "Medium risk"
- else → "Low risk"

**Solution:**
```python
fraud_score = float(input("Enter the fraud probability score(0-1) :"))

if fraud_score > 0.9:
    print("It is high risk.")

elif fraud_score > 0.6:
    print("It is medium risk.")

else:
    print("It is low risk.")
```

---

### ✅ Question 8: Temperature Alert System

**Problem Statement:**
- **Input:** temperature  
- **Print:**
  - "Normal"
  - "Warning"
  - "Critical"

Used in DevOps, IoT systems.

**Solution:**
```python
temperature = int(input("Enter temperature: "))

if temperature < 50:
    print("Normal")
elif temperature < 70:
    print("Warning")
else:
    print("Critical")
```

---

### ✅ Question 9: Discount Engine for E-commerce

**Problem Statement:**
**Inputs:**
- Product price
- Customer type (new/regular/premium)

**Logic:**
- premium → 20% discount
- regular → 10%
- new → 5%

**Solution:**
```python
price = float(input("Enter the product price : "))
print("Select customer type from below :")
print("1.New\n2.Regular\n3.Premium")

customer_type = int(input())
discount = 0
flag = 0

if customer_type == 1:
    discount = 5
elif customer_type == 2:
    discount = 10
elif customer_type == 3:
    discount = 20
else:
    print("Invalid details")
    flag += 1

if flag == 0:
    price = price - (price * discount) / 100
    print(f"You need to pay {price}")
```

---

### ✅ Question 10: Student Grade Calculator

**Problem Statement:**
Convert marks to grade A/B/C/D/F.

**Solution:**
```python
marks = int(input("Enter your marks(0-100) : "))
grade = None

if marks >= 90:
    grade = 'A'
elif marks >= 80:
    grade = 'B'
elif marks >= 70:
    grade = 'C'
elif marks >= 60:
    grade = 'D'
else:
    grade = 'E'

print(f"Your grade is {grade}.")
```

---

## SECTION 2 — Realtime for Loops Exercises

### ❌ Question 11: Generate Employee IDs

**Problem Statement:**
Given 5 employees, generate IDs:
```
EMP001  
EMP002  
EMP003 ...
```

**Status:** Not completed yet

---

### ✅ Question 12: Process List of Orders

**Problem Statement:**
Given list:
```python
orders = [450, 1200, 300, 999, 1450]
```

Print:
- "High-value order" if >1000
- else "Normal order"

**Solution:**
```python
orders = [450, 1200, 300, 999, 1450]
high_value = []
normal = []

for value in orders:
    if value > 1000:
        high_value.append(value)
    else:
        normal.append(value)

print(f"High Value order : {high_value}")
print(f"Normal value order : {normal}")
```

---

### ❌ Question 13: Print Logs with Line Numbers

**Problem Statement:**
- **Input:** list of log messages  
- **Output:**
```
1. initializing system  
2. loading model  
3. model ready
```

**Status:** Not completed yet

---

### ✅ Question 14: Count Vowels in a Company Name

**Problem Statement:**
Loop through string and count vowels.

**Solution:**
```python
company_name = input("Enter the company name : ")
no_of_vowels = 0
company_name = company_name.lower().strip()

for letter in company_name:
    if letter == 'a' or letter == 'e' or letter == 'i' or letter == 'o' or letter == 'u':
        no_of_vowels += 1

print(f"No of vowels in company name are {no_of_vowels}")
```

---

### ✅ Question 15: API Retry Logic Simulation

**Problem Statement:**
Run a loop 5 times:
- If response code == 200 → break
- Else retry

**Solution:**
```python
flag = 0

for i in range(1, 6):
    response_code = int(input("Enter the response code : "))
    if response_code == 200:
        print("Api call successful.")
        flag += 1
        break
    else:
        print("Api call failed")
        print("Try again.")
```

---

### ✅ Question 16: Print Multiplication Table (1–20)

**Problem Statement:**
But only print values ending in digit "5".

**Solution:**
```python
for i in range(1, 21):
    print(f"Table of {i}")
    for j in range(1, 11):
        if (i * j) % 10 == 5:
            print(f"{i} x {j} = {i * j}")
    print(" ")
```

---

### ✅ Question 17: Data Cleaning — Remove Empty Strings

**Problem Statement:**
Given list:
```python
["john", "", "sam", "", "alex"]
```

Skip empty strings and print others.

**Solution:**
```python
names = ["john", "", "sam", "", "alex"]

for name in names:
    if name != "":
        print(name)
```

---

### ❌ Question 18: Temperature Sensor Data Summary

**Problem Statement:**
Given 24 hourly readings:
- Find min, max, average
- (without using min/max/sum built-ins)

**Status:** Not completed yet

---

### ❌ Question 19: Password Strength Checker

**Problem Statement:**
Loop through characters → ensure:
- at least 1 uppercase
- 1 digit
- 1 special character

**Status:** Not completed yet

---

### ✅ Question 20: Inventory Validation

**Problem Statement:**
Given stock list:
```python
stock = [12, 0, 4, 7, 0, 33]
```

Print "Out of stock" where value is 0.

**Solution:**
```python
stock = [12, 0, 4, 7, 0, 33]

for value in stock:
    if value == 0:
        print("Out of stock.")
    else:
        print("In stock")
```

---

## SECTION 3 — While Loops in Real Life

### ✅ Question 21: ATM Withdrawal — Continue Asking

**Problem Statement:**
Users enter withdrawal amount until:
- they enter 0
- OR amount < balance

**Solution:**
```python
amount = int(input("Enter the amount to withdraw : "))
balance = int(input("Enter the current balance : ")) 

if amount < 0:
    print("Invalid amount.")
elif amount > balance:
    print("Insufficient balance.")
else:
    while amount <= balance:
        balance = balance - amount 
        print("Transaction successful.")
        amount = int(input("Enter the amount to withdraw : "))  
        if amount == 0:
            break 
        if amount < 0:
            print("Invalid amount.")
        if amount > balance:
            print("Insufficient balance.")
```

---

### ✅ Question 22: 2FA Verification Simulation

**Problem Statement:**
Ask OTP until correct OTP is entered or attempts reach 3.

**Solution:**
```python
otp = 1918
user_otp = int(input("Enter the OTP(4 digit) : "))
flag = 0

for i in range(3):
    if otp == user_otp:
        print("Verification succesful.")
        flag += 1
        break
    else:
        if i < 2:
            print("Wrong otp.Try again")
            user_otp = int(input("Enter the OTP(4 digit) : "))
        else:
            print("Verification failed.")
```

---

### ✅ Question 23: Menu-Driven CLI App

**Problem Statement:**
Display menu inside a while loop:
```
1. Add Task  
2. Delete Task  
3. Show Tasks  
4. Exit
```

**Solution:**
```python
print("Select one option from below :")
print("1. Add Task \n2. Delete Task \n3. Show Tasks\n4. Exit")
choice = int(input())

while choice != 4:
    if choice == 1 or choice == 2 or choice == 3:
        print("Completed work.")
    print("Select one option from below :")
    print("1. Add Task \n2. Delete Task \n3. Show Tasks\n4. Exit")
    choice = int(input())
```

---

### ✅ Question 24: Number Reversal (No Strings)

**Problem Statement:**
Use while loop to reverse digits.

**Solution:**
```python
num = input("Enter the one integer : ")
no_of_digits = len(num)
no_of_digits -= 1
num = int(num)
reverse_num = 0
while num != 0:
    digit = num % 10
    reverse_num = reverse_num + digit * (10 ** no_of_digits)
    no_of_digits -= 1
    num = num // 10
print(reverse_num)
```

---

### ✅ Question 25: Keep Taking Inputs Until "exit"

**Problem Statement:**
Used in chatbots / CLI tools.

**Solution:**
```python
string = input("Enter the task : ").strip().lower()

while string != "exit":
    print("Task completed.")
    string = input("Enter the new task : ").strip().lower()

print("✋Bye")
```

---

### ✅ Question 26: Find First Number Divisible by Both 3 and 7

**Problem Statement:**
Using `while True`, break when found.

**Solution:**
```python
num1, num2 = map(int, input("Enter two integer").split())

integer = 1

while True:
    if integer % num1 == 0 and integer % num2 == 0:
        print(f"First integer divisible by {num1} and {num2} is {integer}")
        break
    integer += 1
```

---

### ✅ Question 27: Count Login Attempts

**Problem Statement:**
While loop to count attempts until password is correct.

**Solution:**
```python
password = "kiran123"
attempts = 0
while True:
    pass_word = input("Enter the password : ")
    attempts += 1
    if pass_word == password:
        print(f"Login succesful. No of attempts : {attempts}")
        break
    else:
        print("Wrong password, Try again.")
```

---

### ❌ Question 28: CPU Threshold Monitor Simulation

**Problem Statement:**
Generate random CPU usage until cpu < 70, else keep watching.

**Status:** Not completed yet

---

### ✅ Question 29: Random Dice Rolling Game

**Problem Statement:**
Roll dice until user types "stop".

**Solution:**
```python
import random

choice = None

while True:
    choice = input("Enter the choice(Roll/Stop) : ").strip().lower()
    if choice == "stop":
        print("Thank you")
        break
    elif choice == "roll":
        score = random.randint(1, 6)
        print(f"Your score is {score}")
    else: 
        print("Invalid choice. Try again.")
```

---

### ✅ Question 30: Sum of Digits of a Number

**Problem Statement:**
Using while loop (no conversion to string).

**Solution:**
```python
num = int(input("Enter the integer : "))
sum = 0

while num != 0:
    sum = sum + num % 10
    num = num // 10

print(f"Sum of digits is {sum}")
```

---

## SECTION 4 — break / continue / pass (Applied)

### ✅ Question 31: Skip Invalid Transactions

**Problem Statement:**
Transaction list:
```python
txn = [230, -1, 450, 0, 990, -4]
```

Skip negatives and zeros.

**Solution:**
```python
txn = [230, -1, 450, 0, 990, -4]

for value in txn:
    if value > 0:
        print(value)
```

---

### ❌ Question 32: Stop Processing When Fraud Transaction Found

**Problem Statement:**
Stop loop when any amount > 10,000.

**Status:** Not completed yet

---

### ❌ Question 33: Skip Emails Without '@'

**Problem Statement:**
List of user emails, skip invalid ones.

**Status:** Not completed yet

---

### ❌ Question 34: Placeholder Functions using pass

**Problem Statement:**
Create class with methods:
- `login()`
- `logout()`
- `reset_password()`

Use `pass` in each.

**Status:** Not completed yet

---

### ✅ Question 35: Print Even Numbers But Stop at 50

**Problem Statement:**
Use both `continue` and `break` in same loop.

**Solution:**
```python
for i in range(60):
    if i == 50:
        break
    elif i % 2 == 0:
        print(i, end=" ")
    else:
        continue
```

---

## SECTION 5 — List Comprehension (Realtime Intro)

### ✅ Question 36: Convert Product Names to Uppercase

**Problem Statement:**
```python
products = ["macbook", "airpods", "iphone"]
```

**Solution:**
```python
products = ["macbook", "airpods", "iphone"]
products_upper = [x.upper() for x in products]
print(f"Products with uppercase are {products_upper}")
```

---

### ✅ Question 37: Extract Prices Above 500

**Problem Statement:**
```python
prices = [120, 450, 899, 1500, 300]
```

**Solution:**
```python
prices = [120, 450, 899, 1500, 300]
prices_new = [x for x in prices if x > 500]
print(f"Prices above 500 are {prices_new}")
```

---

### ✅ Question 38: Clean Email List

**Problem Statement:**
Remove empty emails:
```python
emails = ["a@gmail.com", "", "test@yahoo.com", None, "sam@test.com"]
```

**Solution:**
```python
emails = ["a@gmail.com", "", "test@yahoo.com", None, "sam@test.com"]
new_emails = [x for x in emails if x != "" and x != None] 
print(f"Valid emails are {new_emails}")
```

---

### ✅ Question 39: Generate List of Even Numbers (1–200)

**Problem Statement:**
Using comprehension.

**Solution:**
```python
even_num = [x for x in range(1, 201) if x % 2 == 0]
print(f"Even numbers are {even_num}")
```

---

### ✅ Question 40: Extract First Letter of Each Name

**Problem Statement:**
```python
names = ["Alice", "Bob", "Charlie", "David"]
```

**Solution:**
```python
names = ["Alice", "Bob", "Charlie", "David"]
first_letter = [x[0] for x in names]
print(f"First letter of each name are {first_letter}")
```

---

## 📊 Progress Summary

**Completed:** 32/40 questions (80%)

**Sections Breakdown:**
- ✅ Section 1 (if/elif/else): 10/10 - **100% Complete**
- ⚠️ Section 2 (for loops): 6/10 - **60% Complete**
- ⚠️ Section 3 (while loops): 7/10 - **70% Complete**
- ⚠️ Section 4 (break/continue/pass): 2/5 - **40% Complete**
- ✅ Section 5 (list comprehension): 5/5 - **100% Complete**

**Remaining Questions:** 11, 13, 18, 19, 28, 32, 33, 34

---

