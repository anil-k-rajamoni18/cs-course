# CSS Fundamentals

## 1. What is CSS?

**CSS** stands for **Cascading Style Sheets**.

CSS is a styling language used to describe the presentation of HTML documents. It controls how HTML elements are displayed on screen, paper, or other media.

### Purpose of CSS

- **Separation of Concerns**: Keeps content (HTML) separate from presentation (CSS)
- **Styling**: Controls colors, fonts, spacing, layouts, animations
- **Consistency**: Apply styles across multiple pages
- **Responsiveness**: Adapt layouts for different screen sizes
- **Maintainability**: Easier to update and manage styles

### Before CSS vs With CSS

**Without CSS (plain HTML):**
```html
<font color="blue" size="5">Hello World</font>
```
❌ Mixing content with styling (hard to maintain)

**With CSS (modern approach):**
```html
<h1>Hello World</h1>
```
```css
h1 {
  color: blue;
  font-size: 2rem;
}
```
✅ Clean separation, reusable, maintainable

---

## 2. How CSS Works

CSS uses **selectors** to target HTML elements and apply **declarations** (style rules).

### Basic Syntax

```css
selector {
  property: value;
  property: value;
}
```

### Example

```css
h1 {
  color: blue;
  font-size: 24px;
  font-weight: bold;
}
```

**Breakdown:**
- `h1` = **Selector** (targets all `<h1>` elements)
- `color`, `font-size`, `font-weight` = **Properties**
- `blue`, `24px`, `bold` = **Values**
- `color: blue;` = **Declaration**
- Everything inside `{ }` = **Declaration Block**

---

## 3. Types of CSS

There are **three ways** to add CSS to HTML:

### A. Inline CSS

CSS applied directly to an HTML element using the `style` attribute.

```html
<h1 style="color: blue; font-size: 24px;">Hello World</h1>
```

**Pros:**
- Quick for testing
- Highest specificity (overrides other styles)

**Cons:**
- ❌ Not reusable
- ❌ Hard to maintain
- ❌ Mixes content with presentation

**When to use:** Rarely, only for quick tests or dynamic styles via JavaScript.

---

### B. Internal CSS (Embedded)

CSS placed inside a `<style>` tag within the HTML document's `<head>`.

```html
<!DOCTYPE html>
<html>
<head>
  <style>
    h1 {
      color: blue;
      font-size: 24px;
    }
    
    p {
      color: gray;
      line-height: 1.6;
    }
  </style>
</head>
<body>
  <h1>Hello World</h1>
  <p>This is a paragraph.</p>
</body>
</html>
```

**Pros:**
- Useful for single-page styles
- No external file needed

**Cons:**
- ❌ Not reusable across pages
- ❌ Increases HTML file size

**When to use:** Single-page websites, email templates, quick prototypes.

---

### C. External CSS (Most Common)

CSS placed in a separate `.css` file and linked to HTML using `<link>`.

**style.css:**
```css
h1 {
  color: blue;
  font-size: 24px;
}

p {
  color: gray;
  line-height: 1.6;
}
```

**index.html:**
```html
<!DOCTYPE html>
<html>
<head>
  <link rel="stylesheet" href="style.css">
</head>
<body>
  <h1>Hello World</h1>
  <p>This is a paragraph.</p>
</body>
</html>
```

**Pros:**
- ✅ Reusable across multiple pages
- ✅ Clean separation of concerns
- ✅ Easier maintenance
- ✅ Browser caching (faster load times)

**Cons:**
- Requires additional HTTP request (minimal impact)

**When to use:** Almost always! This is the standard approach.

---

### Comparison Table

| Type | Location | Reusability | Maintenance | Best For |
|------|----------|-------------|-------------|----------|
| **Inline** | Inside HTML tags | ❌ No | ❌ Difficult | Quick tests, dynamic styles |
| **Internal** | `<style>` in `<head>` | ⚠️ Single page only | ⚠️ Moderate | Single-page sites, emails |
| **External** | Separate `.css` file | ✅ Yes | ✅ Easy | Multi-page websites (recommended) |

---

## 4. CSS Selectors

Selectors are patterns used to target HTML elements.

### Basic Selectors

#### Element Selector
Targets all elements of a specific type.

```css
p {
  color: blue;
}
```
Applies to all `<p>` tags.

#### Class Selector
Targets elements with a specific class (use `.`).

```html
<p class="highlight">This is highlighted</p>
```

```css
.highlight {
  background-color: yellow;
}
```

#### ID Selector
Targets a single element with a specific ID (use `#`).

