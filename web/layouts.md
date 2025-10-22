# CSS Layout Techniques & Flexbox

## 1. Different CSS Layout Techniques

| Layout Method | Description | Best For |
|--------------|-------------|----------|
| **Normal Flow (Block & Inline)** | Default layout (elements stack vertically or inline) | Simple static layouts |
| **Float Layout** | Using `float` and `clear` to position elements | Legacy layouts, wrapping text around images |
| **Positioning** | Using `position: relative, absolute, fixed, sticky` | Overlapping, fixed headers, popups |
| **Flexbox Layout** | One-dimensional layout (row or column) | Navbars, toolbars, cards, centering elements |
| **Grid Layout** | Two-dimensional layout (rows and columns) | Page layouts, dashboards, complex designs |
| **Multi-column Layout** | `column-count` or `column-width` | Newspaper or magazine style layouts |
| **Table Layout** | Using `display: table` (or HTML tables) | Tabular data, legacy systems |

### Most Common Modern Layouts

✅ **Flexbox** for linear content (e.g., navbars, cards)  
✅ **Grid** for page-level layout (e.g., dashboards, templates)

---

## 2. CSS Grid Layout

The CSS Grid Layout is a **two-dimensional layout system** — you can create both rows and columns easily.

Think of it like drawing a table, but with full control over placement, sizing, and alignment.

### Basic Structure

```html
<div class="grid-container">
  <div class="item">1</div>
  <div class="item">2</div>
  <div class="item">3</div>
  <div class="item">4</div>
</div>
```

```css
.grid-container {
  display: grid;                      /* Enable grid */
  grid-template-columns: 100px 100px; /* 2 columns */
  grid-template-rows: 100px 100px;    /* 2 rows */
  gap: 10px;                          /* space between cells */
}

.item {
  background: lightblue;
  padding: 20px;
  text-align: center;
  border: 1px solid #333;
}
```

**Result:** A 2×2 grid with 4 boxes arranged neatly.

### Common Grid Properties

#### `display: grid`
Turns an element into a grid container.

#### `grid-template-columns` / `grid-template-rows`
Defines how many columns and rows and their sizes.

```css
grid-template-columns: 200px 1fr 2fr;
/* 1st column = 200px, 2nd = flexible (1 part), 3rd = flexible (2 parts) */
```

💡 `fr` = fraction unit (very useful for responsive design).

#### `gap` (or `row-gap` / `column-gap`)
Sets the spacing between rows and columns.

```css
gap: 20px;
```

#### `justify-items` & `align-items`
Aligns content inside each grid cell.

| Property | Values | Effect |
|----------|--------|--------|
| `justify-items` | start, end, center, stretch | Align horizontally inside cells |
| `align-items` | start, end, center, stretch | Align vertically inside cells |

#### `justify-content` & `align-content`
Align the whole grid inside the container.

| Property | Values | Effect |
|----------|--------|--------|
| `justify-content` | start, end, center, space-between, space-around | Horizontal alignment of the grid |
| `align-content` | start, end, center, space-between, space-around | Vertical alignment of the grid |

#### `grid-column` & `grid-row`
Lets you place items spanning specific columns/rows.

```css
.item1 {
  grid-column: 1 / 3;   /* spans from col 1 to 3 */
  grid-row: 1 / 2;
}
```

👉 Great for making one item bigger than the others (e.g., header or sidebar).

#### `repeat()` function
A shortcut to avoid repeating column sizes manually.

```css
grid-template-columns: repeat(3, 1fr);
/* 3 columns of equal size */
```

#### `auto-fit` & `auto-fill`
Useful for responsive layouts:

```css
grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
```

✅ This creates as many columns as will fit, each at least 200px, and expands them to fill available space.

### Example: Responsive Grid

```html
<div class="grid-container">
  <div class="item">1</div>
  <div class="item">2</div>
  <div class="item">3</div>
  <div class="item">4</div>
  <div class="item">5</div>
</div>
```

```css
.grid-container {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(150px, 1fr));
  gap: 15px;
}

.item {
  background: lightgreen;
  padding: 20px;
  text-align: center;
  border: 1px solid #333;
}
```

**Result:**
- Automatically adjusts number of columns as the screen shrinks.
- Boxes never overflow.
- Great for galleries, product listings, or dashboards.

### CSS Grid vs Flexbox

| Feature | Flexbox | Grid |
|---------|---------|------|
| Direction | 1-D (row or column) | 2-D (rows and columns) |
| Best for | Menus, toolbars, small layouts | Full page layouts, complex grids |
| Alignment | Per item | Entire structure |
| Gap support | Yes | Yes |

👉 **Flexbox** = for aligning items in a line.  
👉 **Grid** = for structuring an entire layout.

---

## 3. CSS Flexbox Layout

The CSS Flexible Box Layout (commonly called **Flexbox**) is one of the most powerful layout systems in modern CSS.

Unlike Grid, which works in two dimensions (rows + columns), **Flexbox works in one dimension** — either a row or a column.

### Perfect for:
- Navigation bars 🧭
- Horizontal/vertical centering 🎯
- Equal-height boxes 📦
- Responsive content alignment 📱

