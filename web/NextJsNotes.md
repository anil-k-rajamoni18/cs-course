# 🚀 Next.js 15 + TypeScript — In-Depth Crash Course

> **Stack:** Next.js 15 (App Router) · TypeScript 5.x · Tailwind CSS v4 · Prisma · NextAuth.js v5 · Zod · React 19 · shadcn/ui · Zustand · React Query (TanStack Query v5)

---

## Table of Contents

1. [TypeScript Foundations for Next.js](#1-typescript-foundations)
2. [Next.js 15 App Router Architecture](#2-nextjs-15-app-router)
3. [Server Components vs Client Components](#3-server-vs-client-components)
4. [Routing — Advanced Patterns](#4-routing)
5. [Data Fetching & Caching](#5-data-fetching--caching)
6. [Server Actions](#6-server-actions)
7. [Layouts, Templates & Metadata](#7-layouts-templates--metadata)
8. [Middleware & Edge Runtime](#8-middleware--edge-runtime)
9. [Authentication with NextAuth v5](#9-authentication-nextauth-v5)
10. [Database with Prisma ORM](#10-database-with-prisma)
11. [State Management — Zustand + React Query](#11-state-management)
12. [Forms & Validation with Zod + React Hook Form](#12-forms--validation)
13. [API Routes & Route Handlers](#13-api-routes--route-handlers)
14. [Performance Optimization](#14-performance-optimization)
15. [Testing — Vitest + Playwright](#15-testing)
16. [Deployment & DevOps](#16-deployment--devops)
17. [🏗️ Final Real-World Project: TaskFlow SaaS](#17-final-project-taskflow-saas)

---

## 1. TypeScript Foundations

### 1.1 Essential Types for Next.js

```typescript
// ─── Primitive & Utility Types ───────────────────────────────────────────────
type ID = string | number;
type Nullable<T> = T | null;
type Optional<T> = T | undefined;
type Maybe<T> = T | null | undefined;

// ─── Record & Map Types ───────────────────────────────────────────────────────
type UserMap = Record<string, User>;
type StatusMap = Record<"active" | "inactive" | "pending", number>;

// ─── Deep Readonly ────────────────────────────────────────────────────────────
type DeepReadonly<T> = {
  readonly [P in keyof T]: T[P] extends object ? DeepReadonly<T[P]> : T[P];
};

// ─── Branded Types (prevent mixing IDs) ──────────────────────────────────────
type Brand<T, B> = T & { readonly _brand: B };
type UserId = Brand<string, "UserId">;
type ProjectId = Brand<string, "ProjectId">;

function getUser(id: UserId) { /* ... */ }
// getUser("raw-string") // ❌ Type Error
// getUser("abc" as UserId) // ✅ Explicit cast
```

### 1.2 Generics & Conditional Types

```typescript
// ─── Generic API Response Wrapper ─────────────────────────────────────────────
type ApiResponse<T, E = string> =
  | { success: true; data: T; meta?: ResponseMeta }
  | { success: false; error: E; code: number };

type ResponseMeta = {
  page: number;
  total: number;
  perPage: number;
};

// ─── Conditional Types ────────────────────────────────────────────────────────
type IsArray<T> = T extends any[] ? true : false;
type Flatten<T> = T extends Array<infer Item> ? Item : T;

// ─── Infer from function return ───────────────────────────────────────────────
type AsyncReturnType<T extends (...args: any) => Promise<any>> =
  T extends (...args: any) => Promise<infer R> ? R : never;

// Usage
async function fetchUser() { return { id: "1", name: "Alice" }; }
type FetchedUser = AsyncReturnType<typeof fetchUser>; // { id: string; name: string }
```

### 1.3 Discriminated Unions

```typescript
// ─── Task Status — Discriminated Union ───────────────────────────────────────
type TaskStatus =
  | { status: "idle" }
  | { status: "loading" }
  | { status: "success"; data: Task[] }
  | { status: "error"; error: string };

function renderTask(state: TaskStatus) {
  switch (state.status) {
    case "idle":    return "Ready";
    case "loading": return "Loading...";
    case "success": return state.data.map(t => t.title).join(", "); // ✅ data available
    case "error":   return `Error: ${state.error}`;                 // ✅ error available
  }
}
```

### 1.4 Template Literal Types

```typescript
type HttpMethod = "GET" | "POST" | "PUT" | "PATCH" | "DELETE";
type ApiEndpoint = `/api/${string}`;
type RouteKey = `${Lowercase<HttpMethod>}:${ApiEndpoint}`;

// "get:/api/users" | "post:/api/users" | ...
type EventName = `on${Capitalize<string>}`;
```

### 1.5 satisfies Operator (TS 4.9+)

```typescript
const config = {
  theme: "dark",
  locale: "en-US",
  features: { darkMode: true, beta: false },
} satisfies AppConfig; // ✅ Validates shape, keeps literal types
```

---

## 2. Next.js 15 App Router

### 2.1 Project Structure

```
my-app/
├── app/                          # App Router root
│   ├── layout.tsx                # Root layout (required)
│   ├── page.tsx                  # Home page  /
│   ├── loading.tsx               # Suspense loading UI
│   ├── error.tsx                 # Error boundary
│   ├── not-found.tsx             # 404 page
│   ├── global-error.tsx          # Root error boundary
│   ├── (auth)/                   # Route group (no URL segment)
│   │   ├── login/page.tsx        # /login
│   │   └── register/page.tsx     # /register
│   ├── (dashboard)/
│   │   ├── layout.tsx            # Nested layout
│   │   ├── dashboard/page.tsx    # /dashboard
│   │   └── projects/
│   │       ├── page.tsx          # /projects
│   │       ├── [id]/             # Dynamic segment
│   │       │   ├── page.tsx      # /projects/[id]
│   │       │   └── edit/page.tsx # /projects/[id]/edit
│   │       └── [...slug]/page.tsx # Catch-all /projects/a/b/c
│   └── api/                      # Route Handlers
│       └── users/
│           └── route.ts
├── components/
│   ├── ui/                       # shadcn/ui components
│   └── features/                 # Feature-specific components
├── lib/
│   ├── db.ts                     # Prisma client
│   ├── auth.ts                   # NextAuth config
│   └── utils.ts                  # Utilities
├── hooks/                        # Custom React hooks
├── store/                        # Zustand stores
├── types/                        # Global TypeScript types
├── actions/                      # Server Actions
├── middleware.ts                 # Next.js Middleware
└── next.config.ts                # Config (ESM)
```

### 2.2 next.config.ts (Latest)

```typescript
import type { NextConfig } from "next";

const nextConfig: NextConfig = {
  experimental: {
    ppr: true,             // Partial Pre-Rendering
    reactCompiler: true,   // React 19 compiler
    typedRoutes: true,     // Type-safe routing
  },
  images: {
    remotePatterns: [
      { protocol: "https", hostname: "avatars.githubusercontent.com" },
      { protocol: "https", hostname: "**.cloudinary.com" },
    ],
  },
  logging: {
    fetches: { fullUrl: true },
  },
};

export default nextConfig;
```

---

## 3. Server vs Client Components

### 3.1 Server Components (Default)

```tsx
// app/projects/page.tsx — Server Component (no "use client")
import { db } from "@/lib/db";
import { ProjectCard } from "@/components/features/project-card";

// Props from URL params & search params
interface ProjectsPageProps {
  searchParams: Promise<{ q?: string; page?: string }>;
}

export default async function ProjectsPage({ searchParams }: ProjectsPageProps) {
  // ✅ Direct DB access — never exposed to client
  const { q, page = "1" } = await searchParams;

  const projects = await db.project.findMany({
    where: q ? { title: { contains: q, mode: "insensitive" } } : undefined,
    skip: (parseInt(page) - 1) * 10,
    take: 10,
    include: { owner: true, _count: { select: { tasks: true } } },
  });

  return (
    <section>
      <h1 className="text-3xl font-bold">Projects</h1>
      <div className="grid grid-cols-3 gap-4 mt-6">
        {projects.map((project) => (
          <ProjectCard key={project.id} project={project} />
        ))}
      </div>
    </section>
  );
}
```

### 3.2 Client Components

```tsx
// components/features/task-toggle.tsx
"use client";

import { useState, useTransition } from "react";
import { toggleTaskAction } from "@/actions/tasks";
import { cn } from "@/lib/utils";

interface TaskToggleProps {
  taskId: string;
  initialCompleted: boolean;
}

export function TaskToggle({ taskId, initialCompleted }: TaskToggleProps) {
  const [completed, setCompleted] = useState(initialCompleted);
  const [isPending, startTransition] = useTransition();

  const handleToggle = () => {
    // Optimistic update
    setCompleted((prev) => !prev);

    startTransition(async () => {
      const result = await toggleTaskAction(taskId);
      if (!result.success) {
        setCompleted((prev) => !prev); // Revert on failure
      }
    });
  };

  return (
    <button
      onClick={handleToggle}
      disabled={isPending}
      className={cn(
        "w-5 h-5 rounded-full border-2 transition-colors",
        completed ? "bg-green-500 border-green-500" : "border-gray-400"
      )}
      aria-label={completed ? "Mark incomplete" : "Mark complete"}
    />
  );
}
```

### 3.3 Composition Pattern (Server + Client)

```tsx
// ✅ CORRECT: Server component wraps client component
// app/dashboard/page.tsx (Server)
import { TaskList } from "@/components/features/task-list";   // Client
import { getTasks } from "@/lib/queries";

export default async function DashboardPage() {
  const tasks = await getTasks(); // Server-side data fetch

  return (
    <main>
      {/* Pass server data as props to client component */}
      <TaskList initialTasks={tasks} />
    </main>
  );
}

// ✅ Pass server components as children to client components
// components/features/modal.tsx (Client)
"use client";
export function Modal({ children }: { children: React.ReactNode }) {
  const [open, setOpen] = useState(false);
  return (
    <div>
      <button onClick={() => setOpen(true)}>Open</button>
      {open && <div className="modal">{children}</div>}
    </div>
  );
}

// app/page.tsx (Server) — Passing Server Component as children
import { Modal } from "@/components/features/modal";
import { UserProfile } from "@/components/features/user-profile"; // Server

export default function Page() {
  return (
    <Modal>
      <UserProfile /> {/* ✅ Server component inside Client component via children */}
    </Modal>
  );
}
```

---

## 4. Routing

### 4.1 Dynamic Routes & Params

```tsx
// app/projects/[id]/page.tsx
interface ProjectPageProps {
  params: Promise<{ id: string }>;    // Always Promise in Next.js 15
  searchParams: Promise<{ tab?: string }>;
}

export default async function ProjectPage({
  params,
  searchParams,
}: ProjectPageProps) {
  const { id } = await params;
  const { tab = "overview" } = await searchParams;

  const project = await db.project.findUnique({ where: { id } });
  if (!project) notFound(); // Triggers not-found.tsx

  return <ProjectDetail project={project} activeTab={tab} />;
}

// ─── Static params for SSG ────────────────────────────────────────────────────
export async function generateStaticParams() {
  const projects = await db.project.findMany({ select: { id: true } });
  return projects.map(({ id }) => ({ id }));
}

// ─── Dynamic Metadata ─────────────────────────────────────────────────────────
export async function generateMetadata({ params }: ProjectPageProps) {
  const { id } = await params;
  const project = await db.project.findUnique({ where: { id } });

  return {
    title: project?.title ?? "Project Not Found",
    description: project?.description,
    openGraph: {
      images: [{ url: `/api/og?title=${project?.title}` }],
    },
  };
}
```

### 4.2 Parallel Routes

```tsx
// app/dashboard/@analytics/page.tsx — Slot: analytics
export default function AnalyticsSlot() {
  return <AnalyticsWidget />;
}

// app/dashboard/@team/page.tsx — Slot: team
export default function TeamSlot() {
  return <TeamWidget />;
}

// app/dashboard/layout.tsx — Consumes both slots
export default function DashboardLayout({
  children,
  analytics,
  team,
}: {
  children: React.ReactNode;
  analytics: React.ReactNode;
  team: React.ReactNode;
}) {
  return (
    <div className="grid grid-cols-12 gap-6">
      <main className="col-span-8">{children}</main>
      <aside className="col-span-4 space-y-4">
        {analytics}
        {team}
      </aside>
    </div>
  );
}
```

### 4.3 Intercepting Routes (Modals)

```
app/
├── projects/
│   ├── page.tsx              # /projects — full list
│   ├── [id]/page.tsx         # /projects/[id] — full detail
│   └── @modal/
│       └── (.)projects/      # Intercepts /projects/[id]
│           └── [id]/page.tsx # Shows as modal over list
```

```tsx
// app/projects/@modal/(.)projects/[id]/page.tsx
import { Modal } from "@/components/ui/modal";
import { ProjectQuickView } from "@/components/features/project-quick-view";

export default async function ProjectModal({
  params,
}: {
  params: Promise<{ id: string }>;
}) {
  const { id } = await params;
  const project = await db.project.findUnique({ where: { id } });

  return (
    <Modal>
      <ProjectQuickView project={project} />
    </Modal>
  );
}
```

### 4.4 Type-Safe Links (typedRoutes)

```tsx
import Link from "next/link";
import { useRouter } from "next/navigation";

// With typedRoutes: true in next.config.ts
// TypeScript will error on invalid routes!
<Link href="/projects/123">Project</Link>          // ✅
<Link href="/projects/123/edit">Edit</Link>        // ✅
// <Link href="/projcts">Typo</Link>               // ❌ Type Error

const router = useRouter();
router.push("/dashboard");  // ✅ Type-safe
```

---

## 5. Data Fetching & Caching

### 5.1 fetch with Cache Control (Next.js 15)

```typescript
// lib/queries.ts

// ─── Static (cached forever, revalidated on demand) ───────────────────────────
export async function getStaticData() {
  const res = await fetch("https://api.example.com/config", {
    cache: "force-cache",  // Default in Next.js 15 for static
  });
  return res.json();
}

// ─── Dynamic (never cached — always fresh) ────────────────────────────────────
export async function getDynamicData() {
  const res = await fetch("https://api.example.com/live-prices", {
    cache: "no-store",
  });
  return res.json();
}

// ─── ISR — Time-based revalidation ───────────────────────────────────────────
export async function getISRData() {
  const res = await fetch("https://api.example.com/posts", {
    next: { revalidate: 3600 }, // Revalidate every 1 hour
  });
  return res.json();
}

// ─── Tag-based revalidation ───────────────────────────────────────────────────
export async function getProjects() {
  const res = await fetch("https://api.example.com/projects", {
    next: { tags: ["projects"] }, // Tag for on-demand revalidation
  });
  return res.json();
}
```

### 5.2 React cache() — Deduplicate DB Calls

```typescript
import { cache } from "react";
import { db } from "@/lib/db";

// ✅ Called multiple times in one render → executes DB query ONCE
export const getUser = cache(async (id: string) => {
  return db.user.findUnique({
    where: { id },
    include: { profile: true },
  });
});

// Both of these within one server render share the same result
// await getUser("123") — DB query executes
// await getUser("123") — Returns cached result, NO second query
```

### 5.3 Suspense & Streaming

```tsx
// app/dashboard/page.tsx
import { Suspense } from "react";
import { ProjectsSkeleton } from "@/components/ui/skeletons";

export default function DashboardPage() {
  return (
    <div>
      <h1>Dashboard</h1>
      {/* Streams in independently when ready */}
      <Suspense fallback={<ProjectsSkeleton />}>
        <ProjectsSection />
      </Suspense>
      <Suspense fallback={<div>Loading analytics...</div>}>
        <AnalyticsSection />
      </Suspense>
    </div>
  );
}

// Each async component streams independently
async function ProjectsSection() {
  const projects = await getProjects(); // Slow query — doesn't block AnalyticsSection
  return <ProjectList projects={projects} />;
}

async function AnalyticsSection() {
  const stats = await getStats(); // Fast query
  return <StatsGrid stats={stats} />;
}
```

### 5.4 On-Demand Revalidation

```typescript
// actions/revalidate.ts
"use server";
import { revalidatePath, revalidateTag } from "next/cache";

export async function revalidateProjects() {
  revalidatePath("/projects");           // Revalidate specific path
  revalidateTag("projects");             // Revalidate all tagged fetches
}
```

---

## 6. Server Actions

### 6.1 Basic Server Action with Zod

```typescript
// actions/projects.ts
"use server";

import { z } from "zod";
import { revalidatePath } from "next/cache";
import { auth } from "@/lib/auth";
import { db } from "@/lib/db";

const CreateProjectSchema = z.object({
  title: z.string().min(1, "Title required").max(100),
  description: z.string().optional(),
  color: z.enum(["red", "blue", "green", "purple", "orange"]),
  dueDate: z.coerce.date().optional(),
});

type ActionResult<T = void> =
  | { success: true; data: T }
  | { success: false; error: string; fieldErrors?: Record<string, string[]> };

export async function createProjectAction(
  formData: FormData
): Promise<ActionResult<{ id: string }>> {
  // 1. Auth check
  const session = await auth();
  if (!session?.user) return { success: false, error: "Unauthorized" };

  // 2. Parse & validate
  const parsed = CreateProjectSchema.safeParse({
    title: formData.get("title"),
    description: formData.get("description"),
    color: formData.get("color"),
    dueDate: formData.get("dueDate"),
  });

  if (!parsed.success) {
    return {
      success: false,
      error: "Validation failed",
      fieldErrors: parsed.error.flatten().fieldErrors,
    };
  }

  // 3. Business logic
  try {
    const project = await db.project.create({
      data: {
        ...parsed.data,
        ownerId: session.user.id,
      },
    });

    // 4. Revalidate
    revalidatePath("/projects");
    revalidateTag("projects");

    return { success: true, data: { id: project.id } };
  } catch (error) {
    console.error("createProject error:", error);
    return { success: false, error: "Failed to create project" };
  }
}
```

### 6.2 useActionState Hook (React 19)

```tsx
// components/features/create-project-form.tsx
"use client";

import { useActionState, useRef } from "react";
import { createProjectAction } from "@/actions/projects";

const initialState = { success: false as const, error: "" };

export function CreateProjectForm() {
  const [state, action, isPending] = useActionState(
    createProjectAction,
    initialState
  );
  const formRef = useRef<HTMLFormElement>(null);

  return (
    <form ref={formRef} action={action} className="space-y-4">
      <div>
        <label htmlFor="title">Project Title</label>
        <input
          id="title"
          name="title"
          required
          className="input"
          aria-describedby={state.fieldErrors?.title ? "title-error" : undefined}
        />
        {state.fieldErrors?.title && (
          <p id="title-error" className="text-red-500 text-sm">
            {state.fieldErrors.title[0]}
          </p>
        )}
      </div>

      <select name="color" defaultValue="blue">
        {["red", "blue", "green", "purple", "orange"].map((c) => (
          <option key={c} value={c}>{c}</option>
        ))}
      </select>

      {!state.success && state.error && (
        <p className="text-red-500">{state.error}</p>
      )}

      <button type="submit" disabled={isPending}>
        {isPending ? "Creating..." : "Create Project"}
      </button>
    </form>
  );
}
```

### 6.3 Optimistic Updates with useOptimistic

```tsx
"use client";
import { useOptimistic, useTransition } from "react";
import { toggleTaskAction } from "@/actions/tasks";

interface Task { id: string; title: string; completed: boolean; }

export function TaskList({ tasks }: { tasks: Task[] }) {
  const [optimisticTasks, addOptimistic] = useOptimistic(
    tasks,
    (state, { id, completed }: { id: string; completed: boolean }) =>
      state.map((t) => (t.id === id ? { ...t, completed } : t))
  );
  const [, startTransition] = useTransition();

  const toggle = (task: Task) => {
    startTransition(async () => {
      // Optimistic update applied immediately
      addOptimistic({ id: task.id, completed: !task.completed });
      // Real update in background
      await toggleTaskAction(task.id);
    });
  };

  return (
    <ul>
      {optimisticTasks.map((task) => (
        <li key={task.id} onClick={() => toggle(task)}>
          <span className={task.completed ? "line-through opacity-50" : ""}>
            {task.title}
          </span>
        </li>
      ))}
    </ul>
  );
}
```

---

## 7. Layouts, Templates & Metadata

### 7.1 Root Layout

```tsx
// app/layout.tsx
import type { Metadata, Viewport } from "next";
import { Geist, Geist_Mono } from "next/font/google";
import { ThemeProvider } from "@/components/providers/theme-provider";
import { Toaster } from "@/components/ui/sonner";
import "./globals.css";

const geist = Geist({ subsets: ["latin"], variable: "--font-geist" });
const geistMono = Geist_Mono({ subsets: ["latin"], variable: "--font-mono" });

export const metadata: Metadata = {
  metadataBase: new URL("https://taskflow.app"),
  title: { default: "TaskFlow", template: "%s | TaskFlow" },
  description: "Modern project management for teams",
  applicationName: "TaskFlow",
  keywords: ["project management", "tasks", "collaboration"],
  authors: [{ name: "TaskFlow Team" }],
  creator: "TaskFlow",
  openGraph: {
    type: "website",
    locale: "en_US",
    url: "https://taskflow.app",
    siteName: "TaskFlow",
    images: [{ url: "/og-image.png", width: 1200, height: 630 }],
  },
  twitter: { card: "summary_large_image", creator: "@taskflow" },
  robots: { index: true, follow: true },
};

export const viewport: Viewport = {
  themeColor: [
    { media: "(prefers-color-scheme: light)", color: "#ffffff" },
    { media: "(prefers-color-scheme: dark)", color: "#0a0a0a" },
  ],
  width: "device-width",
  initialScale: 1,
};

export default function RootLayout({ children }: { children: React.ReactNode }) {
  return (
    <html lang="en" suppressHydrationWarning>
      <body className={`${geist.variable} ${geistMono.variable} antialiased`}>
        <ThemeProvider attribute="class" defaultTheme="system" enableSystem>
          {children}
          <Toaster richColors position="top-right" />
        </ThemeProvider>
      </body>
    </html>
  );
}
```

### 7.2 Template vs Layout

```tsx
// Layout: Persists across navigations (state preserved)
// app/(dashboard)/layout.tsx
export default function DashboardLayout({ children }: { children: React.ReactNode }) {
  return (
    <div className="flex h-screen">
      <Sidebar />         {/* ← NOT re-mounted on navigation */}
      <main>{children}</main>
    </div>
  );
}

// Template: Re-mounts on every navigation (fresh state)
// app/(dashboard)/template.tsx
export default function DashboardTemplate({ children }: { children: React.ReactNode }) {
  return (
    <div className="animate-fade-in">
      {children}           {/* ← Re-mounts (animations replay) */}
    </div>
  );
}
```

---

## 8. Middleware & Edge Runtime

```typescript
// middleware.ts
import { NextResponse } from "next/server";
import type { NextRequest } from "next/server";
import { auth } from "@/lib/auth";

export async function middleware(request: NextRequest) {
  const { pathname } = request.nextUrl;

  // ─── Auth protection ───────────────────────────────────────────────────────
  const session = await auth();

  const protectedPaths = ["/dashboard", "/projects", "/settings"];
  const authPaths = ["/login", "/register"];

  const isProtected = protectedPaths.some((p) => pathname.startsWith(p));
  const isAuthPath = authPaths.some((p) => pathname.startsWith(p));

  if (isProtected && !session) {
    const loginUrl = new URL("/login", request.url);
    loginUrl.searchParams.set("callbackUrl", pathname);
    return NextResponse.redirect(loginUrl);
  }

  if (isAuthPath && session) {
    return NextResponse.redirect(new URL("/dashboard", request.url));
  }

  // ─── Rate limiting (example with custom headers) ──────────────────────────
  const response = NextResponse.next();
  response.headers.set("X-Frame-Options", "DENY");
  response.headers.set("X-Content-Type-Options", "nosniff");

  return response;
}

export const config = {
  matcher: [
    "/((?!api/auth|_next/static|_next/image|favicon.ico|public).*)",
  ],
};
```

---

## 9. Authentication — NextAuth v5

### 9.1 Auth Configuration

```typescript
// lib/auth.ts
import NextAuth from "next-auth";
import { PrismaAdapter } from "@auth/prisma-adapter";
import GitHub from "next-auth/providers/github";
import Google from "next-auth/providers/google";
import Credentials from "next-auth/providers/credentials";
import { db } from "@/lib/db";
import { compare } from "bcryptjs";
import { z } from "zod";

const CredentialsSchema = z.object({
  email: z.string().email(),
  password: z.string().min(8),
});

export const { handlers, auth, signIn, signOut } = NextAuth({
  adapter: PrismaAdapter(db),
  session: { strategy: "jwt" },
  pages: {
    signIn: "/login",
    error: "/auth/error",
  },
  providers: [
    GitHub({
      clientId: process.env.GITHUB_CLIENT_ID!,
      clientSecret: process.env.GITHUB_CLIENT_SECRET!,
    }),
    Google({
      clientId: process.env.GOOGLE_CLIENT_ID!,
      clientSecret: process.env.GOOGLE_CLIENT_SECRET!,
    }),
    Credentials({
      async authorize(credentials) {
        const parsed = CredentialsSchema.safeParse(credentials);
        if (!parsed.success) return null;

        const user = await db.user.findUnique({
          where: { email: parsed.data.email },
        });
        if (!user?.password) return null;

        const valid = await compare(parsed.data.password, user.password);
        if (!valid) return null;

        return { id: user.id, email: user.email, name: user.name, image: user.image };
      },
    }),
  ],
  callbacks: {
    async jwt({ token, user, trigger, session }) {
      if (user) {
        token.id = user.id;
        token.role = (user as any).role ?? "USER";
      }
      // Handle session update
      if (trigger === "update" && session?.name) {
        token.name = session.name;
      }
      return token;
    },
    async session({ session, token }) {
      session.user.id = token.id as string;
      session.user.role = token.role as string;
      return session;
    },
  },
});

// Type augmentation
declare module "next-auth" {
  interface Session {
    user: { id: string; role: string; } & DefaultSession["user"];
  }
}
```

### 9.2 Auth Route Handler

```typescript
// app/api/auth/[...nextauth]/route.ts
import { handlers } from "@/lib/auth";
export const { GET, POST } = handlers;
```

### 9.3 Using Auth in Components

```tsx
// Server Component
import { auth } from "@/lib/auth";
import { redirect } from "next/navigation";

export default async function ProtectedPage() {
  const session = await auth();
  if (!session) redirect("/login");

  return <div>Hello, {session.user.name}!</div>;
}

// Client Component
"use client";
import { useSession, signIn, signOut } from "next-auth/react";

export function UserMenu() {
  const { data: session, status } = useSession();

  if (status === "loading") return <Spinner />;
  if (!session) return <button onClick={() => signIn()}>Sign In</button>;

  return (
    <div>
      <img src={session.user.image ?? ""} alt="Avatar" />
      <span>{session.user.name}</span>
      <button onClick={() => signOut()}>Sign Out</button>
    </div>
  );
}
```

---

## 10. Database with Prisma

### 10.1 Schema

```prisma
// prisma/schema.prisma
generator client {
  provider = "prisma-client-js"
}

datasource db {
  provider  = "postgresql"
  url       = env("DATABASE_URL")
  directUrl = env("DIRECT_URL") // For Supabase/PgBouncer
}

model User {
  id        String   @id @default(cuid())
  email     String   @unique
  name      String?
  password  String?
  image     String?
  role      Role     @default(USER)
  createdAt DateTime @default(now())
  updatedAt DateTime @updatedAt

  accounts Account[]
  sessions Session[]
  projects Project[]
  tasks    Task[]    @relation("assignedTasks")

  @@index([email])
  @@map("users")
}

model Project {
  id          String        @id @default(cuid())
  title       String
  description String?
  color       String        @default("blue")
  status      ProjectStatus @default(ACTIVE)
  dueDate     DateTime?
  createdAt   DateTime      @default(now())
  updatedAt   DateTime      @updatedAt

  owner   User   @relation(fields: [ownerId], references: [id], onDelete: Cascade)
  ownerId String

  tasks Task[]

  @@index([ownerId])
  @@map("projects")
}

model Task {
  id          String     @id @default(cuid())
  title       String
  description String?
  completed   Boolean    @default(false)
  priority    Priority   @default(MEDIUM)
  dueDate     DateTime?
  position    Int        @default(0)
  createdAt   DateTime   @default(now())
  updatedAt   DateTime   @updatedAt

  project   Project @relation(fields: [projectId], references: [id], onDelete: Cascade)
  projectId String

  assignee   User?   @relation("assignedTasks", fields: [assigneeId], references: [id])
  assigneeId String?

  tags Tag[]

  @@index([projectId])
  @@index([assigneeId])
  @@map("tasks")
}

model Tag {
  id    String @id @default(cuid())
  name  String
  color String @default("#6366f1")
  tasks Task[]

  @@map("tags")
}

enum Role          { USER ADMIN }
enum ProjectStatus { ACTIVE ARCHIVED COMPLETED }
enum Priority      { LOW MEDIUM HIGH URGENT }

// NextAuth required models
model Account { /* ... standard NextAuth fields */ }
model Session { /* ... standard NextAuth fields */ }
```

### 10.2 Prisma Client Singleton

```typescript
// lib/db.ts
import { PrismaClient } from "@prisma/client";

const globalForPrisma = globalThis as unknown as {
  prisma: PrismaClient | undefined;
};

export const db =
  globalForPrisma.prisma ??
  new PrismaClient({
    log: process.env.NODE_ENV === "development"
      ? ["query", "error", "warn"]
      : ["error"],
  });

if (process.env.NODE_ENV !== "production") {
  globalForPrisma.prisma = db;
}
```

### 10.3 Type-Safe Queries

```typescript
// lib/queries/projects.ts
import { db } from "@/lib/db";
import type { Prisma } from "@prisma/client";

// Type from Prisma — always accurate to schema
type ProjectWithTaskCount = Prisma.ProjectGetPayload<{
  include: { _count: { select: { tasks: true } }; owner: true };
}>;

export async function getProjectsWithCounts(
  userId: string
): Promise<ProjectWithTaskCount[]> {
  return db.project.findMany({
    where: { ownerId: userId },
    include: {
      owner: true,
      _count: { select: { tasks: true } },
    },
    orderBy: { createdAt: "desc" },
  });
}

// Paginated query
export async function getPaginatedTasks(
  projectId: string,
  page: number = 1,
  pageSize: number = 20
) {
  const [tasks, total] = await db.$transaction([
    db.task.findMany({
      where: { projectId },
      skip: (page - 1) * pageSize,
      take: pageSize,
      orderBy: [{ position: "asc" }, { createdAt: "desc" }],
      include: { assignee: { select: { id: true, name: true, image: true } } },
    }),
    db.task.count({ where: { projectId } }),
  ]);

  return { tasks, total, totalPages: Math.ceil(total / pageSize) };
}
```

---

## 11. State Management

### 11.1 Zustand Store

```typescript
// store/use-task-store.ts
import { create } from "zustand";
import { devtools, persist, subscribeWithSelector } from "zustand/middleware";
import { immer } from "zustand/middleware/immer";
import type { Task } from "@prisma/client";

interface TaskState {
  tasks: Task[];
  selectedTaskId: string | null;
  filter: "all" | "completed" | "pending";
  // Actions
  setTasks: (tasks: Task[]) => void;
  addTask: (task: Task) => void;
  updateTask: (id: string, updates: Partial<Task>) => void;
  removeTask: (id: string) => void;
  selectTask: (id: string | null) => void;
  setFilter: (filter: TaskState["filter"]) => void;
  // Computed
  filteredTasks: () => Task[];
}

export const useTaskStore = create<TaskState>()(
  devtools(
    persist(
      subscribeWithSelector(
        immer((set, get) => ({
          tasks: [],
          selectedTaskId: null,
          filter: "all",

          setTasks: (tasks) => set({ tasks }),
          addTask: (task) =>
            set((state) => { state.tasks.push(task); }),
          updateTask: (id, updates) =>
            set((state) => {
              const idx = state.tasks.findIndex((t) => t.id === id);
              if (idx !== -1) Object.assign(state.tasks[idx], updates);
            }),
          removeTask: (id) =>
            set((state) => {
              state.tasks = state.tasks.filter((t) => t.id !== id);
            }),
          selectTask: (id) => set({ selectedTaskId: id }),
          setFilter: (filter) => set({ filter }),

          filteredTasks: () => {
            const { tasks, filter } = get();
            if (filter === "completed") return tasks.filter((t) => t.completed);
            if (filter === "pending") return tasks.filter((t) => !t.completed);
            return tasks;
          },
        }))
      ),
      { name: "task-store", partialize: (s) => ({ filter: s.filter }) }
    )
  )
);

// Selector hooks (prevent unnecessary rerenders)
export const useTasks = () => useTaskStore((s) => s.tasks);
export const useSelectedTask = () =>
  useTaskStore((s) => s.tasks.find((t) => t.id === s.selectedTaskId));
```

### 11.2 TanStack Query v5

```tsx
// hooks/use-projects.ts
import { useQuery, useMutation, useQueryClient } from "@tanstack/react-query";
import type { Project } from "@prisma/client";

// ─── Query Keys (type-safe factory) ──────────────────────────────────────────
export const projectKeys = {
  all: ["projects"] as const,
  lists: () => [...projectKeys.all, "list"] as const,
  list: (filters: object) => [...projectKeys.lists(), filters] as const,
  details: () => [...projectKeys.all, "detail"] as const,
  detail: (id: string) => [...projectKeys.details(), id] as const,
};

// ─── Fetch function ───────────────────────────────────────────────────────────
async function fetchProjects(): Promise<Project[]> {
  const res = await fetch("/api/projects");
  if (!res.ok) throw new Error("Failed to fetch projects");
  return res.json();
}

// ─── Query hook ───────────────────────────────────────────────────────────────
export function useProjects() {
  return useQuery({
    queryKey: projectKeys.lists(),
    queryFn: fetchProjects,
    staleTime: 1000 * 60 * 5, // 5 minutes
  });
}

// ─── Mutation hook ────────────────────────────────────────────────────────────
export function useCreateProject() {
  const queryClient = useQueryClient();

  return useMutation({
    mutationFn: async (data: Partial<Project>) => {
      const res = await fetch("/api/projects", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(data),
      });
      return res.json();
    },
    onMutate: async (newProject) => {
      await queryClient.cancelQueries({ queryKey: projectKeys.lists() });
      const prev = queryClient.getQueryData<Project[]>(projectKeys.lists());

      // Optimistic update
      queryClient.setQueryData<Project[]>(projectKeys.lists(), (old = []) => [
        ...old,
        { id: "temp-" + Date.now(), ...newProject } as Project,
      ]);

      return { prev };
    },
    onError: (_err, _vars, ctx) => {
      if (ctx?.prev) {
        queryClient.setQueryData(projectKeys.lists(), ctx.prev);
      }
    },
    onSettled: () => {
      queryClient.invalidateQueries({ queryKey: projectKeys.lists() });
    },
  });
}
```

### 11.3 Provider Setup

```tsx
// components/providers/query-provider.tsx
"use client";

import { QueryClient, QueryClientProvider } from "@tanstack/react-query";
import { ReactQueryDevtools } from "@tanstack/react-query-devtools";
import { useState } from "react";

export function QueryProvider({ children }: { children: React.ReactNode }) {
  const [queryClient] = useState(
    () =>
      new QueryClient({
        defaultOptions: {
          queries: {
            staleTime: 60 * 1000,
            retry: (failureCount, error: any) => {
              if (error?.status === 404) return false;
              return failureCount < 3;
            },
          },
        },
      })
  );

  return (
    <QueryClientProvider client={queryClient}>
      {children}
      <ReactQueryDevtools initialIsOpen={false} />
    </QueryClientProvider>
  );
}
```

---

## 12. Forms & Validation

### 12.1 React Hook Form + Zod

```tsx
// components/features/create-task-form.tsx
"use client";

import { useForm } from "react-hook-form";
import { zodResolver } from "@hookform/resolvers/zod";
import { z } from "zod";
import { toast } from "sonner";
import { useCreateTask } from "@/hooks/use-tasks";

const CreateTaskSchema = z.object({
  title: z.string().min(1, "Title is required").max(200),
  description: z.string().max(2000).optional(),
  priority: z.enum(["LOW", "MEDIUM", "HIGH", "URGENT"]),
  dueDate: z.string().optional().transform((v) => v ? new Date(v) : undefined),
  assigneeId: z.string().cuid().optional(),
});

type CreateTaskInput = z.infer<typeof CreateTaskSchema>;

export function CreateTaskForm({ projectId }: { projectId: string }) {
  const { mutateAsync: createTask } = useCreateTask(projectId);

  const {
    register,
    handleSubmit,
    reset,
    formState: { errors, isSubmitting, isDirty },
  } = useForm<CreateTaskInput>({
    resolver: zodResolver(CreateTaskSchema),
    defaultValues: { priority: "MEDIUM" },
  });

  const onSubmit = async (data: CreateTaskInput) => {
    try {
      await createTask({ ...data, projectId });
      toast.success("Task created!");
      reset();
    } catch {
      toast.error("Failed to create task");
    }
  };

  return (
    <form onSubmit={handleSubmit(onSubmit)} className="space-y-4">
      <div>
        <input
          {...register("title")}
          placeholder="Task title"
          className="input w-full"
        />
        {errors.title && (
          <p className="text-sm text-red-500 mt-1">{errors.title.message}</p>
        )}
      </div>

      <textarea
        {...register("description")}
        placeholder="Description (optional)"
        rows={3}
        className="input w-full"
      />

      <div className="flex gap-3">
        <select {...register("priority")} className="input">
          <option value="LOW">Low</option>
          <option value="MEDIUM">Medium</option>
          <option value="HIGH">High</option>
          <option value="URGENT">Urgent</option>
        </select>

        <input
          type="date"
          {...register("dueDate")}
          className="input"
        />
      </div>

      <button
        type="submit"
        disabled={isSubmitting || !isDirty}
        className="btn-primary w-full"
      >
        {isSubmitting ? "Creating..." : "Add Task"}
      </button>
    </form>
  );
}
```

---

## 13. API Routes & Route Handlers

### 13.1 RESTful Route Handler

```typescript
// app/api/projects/route.ts
import { NextResponse } from "next/server";
import type { NextRequest } from "next/server";
import { auth } from "@/lib/auth";
import { db } from "@/lib/db";
import { z } from "zod";

const CreateProjectSchema = z.object({
  title: z.string().min(1).max(100),
  description: z.string().optional(),
  color: z.enum(["red", "blue", "green", "purple", "orange"]).default("blue"),
});

export async function GET(request: NextRequest) {
  const session = await auth();
  if (!session?.user) return NextResponse.json({ error: "Unauthorized" }, { status: 401 });

  const { searchParams } = request.nextUrl;
  const page = parseInt(searchParams.get("page") ?? "1");
  const limit = Math.min(parseInt(searchParams.get("limit") ?? "10"), 100);

  const projects = await db.project.findMany({
    where: { ownerId: session.user.id },
    skip: (page - 1) * limit,
    take: limit,
    include: { _count: { select: { tasks: true } } },
    orderBy: { createdAt: "desc" },
  });

  return NextResponse.json(
    { data: projects, page, limit },
    {
      headers: {
        "Cache-Control": "private, max-age=60",
      },
    }
  );
}

export async function POST(request: NextRequest) {
  const session = await auth();
  if (!session?.user) return NextResponse.json({ error: "Unauthorized" }, { status: 401 });

  const body = await request.json().catch(() => null);
  const parsed = CreateProjectSchema.safeParse(body);

  if (!parsed.success) {
    return NextResponse.json(
      { error: "Validation failed", details: parsed.error.flatten() },
      { status: 422 }
    );
  }

  const project = await db.project.create({
    data: { ...parsed.data, ownerId: session.user.id },
  });

  return NextResponse.json({ data: project }, { status: 201 });
}
```

### 13.2 Dynamic Route Handler

```typescript
// app/api/projects/[id]/route.ts
import { NextResponse } from "next/server";
import type { NextRequest } from "next/server";

interface RouteContext {
  params: Promise<{ id: string }>;
}

export async function GET(_req: NextRequest, { params }: RouteContext) {
  const { id } = await params;
  const project = await db.project.findUnique({
    where: { id },
    include: { tasks: true, owner: true },
  });

  if (!project) return NextResponse.json({ error: "Not found" }, { status: 404 });
  return NextResponse.json({ data: project });
}

export async function PATCH(req: NextRequest, { params }: RouteContext) {
  const { id } = await params;
  const session = await auth();
  if (!session?.user) return NextResponse.json({ error: "Unauthorized" }, { status: 401 });

  const body = await req.json();
  const project = await db.project.update({ where: { id }, data: body });
  return NextResponse.json({ data: project });
}

export async function DELETE(_req: NextRequest, { params }: RouteContext) {
  const { id } = await params;
  await db.project.delete({ where: { id } });
  return new NextResponse(null, { status: 204 });
}
```

---

## 14. Performance Optimization

### 14.1 Image Optimization

```tsx
import Image from "next/image";

// ─── Fixed size (always specify width/height) ─────────────────────────────────
<Image
  src="/hero.jpg"
  alt="Hero image"
  width={1200}
  height={630}
  priority  // Preload for above-the-fold
  quality={90}
/>

// ─── Responsive / Fill ────────────────────────────────────────────────────────
<div className="relative h-64 w-full">
  <Image
    src={project.coverImage}
    alt={project.title}
    fill
    sizes="(max-width: 768px) 100vw, (max-width: 1200px) 50vw, 33vw"
    className="object-cover rounded-lg"
  />
</div>

// ─── Placeholder blur ─────────────────────────────────────────────────────────
<Image
  src={user.avatarUrl}
  alt="Avatar"
  width={40}
  height={40}
  placeholder="blur"
  blurDataURL="data:image/jpeg;base64,/9j/4AAQ..."
  className="rounded-full"
/>
```

### 14.2 Dynamic Imports

```tsx
import dynamic from "next/dynamic";

// Client-side only (skip SSR)
const RichTextEditor = dynamic(
  () => import("@/components/features/rich-text-editor"),
  {
    ssr: false,
    loading: () => <div className="h-64 bg-gray-100 animate-pulse rounded" />,
  }
);

// Heavy chart library — code split
const AnalyticsChart = dynamic(
  () => import("@/components/features/analytics-chart").then((m) => m.AnalyticsChart),
  { loading: () => <ChartSkeleton /> }
);
```

### 14.3 Partial Pre-Rendering (PPR)

```tsx
// app/projects/[id]/page.tsx
import { Suspense } from "react";
import { unstable_noStore as noStore } from "next/cache";

// Static shell rendered at build time
export default async function ProjectPage({ params }: { params: Promise<{ id: string }> }) {
  const { id } = await params;

  return (
    <div>
      {/* ✅ Static — rendered at build time */}
      <ProjectHeader id={id} />

      {/* ✅ Dynamic — streamed in after */}
      <Suspense fallback={<TasksSkeleton />}>
        <DynamicTaskList projectId={id} />
      </Suspense>
    </div>
  );
}

async function DynamicTaskList({ projectId }: { projectId: string }) {
  noStore(); // Opt out of caching
  const tasks = await getLiveTasks(projectId);
  return <TaskList tasks={tasks} />;
}
```

---

## 15. Testing

### 15.1 Vitest — Unit & Integration

```typescript
// __tests__/actions/projects.test.ts
import { describe, it, expect, vi, beforeEach } from "vitest";
import { createProjectAction } from "@/actions/projects";

// Mock Prisma
vi.mock("@/lib/db", () => ({
  db: {
    project: {
      create: vi.fn().mockResolvedValue({
        id: "proj_123",
        title: "Test Project",
        color: "blue",
      }),
    },
  },
}));

// Mock Auth
vi.mock("@/lib/auth", () => ({
  auth: vi.fn().mockResolvedValue({
    user: { id: "user_123", email: "test@example.com" },
  }),
}));

describe("createProjectAction", () => {
  it("creates a project with valid data", async () => {
    const formData = new FormData();
    formData.set("title", "Test Project");
    formData.set("color", "blue");

    const result = await createProjectAction(formData);

    expect(result.success).toBe(true);
    if (result.success) {
      expect(result.data.id).toBe("proj_123");
    }
  });

  it("returns error for missing title", async () => {
    const formData = new FormData();
    formData.set("color", "blue");

    const result = await createProjectAction(formData);

    expect(result.success).toBe(false);
    if (!result.success) {
      expect(result.fieldErrors?.title).toBeDefined();
    }
  });
});
```

### 15.2 Playwright — E2E

```typescript
// e2e/projects.spec.ts
import { test, expect } from "@playwright/test";

test.describe("Projects", () => {
  test.beforeEach(async ({ page }) => {
    // Login
    await page.goto("/login");
    await page.fill('[name="email"]', "test@example.com");
    await page.fill('[name="password"]', "password123");
    await page.click('[type="submit"]');
    await page.waitForURL("/dashboard");
  });

  test("creates a new project", async ({ page }) => {
    await page.goto("/projects");
    await page.click('[data-testid="new-project-btn"]');

    await page.fill('[name="title"]', "E2E Test Project");
    await page.selectOption('[name="color"]', "blue");
    await page.click('[type="submit"]');

    await expect(page.getByText("E2E Test Project")).toBeVisible();
  });

  test("project list is paginated", async ({ page }) => {
    await page.goto("/projects");
    const cards = page.locator('[data-testid="project-card"]');
    await expect(cards).toHaveCount(10);
  });
});
```

---

## 16. Deployment & DevOps

### 16.1 Environment Variables

```bash
# .env.local
DATABASE_URL="postgresql://user:pass@host/db?sslmode=require"
DIRECT_URL="postgresql://user:pass@host/db"
NEXTAUTH_URL="http://localhost:3000"
NEXTAUTH_SECRET="your-secret-here"
GITHUB_CLIENT_ID="..."
GITHUB_CLIENT_SECRET="..."
GOOGLE_CLIENT_ID="..."
GOOGLE_CLIENT_SECRET="..."
```

```typescript
// env.ts — Type-safe env validation (T3 Env)
import { createEnv } from "@t3-oss/env-nextjs";
import { z } from "zod";

export const env = createEnv({
  server: {
    DATABASE_URL: z.string().url(),
    NEXTAUTH_SECRET: z.string().min(32),
    GITHUB_CLIENT_ID: z.string(),
    GITHUB_CLIENT_SECRET: z.string(),
  },
  client: {
    NEXT_PUBLIC_APP_URL: z.string().url(),
  },
  runtimeEnv: {
    DATABASE_URL: process.env.DATABASE_URL,
    NEXTAUTH_SECRET: process.env.NEXTAUTH_SECRET,
    GITHUB_CLIENT_ID: process.env.GITHUB_CLIENT_ID,
    GITHUB_CLIENT_SECRET: process.env.GITHUB_CLIENT_SECRET,
    NEXT_PUBLIC_APP_URL: process.env.NEXT_PUBLIC_APP_URL,
  },
});
```

### 16.2 Docker

```dockerfile
# Dockerfile
FROM node:22-alpine AS base
RUN apk add --no-cache libc6-compat
WORKDIR /app

FROM base AS deps
COPY package.json pnpm-lock.yaml ./
RUN corepack enable pnpm && pnpm install --frozen-lockfile

FROM base AS builder
COPY --from=deps /app/node_modules ./node_modules
COPY . .
RUN pnpm prisma generate
RUN pnpm build

FROM base AS runner
ENV NODE_ENV=production
RUN addgroup --system --gid 1001 nodejs
RUN adduser --system --uid 1001 nextjs

COPY --from=builder /app/public ./public
COPY --from=builder --chown=nextjs:nodejs /app/.next/standalone ./
COPY --from=builder --chown=nextjs:nodejs /app/.next/static ./.next/static

USER nextjs
EXPOSE 3000
CMD ["node", "server.js"]
```

---

## 17. Final Project: TaskFlow SaaS

> A full-featured project management SaaS with real-time collaboration

### Tech Stack
- **Next.js 15** (App Router + PPR)
- **TypeScript 5** (strict mode)
- **PostgreSQL** + Prisma ORM
- **NextAuth v5** (OAuth + Credentials)
- **Zustand** (UI state)
- **TanStack Query v5** (server state)
- **Zod** (validation)
- **Tailwind CSS v4** + **shadcn/ui**
- **Resend** (emails)
- **Uploadthing** (file uploads)
- **Trigger.dev** (background jobs)

---

### Project Structure

```
taskflow/
├── app/
│   ├── (auth)/
│   │   ├── login/page.tsx
│   │   └── register/page.tsx
│   ├── (dashboard)/
│   │   ├── layout.tsx
│   │   ├── dashboard/page.tsx
│   │   ├── projects/
│   │   │   ├── page.tsx
│   │   │   ├── [id]/
│   │   │   │   ├── page.tsx
│   │   │   │   ├── settings/page.tsx
│   │   │   │   └── @modal/(.)tasks/[taskId]/page.tsx
│   │   └── settings/page.tsx
│   └── api/
│       ├── auth/[...nextauth]/route.ts
│       ├── projects/route.ts
│       ├── projects/[id]/route.ts
│       ├── tasks/route.ts
│       ├── tasks/[id]/route.ts
│       ├── upload/route.ts
│       └── og/route.tsx          ← OG image generation
├── actions/
│   ├── projects.ts
│   ├── tasks.ts
│   └── users.ts
├── components/
│   ├── ui/                       ← shadcn components
│   ├── providers/
│   └── features/
│       ├── project-board.tsx     ← Kanban board
│       ├── task-card.tsx
│       ├── task-drawer.tsx
│       └── team-invite-modal.tsx
├── hooks/
│   ├── use-projects.ts
│   ├── use-tasks.ts
│   └── use-keyboard-shortcuts.ts
├── store/
│   ├── use-task-store.ts
│   └── use-ui-store.ts
├── lib/
│   ├── db.ts
│   ├── auth.ts
│   ├── email.ts                  ← Resend
│   └── validations.ts
└── types/
    └── index.ts
```

---

### Core Features Implementation

#### Feature 1: Kanban Board

```tsx
// components/features/project-board.tsx
"use client";

import { useState } from "react";
import {
  DndContext,
  DragEndEvent,
  DragOverEvent,
  DragOverlay,
  PointerSensor,
  useSensor,
  useSensors,
} from "@dnd-kit/core";
import { SortableContext, arrayMove, verticalListSortingStrategy } from "@dnd-kit/sortable";
import { TaskCard } from "./task-card";
import { useTaskStore } from "@/store/use-task-store";
import { updateTaskPositionAction } from "@/actions/tasks";
import type { Task } from "@prisma/client";

const COLUMNS = ["TODO", "IN_PROGRESS", "IN_REVIEW", "DONE"] as const;
type Column = (typeof COLUMNS)[number];

export function ProjectBoard({ projectId }: { projectId: string }) {
  const { tasks, updateTask } = useTaskStore();
  const [activeTask, setActiveTask] = useState<Task | null>(null);

  const sensors = useSensors(
    useSensor(PointerSensor, { activationConstraint: { distance: 8 } })
  );

  const tasksByColumn = COLUMNS.reduce((acc, col) => {
    acc[col] = tasks.filter((t) => t.status === col).sort((a, b) => a.position - b.position);
    return acc;
  }, {} as Record<Column, Task[]>);

  const handleDragEnd = async ({ active, over }: DragEndEvent) => {
    if (!over) return;

    const activeTask = tasks.find((t) => t.id === active.id);
    const overColumn = over.data.current?.column as Column | undefined;

    if (!activeTask || !overColumn) return;

    const newStatus = overColumn !== activeTask.status ? overColumn : activeTask.status;

    // Optimistic update
    updateTask(activeTask.id, { status: newStatus as any });

    // Persist
    await updateTaskPositionAction(activeTask.id, { status: newStatus });

    setActiveTask(null);
  };

  return (
    <DndContext sensors={sensors} onDragEnd={handleDragEnd} onDragStart={({ active }) =>
      setActiveTask(tasks.find((t) => t.id === active.id) ?? null)
    }>
      <div className="flex gap-4 overflow-x-auto pb-4">
        {COLUMNS.map((col) => (
          <KanbanColumn
            key={col}
            column={col}
            tasks={tasksByColumn[col]}
          />
        ))}
      </div>
      <DragOverlay>
        {activeTask ? <TaskCard task={activeTask} overlay /> : null}
      </DragOverlay>
    </DndContext>
  );
}
```

#### Feature 2: OG Image Generation

```tsx
// app/api/og/route.tsx
import { ImageResponse } from "next/og";
import type { NextRequest } from "next/server";

export const runtime = "edge";

export async function GET(req: NextRequest) {
  const { searchParams } = req.nextUrl;
  const title = searchParams.get("title") ?? "TaskFlow";
  const description = searchParams.get("description") ?? "Project Management";

  return new ImageResponse(
    (
      <div
        style={{
          display: "flex",
          flexDirection: "column",
          width: "100%",
          height: "100%",
          background: "linear-gradient(135deg, #667eea 0%, #764ba2 100%)",
          padding: 60,
          justifyContent: "flex-end",
        }}
      >
        <div style={{ fontSize: 72, fontWeight: 800, color: "white" }}>{title}</div>
        <div style={{ fontSize: 32, color: "rgba(255,255,255,0.8)", marginTop: 16 }}>
          {description}
        </div>
        <div style={{ fontSize: 24, color: "rgba(255,255,255,0.6)", marginTop: 32 }}>
          taskflow.app
        </div>
      </div>
    ),
    { width: 1200, height: 630 }
  );
}
```

#### Feature 3: Background Email Jobs (Trigger.dev)

```typescript
// trigger/send-task-assigned.ts
import { task, logger } from "@trigger.dev/sdk/v3";
import { Resend } from "resend";
import { TaskAssignedEmail } from "@/emails/task-assigned";

const resend = new Resend(process.env.RESEND_API_KEY);

export const sendTaskAssignedEmail = task({
  id: "send-task-assigned-email",
  retry: { maxAttempts: 3, minTimeoutInMs: 1000, factor: 2 },

  run: async (payload: {
    taskId: string;
    taskTitle: string;
    assigneeName: string;
    assigneeEmail: string;
    projectName: string;
    assignerName: string;
  }) => {
    logger.info("Sending task assigned email", { taskId: payload.taskId });

    const { error } = await resend.emails.send({
      from: "TaskFlow <noreply@taskflow.app>",
      to: payload.assigneeEmail,
      subject: `You've been assigned: ${payload.taskTitle}`,
      react: TaskAssignedEmail(payload),
    });

    if (error) throw new Error(`Email failed: ${error.message}`);

    logger.info("Email sent successfully");
    return { sent: true };
  },
});

// Usage in Server Action
// await sendTaskAssignedEmail.trigger({ taskId, ... });
```

#### Feature 4: Real-time with Server-Sent Events

```typescript
// app/api/projects/[id]/events/route.ts
export const runtime = "edge";

export async function GET(
  _req: Request,
  { params }: { params: Promise<{ id: string }> }
) {
  const { id: projectId } = await params;

  const stream = new ReadableStream({
    start(controller) {
      const encoder = new TextEncoder();
      const send = (data: object) => {
        controller.enqueue(encoder.encode(`data: ${JSON.stringify(data)}\n\n`));
      };

      // Heartbeat
      const heartbeat = setInterval(() => {
        send({ type: "ping", timestamp: Date.now() });
      }, 30000);

      // Cleanup
      return () => clearInterval(heartbeat);
    },
  });

  return new Response(stream, {
    headers: {
      "Content-Type": "text/event-stream",
      "Cache-Control": "no-cache",
      "Connection": "keep-alive",
    },
  });
}
```

#### Feature 5: Advanced Search with URL State

```tsx
// components/features/task-search.tsx
"use client";

import { useRouter, usePathname, useSearchParams } from "next/navigation";
import { useDebouncedCallback } from "use-debounce";

export function TaskSearch() {
  const router = useRouter();
  const pathname = usePathname();
  const searchParams = useSearchParams();

  const handleSearch = useDebouncedCallback((term: string) => {
    const params = new URLSearchParams(searchParams);
    if (term) {
      params.set("q", term);
    } else {
      params.delete("q");
    }
    params.set("page", "1"); // Reset pagination
    router.replace(`${pathname}?${params.toString()}`);
  }, 300);

  return (
    <div className="flex gap-2">
      <input
        placeholder="Search tasks..."
        defaultValue={searchParams.get("q") ?? ""}
        onChange={(e) => handleSearch(e.target.value)}
        className="input"
      />
      <select
        defaultValue={searchParams.get("priority") ?? ""}
        onChange={(e) => {
          const params = new URLSearchParams(searchParams);
          if (e.target.value) params.set("priority", e.target.value);
          else params.delete("priority");
          router.replace(`${pathname}?${params.toString()}`);
        }}
        className="input"
      >
        <option value="">All priorities</option>
        <option value="URGENT">Urgent</option>
        <option value="HIGH">High</option>
        <option value="MEDIUM">Medium</option>
        <option value="LOW">Low</option>
      </select>
    </div>
  );
}
```

---

### Key TypeScript Patterns Used

```typescript
// types/index.ts

// Re-export Prisma types with extensions
import type { Prisma } from "@prisma/client";

export type ProjectWithDetails = Prisma.ProjectGetPayload<{
  include: {
    owner: { select: { id: true; name: true; image: true } };
    tasks: { include: { assignee: true } };
    _count: { select: { tasks: true } };
  };
}>;

export type TaskWithAssignee = Prisma.TaskGetPayload<{
  include: { assignee: { select: { id: true; name: true; image: true } } };
}>;

// Pagination helper type
export type PaginatedResponse<T> = {
  data: T[];
  meta: { page: number; pageSize: number; total: number; totalPages: number };
};

// Component props pattern
export type WithClassName<T = {}> = T & { className?: string };
export type WithChildren<T = {}> = T & { children: React.ReactNode };
```

---

### Scripts & Setup Commands

```bash
# Initialize project
pnpm create next-app@latest taskflow --typescript --tailwind --eslint --app --src-dir=false

# Install dependencies
pnpm add @prisma/client @auth/prisma-adapter next-auth@beta
pnpm add @tanstack/react-query @tanstack/react-query-devtools
pnpm add zustand immer
pnpm add react-hook-form @hookform/resolvers zod
pnpm add @dnd-kit/core @dnd-kit/sortable @dnd-kit/utilities
pnpm add sonner use-debounce clsx tailwind-merge
pnpm add @uploadthing/react uploadthing
pnpm add resend @react-email/components
pnpm add @trigger.dev/sdk

pnpm add -D prisma vitest @vitejs/plugin-react @playwright/test
pnpm add -D @testing-library/react @testing-library/user-event

# shadcn/ui
pnpm dlx shadcn@latest init
pnpm dlx shadcn@latest add button input label card badge avatar

# Prisma
pnpm prisma init
pnpm prisma migrate dev --name init
pnpm prisma generate
pnpm prisma studio
```

---

## Quick Reference Cheatsheet

| Concept | Code Pattern |
|---|---|
| Server Component | `async function Page()` (default) |
| Client Component | `"use client"` at top |
| Server Action | `"use server"` + async function |
| Route params | `params: Promise<{ id: string }>` |
| Search params | `searchParams: Promise<{ q?: string }>` |
| Static data | `cache: "force-cache"` |
| Dynamic data | `cache: "no-store"` or `noStore()` |
| ISR | `next: { revalidate: 3600 }` |
| Tag revalidation | `next: { tags: ["key"] }` |
| Dedup DB calls | `import { cache } from "react"` |
| Metadata | `export const metadata: Metadata` |
| Dynamic metadata | `export async function generateMetadata()` |
| Static paths | `export async function generateStaticParams()` |
| Not found | `import { notFound } from "next/navigation"` |
| Redirect | `import { redirect } from "next/navigation"` |
| Optimistic UI | `useOptimistic()` |
| Form state | `useActionState(action, initialState)` |
| Transitions | `useTransition()` + `startTransition` |

---

*Built with ❤️ using Next.js 15, TypeScript 5, React 19 — March 2026*