```html
<div id="header">Header Content</div>
```

```css
#header {
  background-color: navy;
  color: white;
}
```

#### Universal Selector
Targets all elements (use `*`).

```css
* {
  margin: 0;
  padding: 0;
}
```

#### Multiple Selectors (Grouping)
Apply same styles to multiple selectors.

```css
h1, h2, h3 {
  font-family: Arial, sans-serif;
  color: #333;
}
```

### Combinator Selectors

#### Descendant Selector (space)
Targets elements inside another element.

```css
div p {
  color: blue;
}
```
Targets all `<p>` inside `<div>`.

#### Child Selector (`>`)
Targets direct children only.

```css
div > p {
  color: red;
}
```
Only direct `<p>` children of `<div>`.

#### Adjacent Sibling (`+`)
Targets the next immediate sibling.

```css
h1 + p {
  font-weight: bold;
}
```
Targets `<p>` immediately after `<h1>`.

#### General Sibling (`~`)
Targets all siblings.

```css
h1 ~ p {
  color: gray;
}
```
All `<p>` that come after `<h1>`.

### Attribute Selectors

```css
/* Has attribute */
input[type] {
  border: 1px solid black;
}

/* Specific value */
input[type="text"] {
  background: #f0f0f0;
}

/* Contains value */
a[href*="google"] {
  color: blue;
}

/* Starts with */
a[href^="https"] {
  color: green;
}

/* Ends with */
a[href$=".pdf"] {
  color: red;
}
```

### Pseudo-classes

Target elements based on state or position.

```css
/* Hover state */
a:hover {
  color: red;
}

/* First child */
li:first-child {
  font-weight: bold;
}

/* Last child */
li:last-child {
  border-bottom: none;
}

/* Nth child */
li:nth-child(odd) {
  background: #f0f0f0;
}

/* Focus state */
input:focus {
  border-color: blue;
}

/* Checked state */
input:checked {
  background: green;
}
```

### Pseudo-elements

Target specific parts of elements.

```css
/* First letter */
p::first-letter {
  font-size: 2em;
  color: red;
}

/* First line */
p::first-line {
  font-weight: bold;
}

/* Before content */
h1::before {
  content: "→ ";
  color: blue;
}

/* After content */
h1::after {
  content: " ←";
  color: blue;
}

/* Selection */
::selection {
  background: yellow;
  color: black;
}
```

---

## 5. Common CSS Properties

### Text & Font Properties

```css
/* Font family */
font-family: Arial, Helvetica, sans-serif;

/* Font size */
font-size: 16px;
font-size: 1rem;
font-size: 100%;

/* Font weight */
font-weight: normal;    /* 400 */
font-weight: bold;      /* 700 */
font-weight: 600;

/* Font style */
font-style: normal;
font-style: italic;
font-style: oblique;

/* Text color */
color: blue;
color: #007bff;
color: rgb(0, 123, 255);
color: rgba(0, 123, 255, 0.8);

/* Text alignment */
text-align: left;
text-align: center;
text-align: right;
text-align: justify;

/* Text decoration */
text-decoration: none;
text-decoration: underline;
text-decoration: line-through;
text-decoration: overline;

/* Text transform */
text-transform: uppercase;
text-transform: lowercase;
text-transform: capitalize;

/* Line height */
line-height: 1.6;
line-height: 24px;

/* Letter spacing */
letter-spacing: 1px;
letter-spacing: 0.05em;

/* Word spacing */
word-spacing: 2px;

/* Text shadow */
text-shadow: 2px 2px 4px rgba(0,0,0,0.3);
```

### Background Properties

```css
/* Background color */
background-color: white;
background-color: #f0f0f0;
background-color: rgba(255, 255, 255, 0.9);

/* Background image */
background-image: url('image.jpg');

/* Background size */
background-size: cover;      /* fills container */
background-size: contain;    /* fits inside */
background-size: 100% 100%;  /* specific size */

/* Background position */
background-position: center;
background-position: top right;
background-position: 50% 50%;

/* Background repeat */
background-repeat: no-repeat;
background-repeat: repeat;
background-repeat: repeat-x;  /* horizontal only */
background-repeat: repeat-y;  /* vertical only */

/* Background attachment */
background-attachment: fixed;   /* parallax effect */
background-attachment: scroll;  /* default */

/* Shorthand */
background: #f0f0f0 url('bg.jpg') no-repeat center/cover;
```

### Box Model Properties