### How Flexbox Works

To use Flexbox:
1. Make the parent container a flex container with `display: flex;`.
2. The child elements inside become flex items and can be aligned or ordered.

```html
<div class="container">
  <div class="item">1</div>
  <div class="item">2</div>
  <div class="item">3</div>
</div>
```

```css
.container {
  display: flex;
  background: #eee;
  padding: 10px;
}

.item {
  background: tomato;
  color: white;
  padding: 20px;
  margin: 5px;
}
```

**Result:** All three boxes are arranged in a single row.

### Container Properties (Parent)

| Property | Description |
|----------|-------------|
| `display: flex` | Enables flexbox layout on the container |
| `flex-direction` | Sets the direction of flex items (row or column) |
| `justify-content` | Aligns items horizontally along main axis |
| `align-items` | Aligns items vertically along cross axis |
| `align-content` | Aligns multiple rows (when wrapping) |
| `flex-wrap` | Allows items to wrap onto multiple lines |
| `gap` | Adds space between flex items |

#### `flex-direction`
Determines the main axis direction.

```css
flex-direction: row;        /* default — items go left to right */
flex-direction: row-reverse;
flex-direction: column;     /* top to bottom */
flex-direction: column-reverse;
```

#### `justify-content` (main axis)
Aligns items along the main axis.

```css
justify-content: flex-start;    /* default, left aligned */
justify-content: flex-end;      /* right aligned */
justify-content: center;        /* centered */
justify-content: space-between; /* equal space between */
justify-content: space-around;  /* space around each item */
justify-content: space-evenly;  /* equal space on all sides */
```

#### `align-items` (cross axis)
Aligns items perpendicular to the main axis.

```css
align-items: stretch;     /* default */
align-items: flex-start;  /* top (or left if column) */
align-items: flex-end;    /* bottom (or right if column) */
align-items: center;      /* center */
align-items: baseline;    /* align by text baseline */
```

#### `flex-wrap`
By default, flex items don't wrap. You can change that:

```css
flex-wrap: nowrap;      /* default */
flex-wrap: wrap;        /* wraps items to new lines */
flex-wrap: wrap-reverse;
```

Often used with `flex-direction`:

```css
flex-flow: row wrap;  /* shorthand for flex-direction + flex-wrap */
```

#### `gap`
Adds spacing between flex items (no need for margins!):

```css
gap: 10px;
```

#### `align-content` (when multiple rows exist)
Controls spacing between wrapped lines (not single-line).

```css
align-content: flex-start;
align-content: flex-end;
align-content: center;
align-content: space-between;
align-content: space-around;
align-content: stretch;
```

### Item Properties (Child)

| Property | Description |
|----------|-------------|
| `order` | Changes the visual order of the item |
| `flex-grow` | Defines how much an item grows relative to others |
| `flex-shrink` | Defines how much an item shrinks |
| `flex-basis` | Defines the starting size of the item |
| `flex` | Shorthand for `flex-grow`, `flex-shrink`, and `flex-basis` |
| `align-self` | Overrides `align-items` for a specific item |

#### `order`

```css
.item1 { order: 3; }
.item2 { order: 1; }
.item3 { order: 2; }
```

✅ Changes the visual order without touching the HTML.

#### `flex-grow` / `flex-shrink` / `flex-basis`

```css
.item1 { flex-grow: 1; }  /* expands more */
.item2 { flex-grow: 2; }  /* expands twice as much */
```

👉 `flex` shorthand:

```css
flex: 1 1 100px;  /* grow | shrink | basis */
```

#### `align-self`
Overrides vertical alignment for one item:

```css
.item2 {
  align-self: flex-end;
}
```

### Example: Centering with Flexbox

```html
<div class="container">
  <div class="item">Centered</div>
</div>
```

```css
.container {
  display: flex;
  justify-content: center;  /* horizontal */
  align-items: center;      /* vertical */
  height: 300px;
  background: lightgray;
}

.item {
  background: tomato;
  color: #fff;
  padding: 20px;
}
```

✅ **Result:** The box is perfectly centered both horizontally and vertically.

### Flexbox vs Grid

| Feature | Flexbox | Grid |
|---------|---------|------|
| Direction | 1D (row OR column) | 2D (rows AND columns) |
| Alignment | Per line | Entire layout |
| Use case | Navbars, small components | Page structure, complex layouts |
| Wrapping | `flex-wrap` | Controlled with row/column definitions |

### Common Real Uses of Flexbox:
- ✅ Navbars & menus
- ✅ Centering content inside a container
- ✅ Equal-width or height columns
- ✅ Responsive cards layout
- ✅ Sidebar + content structure

---

## Quick Recap

### CSS Grid Key Properties:
- `grid-template-columns`, `grid-template-rows`
- `gap`
- `justify-items`, `align-items`
- `grid-column`, `grid-row`
- `repeat()`, `auto-fit` for responsive layouts

### Flexbox Key Properties:
- **Container:** `display: flex`, `flex-direction`, `justify-content`, `align-items`, `flex-wrap`, `gap`
- **Items:** `order`, `flex-grow`, `flex-shrink`, `flex-basis`, `flex`, `align-self`