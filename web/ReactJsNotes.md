# ⚛️ React 19 + TypeScript — In-Depth Crash Course

> **Stack:** React 19 · TypeScript 5.x · Vite 6 · React Router v7 · TanStack Query v5 · Zustand v5 · React Hook Form v7 · Zod v3 · Tailwind CSS v4 · Framer Motion v12 · Vitest · Testing Library

---

## Table of Contents

1. [TypeScript Essentials for React](#1-typescript-essentials-for-react)
2. [React 19 Fundamentals](#2-react-19-fundamentals)
3. [Hooks — Deep Dive](#3-hooks--deep-dive)
4. [New React 19 Hooks & APIs](#4-new-react-19-hooks--apis)
5. [Component Patterns](#5-component-patterns)
6. [React Context — Advanced](#6-react-context--advanced)
7. [Performance Optimization](#7-performance-optimization)
8. [React Router v7](#8-react-router-v7)
9. [Data Fetching — TanStack Query v5](#9-data-fetching--tanstack-query-v5)
10. [State Management — Zustand v5](#10-state-management--zustand-v5)
11. [Forms — React Hook Form + Zod](#11-forms--react-hook-form--zod)
12. [Animations — Framer Motion v12](#12-animations--framer-motion-v12)
13. [Error Handling & Boundaries](#13-error-handling--boundaries)
14. [Testing — Vitest + Testing Library](#14-testing--vitest--testing-library)
15. [Custom Hooks Library](#15-custom-hooks-library)
16. [🏗️ Final Project: DevBoard — Real-Time Dev Dashboard](#16-final-project-devboard)

---

## 1. TypeScript Essentials for React

### 1.1 Component Props Typing

```tsx
// ─── Basic Props ──────────────────────────────────────────────────────────────
interface ButtonProps {
  label: string;
  variant?: "primary" | "secondary" | "ghost" | "danger";
  size?: "sm" | "md" | "lg";
  disabled?: boolean;
  loading?: boolean;
  onClick?: (event: React.MouseEvent<HTMLButtonElement>) => void;
  className?: string;
}

const Button: React.FC<ButtonProps> = ({
  label,
  variant = "primary",
  size = "md",
  disabled = false,
  loading = false,
  onClick,
  className,
}) => {
  return (
    <button
      className={`btn btn-${variant} btn-${size} ${className ?? ""}`}
      disabled={disabled || loading}
      onClick={onClick}
    >
      {loading ? <Spinner /> : label}
    </button>
  );
};

// ─── Children Props ───────────────────────────────────────────────────────────
interface CardProps {
  title: string;
  children: React.ReactNode;       // Any renderable content
  footer?: React.ReactElement;     // Specifically a React element
  header?: JSX.Element;            // Same as React.ReactElement
}

// ─── Extending HTML Elements ──────────────────────────────────────────────────
interface InputProps extends React.InputHTMLAttributes<HTMLInputElement> {
  label: string;
  error?: string;
  hint?: string;
}

const Input = React.forwardRef<HTMLInputElement, InputProps>(
  ({ label, error, hint, className, ...rest }, ref) => (
    <div className="form-field">
      <label>{label}</label>
      <input ref={ref} className={`input ${error ? "input-error" : ""} ${className ?? ""}`} {...rest} />
      {hint && <span className="hint">{hint}</span>}
      {error && <span className="error">{error}</span>}
    </div>
  )
);
Input.displayName = "Input";
```

### 1.2 Generic Components

```tsx
// ─── Generic List ─────────────────────────────────────────────────────────────
interface ListProps<T> {
  items: T[];
  renderItem: (item: T, index: number) => React.ReactNode;
  keyExtractor: (item: T) => string;
  emptyState?: React.ReactNode;
  className?: string;
}

function List<T>({ items, renderItem, keyExtractor, emptyState, className }: ListProps<T>) {
  if (items.length === 0) return <>{emptyState ?? <p>No items found</p>}</>;
  return (
    <ul className={className}>
      {items.map((item, i) => (
        <li key={keyExtractor(item)}>{renderItem(item, i)}</li>
      ))}
    </ul>
  );
}

// Usage — TypeScript infers T as User
<List
  items={users}
  keyExtractor={(u) => u.id}
  renderItem={(u) => <UserCard user={u} />}
/>

// ─── Generic Select ───────────────────────────────────────────────────────────
interface SelectProps<T extends { id: string; label: string }> {
  options: T[];
  value: T | null;
  onChange: (value: T) => void;
  placeholder?: string;
}

function Select<T extends { id: string; label: string }>({
  options, value, onChange, placeholder = "Select...",
}: SelectProps<T>) {
  return (
    <select value={value?.id ?? ""} onChange={(e) => {
      const found = options.find((o) => o.id === e.target.value);
      if (found) onChange(found);
    }}>
      <option value="" disabled>{placeholder}</option>
      {options.map((opt) => (
        <option key={opt.id} value={opt.id}>{opt.label}</option>
      ))}
    </select>
  );
}
```

### 1.3 Event & Handler Types

```tsx
// ─── Common event handler types ───────────────────────────────────────────────
type ClickHandler = React.MouseEventHandler<HTMLButtonElement>;
type ChangeHandler = React.ChangeEventHandler<HTMLInputElement>;
type SubmitHandler = React.FormEventHandler<HTMLFormElement>;
type KeyHandler = React.KeyboardEventHandler<HTMLInputElement>;
type FocusHandler = React.FocusEventHandler<HTMLInputElement>;

// ─── Custom event payloads ────────────────────────────────────────────────────
type SortDirection = "asc" | "desc";
type SortChangeHandler<T extends string = string> = (
  field: T,
  direction: SortDirection
) => void;

// ─── Async handlers with explicit types ──────────────────────────────────────
interface FormState {
  isSubmitting: boolean;
  error: string | null;
}

const handleSubmit = async (e: React.FormEvent<HTMLFormElement>): Promise<void> => {
  e.preventDefault();
  const formData = new FormData(e.currentTarget);
  const email = formData.get("email") as string;
  // ...
};
```

### 1.4 Utility Types for React

```tsx
// ─── Extract component props ──────────────────────────────────────────────────
type ButtonProps = React.ComponentProps<typeof Button>;
type DivProps = React.ComponentPropsWithoutRef<"div">;
type InputWithRef = React.ComponentPropsWithRef<"input">;

// ─── Polymorphic component pattern ───────────────────────────────────────────
type PolymorphicProps<T extends React.ElementType, P = {}> = P &
  Omit<React.ComponentPropsWithoutRef<T>, keyof P> & { as?: T };

function Text<T extends React.ElementType = "p">({
  as,
  children,
  ...props
}: PolymorphicProps<T, { children: React.ReactNode }>) {
  const Component = as ?? "p";
  return <Component {...props}>{children}</Component>;
}

<Text as="h1" className="text-3xl">Heading</Text>  // renders <h1>
<Text as="span" className="text-sm">Small</Text>   // renders <span>

// ─── Discriminated union props ────────────────────────────────────────────────
type AlertProps =
  | { variant: "success"; message: string }
  | { variant: "error"; message: string; retry?: () => void }
  | { variant: "warning"; message: string; dismissible: boolean };

function Alert(props: AlertProps) {
  if (props.variant === "error" && props.retry) {
    return <div>Error: {props.message} <button onClick={props.retry}>Retry</button></div>;
  }
  return <div className={`alert-${props.variant}`}>{props.message}</div>;
}
```

---

## 2. React 19 Fundamentals

### 2.1 JSX & Rendering

```tsx
// ─── JSX fundamentals ─────────────────────────────────────────────────────────
// React 19: No need to import React for JSX (automatic runtime)
function App() {
  const name = "World";
  const isLoggedIn = true;
  const items = ["Apple", "Banana", "Cherry"];
  const style: React.CSSProperties = { color: "blue", fontSize: 16 };

  return (
    <div style={style}>
      {/* Expressions in JSX */}
      <h1>Hello, {name}!</h1>

      {/* Conditional rendering */}
      {isLoggedIn ? <Dashboard /> : <Login />}
      {isLoggedIn && <UserMenu />}

      {/* List rendering */}
      <ul>
        {items.map((item) => (
          <li key={item}>{item}</li>
        ))}
      </ul>

      {/* Fragment shorthand */}
      <>
        <Header />
        <Main />
        <Footer />
      </>
    </div>
  );
}
```

### 2.2 Functional Components

```tsx
// ─── Function declaration ─────────────────────────────────────────────────────
function UserCard({ user }: { user: User }) {
  return (
    <div className="card">
      <img src={user.avatar} alt={user.name} />
      <h3>{user.name}</h3>
      <p>{user.email}</p>
    </div>
  );
}

// ─── Arrow function ───────────────────────────────────────────────────────────
const UserBadge = ({ role }: { role: string }) => (
  <span className={`badge badge-${role}`}>{role}</span>
);

// ─── Default props pattern ────────────────────────────────────────────────────
interface AvatarProps {
  src?: string;
  name: string;
  size?: number;
}

function Avatar({ src, name, size = 40 }: AvatarProps) {
  if (!src) {
    return (
      <div
        style={{ width: size, height: size }}
        className="avatar-placeholder"
        aria-label={name}
      >
        {name.charAt(0).toUpperCase()}
      </div>
    );
  }
  return <img src={src} alt={name} width={size} height={size} className="avatar" />;
}
```

### 2.3 React 19 — ref as Prop (No More forwardRef)

```tsx
// ✅ React 19 — ref is just a prop now!
interface InputProps extends React.InputHTMLAttributes<HTMLInputElement> {
  label: string;
  ref?: React.Ref<HTMLInputElement>;
}

function Input({ label, ref, ...props }: InputProps) {
  return (
    <div>
      <label>{label}</label>
      <input ref={ref} {...props} />
    </div>
  );
}

// Usage — no forwardRef wrapper needed
const inputRef = useRef<HTMLInputElement>(null);
<Input label="Email" ref={inputRef} type="email" />;

// ─── React 18 (old way — still works but deprecated) ──────────────────────────
const OldInput = React.forwardRef<HTMLInputElement, InputProps>((props, ref) => {
  return <input ref={ref} {...props} />;
});
```

---

## 3. Hooks — Deep Dive

### 3.1 useState

```tsx
import { useState } from "react";

// ─── Basic ─────────────────────────────────────────────────────────────────────
const [count, setCount] = useState(0);
const [name, setName] = useState<string>("");
const [user, setUser] = useState<User | null>(null);

// ─── Lazy initialization (expensive computation runs once) ───────────────────
const [data, setData] = useState<number[]>(() => {
  return Array.from({ length: 1000 }, (_, i) => i * 2);
});

// ─── Functional updates (always use when new state depends on old) ────────────
setCount((prev) => prev + 1);  // ✅ Safe
setCount(count + 1);            // ❌ Stale closure risk

// ─── Object state ─────────────────────────────────────────────────────────────
const [form, setForm] = useState({ name: "", email: "", age: 0 });

// ✅ Spread to keep other fields
const updateField = (field: keyof typeof form, value: string) => {
  setForm((prev) => ({ ...prev, [field]: value }));
};

// ─── Toggle pattern ───────────────────────────────────────────────────────────
const [isOpen, setIsOpen] = useState(false);
const toggle = () => setIsOpen((prev) => !prev);
```

### 3.2 useEffect

```tsx
import { useEffect, useState } from "react";

// ─── Dependency rules ─────────────────────────────────────────────────────────
// [] = run once on mount
// [dep] = run when dep changes
// no array = run on every render ← rarely what you want

// ─── Data fetching (basic) ────────────────────────────────────────────────────
function UserProfile({ userId }: { userId: string }) {
  const [user, setUser] = useState<User | null>(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState<Error | null>(null);

  useEffect(() => {
    let cancelled = false; // Prevent setting state after unmount

    const fetchUser = async () => {
      try {
        setLoading(true);
        const data = await api.getUser(userId);
        if (!cancelled) setUser(data);
      } catch (err) {
        if (!cancelled) setError(err as Error);
      } finally {
        if (!cancelled) setLoading(false);
      }
    };

    fetchUser();

    return () => { cancelled = true; }; // Cleanup
  }, [userId]); // Re-fetch when userId changes

  if (loading) return <Spinner />;
  if (error) return <ErrorMessage error={error} />;
  return <div>{user?.name}</div>;
}

// ─── Event listeners ──────────────────────────────────────────────────────────
function useWindowSize() {
  const [size, setSize] = useState({ width: window.innerWidth, height: window.innerHeight });

  useEffect(() => {
    const handler = () => setSize({ width: window.innerWidth, height: window.innerHeight });
    window.addEventListener("resize", handler);
    return () => window.removeEventListener("resize", handler);
  }, []);

  return size;
}

// ─── Subscription cleanup ─────────────────────────────────────────────────────
useEffect(() => {
  const subscription = store.subscribe((state) => setData(state));
  return () => subscription.unsubscribe(); // Always clean up subscriptions
}, []);

// ─── Interval ────────────────────────────────────────────────────────────────
useEffect(() => {
  const id = setInterval(() => setTick((t) => t + 1), 1000);
  return () => clearInterval(id);
}, []);
```

### 3.3 useReducer

```tsx
import { useReducer } from "react";

// ─── Types ────────────────────────────────────────────────────────────────────
interface TodoState {
  todos: Todo[];
  filter: "all" | "active" | "completed";
  loading: boolean;
  error: string | null;
}

type TodoAction =
  | { type: "ADD_TODO"; payload: Todo }
  | { type: "TOGGLE_TODO"; payload: string }
  | { type: "REMOVE_TODO"; payload: string }
  | { type: "SET_FILTER"; payload: TodoState["filter"] }
  | { type: "SET_LOADING"; payload: boolean }
  | { type: "SET_ERROR"; payload: string | null }
  | { type: "LOAD_TODOS"; payload: Todo[] };

const initialState: TodoState = {
  todos: [],
  filter: "all",
  loading: false,
  error: null,
};

function todoReducer(state: TodoState, action: TodoAction): TodoState {
  switch (action.type) {
    case "ADD_TODO":
      return { ...state, todos: [...state.todos, action.payload] };
    case "TOGGLE_TODO":
      return {
        ...state,
        todos: state.todos.map((t) =>
          t.id === action.payload ? { ...t, completed: !t.completed } : t
        ),
      };
    case "REMOVE_TODO":
      return { ...state, todos: state.todos.filter((t) => t.id !== action.payload) };
    case "SET_FILTER":
      return { ...state, filter: action.payload };
    case "SET_LOADING":
      return { ...state, loading: action.payload };
    case "SET_ERROR":
      return { ...state, error: action.payload };
    case "LOAD_TODOS":
      return { ...state, todos: action.payload, loading: false };
    default:
      return state;
  }
}

function TodoApp() {
  const [state, dispatch] = useReducer(todoReducer, initialState);

  const addTodo = (title: string) => {
    dispatch({ type: "ADD_TODO", payload: { id: crypto.randomUUID(), title, completed: false } });
  };

  const filteredTodos = state.todos.filter((t) => {
    if (state.filter === "active") return !t.completed;
    if (state.filter === "completed") return t.completed;
    return true;
  });

  return (/* ... */);
}
```

### 3.4 useRef

```tsx
import { useRef, useEffect } from "react";

// ─── DOM access ───────────────────────────────────────────────────────────────
function AutoFocusInput() {
  const inputRef = useRef<HTMLInputElement>(null);

  useEffect(() => {
    inputRef.current?.focus();
  }, []);

  return <input ref={inputRef} placeholder="Auto-focused" />;
}

// ─── Mutable value (does NOT trigger re-render) ───────────────────────────────
function StopWatch() {
  const [elapsed, setElapsed] = useState(0);
  const intervalRef = useRef<ReturnType<typeof setInterval> | null>(null);

  const start = () => {
    if (intervalRef.current) return;
    const startTime = Date.now() - elapsed;
    intervalRef.current = setInterval(() => {
      setElapsed(Date.now() - startTime);
    }, 10);
  };

  const stop = () => {
    if (intervalRef.current) {
      clearInterval(intervalRef.current);
      intervalRef.current = null;
    }
  };

  return (
    <div>
      <span>{(elapsed / 1000).toFixed(2)}s</span>
      <button onClick={start}>Start</button>
      <button onClick={stop}>Stop</button>
    </div>
  );
}

// ─── Previous value pattern ───────────────────────────────────────────────────
function usePrevious<T>(value: T): T | undefined {
  const ref = useRef<T | undefined>(undefined);
  useEffect(() => { ref.current = value; });
  return ref.current;
}
```

### 3.5 useMemo & useCallback

```tsx
import { useMemo, useCallback } from "react";

// ─── useMemo — expensive computation ─────────────────────────────────────────
function DataTable({ data, filters }: { data: Row[]; filters: Filters }) {
  // Only recomputes when data or filters change
  const filteredData = useMemo(() => {
    return data
      .filter((row) => row.status === filters.status)
      .filter((row) => row.name.toLowerCase().includes(filters.search.toLowerCase()))
      .sort((a, b) => a.name.localeCompare(b.name));
  }, [data, filters]);

  const stats = useMemo(() => ({
    total: filteredData.length,
    active: filteredData.filter((r) => r.status === "active").length,
    avgScore: filteredData.reduce((sum, r) => sum + r.score, 0) / filteredData.length,
  }), [filteredData]);

  return (/* ... */);
}

// ─── useCallback — stable function reference ──────────────────────────────────
function ParentList({ items }: { items: Item[] }) {
  const [selected, setSelected] = useState<string[]>([]);

  // Without useCallback: new function on every render → ChildItem always re-renders
  // With useCallback: same reference if no deps change → ChildItem skips re-render
  const handleSelect = useCallback((id: string) => {
    setSelected((prev) =>
      prev.includes(id) ? prev.filter((x) => x !== id) : [...prev, id]
    );
  }, []); // No deps — setSelected is stable

  return (
    <ul>
      {items.map((item) => (
        <ChildItem key={item.id} item={item} onSelect={handleSelect} />
      ))}
    </ul>
  );
}

const ChildItem = React.memo(({ item, onSelect }: {
  item: Item;
  onSelect: (id: string) => void;
}) => {
  console.log("ChildItem render:", item.id); // Only fires when needed
  return <li onClick={() => onSelect(item.id)}>{item.name}</li>;
});
```

### 3.6 useContext

```tsx
import { createContext, useContext, useState } from "react";

// ─── Typed context ────────────────────────────────────────────────────────────
interface ThemeContextValue {
  theme: "light" | "dark";
  toggleTheme: () => void;
  setTheme: (theme: "light" | "dark") => void;
}

const ThemeContext = createContext<ThemeContextValue | null>(null);

// Safe hook that throws if used outside provider
export function useTheme(): ThemeContextValue {
  const ctx = useContext(ThemeContext);
  if (!ctx) throw new Error("useTheme must be used within ThemeProvider");
  return ctx;
}

export function ThemeProvider({ children }: { children: React.ReactNode }) {
  const [theme, setTheme] = useState<"light" | "dark">(() => {
    return (localStorage.getItem("theme") as "light" | "dark") ?? "light";
  });

  const toggleTheme = () => {
    setTheme((prev) => {
      const next = prev === "light" ? "dark" : "light";
      localStorage.setItem("theme", next);
      return next;
    });
  };

  return (
    <ThemeContext.Provider value={{ theme, toggleTheme, setTheme }}>
      <div data-theme={theme}>{children}</div>
    </ThemeContext.Provider>
  );
}

// Usage
function Header() {
  const { theme, toggleTheme } = useTheme();
  return (
    <header>
      <span>Current: {theme}</span>
      <button onClick={toggleTheme}>Toggle</button>
    </header>
  );
}
```

---

## 4. New React 19 Hooks & APIs

### 4.1 use() Hook

```tsx
import { use, Suspense } from "react";

// ─── Unwrap Promises directly in render ───────────────────────────────────────
function UserProfile({ userPromise }: { userPromise: Promise<User> }) {
  // use() suspends until the promise resolves
  const user = use(userPromise);
  return <div>{user.name}</div>;
}

// Parent wraps with Suspense
function App() {
  const userPromise = fetchUser("123"); // Promise, not await

  return (
    <Suspense fallback={<Spinner />}>
      <UserProfile userPromise={userPromise} />
    </Suspense>
  );
}

// ─── use() with Context (conditionally!) ──────────────────────────────────────
// Unlike useContext, use() can be called inside if/loops
function Button({ type }: { type: "submit" | "button" }) {
  if (type === "submit") {
    const theme = use(ThemeContext); // ✅ Conditional context use
    return <button style={{ background: theme?.primary }}>Submit</button>;
  }
  return <button>Button</button>;
}
```

### 4.2 useTransition & startTransition

```tsx
import { useTransition, useState } from "react";

// ─── Mark non-urgent state updates ────────────────────────────────────────────
function SearchPage() {
  const [query, setQuery] = useState("");
  const [results, setResults] = useState<SearchResult[]>([]);
  const [isPending, startTransition] = useTransition();

  const handleSearch = (value: string) => {
    setQuery(value); // Urgent: update input immediately

    startTransition(() => {
      // Non-urgent: React can interrupt this for more important updates
      const filtered = heavySearch(allData, value);
      setResults(filtered);
    });
  };

  return (
    <div>
      <input value={query} onChange={(e) => handleSearch(e.target.value)} />
      {isPending && <div className="loading-bar" />}
      <ResultsList results={results} />
    </div>
  );
}
```

### 4.3 useOptimistic (React 19)

```tsx
import { useOptimistic, useTransition } from "react";

interface Message { id: string; text: string; status: "sent" | "pending" | "failed"; }

function Chat({ messages, projectId }: { messages: Message[]; projectId: string }) {
  const [optimisticMessages, addOptimisticMessage] = useOptimistic(
    messages,
    (state: Message[], newMessage: Message) => [...state, newMessage]
  );
  const [, startTransition] = useTransition();

  const sendMessage = (text: string) => {
    const tempMessage: Message = {
      id: crypto.randomUUID(),
      text,
      status: "pending",
    };

    startTransition(async () => {
      addOptimisticMessage(tempMessage); // Shows immediately

      try {
        await api.sendMessage(projectId, text); // Real API call
        // On success, server response refreshes messages
      } catch {
        // On failure, optimistic update is reverted automatically
      }
    });
  };

  return (
    <div>
      {optimisticMessages.map((msg) => (
        <div key={msg.id} className={`message ${msg.status}`}>
          {msg.text}
          {msg.status === "pending" && <span>...</span>}
        </div>
      ))}
      <MessageInput onSend={sendMessage} />
    </div>
  );
}
```

### 4.4 useFormStatus & useActionState (React 19)

```tsx
import { useFormStatus, useActionState } from "react-dom";

// ─── useFormStatus — access parent form state ─────────────────────────────────
function SubmitButton() {
  const { pending, data, method, action } = useFormStatus();

  return (
    <button type="submit" disabled={pending}>
      {pending ? "Submitting..." : "Submit"}
    </button>
  );
}

// ─── useActionState — manage form action state ───────────────────────────────
type FormState = { success: boolean; message: string; errors?: Record<string, string> };

async function submitContactForm(
  prevState: FormState,
  formData: FormData
): Promise<FormState> {
  const name = formData.get("name") as string;
  const email = formData.get("email") as string;

  if (!name) return { success: false, message: "Validation failed", errors: { name: "Required" } };

  try {
    await api.submitContact({ name, email });
    return { success: true, message: "Message sent successfully!" };
  } catch {
    return { success: false, message: "Failed to send. Please try again." };
  }
}

function ContactForm() {
  const [state, formAction, isPending] = useActionState(submitContactForm, {
    success: false,
    message: "",
  });

  return (
    <form action={formAction}>
      <input name="name" placeholder="Your name" />
      {state.errors?.name && <span className="error">{state.errors.name}</span>}
      <input name="email" placeholder="Your email" />
      {state.message && (
        <p className={state.success ? "text-green-500" : "text-red-500"}>
          {state.message}
        </p>
      )}
      <SubmitButton />
    </form>
  );
}
```

### 4.5 useDeferredValue

```tsx
import { useDeferredValue, memo } from "react";

function SearchResults({ query }: { query: string }) {
  const deferredQuery = useDeferredValue(query);
  const isStale = query !== deferredQuery;

  // deferredQuery lags behind query — UI stays responsive while computing
  const results = useMemo(() => heavyFilter(data, deferredQuery), [deferredQuery]);

  return (
    <div style={{ opacity: isStale ? 0.5 : 1 }}>
      {results.map((r) => <ResultItem key={r.id} item={r} />)}
    </div>
  );
}
```

### 4.6 React 19 — Document Metadata in Components

```tsx
// React 19: You can render <title>, <meta>, <link> directly in components
// They automatically hoist to <head>

function ProductPage({ product }: { product: Product }) {
  return (
    <>
      <title>{product.name} | My Store</title>
      <meta name="description" content={product.description} />
      <link rel="canonical" href={`https://store.com/products/${product.slug}`} />

      <main>
        <h1>{product.name}</h1>
        <p>{product.description}</p>
      </main>
    </>
  );
}
```

---

## 5. Component Patterns

### 5.1 Compound Components

```tsx
// ─── Compound Component Pattern ───────────────────────────────────────────────
interface TabsContextValue {
  activeTab: string;
  setActiveTab: (id: string) => void;
}

const TabsContext = createContext<TabsContextValue | null>(null);

const useTabsContext = () => {
  const ctx = useContext(TabsContext);
  if (!ctx) throw new Error("Must be used inside <Tabs>");
  return ctx;
};

// Root
function Tabs({ children, defaultTab }: { children: React.ReactNode; defaultTab: string }) {
  const [activeTab, setActiveTab] = useState(defaultTab);
  return (
    <TabsContext.Provider value={{ activeTab, setActiveTab }}>
      <div className="tabs">{children}</div>
    </TabsContext.Provider>
  );
}

// Sub-components
Tabs.List = function TabsList({ children }: { children: React.ReactNode }) {
  return <div className="tabs-list" role="tablist">{children}</div>;
};

Tabs.Tab = function Tab({ id, children }: { id: string; children: React.ReactNode }) {
  const { activeTab, setActiveTab } = useTabsContext();
  return (
    <button
      role="tab"
      aria-selected={activeTab === id}
      onClick={() => setActiveTab(id)}
      className={`tab ${activeTab === id ? "tab-active" : ""}`}
    >
      {children}
    </button>
  );
};

Tabs.Panel = function TabPanel({ id, children }: { id: string; children: React.ReactNode }) {
  const { activeTab } = useTabsContext();
  if (activeTab !== id) return null;
  return <div role="tabpanel">{children}</div>;
};

// Usage — Beautiful API!
<Tabs defaultTab="overview">
  <Tabs.List>
    <Tabs.Tab id="overview">Overview</Tabs.Tab>
    <Tabs.Tab id="activity">Activity</Tabs.Tab>
    <Tabs.Tab id="settings">Settings</Tabs.Tab>
  </Tabs.List>
  <Tabs.Panel id="overview"><OverviewContent /></Tabs.Panel>
  <Tabs.Panel id="activity"><ActivityContent /></Tabs.Panel>
  <Tabs.Panel id="settings"><SettingsContent /></Tabs.Panel>
</Tabs>
```

### 5.2 Render Props

```tsx
interface MousePosition { x: number; y: number; }

function MouseTracker({ render }: { render: (pos: MousePosition) => React.ReactNode }) {
  const [pos, setPos] = useState<MousePosition>({ x: 0, y: 0 });

  useEffect(() => {
    const handler = (e: MouseEvent) => setPos({ x: e.clientX, y: e.clientY });
    window.addEventListener("mousemove", handler);
    return () => window.removeEventListener("mousemove", handler);
  }, []);

  return <>{render(pos)}</>;
}

// Usage
<MouseTracker render={({ x, y }) => (
  <div>Mouse: {x}, {y}</div>
)} />
```

### 5.3 HOC — Higher Order Components

```tsx
// ─── withAuth HOC ─────────────────────────────────────────────────────────────
function withAuth<P extends object>(
  WrappedComponent: React.ComponentType<P>
): React.FC<P> {
  return function AuthenticatedComponent(props: P) {
    const { user, loading } = useAuth();

    if (loading) return <FullPageSpinner />;
    if (!user) return <Navigate to="/login" />;

    return <WrappedComponent {...props} />;
  };
}

// Usage
const ProtectedDashboard = withAuth(Dashboard);

// ─── withErrorBoundary HOC ────────────────────────────────────────────────────
function withErrorBoundary<P extends object>(
  Component: React.ComponentType<P>,
  fallback: React.ReactNode
) {
  return function WithErrorBoundary(props: P) {
    return (
      <ErrorBoundary fallback={fallback}>
        <Component {...props} />
      </ErrorBoundary>
    );
  };
}
```

### 5.4 Slots Pattern

```tsx
// ─── Named children / slots pattern ──────────────────────────────────────────
interface PageLayoutProps {
  header: React.ReactNode;
  sidebar: React.ReactNode;
  children: React.ReactNode;
  footer?: React.ReactNode;
}

function PageLayout({ header, sidebar, children, footer }: PageLayoutProps) {
  return (
    <div className="page-layout">
      <header>{header}</header>
      <div className="content">
        <aside>{sidebar}</aside>
        <main>{children}</main>
      </div>
      {footer && <footer>{footer}</footer>}
    </div>
  );
}

// Usage
<PageLayout
  header={<NavBar />}
  sidebar={<ProjectTree />}
  footer={<StatusBar />}
>
  <CodeEditor />
</PageLayout>
```

---

## 6. React Context — Advanced

### 6.1 Multi-Context Architecture

```tsx
// ─── Split context for performance ────────────────────────────────────────────
// Rule: Separate frequently-changing values from stable values

// Stable context (rarely changes)
const AuthContext = createContext<{ user: User | null; isAdmin: boolean } | null>(null);

// Dynamic context (changes often)
const NotificationsContext = createContext<{
  notifications: Notification[];
  unreadCount: number;
  markRead: (id: string) => void;
} | null>(null);

// ─── Context with useReducer ──────────────────────────────────────────────────
interface AppState {
  user: User | null;
  preferences: UserPreferences;
  notifications: Notification[];
}

type AppAction =
  | { type: "SET_USER"; payload: User | null }
  | { type: "UPDATE_PREFERENCES"; payload: Partial<UserPreferences> }
  | { type: "ADD_NOTIFICATION"; payload: Notification }
  | { type: "CLEAR_NOTIFICATION"; payload: string };

const AppStateContext = createContext<AppState | null>(null);
const AppDispatchContext = createContext<React.Dispatch<AppAction> | null>(null);

function AppProvider({ children }: { children: React.ReactNode }) {
  const [state, dispatch] = useReducer(appReducer, initialAppState);

  return (
    <AppStateContext.Provider value={state}>
      <AppDispatchContext.Provider value={dispatch}>
        {children}
      </AppDispatchContext.Provider>
    </AppStateContext.Provider>
  );
}

// Split hooks prevent unnecessary re-renders
export const useAppState = () => {
  const ctx = useContext(AppStateContext);
  if (!ctx) throw new Error("useAppState must be inside AppProvider");
  return ctx;
};

export const useAppDispatch = () => {
  const ctx = useContext(AppDispatchContext);
  if (!ctx) throw new Error("useAppDispatch must be inside AppProvider");
  return ctx;
};
```

---

## 7. Performance Optimization

### 7.1 React.memo

```tsx
import { memo } from "react";

// ─── Basic memo ───────────────────────────────────────────────────────────────
const ExpensiveCard = memo(function ExpensiveCard({ data }: { data: CardData }) {
  // Only re-renders if data reference changes
  return <div>{/* expensive render */}</div>;
});

// ─── Custom comparison ────────────────────────────────────────────────────────
const TaskRow = memo(
  function TaskRow({ task, onToggle }: { task: Task; onToggle: (id: string) => void }) {
    return (
      <tr>
        <td>{task.title}</td>
        <td>
          <input type="checkbox" checked={task.completed} onChange={() => onToggle(task.id)} />
        </td>
      </tr>
    );
  },
  (prevProps, nextProps) => {
    // Return true = skip re-render (props "equal")
    return (
      prevProps.task.id === nextProps.task.id &&
      prevProps.task.completed === nextProps.task.completed &&
      prevProps.task.title === nextProps.task.title &&
      prevProps.onToggle === nextProps.onToggle
    );
  }
);
```

### 7.2 Code Splitting & Lazy Loading

```tsx
import { lazy, Suspense } from "react";

// ─── Route-level splitting ────────────────────────────────────────────────────
const Dashboard = lazy(() => import("./pages/Dashboard"));
const Analytics = lazy(() => import("./pages/Analytics"));
const Settings = lazy(() => import("./pages/Settings"));

// ─── Component-level splitting ────────────────────────────────────────────────
const HeavyChart = lazy(() =>
  import("./components/HeavyChart").then((m) => ({ default: m.HeavyChart }))
);
const RichEditor = lazy(() => import("./components/RichEditor"));

function App() {
  return (
    <Suspense fallback={<PageLoader />}>
      <Routes>
        <Route path="/dashboard" element={<Dashboard />} />
        <Route path="/analytics" element={<Analytics />} />
        <Route path="/settings" element={<Settings />} />
      </Routes>
    </Suspense>
  );
}

// ─── Preloading ───────────────────────────────────────────────────────────────
// Preload when hovering nav link — before user clicks
const preloadDashboard = () => import("./pages/Dashboard");

<Link to="/dashboard" onMouseEnter={preloadDashboard}>Dashboard</Link>
```

### 7.3 Virtual Lists (Large Data)

```tsx
import { useVirtualizer } from "@tanstack/react-virtual";
import { useRef } from "react";

function VirtualTaskList({ tasks }: { tasks: Task[] }) {
  const parentRef = useRef<HTMLDivElement>(null);

  const virtualizer = useVirtualizer({
    count: tasks.length,
    getScrollElement: () => parentRef.current,
    estimateSize: () => 60, // Row height in px
    overscan: 10,           // Render 10 extra rows outside viewport
  });

  return (
    <div ref={parentRef} className="h-[600px] overflow-auto">
      {/* Total scroll height */}
      <div style={{ height: virtualizer.getTotalSize(), position: "relative" }}>
        {virtualizer.getVirtualItems().map((virtualRow) => (
          <div
            key={virtualRow.key}
            style={{
              position: "absolute",
              top: virtualRow.start,
              left: 0,
              width: "100%",
              height: virtualRow.size,
            }}
          >
            <TaskRow task={tasks[virtualRow.index]} />
          </div>
        ))}
      </div>
    </div>
  );
}
```

### 7.4 Performance Profiling Pattern

```tsx
// ─── Why Did I Render? — debug unnecessary renders ───────────────────────────
// Add to dev only: npm i @welldone-software/why-did-you-render
// wdyr.ts (import before React)
import React from "react";
if (process.env.NODE_ENV === "development") {
  const whyDidYouRender = require("@welldone-software/why-did-you-render");
  whyDidYouRender(React, { trackAllPureComponents: true });
}

// Mark components to track
MyComponent.whyDidYouRender = true;
```

---

## 8. React Router v7

### 8.1 Setup & Basic Routing

```tsx
// main.tsx
import { createBrowserRouter, RouterProvider } from "react-router";
import { createRoot } from "react-dom/client";

const router = createBrowserRouter([
  {
    path: "/",
    element: <RootLayout />,
    errorElement: <RootErrorBoundary />,
    children: [
      { index: true, element: <Home /> },
      {
        path: "projects",
        element: <ProjectsLayout />,
        children: [
          { index: true, element: <ProjectsList />, loader: projectsLoader },
          {
            path: ":projectId",
            element: <ProjectDetail />,
            loader: projectLoader,
            action: projectAction,
            children: [
              { index: true, element: <ProjectOverview /> },
              { path: "tasks", element: <TasksView /> },
              { path: "settings", element: <ProjectSettings /> },
            ],
          },
        ],
      },
      { path: "settings", element: <Settings /> },
      { path: "*", element: <NotFound /> },
    ],
  },
]);

createRoot(document.getElementById("root")!).render(
  <RouterProvider router={router} />
);
```

### 8.2 Loaders & Actions

```tsx
// ─── Loader: load data before render ─────────────────────────────────────────
import { LoaderFunctionArgs, ActionFunctionArgs, redirect } from "react-router";

export async function projectsLoader({ request }: LoaderFunctionArgs) {
  const url = new URL(request.url);
  const q = url.searchParams.get("q") ?? "";
  const page = Number(url.searchParams.get("page") ?? 1);

  const { projects, total } = await api.getProjects({ q, page });
  return { projects, total, q, page };
}

// ─── Access loader data in component ─────────────────────────────────────────
import { useLoaderData } from "react-router";

function ProjectsList() {
  const { projects, total, q } = useLoaderData<typeof projectsLoader>();
  return (/* ... */);
}

// ─── Action: handle mutations ─────────────────────────────────────────────────
export async function projectAction({ request, params }: ActionFunctionArgs) {
  const formData = await request.formData();
  const intent = formData.get("intent") as string;

  if (intent === "delete") {
    await api.deleteProject(params.projectId!);
    return redirect("/projects");
  }

  if (intent === "update") {
    const title = formData.get("title") as string;
    await api.updateProject(params.projectId!, { title });
    return { success: true };
  }

  return { error: "Unknown intent" };
}
```

### 8.3 Navigation Hooks

```tsx
import {
  useNavigate, useParams, useSearchParams,
  useLocation, useNavigation, Link, NavLink, Form,
} from "react-router";

function ProjectDetail() {
  const navigate = useNavigate();
  const { projectId } = useParams<{ projectId: string }>();
  const [searchParams, setSearchParams] = useSearchParams();
  const location = useLocation();
  const navigation = useNavigation(); // loading state for transitions

  const tab = searchParams.get("tab") ?? "overview";
  const isLoading = navigation.state === "loading";

  return (
    <div>
      {isLoading && <TopProgressBar />}

      {/* NavLink — auto applies active class */}
      <nav>
        <NavLink to="overview" className={({ isActive }) => isActive ? "nav-active" : ""}>
          Overview
        </NavLink>
        <NavLink to="tasks">Tasks</NavLink>
      </nav>

      {/* Programmatic navigation */}
      <button onClick={() => navigate(-1)}>Back</button>
      <button onClick={() => navigate("/projects", { replace: true })}>All Projects</button>

      {/* Form — triggers action automatically */}
      <Form method="post">
        <input type="hidden" name="intent" value="delete" />
        <button type="submit">Delete Project</button>
      </Form>
    </div>
  );
}
```

---

## 9. Data Fetching — TanStack Query v5

### 9.1 Setup & Query Client

```tsx
// main.tsx
import { QueryClient, QueryClientProvider } from "@tanstack/react-query";
import { ReactQueryDevtools } from "@tanstack/react-query-devtools";

const queryClient = new QueryClient({
  defaultOptions: {
    queries: {
      staleTime: 1000 * 60 * 5,  // 5 min
      gcTime: 1000 * 60 * 10,    // 10 min (formerly cacheTime)
      retry: (count, error: any) => {
        if (error?.status === 404 || error?.status === 401) return false;
        return count < 3;
      },
      refetchOnWindowFocus: true,
    },
    mutations: {
      onError: (error) => toast.error(String(error)),
    },
  },
});
```

### 9.2 Query Patterns

```tsx
import { useQuery, useInfiniteQuery, useSuspenseQuery } from "@tanstack/react-query";

// ─── Query key factory ────────────────────────────────────────────────────────
export const taskKeys = {
  all: ["tasks"] as const,
  lists: () => [...taskKeys.all, "list"] as const,
  list: (filters: TaskFilters) => [...taskKeys.lists(), filters] as const,
  details: () => [...taskKeys.all, "detail"] as const,
  detail: (id: string) => [...taskKeys.details(), id] as const,
};

// ─── Basic query ──────────────────────────────────────────────────────────────
export function useTasks(filters: TaskFilters) {
  return useQuery({
    queryKey: taskKeys.list(filters),
    queryFn: () => api.getTasks(filters),
    select: (data) => ({
      tasks: data.items,
      total: data.total,
      urgent: data.items.filter((t) => t.priority === "URGENT"),
    }),
    placeholderData: keepPreviousData, // Keeps old data while fetching new page
  });
}

// ─── Dependent query ──────────────────────────────────────────────────────────
export function useProjectTasks(projectId: string | undefined) {
  return useQuery({
    queryKey: taskKeys.list({ projectId: projectId! }),
    queryFn: () => api.getProjectTasks(projectId!),
    enabled: !!projectId, // Only run when projectId exists
  });
}

// ─── Infinite query ───────────────────────────────────────────────────────────
export function useInfiniteTasks(search: string) {
  return useInfiniteQuery({
    queryKey: [...taskKeys.lists(), "infinite", search],
    queryFn: ({ pageParam }) => api.getTasks({ search, page: pageParam as number }),
    initialPageParam: 1,
    getNextPageParam: (lastPage, _allPages, lastPageParam) => {
      return lastPage.hasMore ? (lastPageParam as number) + 1 : undefined;
    },
  });
}

// ─── Suspense query (React 19 + Suspense) ─────────────────────────────────────
export function useTaskSuspense(id: string) {
  return useSuspenseQuery({
    queryKey: taskKeys.detail(id),
    queryFn: () => api.getTask(id),
  });
}
```

### 9.3 Mutations

```tsx
import { useMutation, useQueryClient } from "@tanstack/react-query";

export function useCreateTask(projectId: string) {
  const queryClient = useQueryClient();

  return useMutation({
    mutationFn: (data: CreateTaskInput) => api.createTask(projectId, data),

    // Optimistic update
    onMutate: async (newTask) => {
      await queryClient.cancelQueries({ queryKey: taskKeys.list({ projectId }) });
      const previous = queryClient.getQueryData(taskKeys.list({ projectId }));

      queryClient.setQueryData(taskKeys.list({ projectId }), (old: any) => ({
        ...old,
        items: [...(old?.items ?? []), { id: "temp", ...newTask, status: "pending" }],
      }));

      return { previous };
    },

    onError: (_err, _vars, context) => {
      if (context?.previous) {
        queryClient.setQueryData(taskKeys.list({ projectId }), context.previous);
      }
      toast.error("Failed to create task");
    },

    onSuccess: () => {
      toast.success("Task created!");
    },

    onSettled: () => {
      queryClient.invalidateQueries({ queryKey: taskKeys.list({ projectId }) });
    },
  });
}
```

---

## 10. State Management — Zustand v5

### 10.1 Store Patterns

```tsx
import { create } from "zustand";
import { devtools, persist, subscribeWithSelector } from "zustand/middleware";
import { immer } from "zustand/middleware/immer";

// ─── Slice pattern (split large stores) ──────────────────────────────────────
interface UISlice {
  sidebarOpen: boolean;
  activeModal: string | null;
  theme: "light" | "dark";
  toggleSidebar: () => void;
  openModal: (id: string) => void;
  closeModal: () => void;
  setTheme: (theme: "light" | "dark") => void;
}

interface ProjectSlice {
  projects: Project[];
  selectedProjectId: string | null;
  setProjects: (p: Project[]) => void;
  selectProject: (id: string | null) => void;
  addProject: (p: Project) => void;
  updateProject: (id: string, updates: Partial<Project>) => void;
  removeProject: (id: string) => void;
}

type AppStore = UISlice & ProjectSlice;

export const useAppStore = create<AppStore>()(
  devtools(
    persist(
      subscribeWithSelector(
        immer((set, get) => ({
          // UI Slice
          sidebarOpen: true,
          activeModal: null,
          theme: "light",
          toggleSidebar: () => set((s) => { s.sidebarOpen = !s.sidebarOpen; }),
          openModal: (id) => set((s) => { s.activeModal = id; }),
          closeModal: () => set((s) => { s.activeModal = null; }),
          setTheme: (theme) => set((s) => { s.theme = theme; }),

          // Project Slice
          projects: [],
          selectedProjectId: null,
          setProjects: (p) => set((s) => { s.projects = p; }),
          selectProject: (id) => set((s) => { s.selectedProjectId = id; }),
          addProject: (p) => set((s) => { s.projects.push(p); }),
          updateProject: (id, updates) => set((s) => {
            const idx = s.projects.findIndex((p) => p.id === id);
            if (idx !== -1) Object.assign(s.projects[idx], updates);
          }),
          removeProject: (id) => set((s) => {
            s.projects = s.projects.filter((p) => p.id !== id);
          }),
        }))
      ),
      {
        name: "app-store",
        partialize: (s) => ({ theme: s.theme, sidebarOpen: s.sidebarOpen }),
      }
    )
  )
);

// ─── Atomic selector hooks (prevent over-rendering) ───────────────────────────
export const useTheme = () => useAppStore((s) => s.theme);
export const useSidebarOpen = () => useAppStore((s) => s.sidebarOpen);
export const useActiveModal = () => useAppStore((s) => s.activeModal);
export const useProjects = () => useAppStore((s) => s.projects);
export const useSelectedProject = () =>
  useAppStore((s) => s.projects.find((p) => p.id === s.selectedProjectId));
```

### 10.2 Subscribe Outside Components

```tsx
// Subscribe to store changes outside React (e.g., for analytics)
const unsubscribe = useAppStore.subscribe(
  (state) => state.selectedProjectId,
  (projectId) => {
    analytics.track("project_selected", { projectId });
  }
);

// Manually get state anywhere
const theme = useAppStore.getState().theme;
useAppStore.setState({ theme: "dark" });
```

---

## 11. Forms — React Hook Form + Zod

### 11.1 Full Form Implementation

```tsx
import { useForm, useFieldArray, Controller } from "react-hook-form";
import { zodResolver } from "@hookform/resolvers/zod";
import { z } from "zod";

// ─── Schema ───────────────────────────────────────────────────────────────────
const ProjectSchema = z.object({
  title: z.string().min(1, "Title required").max(100, "Max 100 chars"),
  description: z.string().max(500).optional(),
  priority: z.enum(["LOW", "MEDIUM", "HIGH", "URGENT"]),
  dueDate: z.string().refine((d) => !d || !isNaN(Date.parse(d)), "Invalid date").optional(),
  tags: z.array(
    z.object({ name: z.string().min(1, "Tag name required") })
  ).max(10, "Max 10 tags"),
  settings: z.object({
    isPublic: z.boolean(),
    notifications: z.boolean(),
    autoAssign: z.boolean(),
  }),
  budget: z.coerce.number().positive("Must be positive").optional(),
}).refine(
  (data) => !(data.priority === "URGENT" && !data.dueDate),
  { message: "Urgent tasks require a due date", path: ["dueDate"] }
);

type ProjectFormData = z.infer<typeof ProjectSchema>;

// ─── Component ────────────────────────────────────────────────────────────────
export function CreateProjectForm({ onSuccess }: { onSuccess: () => void }) {
  const { mutateAsync: createProject } = useCreateProject();

  const {
    register,
    control,
    handleSubmit,
    watch,
    setValue,
    reset,
    formState: { errors, isSubmitting, isDirty, dirtyFields },
  } = useForm<ProjectFormData>({
    resolver: zodResolver(ProjectSchema),
    defaultValues: {
      priority: "MEDIUM",
      tags: [],
      settings: { isPublic: false, notifications: true, autoAssign: false },
    },
  });

  // ─── Field arrays for tags ────────────────────────────────────────────────
  const { fields: tagFields, append, remove } = useFieldArray({
    control,
    name: "tags",
  });

  const watchedPriority = watch("priority");

  const onSubmit = async (data: ProjectFormData) => {
    try {
      await createProject(data);
      reset();
      onSuccess();
    } catch (err) {
      console.error(err);
    }
  };

  return (
    <form onSubmit={handleSubmit(onSubmit)} className="space-y-6">
      {/* Title */}
      <div>
        <label>Title *</label>
        <input {...register("title")} className={errors.title ? "input-error" : "input"} />
        {errors.title && <p className="error">{errors.title.message}</p>}
      </div>

      {/* Priority */}
      <div>
        <label>Priority</label>
        <select {...register("priority")}>
          <option value="LOW">Low</option>
          <option value="MEDIUM">Medium</option>
          <option value="HIGH">High</option>
          <option value="URGENT">Urgent</option>
        </select>
      </div>

      {/* Due date — conditionally required */}
      <div>
        <label>Due Date {watchedPriority === "URGENT" && <span className="text-red-500">*</span>}</label>
        <input type="date" {...register("dueDate")} />
        {errors.dueDate && <p className="error">{errors.dueDate.message}</p>}
      </div>

      {/* Controller for custom components */}
      <Controller
        name="settings.isPublic"
        control={control}
        render={({ field }) => (
          <Toggle label="Public project" checked={field.value} onChange={field.onChange} />
        )}
      />

      {/* Dynamic tag fields */}
      <div>
        <label>Tags</label>
        {tagFields.map((field, index) => (
          <div key={field.id} className="flex gap-2">
            <input {...register(`tags.${index}.name`)} placeholder="Tag name" />
            {errors.tags?.[index]?.name && (
              <p className="error">{errors.tags[index].name?.message}</p>
            )}
            <button type="button" onClick={() => remove(index)}>✕</button>
          </div>
        ))}
        <button type="button" onClick={() => append({ name: "" })}>Add Tag</button>
      </div>

      <button type="submit" disabled={isSubmitting || !isDirty}>
        {isSubmitting ? "Creating..." : "Create Project"}
      </button>
    </form>
  );
}
```

---

## 12. Animations — Framer Motion v12

### 12.1 Core Animations

```tsx
import { motion, AnimatePresence, useMotionValue, useTransform, useSpring } from "motion/react";

// ─── Basic animation ──────────────────────────────────────────────────────────
<motion.div
  initial={{ opacity: 0, y: 20 }}
  animate={{ opacity: 1, y: 0 }}
  exit={{ opacity: 0, y: -20 }}
  transition={{ duration: 0.3, ease: "easeOut" }}
>
  Content
</motion.div>

// ─── Hover & tap ──────────────────────────────────────────────────────────────
<motion.button
  whileHover={{ scale: 1.05, boxShadow: "0 8px 24px rgba(0,0,0,0.15)" }}
  whileTap={{ scale: 0.97 }}
  transition={{ type: "spring", stiffness: 400, damping: 25 }}
>
  Click me
</motion.button>

// ─── Variants ────────────────────────────────────────────────────────────────
const containerVariants = {
  hidden: { opacity: 0 },
  visible: {
    opacity: 1,
    transition: { staggerChildren: 0.1, delayChildren: 0.2 },
  },
  exit: { opacity: 0, transition: { staggerChildren: 0.05, staggerDirection: -1 } },
};

const itemVariants = {
  hidden: { opacity: 0, x: -20 },
  visible: { opacity: 1, x: 0, transition: { type: "spring", stiffness: 300 } },
  exit: { opacity: 0, x: 20 },
};

function AnimatedList({ items }: { items: Item[] }) {
  return (
    <AnimatePresence mode="popLayout">
      <motion.ul variants={containerVariants} initial="hidden" animate="visible" exit="exit">
        {items.map((item) => (
          <motion.li key={item.id} variants={itemVariants} layout>
            {item.name}
          </motion.li>
        ))}
      </motion.ul>
    </AnimatePresence>
  );
}
```

### 12.2 Gestures & Drag

```tsx
// ─── Draggable ────────────────────────────────────────────────────────────────
function DraggableCard({ task }: { task: Task }) {
  return (
    <motion.div
      drag
      dragConstraints={{ left: 0, right: 0, top: 0, bottom: 0 }}
      dragElastic={0.1}
      whileDrag={{ scale: 1.05, zIndex: 50, boxShadow: "0 20px 60px rgba(0,0,0,0.3)" }}
      layout
      layoutId={`task-${task.id}`}
    >
      {task.title}
    </motion.div>
  );
}

// ─── Scroll-triggered ────────────────────────────────────────────────────────
import { useInView } from "motion/react";

function AnimatedSection({ children }: { children: React.ReactNode }) {
  const ref = useRef(null);
  const isInView = useInView(ref, { once: true, margin: "-100px" });

  return (
    <motion.section
      ref={ref}
      initial={{ opacity: 0, y: 60 }}
      animate={isInView ? { opacity: 1, y: 0 } : {}}
      transition={{ duration: 0.6, ease: [0.22, 1, 0.36, 1] }}
    >
      {children}
    </motion.section>
  );
}
```

---

## 13. Error Handling & Boundaries

### 13.1 Error Boundary Class

```tsx
interface ErrorBoundaryState {
  hasError: boolean;
  error: Error | null;
  errorInfo: React.ErrorInfo | null;
}

interface ErrorBoundaryProps {
  children: React.ReactNode;
  fallback?: React.ComponentType<{ error: Error; reset: () => void }>;
  onError?: (error: Error, info: React.ErrorInfo) => void;
}

class ErrorBoundary extends React.Component<ErrorBoundaryProps, ErrorBoundaryState> {
  constructor(props: ErrorBoundaryProps) {
    super(props);
    this.state = { hasError: false, error: null, errorInfo: null };
  }

  static getDerivedStateFromError(error: Error): Partial<ErrorBoundaryState> {
    return { hasError: true, error };
  }

  componentDidCatch(error: Error, errorInfo: React.ErrorInfo) {
    this.setState({ errorInfo });
    this.props.onError?.(error, errorInfo);
    // Send to error reporting service
    errorReporting.capture(error, { extra: errorInfo });
  }

  reset = () => this.setState({ hasError: false, error: null, errorInfo: null });

  render() {
    if (this.state.hasError && this.state.error) {
      const Fallback = this.props.fallback ?? DefaultErrorFallback;
      return <Fallback error={this.state.error} reset={this.reset} />;
    }
    return this.props.children;
  }
}

function DefaultErrorFallback({ error, reset }: { error: Error; reset: () => void }) {
  return (
    <div className="error-boundary">
      <h2>Something went wrong</h2>
      <pre className="error-details">{error.message}</pre>
      <button onClick={reset}>Try again</button>
    </div>
  );
}
```

### 13.2 Async Error Handling Pattern

```tsx
// ─── Result type pattern ──────────────────────────────────────────────────────
type Result<T, E = Error> = { ok: true; value: T } | { ok: false; error: E };

async function safeApiCall<T>(fn: () => Promise<T>): Promise<Result<T>> {
  try {
    const value = await fn();
    return { ok: true, value };
  } catch (error) {
    return { ok: false, error: error as Error };
  }
}

// Usage
const result = await safeApiCall(() => api.createTask(data));
if (!result.ok) {
  toast.error(result.error.message);
  return;
}
toast.success("Task created!");
```

---

## 14. Testing — Vitest + Testing Library

### 14.1 Unit Tests

```tsx
// __tests__/Button.test.tsx
import { render, screen, fireEvent } from "@testing-library/react";
import userEvent from "@testing-library/user-event";
import { describe, it, expect, vi } from "vitest";
import { Button } from "@/components/ui/Button";

describe("Button", () => {
  it("renders with correct label", () => {
    render(<Button label="Click me" />);
    expect(screen.getByText("Click me")).toBeInTheDocument();
  });

  it("calls onClick when clicked", async () => {
    const user = userEvent.setup();
    const handleClick = vi.fn();
    render(<Button label="Click" onClick={handleClick} />);
    await user.click(screen.getByRole("button"));
    expect(handleClick).toHaveBeenCalledTimes(1);
  });

  it("is disabled when loading", () => {
    render(<Button label="Submit" loading />);
    expect(screen.getByRole("button")).toBeDisabled();
  });

  it("applies variant class", () => {
    render(<Button label="Danger" variant="danger" />);
    expect(screen.getByRole("button")).toHaveClass("btn-danger");
  });
});
```

### 14.2 Hook Tests

```tsx
// __tests__/useCounter.test.tsx
import { renderHook, act } from "@testing-library/react";
import { describe, it, expect } from "vitest";
import { useCounter } from "@/hooks/useCounter";

describe("useCounter", () => {
  it("initializes with default value", () => {
    const { result } = renderHook(() => useCounter(10));
    expect(result.current.count).toBe(10);
  });

  it("increments correctly", () => {
    const { result } = renderHook(() => useCounter(0));
    act(() => result.current.increment());
    expect(result.current.count).toBe(1);
  });

  it("does not go below min", () => {
    const { result } = renderHook(() => useCounter(0, { min: 0 }));
    act(() => result.current.decrement());
    expect(result.current.count).toBe(0);
  });
});
```

### 14.3 Integration Tests with MSW

```tsx
// __tests__/TaskList.test.tsx
import { render, screen, waitFor } from "@testing-library/react";
import { http, HttpResponse } from "msw";
import { setupServer } from "msw/node";
import { TaskList } from "@/components/features/TaskList";
import { wrapper } from "@/test-utils"; // QueryClient wrapper

const server = setupServer(
  http.get("/api/tasks", () =>
    HttpResponse.json({
      items: [
        { id: "1", title: "Fix bug #123", completed: false, priority: "HIGH" },
        { id: "2", title: "Write tests", completed: true, priority: "MEDIUM" },
      ],
      total: 2,
    })
  )
);

beforeAll(() => server.listen());
afterEach(() => server.resetHandlers());
afterAll(() => server.close());

describe("TaskList", () => {
  it("renders tasks after loading", async () => {
    render(<TaskList projectId="proj_1" />, { wrapper });
    expect(screen.getByTestId("skeleton")).toBeInTheDocument();
    await waitFor(() => {
      expect(screen.getByText("Fix bug #123")).toBeInTheDocument();
      expect(screen.getByText("Write tests")).toBeInTheDocument();
    });
  });

  it("shows error state on API failure", async () => {
    server.use(http.get("/api/tasks", () => HttpResponse.error()));
    render(<TaskList projectId="proj_1" />, { wrapper });
    await waitFor(() => {
      expect(screen.getByText(/failed to load/i)).toBeInTheDocument();
    });
  });
});
```

---

## 15. Custom Hooks Library

```tsx
// ─── useLocalStorage ──────────────────────────────────────────────────────────
function useLocalStorage<T>(key: string, initialValue: T) {
  const [value, setValue] = useState<T>(() => {
    try {
      const item = window.localStorage.getItem(key);
      return item ? JSON.parse(item) : initialValue;
    } catch { return initialValue; }
  });

  const setStoredValue = (value: T | ((prev: T) => T)) => {
    setValue((prev) => {
      const next = typeof value === "function" ? (value as (prev: T) => T)(prev) : value;
      localStorage.setItem(key, JSON.stringify(next));
      return next;
    });
  };

  return [value, setStoredValue] as const;
}

// ─── useDebounce ──────────────────────────────────────────────────────────────
function useDebounce<T>(value: T, delay: number): T {
  const [debouncedValue, setDebouncedValue] = useState<T>(value);
  useEffect(() => {
    const timer = setTimeout(() => setDebouncedValue(value), delay);
    return () => clearTimeout(timer);
  }, [value, delay]);
  return debouncedValue;
}

// ─── useIntersectionObserver ──────────────────────────────────────────────────
function useIntersectionObserver(
  options?: IntersectionObserverInit
): [React.RefCallback<Element>, boolean] {
  const [isIntersecting, setIsIntersecting] = useState(false);
  const observerRef = useRef<IntersectionObserver | null>(null);

  const ref = useCallback<React.RefCallback<Element>>(
    (node) => {
      if (observerRef.current) observerRef.current.disconnect();
      if (!node) return;
      observerRef.current = new IntersectionObserver(([entry]) => {
        setIsIntersecting(entry.isIntersecting);
      }, options);
      observerRef.current.observe(node);
    },
    [options]
  );

  return [ref, isIntersecting];
}

// ─── useAsync ─────────────────────────────────────────────────────────────────
type AsyncState<T> =
  | { status: "idle" }
  | { status: "loading" }
  | { status: "success"; data: T }
  | { status: "error"; error: Error };

function useAsync<T>(asyncFn: () => Promise<T>, deps: React.DependencyList) {
  const [state, setState] = useState<AsyncState<T>>({ status: "idle" });

  useEffect(() => {
    let cancelled = false;
    setState({ status: "loading" });

    asyncFn()
      .then((data) => { if (!cancelled) setState({ status: "success", data }); })
      .catch((error) => { if (!cancelled) setState({ status: "error", error }); });

    return () => { cancelled = true; };
  }, deps); // eslint-disable-line react-hooks/exhaustive-deps

  return state;
}

// ─── useKeyboard ──────────────────────────────────────────────────────────────
function useKeyboard(bindings: Record<string, () => void>) {
  useEffect(() => {
    const handler = (e: KeyboardEvent) => {
      const key = [
        e.metaKey && "meta",
        e.ctrlKey && "ctrl",
        e.shiftKey && "shift",
        e.altKey && "alt",
        e.key.toLowerCase(),
      ].filter(Boolean).join("+");

      bindings[key]?.();
    };

    window.addEventListener("keydown", handler);
    return () => window.removeEventListener("keydown", handler);
  }, [bindings]);
}

// Usage
useKeyboard({
  "meta+k": openCommandPalette,
  "meta+s": saveDocument,
  "escape": closeModal,
  "meta+shift+d": openDevTools,
});
```

---

## 16. Final Project: DevBoard

> A real-time developer dashboard for managing projects, tasks, pull requests, and deployments.

### Tech Stack

| Layer | Technology |
|---|---|
| Framework | React 19 + TypeScript 5 + Vite 6 |
| Routing | React Router v7 |
| Server State | TanStack Query v5 |
| Client State | Zustand v5 + Immer |
| Forms | React Hook Form v7 + Zod v3 |
| Styling | Tailwind CSS v4 + shadcn/ui |
| Animation | Framer Motion v12 |
| Testing | Vitest + Testing Library + MSW v2 |
| Charts | Recharts v2 |
| DnD | @dnd-kit/core |
| Realtime | Native EventSource (SSE) |
| Icons | Lucide React |

---

### Project Structure

```
devboard/
├── src/
│   ├── app/
│   │   ├── router.tsx              # React Router v7 config
│   │   └── providers.tsx           # All providers
│   ├── pages/
│   │   ├── Dashboard/
│   │   │   ├── index.tsx
│   │   │   ├── DashboardMetrics.tsx
│   │   │   └── RecentActivity.tsx
│   │   ├── Projects/
│   │   │   ├── index.tsx
│   │   │   ├── ProjectDetail.tsx
│   │   │   └── KanbanBoard.tsx
│   │   ├── Tasks/
│   │   │   ├── index.tsx
│   │   │   └── TaskDrawer.tsx
│   │   └── Deployments/
│   │       └── index.tsx
│   ├── components/
│   │   ├── ui/                     # shadcn + custom primitives
│   │   ├── layout/
│   │   │   ├── Sidebar.tsx
│   │   │   ├── TopBar.tsx
│   │   │   └── CommandPalette.tsx
│   │   └── features/
│   │       ├── TaskCard.tsx
│   │       ├── ProjectCard.tsx
│   │       ├── MetricCard.tsx
│   │       └── DeploymentStatus.tsx
│   ├── hooks/
│   │   ├── useProjects.ts
│   │   ├── useTasks.ts
│   │   ├── useDeployments.ts
│   │   ├── useRealtime.ts
│   │   ├── useKeyboard.ts
│   │   └── useDebounce.ts
│   ├── store/
│   │   ├── useUIStore.ts
│   │   └── useProjectStore.ts
│   ├── lib/
│   │   ├── api.ts
│   │   ├── queryClient.ts
│   │   └── utils.ts
│   ├── types/
│   │   └── index.ts
│   └── main.tsx
```

---

### Core Implementation

#### types/index.ts

```tsx
export type Priority = "LOW" | "MEDIUM" | "HIGH" | "URGENT";
export type TaskStatus = "TODO" | "IN_PROGRESS" | "IN_REVIEW" | "DONE";
export type ProjectStatus = "ACTIVE" | "PAUSED" | "COMPLETED" | "ARCHIVED";
export type DeployStatus = "QUEUED" | "BUILDING" | "SUCCESS" | "FAILED" | "CANCELLED";

export interface User {
  id: string;
  name: string;
  email: string;
  avatar?: string;
  role: "OWNER" | "ADMIN" | "MEMBER" | "VIEWER";
}

export interface Project {
  id: string;
  name: string;
  description?: string;
  color: string;
  status: ProjectStatus;
  owner: User;
  members: User[];
  taskCount: number;
  completedTaskCount: number;
  dueDate?: string;
  createdAt: string;
}

export interface Task {
  id: string;
  title: string;
  description?: string;
  status: TaskStatus;
  priority: Priority;
  projectId: string;
  assignee?: User;
  dueDate?: string;
  tags: string[];
  position: number;
  createdAt: string;
  updatedAt: string;
}

export interface Deployment {
  id: string;
  projectId: string;
  environment: "development" | "staging" | "production";
  status: DeployStatus;
  branch: string;
  commit: string;
  commitMessage: string;
  triggeredBy: User;
  duration?: number;
  startedAt: string;
  finishedAt?: string;
  logs?: string[];
}

export interface DashboardMetrics {
  totalProjects: number;
  activeProjects: number;
  totalTasks: number;
  completedToday: number;
  deployments: { success: number; failed: number; pending: number };
  velocity: { current: number; previous: number };
}
```

---

#### app/router.tsx

```tsx
import { createBrowserRouter } from "react-router";
import { RootLayout } from "@/components/layout/RootLayout";
import { lazy, Suspense } from "react";

const Dashboard = lazy(() => import("@/pages/Dashboard"));
const Projects = lazy(() => import("@/pages/Projects"));
const ProjectDetail = lazy(() => import("@/pages/Projects/ProjectDetail"));
const Tasks = lazy(() => import("@/pages/Tasks"));
const Deployments = lazy(() => import("@/pages/Deployments"));

const Fallback = () => (
  <div className="flex items-center justify-center h-64">
    <div className="animate-spin rounded-full h-8 w-8 border-b-2 border-blue-600" />
  </div>
);

export const router = createBrowserRouter([
  {
    path: "/",
    element: <RootLayout />,
    children: [
      {
        index: true,
        element: <Suspense fallback={<Fallback />}><Dashboard /></Suspense>,
      },
      {
        path: "projects",
        children: [
          {
            index: true,
            element: <Suspense fallback={<Fallback />}><Projects /></Suspense>,
          },
          {
            path: ":projectId",
            element: <Suspense fallback={<Fallback />}><ProjectDetail /></Suspense>,
          },
        ],
      },
      {
        path: "tasks",
        element: <Suspense fallback={<Fallback />}><Tasks /></Suspense>,
      },
      {
        path: "deployments",
        element: <Suspense fallback={<Fallback />}><Deployments /></Suspense>,
      },
    ],
  },
]);
```

---

#### hooks/useRealtime.ts

```tsx
import { useEffect, useRef, useCallback } from "react";
import { useQueryClient } from "@tanstack/react-query";

type RealtimeEvent =
  | { type: "task:updated"; payload: { taskId: string; projectId: string } }
  | { type: "deployment:status"; payload: { deploymentId: string; status: string } }
  | { type: "project:updated"; payload: { projectId: string } };

export function useRealtime(projectId?: string) {
  const queryClient = useQueryClient();
  const eventSourceRef = useRef<EventSource | null>(null);

  const handleEvent = useCallback((event: RealtimeEvent) => {
    switch (event.type) {
      case "task:updated":
        queryClient.invalidateQueries({ queryKey: ["tasks", event.payload.projectId] });
        break;
      case "deployment:status":
        queryClient.invalidateQueries({ queryKey: ["deployments"] });
        break;
      case "project:updated":
        queryClient.invalidateQueries({ queryKey: ["projects"] });
        break;
    }
  }, [queryClient]);

  useEffect(() => {
    const url = projectId ? `/api/events?projectId=${projectId}` : "/api/events";
    const es = new EventSource(url);
    eventSourceRef.current = es;

    es.onmessage = (event) => {
      try {
        handleEvent(JSON.parse(event.data) as RealtimeEvent);
      } catch { /* ignore malformed messages */ }
    };

    es.onerror = () => {
      setTimeout(() => es.close(), 5000); // Retry after 5s
    };

    return () => es.close();
  }, [projectId, handleEvent]);
}
```

---

#### pages/Projects/KanbanBoard.tsx

```tsx
"use client";
import { useState, useCallback } from "react";
import {
  DndContext, DragEndEvent, DragOverlay, DragStartEvent,
  PointerSensor, useSensor, useSensors, closestCorners,
} from "@dnd-kit/core";
import { SortableContext, verticalListSortingStrategy, useSortable } from "@dnd-kit/sortable";
import { CSS } from "@dnd-kit/utilities";
import { motion, AnimatePresence } from "motion/react";
import { useQueryClient } from "@tanstack/react-query";
import type { Task, TaskStatus } from "@/types";
import { useUpdateTask } from "@/hooks/useTasks";

const COLUMNS: TaskStatus[] = ["TODO", "IN_PROGRESS", "IN_REVIEW", "DONE"];

const COLUMN_CONFIG: Record<TaskStatus, { label: string; color: string }> = {
  TODO:        { label: "To Do",       color: "bg-gray-100" },
  IN_PROGRESS: { label: "In Progress", color: "bg-blue-50" },
  IN_REVIEW:   { label: "In Review",   color: "bg-yellow-50" },
  DONE:        { label: "Done",        color: "bg-green-50" },
};

function SortableTaskCard({ task }: { task: Task }) {
  const { attributes, listeners, setNodeRef, transform, transition, isDragging } =
    useSortable({ id: task.id });

  const style = {
    transform: CSS.Transform.toString(transform),
    transition,
    opacity: isDragging ? 0.4 : 1,
  };

  return (
    <div ref={setNodeRef} style={style} {...attributes} {...listeners}>
      <motion.div
        layout
        layoutId={task.id}
        className="bg-white rounded-lg p-3 shadow-sm border border-gray-100 cursor-grab active:cursor-grabbing"
        whileHover={{ y: -2, shadow: "0 4px 12px rgba(0,0,0,0.1)" }}
      >
        <p className="text-sm font-medium text-gray-800">{task.title}</p>
        <div className="flex items-center justify-between mt-2">
          <span className={`text-xs px-2 py-0.5 rounded-full ${getPriorityColor(task.priority)}`}>
            {task.priority}
          </span>
          {task.assignee && (
            <img
              src={task.assignee.avatar}
              alt={task.assignee.name}
              className="w-6 h-6 rounded-full"
            />
          )}
        </div>
      </motion.div>
    </div>
  );
}

export function KanbanBoard({ tasks }: { tasks: Task[] }) {
  const [activeTask, setActiveTask] = useState<Task | null>(null);
  const { mutate: updateTask } = useUpdateTask();

  const sensors = useSensors(
    useSensor(PointerSensor, { activationConstraint: { distance: 8 } })
  );

  const tasksByColumn = COLUMNS.reduce((acc, col) => {
    acc[col] = tasks.filter((t) => t.status === col)
                    .sort((a, b) => a.position - b.position);
    return acc;
  }, {} as Record<TaskStatus, Task[]>);

  const handleDragStart = ({ active }: DragStartEvent) => {
    setActiveTask(tasks.find((t) => t.id === active.id) ?? null);
  };

  const handleDragEnd = ({ active, over }: DragEndEvent) => {
    setActiveTask(null);
    if (!over) return;

    const task = tasks.find((t) => t.id === active.id);
    const newStatus = over.data.current?.column as TaskStatus;
    if (!task || !newStatus || task.status === newStatus) return;

    updateTask({ id: task.id, status: newStatus });
  };

  return (
    <DndContext
      sensors={sensors}
      collisionDetection={closestCorners}
      onDragStart={handleDragStart}
      onDragEnd={handleDragEnd}
    >
      <div className="grid grid-cols-4 gap-4 h-full">
        {COLUMNS.map((col) => (
          <div key={col} className={`rounded-xl p-3 ${COLUMN_CONFIG[col].color}`}>
            <div className="flex items-center justify-between mb-3">
              <h3 className="font-semibold text-sm text-gray-700">
                {COLUMN_CONFIG[col].label}
              </h3>
              <span className="text-xs bg-white rounded-full px-2 py-0.5 text-gray-500">
                {tasksByColumn[col].length}
              </span>
            </div>
            <SortableContext
              items={tasksByColumn[col].map((t) => t.id)}
              strategy={verticalListSortingStrategy}
            >
              <div className="space-y-2 min-h-[200px]" data-column={col}>
                <AnimatePresence>
                  {tasksByColumn[col].map((task) => (
                    <SortableTaskCard key={task.id} task={task} />
                  ))}
                </AnimatePresence>
              </div>
            </SortableContext>
          </div>
        ))}
      </div>

      <DragOverlay>
        {activeTask && (
          <div className="bg-white rounded-lg p-3 shadow-2xl border border-blue-200 rotate-3">
            <p className="text-sm font-medium">{activeTask.title}</p>
          </div>
        )}
      </DragOverlay>
    </DndContext>
  );
}

function getPriorityColor(priority: string) {
  const map: Record<string, string> = {
    LOW: "bg-gray-100 text-gray-600",
    MEDIUM: "bg-blue-100 text-blue-700",
    HIGH: "bg-orange-100 text-orange-700",
    URGENT: "bg-red-100 text-red-700",
  };
  return map[priority] ?? map.MEDIUM;
}
```

---

#### components/layout/CommandPalette.tsx

```tsx
import { useState, useEffect, useMemo } from "react";
import { useNavigate } from "react-router";
import { motion, AnimatePresence } from "motion/react";
import { useKeyboard } from "@/hooks/useKeyboard";
import { useDebounce } from "@/hooks/useDebounce";
import { useProjects } from "@/hooks/useProjects";

interface Command {
  id: string;
  label: string;
  description?: string;
  icon: React.ReactNode;
  action: () => void;
  group: "navigation" | "actions" | "projects";
  keywords?: string[];
}

export function CommandPalette() {
  const [open, setOpen] = useState(false);
  const [query, setQuery] = useState("");
  const navigate = useNavigate();
  const { data: projects } = useProjects();
  const debouncedQuery = useDebounce(query, 150);

  useKeyboard({ "meta+k": () => setOpen((o) => !o), "escape": () => setOpen(false) });

  const commands: Command[] = useMemo(() => [
    {
      id: "go-dashboard",
      label: "Go to Dashboard",
      icon: "📊",
      action: () => navigate("/"),
      group: "navigation",
      keywords: ["home", "overview"],
    },
    {
      id: "go-projects",
      label: "Go to Projects",
      icon: "📁",
      action: () => navigate("/projects"),
      group: "navigation",
    },
    {
      id: "go-tasks",
      label: "Go to Tasks",
      icon: "✅",
      action: () => navigate("/tasks"),
      group: "navigation",
    },
    {
      id: "new-project",
      label: "Create New Project",
      icon: "➕",
      action: () => { navigate("/projects"); /* open modal */ },
      group: "actions",
      keywords: ["create", "add"],
    },
    ...(projects?.map((p) => ({
      id: `project-${p.id}`,
      label: p.name,
      description: `${p.taskCount} tasks`,
      icon: <span style={{ color: p.color }}>●</span>,
      action: () => navigate(`/projects/${p.id}`),
      group: "projects" as const,
    })) ?? []),
  ], [navigate, projects]);

  const filtered = useMemo(() => {
    if (!debouncedQuery) return commands.slice(0, 8);
    const q = debouncedQuery.toLowerCase();
    return commands.filter(
      (c) =>
        c.label.toLowerCase().includes(q) ||
        c.description?.toLowerCase().includes(q) ||
        c.keywords?.some((k) => k.includes(q))
    );
  }, [commands, debouncedQuery]);

  return (
    <AnimatePresence>
      {open && (
        <>
          <motion.div
            className="fixed inset-0 bg-black/40 backdrop-blur-sm z-40"
            initial={{ opacity: 0 }}
            animate={{ opacity: 1 }}
            exit={{ opacity: 0 }}
            onClick={() => setOpen(false)}
          />
          <motion.div
            className="fixed top-[20vh] left-1/2 -translate-x-1/2 w-full max-w-lg z-50 bg-white rounded-2xl shadow-2xl overflow-hidden"
            initial={{ opacity: 0, scale: 0.95, y: -10 }}
            animate={{ opacity: 1, scale: 1, y: 0 }}
            exit={{ opacity: 0, scale: 0.95, y: -10 }}
            transition={{ type: "spring", stiffness: 400, damping: 30 }}
          >
            <div className="flex items-center gap-3 px-4 py-3 border-b">
              <span className="text-gray-400">🔍</span>
              <input
                autoFocus
                value={query}
                onChange={(e) => setQuery(e.target.value)}
                placeholder="Search commands, projects..."
                className="flex-1 outline-none text-sm text-gray-700 placeholder:text-gray-400"
              />
              <kbd className="text-xs text-gray-400 bg-gray-100 px-2 py-0.5 rounded">ESC</kbd>
            </div>
            <ul className="py-2 max-h-72 overflow-y-auto">
              {filtered.map((cmd) => (
                <li key={cmd.id}>
                  <button
                    className="w-full flex items-center gap-3 px-4 py-2.5 hover:bg-blue-50 text-left transition-colors"
                    onClick={() => { cmd.action(); setOpen(false); }}
                  >
                    <span>{cmd.icon}</span>
                    <div>
                      <p className="text-sm font-medium text-gray-800">{cmd.label}</p>
                      {cmd.description && (
                        <p className="text-xs text-gray-400">{cmd.description}</p>
                      )}
                    </div>
                  </button>
                </li>
              ))}
              {filtered.length === 0 && (
                <li className="px-4 py-8 text-center text-sm text-gray-400">
                  No results for "{debouncedQuery}"
                </li>
              )}
            </ul>
            <div className="px-4 py-2 border-t flex gap-4 text-xs text-gray-400">
              <span><kbd>↑↓</kbd> Navigate</span>
              <span><kbd>↵</kbd> Select</span>
              <span><kbd>⌘K</kbd> Toggle</span>
            </div>
          </motion.div>
        </>
      )}
    </AnimatePresence>
  );
}
```

---

#### pages/Dashboard/index.tsx

```tsx
import { Suspense } from "react";
import { motion } from "motion/react";
import { useSuspenseQuery } from "@tanstack/react-query";
import { useRealtime } from "@/hooks/useRealtime";
import { MetricCard } from "@/components/features/MetricCard";
import type { DashboardMetrics } from "@/types";

function MetricsGrid() {
  const { data: metrics } = useSuspenseQuery<DashboardMetrics>({
    queryKey: ["dashboard-metrics"],
    queryFn: () => api.getDashboardMetrics(),
  });

  const cards = [
    {
      title: "Active Projects",
      value: metrics.activeProjects,
      total: metrics.totalProjects,
      trend: "+2 this month",
      icon: "📁",
      color: "blue",
    },
    {
      title: "Tasks Completed Today",
      value: metrics.completedToday,
      total: metrics.totalTasks,
      trend: "+12% vs yesterday",
      icon: "✅",
      color: "green",
    },
    {
      title: "Successful Deploys",
      value: metrics.deployments.success,
      total: metrics.deployments.success + metrics.deployments.failed,
      trend: `${metrics.deployments.pending} pending`,
      icon: "🚀",
      color: "purple",
    },
    {
      title: "Team Velocity",
      value: metrics.velocity.current,
      trend: `${metrics.velocity.current > metrics.velocity.previous ? "↑" : "↓"} vs last sprint`,
      icon: "⚡",
      color: "orange",
    },
  ];

  return (
    <motion.div
      className="grid grid-cols-1 md:grid-cols-2 xl:grid-cols-4 gap-4"
      variants={{ visible: { transition: { staggerChildren: 0.1 } } }}
      initial="hidden"
      animate="visible"
    >
      {cards.map((card) => (
        <motion.div
          key={card.title}
          variants={{ hidden: { opacity: 0, y: 20 }, visible: { opacity: 1, y: 0 } }}
        >
          <MetricCard {...card} />
        </motion.div>
      ))}
    </motion.div>
  );
}

export default function Dashboard() {
  useRealtime(); // Subscribe to all real-time events

  return (
    <div className="p-6 space-y-6">
      <div>
        <h1 className="text-2xl font-bold text-gray-900">Dashboard</h1>
        <p className="text-gray-500 text-sm mt-1">
          {new Date().toLocaleDateString("en-US", { weekday: "long", month: "long", day: "numeric" })}
        </p>
      </div>

      <Suspense fallback={<MetricsSkeleton />}>
        <MetricsGrid />
      </Suspense>

      <div className="grid grid-cols-1 lg:grid-cols-3 gap-6">
        <div className="lg:col-span-2">
          <Suspense fallback={<ChartSkeleton />}>
            <ActivityChart />
          </Suspense>
        </div>
        <div>
          <Suspense fallback={<ListSkeleton />}>
            <RecentDeployments />
          </Suspense>
        </div>
      </div>
    </div>
  );
}
```

---

### Setup Commands

```bash
# Create project
pnpm create vite@latest devboard -- --template react-ts
cd devboard

# Core dependencies
pnpm add react-router @tanstack/react-query @tanstack/react-query-devtools
pnpm add zustand immer
pnpm add react-hook-form @hookform/resolvers zod
pnpm add motion                          # Framer Motion v12 (new package name)
pnpm add @dnd-kit/core @dnd-kit/sortable @dnd-kit/utilities
pnpm add @tanstack/react-virtual
pnpm add recharts
pnpm add lucide-react
pnpm add clsx tailwind-merge
pnpm add sonner                          # Toast notifications

# Dev tools
pnpm add -D vitest @vitest/ui jsdom @testing-library/react @testing-library/user-event @testing-library/jest-dom
pnpm add -D msw                          # API mocking
pnpm add -D @welldone-software/why-did-you-render

# shadcn/ui
pnpm dlx shadcn@latest init
pnpm dlx shadcn@latest add button input label card badge avatar dialog sheet

# Tailwind v4
pnpm add -D tailwindcss @tailwindcss/vite
```

### vite.config.ts

```ts
import { defineConfig } from "vite";
import react from "@vitejs/plugin-react";
import tailwindcss from "@tailwindcss/vite";
import path from "path";

export default defineConfig({
  plugins: [react(), tailwindcss()],
  resolve: {
    alias: { "@": path.resolve(__dirname, "./src") },
  },
  test: {
    environment: "jsdom",
    globals: true,
    setupFiles: ["./src/test/setup.ts"],
  },
});
```

---

## Quick Reference Cheatsheet

| Hook | Purpose | When to Use |
|---|---|---|
| `useState` | Local component state | Simple values, forms, toggles |
| `useReducer` | Complex local state | Multiple related state values |
| `useEffect` | Side effects & subscriptions | Data sync, event listeners |
| `useRef` | DOM access + mutable values | Focus, intervals, prev values |
| `useMemo` | Memoize computed values | Expensive calculations |
| `useCallback` | Memoize functions | Stable refs passed to children |
| `useContext` | Consume context | Theme, auth, shared state |
| `useTransition` | Non-urgent updates | Search, filtering, navigation |
| `useDeferredValue` | Defer expensive renders | Heavy filtering/search results |
| `useOptimistic` | Optimistic UI | Instant feedback on mutations |
| `use()` | Unwrap promises/context | Conditional context, streaming |
| `useActionState` | Form action state | Server-connected forms |
| `useFormStatus` | Parent form status | Submit buttons inside forms |

---

| Pattern | Use Case |
|---|---|
| Compound Components | Flexible API (Tabs, Accordion, Select) |
| Render Props | Share behavior without coupling |
| HOC | Cross-cutting concerns (auth, logging) |
| Slots | Named children for layout components |
| Polymorphic | Multi-element components (`as` prop) |
| Generic Components | Type-safe reusable lists, tables |

---

*Built with ❤️ — React 19 · TypeScript 5 · Vite 6 — March 2026*