```css
/* Width & Height */
width: 300px;
width: 50%;
width: 100vw;
max-width: 1200px;
min-width: 300px;

height: 200px;
height: 100vh;
max-height: 500px;
min-height: 200px;

/* Padding */
padding: 20px;
padding: 10px 20px;           /* vertical | horizontal */
padding: 10px 15px 20px 25px; /* top | right | bottom | left */

/* Margin */
margin: 20px;
margin: 0 auto;  /* center horizontally */
margin-top: 10px;

/* Border */
border: 1px solid #ddd;
border-width: 2px;
border-style: solid;
border-color: black;
border-radius: 8px;

/* Box sizing */
box-sizing: border-box;  /* includes padding/border in width */
```

### Display & Visibility

```css
/* Display */
display: block;
display: inline;
display: inline-block;
display: flex;
display: grid;
display: none;  /* hides element completely */

/* Visibility */
visibility: visible;
visibility: hidden;  /* hides but keeps space */

/* Opacity */
opacity: 1;      /* fully visible */
opacity: 0.5;    /* 50% transparent */
opacity: 0;      /* invisible */
```

### Positioning

```css
/* Position types */
position: static;    /* default */
position: relative;  /* relative to normal position */
position: absolute;  /* relative to positioned parent */
position: fixed;     /* relative to viewport */
position: sticky;    /* hybrid of relative and fixed */

/* Position offsets */
top: 10px;
right: 20px;
bottom: 30px;
left: 40px;

/* Z-index (stacking order) */
z-index: 10;
z-index: 999;
z-index: -1;
```

### Colors & Effects

```css
/* Color formats */
color: red;
color: #ff0000;
color: rgb(255, 0, 0);
color: rgba(255, 0, 0, 0.5);
color: hsl(0, 100%, 50%);
color: hsla(0, 100%, 50%, 0.5);

/* Box shadow */
box-shadow: 2px 2px 8px rgba(0,0,0,0.2);
box-shadow: 0 4px 6px rgba(0,0,0,0.1), 0 1px 3px rgba(0,0,0,0.08);

/* Text shadow */
text-shadow: 1px 1px 2px rgba(0,0,0,0.3);

/* Filter effects */
filter: blur(5px);
filter: brightness(1.2);
filter: contrast(1.5);
filter: grayscale(100%);
filter: opacity(50%);
```

### List Properties

```css
/* List style type */
list-style-type: disc;      /* filled circle */
list-style-type: circle;    /* hollow circle */
list-style-type: square;
list-style-type: decimal;   /* 1, 2, 3... */
list-style-type: none;      /* no bullets */

/* List style position */
list-style-position: inside;
list-style-position: outside;

/* List style image */
list-style-image: url('bullet.png');

/* Shorthand */
list-style: square inside;
```

### Cursor

```css
cursor: pointer;     /* hand */
cursor: default;     /* arrow */
cursor: text;        /* I-beam */
cursor: move;        /* crosshair */
cursor: not-allowed; /* prohibited */
cursor: wait;        /* loading */
cursor: help;        /* question mark */
```

### Overflow

```css
overflow: visible;   /* default, content can overflow */
overflow: hidden;    /* clips content */
overflow: scroll;    /* adds scrollbars always */
overflow: auto;      /* scrollbars when needed */

/* Individual axes */
overflow-x: hidden;
overflow-y: auto;
```

### Transform

```css
/* Translate (move) */
transform: translate(50px, 100px);
transform: translateX(50px);
transform: translateY(100px);

/* Rotate */
transform: rotate(45deg);

/* Scale */
transform: scale(1.5);
transform: scale(2, 0.5);  /* x, y */

/* Skew */
transform: skew(20deg, 10deg);

/* Multiple transforms */
transform: translate(50px, 50px) rotate(45deg) scale(1.2);
```

### Transition

```css
/* Smooth property changes */
transition: all 0.3s ease;
transition: background-color 0.5s ease-in-out;
transition: transform 0.3s cubic-bezier(0.4, 0, 0.2, 1);

/* Individual properties */
transition-property: color;
transition-duration: 0.3s;
transition-timing-function: ease;
transition-delay: 0.1s;
```

### Animation

```css
/* Define animation */
@keyframes slide-in {
  from {
    transform: translateX(-100%);
    opacity: 0;
  }
  to {
    transform: translateX(0);
    opacity: 1;
  }
}

/* Apply animation */
.element {
  animation: slide-in 0.5s ease-out;
}

/* Multiple steps */
@keyframes pulse {
  0% { transform: scale(1); }
  50% { transform: scale(1.1); }
  100% { transform: scale(1); }
}

.pulse {
  animation: pulse 1s infinite;
}
```

---

## 6. CSS Units Summary

