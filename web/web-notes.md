# Web Fundamentals Session Notes

## 🌐 How the Web Works

### The Basic Flow

1. **You type a URL** (e.g., `www.example.com`) in your browser
2. **DNS Lookup**: Your browser asks a DNS server "What's the IP address of example.com?"
3. **DNS Response**: DNS returns something like `192.168.1.1`
4. **HTTP Request**: Your browser sends a request to that IP address
5. **Server Response**: The server sends back HTML, CSS, JavaScript files
6. **Browser Renders**: Your browser displays the webpage

### Key Components

| Component | What It Does |
|-----------|--------------|
| **Client** | Your browser (Chrome, Firefox, Safari) |
| **Server** | A computer that hosts websites and sends data |
| **DNS** | Domain Name System - converts domain names to IP addresses |
| **HTTP/HTTPS** | Protocol for transferring data (HTTPS is secure) |
| **IP Address** | Unique identifier for devices on the internet |

### Request-Response Cycle

```
Browser → "GET /index.html" → Server
Browser ← HTML + CSS + JS ← Server
```

**HTTP Methods:**
- `GET` - Retrieve data
- `POST` - Send data to server
- `PUT` - Update data
- `DELETE` - Remove data

---

## 🏗️ How a Website Works

### Three Core Technologies

```
HTML → Structure (the skeleton)
CSS → Style (the skin/clothes)
JavaScript → Behavior (the muscles/brain)
```

### The Website Architecture

```
Frontend (Client-Side)
├── HTML files
├── CSS files
├── JavaScript files
└── Images/Assets

Backend (Server-Side)
├── Server (Node.js, Python, PHP, etc.)
├── Database (MySQL, MongoDB, etc.)
└── APIs
```

### What Happens When You Visit a Website?

1. **Browser requests the page** from the server
2. **Server sends HTML file** first
3. **Browser reads HTML** and sees references to CSS and JS files
4. **Browser requests those files** separately
5. **Browser combines everything** and displays the page
6. **JavaScript runs** to add interactivity

### Static vs Dynamic Websites

| Static Website | Dynamic Website |
|----------------|-----------------|
| Fixed content | Content changes based on user |
| HTML/CSS only | Uses databases and backend |
| Fast and simple | More complex |
| Example: Portfolio | Example: Facebook, Twitter |

---

## 🧠 What is the DOM & Rendering

### What is the DOM?

**DOM = Document Object Model**

The DOM is a **tree-like representation** of your HTML that JavaScript can interact with.

### HTML vs DOM

**HTML (Code you write):**
```html
<html>
  <body>
    <h1>Hello</h1>
    <p>World</p>
  </body>
</html>
```

**DOM (What the browser creates):**
```
Document
  └── html
      └── body
          ├── h1 (text: "Hello")
          └── p (text: "World")
```

Each element becomes a **node** in the tree that JavaScript can access and modify.

### The Rendering Process

**Step-by-step what happens:**

1. **Parsing HTML** → Browser reads HTML and creates DOM tree
2. **Parsing CSS** → Browser reads CSS and creates CSSOM (CSS Object Model)
3. **Render Tree** → Combines DOM + CSSOM to know what to display
4. **Layout** → Calculates positions and sizes of elements
5. **Painting** → Actually draws pixels on the screen

```
HTML → DOM Tree
CSS → CSSOM Tree
         ↓
   Render Tree
         ↓
      Layout
         ↓
      Paint
```

### Manipulating the DOM with JavaScript

```javascript
// Select an element
const heading = document.querySelector('h1');

// Change its content
heading.textContent = 'New Heading';

// Change its style
heading.style.color = 'blue';

// Add a new element
const newPara = document.createElement('p');
newPara.textContent = 'New paragraph';
document.body.appendChild(newPara);
```

### Why the DOM Matters

- JavaScript can't directly change HTML files
- It **changes the DOM**, which updates what you see
- This is how web pages become interactive
- React, Vue, and other frameworks are built on DOM manipulation

---

## 🧾 HTML Fundamentals Crash Course

### What is HTML?

**HTML = HyperText Markup Language**

It's the **skeleton** of every webpage. It defines structure and content.

### Basic HTML Structure

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>My Website</title>
</head>
<body>
  <h1>Welcome to My Site</h1>
  <p>This is a paragraph.</p>
</body>
</html>
```

**What each part does:**
- `<!DOCTYPE html>` - Tells browser this is HTML5
- `<html>` - Root element, wraps everything
- `<head>` - Contains metadata (not visible on page)
- `<body>` - Contains visible content

### Essential HTML Tags

#### Text & Headings

```html
<h1>Main Heading</h1>
<h2>Subheading</h2>
<h3>Smaller heading</h3>
<!-- h1 to h6, h1 is largest -->

