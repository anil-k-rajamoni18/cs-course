# 🧠 What is CSS?

Cascading Style Sheets (CSS) is the language used to style HTML documents. It allows you to control:

- Colors, fonts, spacing, sizes
- Layouts and positioning
- Responsive designs
- Animations and transitions
- Themes and dark modes

## 📌 Example:

```html
<h1>Hello World</h1>

<style>
  h1 {
    color: blue;
    font-size: 2rem;
    text-align: center;
  }
</style>
```

👉 Here, the `<h1>` text becomes blue, large, and centered.

---

# 🧰 Popular CSS Frameworks & Libraries

| Framework / Library | Description | Use Case |
|---------------------|-------------|----------|
| **Bootstrap** | Most popular CSS framework with prebuilt components | Quick prototyping |
| **Tailwind CSS** | Utility-first CSS framework | Fast, custom designs without writing CSS files |
| **Bulma** | Lightweight, flexbox-based framework | Simpler alternative to Bootstrap |
| **Foundation** | Responsive front-end framework | Large enterprise projects |
| **Material UI** | React component library implementing Material Design | Modern, Google-like UIs |
| **Chakra UI** | React component library with theme support | Accessible & fast UI building |
| **Ant Design** | Enterprise React UI library | Dashboards, admin panels |

👉 Among these, **Tailwind CSS** has become extremely popular for React/Next.js apps because it:

- Avoids writing long CSS files
- Encourages component-based design
- Gives responsive styles with ease

---

# 🐥 Tailwind CSS Crash Course

## 1. 🧭 What is Tailwind?

Tailwind CSS is a **utility-first CSS framework**. Instead of writing CSS, you use pre-defined utility classes directly in your HTML/JSX.

### 📌 Example (Without Tailwind):

```html
<button class="btn">Click Me</button>

<style>
  .btn {
    background-color: blue;
    color: white;
    padding: 0.5rem 1rem;
    border-radius: 0.5rem;
  }
</style>
```

### 📌 Example (With Tailwind):

```html
<button class="bg-blue-500 text-white px-4 py-2 rounded">Click Me</button>
```

👉 No separate CSS file needed. Just utility classes.

---

## 2. 🧪 Install Tailwind in a Next.js Project

```bash
# Inside your Next.js project
npm install -D tailwindcss postcss autoprefixer
npx tailwindcss init -p
```

Then in `tailwind.config.js`:

```javascript
content: [
  "./app/**/*.{js,ts,jsx,tsx}",
  "./pages/**/*.{js,ts,jsx,tsx}",
  "./components/**/*.{js,ts,jsx,tsx}",
],
```

In `globals.css`:

```css
@tailwind base;
@tailwind components;
@tailwind utilities;
```

Now you can use Tailwind classes anywhere 🚀

---

## 3. 🧱 Common Utility Classes

| Purpose | Examples |
|---------|----------|
| **Colors** | `text-red-500`, `bg-blue-600`, `border-gray-300` |
| **Padding / Margin** | `p-4`, `px-2`, `mt-6`, `mb-2` |
| **Text & Font** | `text-lg`, `font-bold`, `uppercase`, `text-center` |
| **Layout & Flex** | `flex`, `justify-between`, `items-center`, `gap-4` |
| **Sizing** | `w-full`, `h-10`, `max-w-screen-lg` |
| **Borders & Radius** | `border`, `border-2`, `rounded-lg` |
| **Shadows** | `shadow`, `shadow-lg`, `shadow-md` |
| **Responsive** | `md:text-2xl`, `sm:flex-col`, `lg:gap-8` |

### 📌 Example:

```jsx
<div className="flex justify-between items-center bg-gray-100 p-4 rounded-lg">
  <h1 className="text-xl font-bold">Hello Tailwind</h1>
  <button className="bg-blue-500 text-white px-4 py-2 rounded hover:bg-blue-600">
    Click
  </button>
</div>
```

---

## 4. 📱 Responsive Design

Tailwind makes responsiveness simple:

```jsx
<p className="text-sm md:text-base lg:text-lg">
  This text size changes with screen size
</p>
```

- `sm:` → small screens
- `md:` → tablets
- `lg:` → laptops
- `xl:` → large monitors

---

## 5. 🧭 Dark Mode & Themes

In `tailwind.config.js`:

```javascript
darkMode: 'class',
```

Use:

```jsx
<div className="bg-white dark:bg-gray-900 text-black dark:text-white">
  Hello Dark Mode 🌙
</div>
```

Toggling `dark` class on the `<html>` or `<body>` element switches the theme.

---

## 6. ✨ Animations & Transitions

```jsx
<button className="bg-blue-500 text-white px-4 py-2 rounded 
                   hover:bg-blue-600 transition duration-300">
  Hover Me
</button>
```

- `transition` enables smooth hover effect
- `duration-300` = 300ms animation

---

## 7. 🛠️ Reusable Components with @apply

You can combine utility classes in CSS files:

```css
.btn-primary {
  @apply bg-blue-500 text-white px-4 py-2 rounded hover:bg-blue-600;
}
```

Then use:

```html
<button className="btn-primary">Click</button>
```

---

## 8. 🚀 Tailwind UI Add-ons

- **DaisyUI** – prebuilt Tailwind components like buttons, modals, etc.
- **shadcn/ui** – beautiful headless components for React apps.
- **Heroicons** – SVG icons designed for Tailwind.

---

# 🧭 Mini Tailwind Project Idea: "Landing Page"

Build a simple responsive landing page with:

✅ Navbar with logo and links  
✅ Hero section with a call to action  
✅ Features grid  
✅ Footer

### 📌 Example structure:

```
components/
  Navbar.tsx
  Hero.tsx
  Features.tsx
  Footer.tsx
```

Use Tailwind classes for all styling. No CSS file needed.

---

# 🏁 Summary

✅ CSS = styles HTML elements  
✅ Frameworks help speed up styling  
✅ Tailwind = utility-first, responsive, fast UI building  
✅ Integrates beautifully with Next.js & React