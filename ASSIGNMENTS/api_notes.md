# API (Application Programming Interface)

## What is an API?
An **API (Application Programming Interface)** is a way for different software applications to communicate with each other. It acts as a **mediator** between the frontend (UI) and the backend (server, database, services).

```
Request  →  UI  →  API  →  Backend
Response ←      ←       ←
```

The client sends a **request**, the API processes it (or forwards it to the backend), and then sends back a **response**.

---

## Why is an API useful?
- Acts as a **bridge** between frontend and backend
- Helps reuse **already existing code**
- Improves **security** by exposing only required data
- Allows different platforms (web, mobile, desktop) to use the same backend
- Makes applications **scalable** and **maintainable**

---

## Types of APIs

### 1. Free APIs
- Open or public APIs
- Often used for learning and testing
- Example: Public APIs (weather, quotes, etc.)

### 2. Paid APIs
- Require subscription or payment
- Provide advanced features, higher limits, or better reliability
- Example: Payment gateways, premium data APIs

---

## API Methods (HTTP Methods)

| Method | Purpose  | Description |
|------|---------|-------------|
| GET | Read | Fetch data from server |
| POST | Create | Send new data to server |
| PUT | Update | Update entire existing data |
| PATCH | Update | Update partial data |
| DELETE | Delete | Remove data from server |

---

## Endpoint
An **endpoint** is simply a **URL (HTTPS)** where the API can be accessed.

Example:
```
https://api.example.com/users
```

Each endpoint is usually associated with a specific HTTP method.

---

## Tools for API Testing

### Postman
- Used to test API calls
- Can send GET, POST, PUT, PATCH, DELETE requests
- Helps verify request and response
- Useful for debugging APIs

---

## How to Create an API (Using Python & Flask)

### Step 1: Install Requirements
- Install Python
- Install Flask framework

```
pip install flask
```

### Step 2: Create a Simple API

```python
from flask import Flask

app = Flask(__name__)

@app.route('/')  # endpoint
# if this route is called, the below function will execute
def home():
    return "API Created"

if __name__ == '__main__':
    app.run(debug=True)
```

---

## Making API Calls
- APIs can be consumed using tools like **Postman**
- Or using libraries such as:
  - `requests` (Python)
  - `fetch` / `axios` (JavaScript)

Example (Python):
```python
import requests
response = requests.get('http://127.0.0.1:5000/')
print(response.text)
```

---

## Summary
- API enables communication between different systems
- Uses HTTP methods to perform operations
- Endpoints are URLs exposed by APIs
- Flask is a lightweight framework to build APIs in Python
- Tools like Postman help in testing APIs

---

> These notes are suitable for **beginners** and can be extended to advanced topics like authentication (JWT), REST architecture, and database integration.