<p>This is a paragraph</p>
<span>Inline text</span>
<strong>Bold text</strong>
<em>Italic text</em>
<br> <!-- Line break -->
<hr> <!-- Horizontal line -->
```

#### Links & Images

```html
<!-- Link -->
<a href="https://google.com">Click here</a>
<a href="https://google.com" target="_blank">Open in new tab</a>

<!-- Image -->
<img src="image.jpg" alt="Description of image">
```

#### Lists

```html
<!-- Unordered List (bullets) -->
<ul>
  <li>Item 1</li>
  <li>Item 2</li>
  <li>Item 3</li>
</ul>

<!-- Ordered List (numbers) -->
<ol>
  <li>First</li>
  <li>Second</li>
  <li>Third</li>
</ol>
```

#### Containers & Layout

```html
<!-- Generic containers -->
<div>Block-level container</div>
<span>Inline container</span>

<!-- Semantic containers (better for SEO) -->
<header>Top of page</header>
<nav>Navigation menu</nav>
<main>Main content</main>
<section>Section of content</section>
<article>Self-contained content</article>
<aside>Side content</aside>
<footer>Bottom of page</footer>
```

#### Forms & Input

```html
<form action="/submit" method="POST">
  <label for="name">Name:</label>
  <input type="text" id="name" name="name" placeholder="Enter name">
  
  <label for="email">Email:</label>
  <input type="email" id="email" name="email">
  
  <label for="password">Password:</label>
  <input type="password" id="password" name="password">
  
  <label for="message">Message:</label>
  <textarea id="message" name="message" rows="4"></textarea>
  
  <input type="checkbox" id="agree" name="agree">
  <label for="agree">I agree</label>
  
  <button type="submit">Submit</button>
</form>
```

#### Tables

```html
<table>
  <thead>
    <tr>
      <th>Name</th>
      <th>Age</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>John</td>
      <td>25</td>
    </tr>
    <tr>
      <td>Jane</td>
      <td>30</td>
    </tr>
  </tbody>
</table>
```

### HTML Attributes

Attributes provide additional information about elements:

```html
<element attribute="value">

<!-- Examples -->
<a href="https://example.com">Link</a>
<img src="photo.jpg" alt="My photo">
<div class="container">Content</div>
<p id="intro">Introduction</p>
<button disabled>Can't click</button>
```

**Common Attributes:**
- `class` - For CSS styling (can be reused)
- `id` - Unique identifier (use once per page)
- `src` - Source for images/scripts
- `href` - Link destination
- `alt` - Alternative text for images
- `style` - Inline CSS styles

### Semantic HTML

Use meaningful tags instead of just `<div>`:

**❌ Not Semantic:**
```html
<div class="header">
  <div class="nav">...</div>
</div>
<div class="content">...</div>
<div class="footer">...</div>
```

**✅ Semantic:**
```html
<header>
  <nav>...</nav>
</header>
<main>...</main>
<footer>...</footer>
```

**Benefits:**
- Better SEO (search engines understand structure)
- Improved accessibility (screen readers work better)
- Cleaner, more readable code

### HTML Best Practices

✅ **Do:**
- Use lowercase for tag names
- Always close tags properly
- Use semantic HTML
- Include `alt` text for images
- Indent nested elements for readability
- Validate your HTML

❌ **Don't:**
- Mix uppercase and lowercase in tags
- Forget closing tags
- Use too many `<div>` tags
- Skip `alt` attributes on images
- Write messy, unindented code

### Quick Reference: Common Tags

| Category | Tags |
|----------|------|
| **Structure** | `<html>`, `<head>`, `<body>`, `<div>`, `<span>` |
| **Text** | `<h1>`-`<h6>`, `<p>`, `<strong>`, `<em>` |
| **Links/Media** | `<a>`, `<img>`, `<video>`, `<audio>` |
| **Lists** | `<ul>`, `<ol>`, `<li>` |
| **Forms** | `<form>`, `<input>`, `<button>`, `<textarea>`, `<select>` |
| **Semantic** | `<header>`, `<nav>`, `<main>`, `<section>`, `<article>`, `<footer>` |
| **Table** | `<table>`, `<thead>`, `<tbody>`, `<tr>`, `<th>`, `<td>` |

---

## 🎯 Key Takeaways

1. **The Web** = Client-Server communication via HTTP/HTTPS
2. **Websites** = HTML (structure) + CSS (style) + JavaScript (behavior)
3. **DOM** = Browser's representation of HTML that JS can manipulate
4. **HTML** = Markup language that creates the structure of web pages

### Practice Project Ideas

1. **Personal Portfolio**: Use semantic HTML to create a simple portfolio
2. **Contact Form**: Build a form with various input types
3. **Blog Layout**: Create a blog post layout with header, article, and footer
4. **Product Card**: Design a product card with image, title, description, and button

---