### Absolute Units
```css
px    /* pixels (most common) */
pt    /* points (1/72 inch) */
cm    /* centimeters */
mm    /* millimeters */
in    /* inches */
```

### Relative Units
```css
%     /* percentage of parent */
em    /* relative to element's font-size */
rem   /* relative to root font-size */
vw    /* 1% of viewport width */
vh    /* 1% of viewport height */
vmin  /* 1% of smaller viewport dimension */
vmax  /* 1% of larger viewport dimension */
```

---

## 7. Complete Example

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>CSS Example</title>
  <link rel="stylesheet" href="style.css">
</head>
<body>
  <header>
    <h1>My Website</h1>
    <nav>
      <ul>
        <li><a href="#home">Home</a></li>
        <li><a href="#about">About</a></li>
        <li><a href="#contact">Contact</a></li>
      </ul>
    </nav>
  </header>
  
  <main>
    <section class="hero">
      <h2>Welcome to My Site</h2>
      <p>This is a demo of CSS styling</p>
      <button class="btn">Get Started</button>
    </section>
    
    <section class="content">
      <article class="card">
        <h3>Card Title</h3>
        <p>Card content goes here</p>
      </article>
    </section>
  </main>
  
  <footer>
    <p>&copy; 2024 My Website</p>
  </footer>
</body>
</html>
```

```css
/* style.css */

/* Reset */
* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}

/* Body */
body {
  font-family: Arial, sans-serif;
  line-height: 1.6;
  color: #333;
  background-color: #f4f4f4;
}

/* Header */
header {
  background: #007bff;
  color: white;
  padding: 1rem 2rem;
}

header h1 {
  font-size: 2rem;
  margin-bottom: 0.5rem;
}

/* Navigation */
nav ul {
  list-style: none;
  display: flex;
  gap: 2rem;
}

nav a {
  color: white;
  text-decoration: none;
  transition: opacity 0.3s;
}

nav a:hover {
  opacity: 0.8;
}

/* Hero Section */
.hero {
  background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);
  color: white;
  padding: 4rem 2rem;
  text-align: center;
}

.hero h2 {
  font-size: 2.5rem;
  margin-bottom: 1rem;
}

/* Button */
.btn {
  background: white;
  color: #667eea;
  padding: 0.75rem 2rem;
  border: none;
  border-radius: 25px;
  font-size: 1rem;
  cursor: pointer;
  transition: transform 0.3s, box-shadow 0.3s;
}

.btn:hover {
  transform: translateY(-2px);
  box-shadow: 0 4px 8px rgba(0,0,0,0.2);
}

/* Content */
.content {
  max-width: 1200px;
  margin: 2rem auto;
  padding: 0 2rem;
}

/* Card */
.card {
  background: white;
  padding: 2rem;
  border-radius: 8px;
  box-shadow: 0 2px 4px rgba(0,0,0,0.1);
  margin-bottom: 2rem;
}

.card h3 {
  color: #007bff;
  margin-bottom: 1rem;
}

/* Footer */
footer {
  background: #333;
  color: white;
  text-align: center;
  padding: 2rem;
  margin-top: 2rem;
}
```

---

## 8. Best Practices

### ✅ Do's

1. **Use external CSS files**
2. **Use meaningful class names** (e.g., `.btn-primary` not `.blue-btn`)
3. **Keep specificity low** (avoid overly complex selectors)
4. **Use CSS variables for consistency**
   ```css
   :root {
     --primary-color: #007bff;
     --spacing: 1rem;
   }
   
   .button {
     background: var(--primary-color);
     padding: var(--spacing);
   }
   ```
5. **Mobile-first approach** (design for mobile, enhance for desktop)
6. **Use shorthand properties** when possible
7. **Comment your code** for complex sections

### ❌ Don'ts

1. **Avoid inline styles** (except dynamic JS changes)
2. **Don't use `!important`** unless absolutely necessary
3. **Don't use too many IDs** (classes are more flexible)
4. **Don't hardcode colors everywhere** (use variables)
5. **Don't forget browser prefixes** for experimental features
6. **Don't use deprecated properties** (e.g., `<font>` tags)

---

## Summary

- **CSS** = Cascading Style Sheets for styling HTML
- **Three types**: Inline, Internal, External (use external!)
- **Selectors**: Element, class, ID, pseudo-classes, pseudo-elements
- **Common properties**: Text, background, box model, layout, colors, effects
- **Units**: Absolute (px) and relative (%, em, rem, vw, vh)
- **Best practice**: External CSS, meaningful names, low specificity, CSS variables