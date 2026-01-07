# 📘 Complete Java DSA Interview Notes - Enhanced Edition

---

## 📑 Table of Contents
1. [Java Collections Framework - Deep Dive](#1-java-collections-framework)
2. [String & Character Manipulation](#2-string--character-manipulation)
3. [Essential Java Syntax](#3-essential-java-syntax)
4. [Interview-Ready Templates](#4-interview-ready-templates)
5. [Advanced Patterns & Techniques](#5-advanced-patterns--techniques)
6. [Common Java Gotchas](#6-common-java-gotchas)
7. [FAANG Problem → Template Mapping](#7-faang-problem--template-mapping)
8. [Interview Explanation Scripts](#8-interview-explanation-scripts)

---

## 1. Java Collections Framework - Deep Dive

### 1.1 List Interface

#### ArrayList

**Internal Structure:** Dynamic array (contiguous memory)

**When to Use:**
* Frequent random access (get/set operations)
* Append-heavy workloads
* Cache-friendly iteration (better CPU cache utilization)
* When you know approximate size beforehand

**Time Complexity:**
| Operation | Time | Notes |
|-----------|------|-------|
| `get(i)` | O(1) | Direct array access |
| `add(e)` | O(1) amortized | O(n) when resizing |
| `add(i, e)` | O(n) | Shifts elements right |
| `remove(i)` | O(n) | Shifts elements left |
| `contains(e)` | O(n) | Linear scan |
| `indexOf(e)` | O(n) | Linear scan |

**Common Methods & Examples:**

```java
// Initialization
List<Integer> list = new ArrayList<>();
List<Integer> listWithCapacity = new ArrayList<>(100); // Avoid resizing
List<Integer> listFromArray = new ArrayList<>(Arrays.asList(1, 2, 3));

// Adding elements
list.add(10);              // Append at end
list.add(20);
list.add(1, 15);          // Insert at index 1
list.addAll(Arrays.asList(30, 40)); // Add multiple

// Accessing elements
int val = list.get(0);    // Get element at index
list.set(0, 99);          // Update element

// Removing elements
list.remove(1);           // Remove by index (returns element)
list.remove(Integer.valueOf(15)); // Remove by value (returns boolean)
list.clear();             // Remove all

// Searching & checking
boolean exists = list.contains(15);
int index = list.indexOf(20);      // First occurrence (-1 if not found)
int lastIdx = list.lastIndexOf(20); // Last occurrence

// Size & emptiness
int size = list.size();
boolean empty = list.isEmpty();

// Conversion
Integer[] arr = list.toArray(new Integer[0]);
```

**Interview Notes:**
* ✅ Resizing happens at ~1.5x capacity (implementation-dependent)
* ✅ Use `ensureCapacity()` if you know final size
* ❌ Avoid frequent middle insertions (use LinkedList instead)
* ✅ Prefer ArrayList for 99% of use cases

**Real Interview Example - LC 238 (Product Except Self):**
```java
List<Integer> result = new ArrayList<>(nums.length); // Pre-size
```

---

#### LinkedList

**Internal Structure:** Doubly linked list (nodes with prev/next pointers)

**When to Use:**
* Frequent insertions/deletions at beginning/end
* Queue / Deque behavior
* When you don't need random access

**Time Complexity:**
| Operation | Time | Notes |
|-----------|------|-------|
| `addFirst()` / `removeFirst()` | O(1) | Direct pointer manipulation |
| `addLast()` / `removeLast()` | O(1) | Direct pointer manipulation |
| `get(i)` | O(n) | Must traverse list |
| `add(i, e)` | O(n) | Must find position first |

**Methods:**

```java
LinkedList<Integer> ll = new LinkedList<>();

// Add operations
ll.add(10);              // Add at end
ll.addFirst(5);          // Add at beginning
ll.addLast(20);          // Add at end (same as add)

// Remove operations
ll.removeFirst();        // Remove and return first
ll.removeLast();         // Remove and return last
ll.remove(1);            // Remove by index

// Peek operations (don't remove)
ll.getFirst();           // Get first
ll.getLast();            // Get last
ll.peek();               // Same as getFirst (returns null if empty)
ll.peekFirst();
ll.peekLast();

// Poll operations (remove and return, null if empty)
ll.poll();               // Remove first
ll.pollFirst();
ll.pollLast();
```

**Interview Warning:**
❌ **NEVER** say "LinkedList is faster than ArrayList"
✅ Say "LinkedList is faster for **insertions/deletions at ends**"

**When NOT to use LinkedList:**
* Random access needed
* Memory is a concern (extra pointer overhead)
* Most interview problems (ArrayList is usually better)

---

### 1.2 Set Interface

#### HashSet

**Internal Structure:** HashMap (keys only, values are dummy)

**When to Use:**
* Need unique elements
* Fast lookup/insertion/deletion
* Order doesn't matter

**Time Complexity:** O(1) average for add/contains/remove

```java
Set<Integer> set = new HashSet<>();

// Add elements
set.add(1);
set.add(2);
set.add(1);              // Duplicate - ignored
boolean added = set.add(3); // Returns true if added

// Check existence
boolean exists = set.contains(1);

// Remove
set.remove(2);

// Size
int size = set.size();

// Iteration
for (int num : set) {
    // Order is NOT guaranteed
}

// Conversion
List<Integer> list = new ArrayList<>(set);
```

**Interview Use Cases:**
* Detect duplicates: `if (set.contains(num)) return true;`
* Count unique elements: `return set.size();`
* Fast lookup in O(1)

**Real Interview Example - LC 217 (Contains Duplicate):**
```java
Set<Integer> seen = new HashSet<>();
for (int num : nums) {
    if (!seen.add(num)) return true; // add() returns false if duplicate
}
```

---

#### LinkedHashSet

**Maintains insertion order** using doubly-linked list

**When to Use:**
* Need unique elements + predictable iteration order
* Slightly slower than HashSet

```java
Set<Integer> set = new LinkedHashSet<>();
set.add(3);
set.add(1);
set.add(2);
// Iteration order: 3, 1, 2
```

---

#### TreeSet

**Internal Structure:** Red-Black Tree (self-balancing BST)

**When to Use:**
* Need sorted order
* Range queries (floor, ceiling, subSet)
* Natural ordering or custom comparator

**Time Complexity:** O(log n) for add/contains/remove

```java
TreeSet<Integer> ts = new TreeSet<>();
ts.add(10);
ts.add(5);
ts.add(20);

// Ordered operations
ts.first();              // 5 (minimum)
ts.last();               // 20 (maximum)
ts.higher(10);           // 20 (next element > 10)
ts.lower(10);            // 5 (prev element < 10)
ts.ceiling(7);           // 10 (>= 7)
ts.floor(7);             // 5 (<= 7)

// Range operations
ts.subSet(5, 15);        // Elements from 5 (inclusive) to 15 (exclusive)
ts.headSet(10);          // Elements < 10
ts.tailSet(10);          // Elements >= 10

// Remove operations
ts.pollFirst();          // Remove and return first
ts.pollLast();           // Remove and return last

// Custom comparator
TreeSet<Integer> desc = new TreeSet<>((a, b) -> b - a); // Descending
```

**Interview Use Cases:**
* Finding floor/ceiling values
* Maintaining sorted stream of data
* Range queries

**Real Interview Example - LC 220 (Contains Duplicate III):**
```java
TreeSet<Long> set = new TreeSet<>();
Long floor = set.floor((long) nums[i]);
Long ceil = set.ceiling((long) nums[i]);
```

---

### 1.3 Map Interface

#### HashMap

**Internal Structure:** 
* Array of buckets (default size 16)
* Each bucket: LinkedList (Java 7) or Red-Black Tree (Java 8+ after threshold)
* Load factor: 0.75 (resizes when 75% full)

**When to Use:**
* Key-value mapping
* Fast lookup by key
* Frequency counting
* Index mapping

**Time Complexity:** O(1) average, O(n) worst case

```java
Map<Integer, String> map = new HashMap<>();

// Put operations
map.put(1, "A");
map.put(2, "B");
String prev = map.put(1, "X");   // Returns previous value "A"

// Get operations
String val = map.get(1);         // Returns "X"
String def = map.getOrDefault(99, "default"); // "default"

// Check existence
boolean hasKey = map.containsKey(1);
boolean hasVal = map.containsValue("X");

// Remove
String removed = map.remove(1);   // Returns removed value

// Size
int size = map.size();

// Iteration - 3 ways
// 1. Entry set (most efficient)
for (Map.Entry<Integer, String> entry : map.entrySet()) {
    int key = entry.getKey();
    String value = entry.getValue();
}

// 2. Key set
for (int key : map.keySet()) {
    String value = map.get(key);
}

// 3. Values only
for (String value : map.values()) {
    // No access to keys
}

// putIfAbsent (Java 8+)
map.putIfAbsent(3, "C");         // Only puts if key doesn't exist

// compute methods (Java 8+)
map.compute(1, (k, v) -> v == null ? "new" : v + "X");
map.computeIfAbsent(4, k -> "D");
map.computeIfPresent(1, (k, v) -> v + "!");

// merge (Java 8+)
map.merge(1, "suffix", (oldVal, newVal) -> oldVal + newVal);
```

**Interview Patterns:**

**1. Frequency Counter:**
```java
Map<Character, Integer> freq = new HashMap<>();
for (char c : s.toCharArray()) {
    freq.put(c, freq.getOrDefault(c, 0) + 1);
}
```

**2. Two Sum Pattern:**
```java
Map<Integer, Integer> map = new HashMap<>(); // value -> index
for (int i = 0; i < nums.length; i++) {
    int complement = target - nums[i];
    if (map.containsKey(complement)) {
        return new int[]{map.get(complement), i};
    }
    map.put(nums[i], i);
}
```

**3. Anagram Grouping:**
```java
Map<String, List<String>> groups = new HashMap<>();
for (String word : words) {
    char[] chars = word.toCharArray();
    Arrays.sort(chars);
    String key = new String(chars);
    groups.computeIfAbsent(key, k -> new ArrayList<>()).add(word);
}
```

**Interview Notes:**
* ✅ Java 8+: Buckets convert to Red-Black Tree when size > 8
* ✅ Use `getOrDefault()` to avoid null checks
* ✅ Use `computeIfAbsent()` for nested structures
* ❌ HashMap doesn't maintain order

---

#### LinkedHashMap

**Maintains insertion order** using doubly-linked list

**When to Use:**
* Need predictable iteration order
* LRU Cache implementation

```java
Map<Integer, Integer> map = new LinkedHashMap<>();
map.put(3, 30);
map.put(1, 10);
map.put(2, 20);
// Iteration order: 3->1->2

// LRU Cache constructor
LinkedHashMap<Integer, Integer> lruCache = new LinkedHashMap<>(16, 0.75f, true) {
    protected boolean removeEldestEntry(Map.Entry eldest) {
        return size() > capacity;
    }
};
```

**Real Interview Example - LC 146 (LRU Cache):**
Can be implemented using LinkedHashMap with access-order

---

#### TreeMap

**Internal Structure:** Red-Black Tree (sorted by keys)

**When to Use:**
* Need sorted keys
* Range queries on keys
* Floor/ceiling operations

**Time Complexity:** O(log n)

```java
TreeMap<Integer, String> tm = new TreeMap<>();
tm.put(2, "B");
tm.put(1, "A");
tm.put(3, "C");

// Key operations
tm.firstKey();           // 1 (minimum key)
tm.lastKey();            // 3 (maximum key)
tm.higherKey(1);         // 2 (next key > 1)
tm.lowerKey(3);          // 2 (prev key < 3)
tm.ceilingKey(2);        // 2 (>= 2)
tm.floorKey(2);          // 2 (<= 2)

// Entry operations
Map.Entry<Integer, String> first = tm.firstEntry();
Map.Entry<Integer, String> last = tm.lastEntry();

// Range operations
tm.subMap(1, 3);         // Keys from 1 (inclusive) to 3 (exclusive)
tm.headMap(2);           // Keys < 2
tm.tailMap(2);           // Keys >= 2

// Poll operations
tm.pollFirstEntry();     // Remove and return first entry
tm.pollLastEntry();      // Remove and return last entry

// Custom comparator (descending)
TreeMap<Integer, String> desc = new TreeMap<>((a, b) -> b - a);
```

**Real Interview Example - LC 729 (My Calendar I):**
```java
TreeMap<Integer, Integer> calendar = new TreeMap<>();
Integer prev = calendar.floorKey(start);
Integer next = calendar.ceilingKey(start);
```

---

### 1.4 Queue / Deque

#### ArrayDeque (PREFERRED for Stack & Queue)

**Why ArrayDeque > Stack:**
* ✅ Faster (no synchronization overhead)
* ✅ Resizable
* ✅ Null elements not allowed (catches bugs)
* ✅ Modern and recommended by Java docs

```java
Deque<Integer> dq = new ArrayDeque<>();

// Queue operations (FIFO)
dq.offer(1);             // Add at end (returns false if fails)
dq.offerLast(2);         // Same as offer
int first = dq.poll();   // Remove from front (returns null if empty)
int peek = dq.peek();    // View front without removing

// Stack operations (LIFO)
dq.push(1);              // Add at front
dq.offerFirst(0);        // Same as push
int top = dq.pop();      // Remove from front
int peekTop = dq.peek(); // View front

// Deque operations (both ends)
dq.offerFirst(0);        // Add at front
dq.offerLast(2);         // Add at end
dq.pollFirst();          // Remove from front
dq.pollLast();           // Remove from end
dq.peekFirst();          // View front
dq.peekLast();           // View end

// Size operations
int size = dq.size();
boolean empty = dq.isEmpty();
```

**Interview Usage:**

**1. Stack Implementation:**
```java
Deque<Integer> stack = new ArrayDeque<>();
stack.push(1);
stack.push(2);
int top = stack.pop(); // 2
```

**2. Queue Implementation:**
```java
Deque<Integer> queue = new ArrayDeque<>();
queue.offer(1);
queue.offer(2);
int first = queue.poll(); // 1
```

**3. Monotonic Stack:**
```java
Deque<Integer> stack = new ArrayDeque<>();
for (int i = 0; i < n; i++) {
    while (!stack.isEmpty() && nums[stack.peek()] < nums[i]) {
        stack.pop();
    }
    stack.push(i);
}
```

**Real Interview Example - LC 239 (Sliding Window Maximum):**
```java
Deque<Integer> dq = new ArrayDeque<>(); // Store indices
```

---

#### PriorityQueue (Heap)

**Internal Structure:** Binary heap (array-based)

**Default:** Min-heap (smallest element at top)

**When to Use:**
* Top K problems
* Kth largest/smallest
* Merge K sorted arrays
* Median finding

**Time Complexity:**
* `offer()`: O(log n)
* `poll()`: O(log n)
* `peek()`: O(1)

```java
// Min-heap (default)
PriorityQueue<Integer> minHeap = new PriorityQueue<>();

// Max-heap (custom comparator)
PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
// OR
PriorityQueue<Integer> maxHeap2 = new PriorityQueue<>(Collections.reverseOrder());

// Basic operations
minHeap.offer(3);
minHeap.offer(1);
minHeap.offer(2);
int min = minHeap.peek();    // 1 (doesn't remove)
int removed = minHeap.poll(); // 1 (removes and returns)

// Size
int size = minHeap.size();
boolean empty = minHeap.isEmpty();

// Custom objects
class Task {
    int priority;
    String name;
}
PriorityQueue<Task> pq = new PriorityQueue<>((a, b) -> a.priority - b.priority);
```

**Interview Patterns:**

**1. Top K Elements:**
```java
PriorityQueue<Integer> minHeap = new PriorityQueue<>();
for (int num : nums) {
    minHeap.offer(num);
    if (minHeap.size() > k) {
        minHeap.poll(); // Remove smallest
    }
}
// minHeap contains top K largest elements
```

**2. K Closest Points:**
```java
PriorityQueue<int[]> maxHeap = new PriorityQueue<>(
    (a, b) -> (b[0]*b[0] + b[1]*b[1]) - (a[0]*a[0] + a[1]*a[1])
);
```

**3. Median Finder (Two Heaps):**
```java
PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a); // Left half
PriorityQueue<Integer> minHeap = new PriorityQueue<>(); // Right half
```

**Common Mistakes:**
* ❌ Trying to remove arbitrary element (O(n))
* ❌ Assuming sorted order on iteration
* ✅ PriorityQueue is NOT thread-safe
* ✅ No random access

---

## 2. String & Character Manipulation

### 2.1 String Class (Immutable)

```java
String s = "hello";

// Length & access
int len = s.length();
char c = s.charAt(0);

// Substring
String sub = s.substring(1, 4);  // "ell" (start inclusive, end exclusive)
String suffix = s.substring(2);   // "llo"

// Search
int idx = s.indexOf('l');         // 2 (first occurrence)
int lastIdx = s.lastIndexOf('l'); // 3 (last occurrence)
boolean contains = s.contains("ll"); // true
boolean starts = s.startsWith("he"); // true
boolean ends = s.endsWith("lo");     // true

// Comparison
boolean eq = s.equals("hello");      // true
boolean eqIgnore = s.equalsIgnoreCase("HELLO"); // true
int cmp = s.compareTo("world");      // Lexicographic comparison

// Modification (returns new string)
String upper = s.toUpperCase();      // "HELLO"
String lower = s.toLowerCase();      // "hello"
String trimmed = "  hi  ".trim();    // "hi"
String replaced = s.replace('l', 'x'); // "hexxo"
String[] parts = "a,b,c".split(","); // ["a", "b", "c"]

// Conversion
char[] chars = s.toCharArray();
String from = String.valueOf(123);   // "123"
String from2 = String.valueOf(chars);
```

**Interview Warning:**
❌ String concatenation in loop creates new objects each time
```java
// BAD - O(n²)
String result = "";
for (int i = 0; i < n; i++) {
    result += i; // Creates new string object each time
}

// GOOD - O(n)
StringBuilder sb = new StringBuilder();
for (int i = 0; i < n; i++) {
    sb.append(i);
}
String result = sb.toString();
```

---

### 2.2 StringBuilder (Mutable)

**When to Use:**
* Building strings in loops
* Many concatenations
* String manipulation

```java
StringBuilder sb = new StringBuilder();

// Append
sb.append("Hello");
sb.append(' ');
sb.append(123);
sb.append(true);

// Insert
sb.insert(0, "Start: ");  // Insert at position

// Delete
sb.delete(0, 7);          // Delete from index 0 to 6
sb.deleteCharAt(0);       // Delete single character

// Replace
sb.replace(0, 5, "Hi");   // Replace substring

// Reverse
sb.reverse();

// Convert to String
String result = sb.toString();

// Other operations
int len = sb.length();
char c = sb.charAt(0);
sb.setCharAt(0, 'X');
```

**Real Interview Example - LC 151 (Reverse Words):**
```java
StringBuilder sb = new StringBuilder();
for (String word : words) {
    sb.append(word).append(" ");
}
```

---

### 2.3 Character Class

```java
char c = 'a';

// Type checking
boolean isLetter = Character.isLetter(c);
boolean isDigit = Character.isDigit(c);
boolean isLetterOrDigit = Character.isLetterOrDigit(c);
boolean isLowerCase = Character.isLowerCase(c);
boolean isUpperCase = Character.isUpperCase(c);
boolean isWhitespace = Character.isWhitespace(c);

// Conversion
char upper = Character.toLowerCase(c);
char lower = Character.toUpperCase(c);
int digit = Character.getNumericValue('5'); // 5
int digit2 = c - '0'; // For digits only

// Comparison
int cmp = Character.compare('a', 'b'); // -1
```

**Interview Tricks:**

**1. Check Alphanumeric:**
```java
boolean isValid = Character.isLetterOrDigit(c);
```

**2. Case-insensitive comparison:**
```java
if (Character.toLowerCase(c1) == Character.toLowerCase(c2)) { ... }
```

**3. Convert digit char to int:**
```java
int num = c - '0'; // Fast way
int num2 = Character.getNumericValue(c); // Handles more cases
```

---

## 3. Essential Java Syntax for Interviews

### 3.1 Array Operations

```java
// Declaration & initialization
int[] arr = new int[5];
int[] arr2 = {1, 2, 3, 4, 5};
int[] arr3 = new int[]{1, 2, 3};

// 2D arrays
int[][] grid = new int[m][n];
int[][] grid2 = {{1, 2}, {3, 4}};

// Array length
int len = arr.length;
int rows = grid.length;
int cols = grid[0].length;

// Fill array
Arrays.fill(arr, -1);
Arrays.fill(arr, 1, 4, 99); // Fill from index 1 to 3

// Copy array
int[] copy = Arrays.copyOf(arr, arr.length);
int[] subCopy = Arrays.copyOfRange(arr, 1, 4); // Copy from index 1 to 3

// Sort
Arrays.sort(arr);
Arrays.sort(arr, 0, 3); // Sort subarray

// Binary search (array must be sorted)
int idx = Arrays.binarySearch(arr, target);

// Convert to string
String str = Arrays.toString(arr);
String str2D = Arrays.deepToString(grid);

// Compare
boolean eq = Arrays.equals(arr1, arr2);
boolean eq2D = Arrays.deepEquals(grid1, grid2);
```

---

### 3.2 Lambda Expressions & Sorting

**Basic Lambda:**
```java
// Ascending
Arrays.sort(arr, (a, b) -> a - b);
Collections.sort(list, (a, b) -> a - b);

// Descending
Arrays.sort(arr, (a, b) -> b - a);
Collections.sort(list, (a, b) -> b - a);
// OR
Collections.sort(list, Collections.reverseOrder());
```

**Sorting 2D Arrays:**
```java
int[][] intervals = {{1, 3}, {2, 6}, {8, 10}};

// Sort by first element
Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

// Sort by first, then second
Arrays.sort(intervals, (a, b) -> {
    if (a[0] != b[0]) return a[0] - b[0];
    return a[1] - b[1];
});
```

**Sorting Custom Objects:**
```java
class Point {
    int x, y;
}

// Sort by x, then y
Collections.sort(points, (p1, p2) -> {
    if (p1.x != p2.x) return p1.x - p2.x;
    return p1.y - p2.y;
});

// Using Comparator.comparing (Java 8+)
Collections.sort(points, Comparator.comparingInt(p -> p.x)
                                   .thenComparingInt(p -> p.y));
```

**Sorting Strings:**
```java
// By length
Collections.sort(words, (a, b) -> a.length() - b.length());

// By custom criteria
Collections.sort(words, (a, b) -> {
    if (a.length() != b.length()) return a.length() - b.length();
    return a.compareTo(b); // Lexicographic if same length
});
```

---

### 3.3 Math Operations

```java
// Basic math
int max = Math.max(a, b);
int min = Math.min(a, b);
int abs = Math.abs(a);

// Power & roots
double pow = Math.pow(2, 3);  // 8.0
double sqrt = Math.sqrt(16);  // 4.0

// Rounding
double ceil = Math.ceil(3.2);   // 4.0
double floor = Math.floor(3.8); // 3.0
long round = Math.round(3.5);   // 4

// Random
double rand = Math.random(); // [0.0, 1.0)
int randInt = (int)(Math.random() * 100); // [0, 99]
```

**Interview Tricks:**

**1. Integer division ceiling:**
```java
int ceil = (a + b - 1) / b; // Instead of Math.ceil((double)a / b)
```

**2. Check power of 2:**
```java
boolean isPower = (n & (n - 1)) == 0 && n > 0;
```

**3. Swap without temp:**
```java
a = a ^ b;
b = a ^ b;
a = a ^ b;
```

---

### 3.4 Type Conversion

```java
// String to number
int i = Integer.parseInt("123");
long l = Long.parseLong("123456789");
double d = Double.parseDouble("3.14");

// Number to String
String s1 = String.valueOf(123);
String s2 = Integer.toString(123);

// char to int
int num = c - '0'; // '5' -> 5
char ch = (char)('0' + num); // 5 -> '5'

// Array to List (IMPORTANT: Fixed size!)
List<Integer> list = Arrays.asList(1, 2, 3);
// list.add(4); // UnsupportedOperationException!

// Array to mutable List
List<Integer> list2 = new ArrayList<>(Arrays.asList(1, 2, 3));

// List to Array
Integer[] arr = list.toArray(new Integer[0]);
int[] primArr = list.stream().mapToInt(Integer::intValue).toArray();
```

---

## 4. Interview-Ready Templates

### 4.1 Binary Search Variations

**Standard Binary Search:**
```java
int binarySearch(int[] arr, int target) {
    int l = 0, r = arr.length - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2; // Avoid overflow
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1; // Not found
}
```

**Find First Occurrence:**
```java
int findFirst(int[] arr, int target) {
    int l = 0, r = arr.length - 1, result = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            result = mid;
            r = mid - 1; // Continue searching left
        } else if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return result;
}
```

**Find Last Occurrence:**
```java
int findLast(int[] arr, int target) {
    int l = 0, r = arr.length - 1, result = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            result = mid;
            l = mid + 1; // Continue searching right
        } else if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return result;
}
```

**Binary Search on Answer Space:**
```java
int binarySearchAnswer(int[] arr, int k) {
    int l = minPossible, r = maxPossible;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (canAchieve(arr, mid, k)) {
            r = mid; // Try smaller
        } else {
            l = mid + 1;
        }
    }
    return l;
}

boolean canAchieve(int[] arr, int mid, int k) {
    // Check if 'mid' is achievable
    return true; // Implementation specific
}
```

---

### 4.2 Sliding Window Patterns

**Fixed Size Window:**
```java
int fixedWindow(int[] arr, int k) {
    int sum = 0, maxSum = 0;
    // Build first window
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    maxSum = sum;
    
    // Slide window
    for (int i = k; i < arr.length; i++) {
        sum += arr[i] - arr[i - k]; // Add new, remove old
        maxSum = Math.max(maxSum, sum);
    }
    return maxSum;
}
```

**Variable Size Window (Longest):**
```java
int longestSubarray(String s) {
    int left = 0, maxLen = 0;
    Map<Character, Integer> freq = new HashMap<>();
    
    for (int right = 0; right < s.length(); right++) {
        char c = s.charAt(right);
        freq.put(c, freq.getOrDefault(c, 0) + 1);
        
        // Shrink window if invalid
        while (windowInvalid(freq)) {
            char lc = s.charAt(left);
            freq.put(lc, freq.get(lc) - 1);
            if (freq.get(lc) == 0) freq.remove(lc);
            left++;
        }
        
        maxLen = Math.max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

**Variable Size Window (Shortest):**
```java
int shortestSubarray(int[] arr, int target) {
    int left = 0, minLen = Integer.MAX_VALUE, sum = 0;
    
    for (int right = 0; right < arr.length; right++) {
        sum += arr[right];
        
        // Shrink while valid
        while (sum >= target) {
            minLen = Math.min(minLen, right - left + 1);
            sum -= arr[left++];
        }
    }
    
    return minLen == Integer.MAX_VALUE ? -1 : minLen;
}
```

---

### 4.3 Two Pointers Patterns

**Opposite Direction (Sorted Array):**
```java
int[] twoSum(int[] arr, int target) {
    int l = 0, r = arr.length - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == target) {
            return new int[]{l, r};
        } else if (sum < target) {
            l++;
        } else {
            r--;
        }
    }
    return new int[]{-1, -1};
}
```

**Same Direction (Fast & Slow):**
```java
int removeDuplicates(int[] arr) {
    if (arr.length == 0) return 0;
    
    int slow = 0;
    for (int fast = 1; fast < arr.length; fast++) {
        if (arr[fast] != arr[slow]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }
    return slow + 1;
}
```

**Palindrome Check:**
```java
boolean isPalindrome(String s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s.charAt(l) != s.charAt(r)) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
```

---

### 4.4 Graph Traversal Templates

**DFS - Recursive:**
```java
void dfs(int node, List<List<Integer>> graph, boolean[] visited) {
    visited[node] = true;
    
    for (int neighbor : graph.get(node)) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}
```

**DFS - Iterative (with Stack):**
```java
void dfsIterative(int start, List<List<Integer>> graph) {
    boolean[] visited = new boolean[graph.size()];
    Deque<Integer> stack = new ArrayDeque<>();
    
    stack.push(start);
    visited[start] = true;
    
    while (!stack.isEmpty()) {
        int node = stack.pop();
        
        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }
}
```

**BFS (Level Order):**
```java
void bfs(int start, List<List<Integer>> graph) {
    boolean[] visited = new boolean[graph.size()];
    Queue<Integer> queue = new LinkedList<>();
    
    queue.offer(start);
    visited[start] = true;
    
    while (!queue.isEmpty()) {
        int node = queue.poll();
        
        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.offer(neighbor);
            }
        }
    }
}
```

**Grid DFS (4-directional):**
```java
void dfsGrid(int r, int c, int[][] grid, boolean[][] visited) {
    int m = grid.length, n = grid[0].length;
    
    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c]) {
        return;
    }
    
    visited[r][c] = true;
    
    // 4 directions
    int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int[] dir : dirs) {
        dfsGrid(r + dir[0], c + dir[1], grid, visited);
    }
}
```

**Topological Sort (Kahn's Algorithm):**
```java
List<Integer> topologicalSort(int n, List<List<Integer>> graph) {
    int[] indegree = new int[n];
    
    // Calculate indegree
    for (List<Integer> neighbors : graph) {
        for (int nei : neighbors) {
            indegree[nei]++;
        }
    }
    
    // Start with nodes having indegree 0
    Queue<Integer> queue = new LinkedList<>();
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue.offer(i);
        }
    }
    
    List<Integer> result = new ArrayList<>();
    while (!queue.isEmpty()) {
        int node = queue.poll();
        result.add(node);
        
        for (int neighbor : graph.get(node)) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                queue.offer(neighbor);
            }
        }
    }
    
    // Check for cycle
    return result.size() == n ? result : new ArrayList<>();
}
```

---

### 4.5 Tree Traversal Templates

**Tree Node Definition:**
```java
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}
```

**DFS - Preorder (Root → Left → Right):**
```java
void preorder(TreeNode root, List<Integer> result) {
    if (root == null) return;
    result.add(root.val);
    preorder(root.left, result);
    preorder(root.right, result);
}
```

**DFS - Inorder (Left → Root → Right):**
```java
void inorder(TreeNode root, List<Integer> result) {
    if (root == null) return;
    inorder(root.left, result);
    result.add(root.val);
    inorder(root.right, result);
}
```

**DFS - Postorder (Left → Right → Root):**
```java
void postorder(TreeNode root, List<Integer> result) {
    if (root == null) return;
    postorder(root.left, result);
    postorder(root.right, result);
    result.add(root.val);
}
```

**BFS - Level Order:**
```java
List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> result = new ArrayList<>();
    if (root == null) return result;
    
    Queue<TreeNode> queue = new LinkedList<>();
    queue.offer(root);
    
    while (!queue.isEmpty()) {
        int levelSize = queue.size();
        List<Integer> level = new ArrayList<>();
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode node = queue.poll();
            level.add(node.val);
            
            if (node.left != null) queue.offer(node.left);
            if (node.right != null) queue.offer(node.right);
        }
        
        result.add(level);
    }
    
    return result;
}
```

**Height of Tree:**
```java
int height(TreeNode root) {
    if (root == null) return 0;
    int leftHeight = height(root.left);
    int rightHeight = height(root.right);
    return Math.max(leftHeight, rightHeight) + 1;
}
```

---

### 4.6 Backtracking Templates

**Subsets:**
```java
void backtrack(int[] nums, int start, List<Integer> current, List<List<Integer>> result) {
    result.add(new ArrayList<>(current));
    
    for (int i = start; i < nums.length; i++) {
        current.add(nums[i]);
        backtrack(nums, i + 1, current, result);
        current.remove(current.size() - 1);
    }
}
```

**Permutations:**
```java
void backtrack(int[] nums, List<Integer> current, boolean[] used, List<List<Integer>> result) {
    if (current.size() == nums.length) {
        result.add(new ArrayList<>(current));
        return;
    }
    
    for (int i = 0; i < nums.length; i++) {
        if (used[i]) continue;
        
        current.add(nums[i]);
        used[i] = true;
        backtrack(nums, current, used, result);
        used[i] = false;
        current.remove(current.size() - 1);
    }
}
```

**Combination Sum:**
```java
void backtrack(int[] nums, int target, int start, List<Integer> current, List<List<Integer>> result) {
    if (target == 0) {
        result.add(new ArrayList<>(current));
        return;
    }
    if (target < 0) return;
    
    for (int i = start; i < nums.length; i++) {
        current.add(nums[i]);
        backtrack(nums, target - nums[i], i, current, result); // i for reuse, i+1 for no reuse
        current.remove(current.size() - 1);
    }
}
```

---

## 5. Advanced Patterns & Techniques

### 5.1 Prefix Sum

**1D Prefix Sum:**
```java
int[] buildPrefix(int[] nums) {
    int n = nums.length;
    int[] prefix = new int[n + 1]; // Start with 0
    
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    return prefix;
}

// Range sum query [l, r]
int rangeSum(int[] prefix, int l, int r) {
    return prefix[r + 1] - prefix[l];
}
```

**2D Prefix Sum:**
```java
int[][] buildPrefix2D(int[][] matrix) {
    int m = matrix.length, n = matrix[0].length;
    int[][] prefix = new int[m + 1][n + 1];
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = matrix[i-1][j-1] 
                         + prefix[i-1][j] 
                         + prefix[i][j-1] 
                         - prefix[i-1][j-1];
        }
    }
    return prefix;
}

// Range sum query [(r1,c1), (r2,c2)]
int rangeSum2D(int[][] prefix, int r1, int c1, int r2, int c2) {
    return prefix[r2+1][c2+1] 
         - prefix[r1][c2+1] 
         - prefix[r2+1][c1] 
         + prefix[r1][c1];
}
```

---

### 5.2 Union Find (Disjoint Set Union)

```java
class UnionFind {
    int[] parent, rank;
    int components;
    
    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];
        components = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    public boolean union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;
        
        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        components--;
        return true;
    }
    
    public boolean connected(int x, int y) {
        return find(x) == find(y);
    }
    
    public int getComponents() {
        return components;
    }
}
```

---

### 5.3 Trie (Prefix Tree)

```java
class TrieNode {
    TrieNode[] children = new TrieNode[26];
    boolean isEnd = false;
}

class Trie {
    TrieNode root = new TrieNode();
    
    public void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new TrieNode();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }
    
    public boolean search(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) return false;
            node = node.children[idx];
        }
        return node.isEnd;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode node = root;
        for (char c : prefix.toCharArray()) {
            int idx = c - 'a';
            if (node.children[idx] == null) return false;
            node = node.children[idx];
        }
        return true;
    }
}
```

---

### 5.4 Monotonic Stack Patterns

**Next Greater Element:**
```java
int[] nextGreater(int[] nums) {
    int n = nums.length;
    int[] result = new int[n];
    Arrays.fill(result, -1);
    Deque<Integer> stack = new ArrayDeque<>();
    
    for (int i = 0; i < n; i++) {
        while (!stack.isEmpty() && nums[stack.peek()] < nums[i]) {
            result[stack.pop()] = nums[i];
        }
        stack.push(i);
    }
    
    return result;
}
```

**Next Smaller Element:**
```java
int[] nextSmaller(int[] nums) {
    int n = nums.length;
    int[] result = new int[n];
    Arrays.fill(result, -1);
    Deque<Integer> stack = new ArrayDeque<>();
    
    for (int i = 0; i < n; i++) {
        while (!stack.isEmpty() && nums[stack.peek()] > nums[i]) {
            result[stack.pop()] = nums[i];
        }
        stack.push(i);
    }
    
    return result;
}
```

---

## 6. Common Java Gotchas

### 6.1 == vs equals()

```java
// Primitives - use ==
int a = 5, b = 5;
System.out.println(a == b); // true

// Objects - use equals()
String s1 = new String("hello");
String s2 = new String("hello");
System.out.println(s1 == s2);       // false (different objects)
System.out.println(s1.equals(s2));  // true (same content)

// String literals (interned)
String s3 = "hello";
String s4 = "hello";
System.out.println(s3 == s4);       // true (same object from pool)
```

---

### 6.2 Integer Caching

```java
// Range: -128 to 127 are cached
Integer a = 100, b = 100;
System.out.println(a == b); // true (cached)

Integer x = 200, y = 200;
System.out.println(x == y); // false (not cached)
System.out.println(x.equals(y)); // true

// ALWAYS use equals() for Integer comparison
```

---

### 6.3 Array Initialization Pitfalls

```java
// Wrong - all rows point to same array!
int[][] wrong = new int[3][];
int[] row = new int[3];
for (int i = 0; i < 3; i++) {
    wrong[i] = row; // BAD!
}

// Correct
int[][] correct = new int[3][3];
// OR
int[][] correct2 = new int[3][];
for (int i = 0; i < 3; i++) {
    correct2[i] = new int[3];
}
```

---

### 6.4 Integer Overflow

```java
// Problem
int a = Integer.MAX_VALUE;
int b = a + 1; // Overflow! Becomes Integer.MIN_VALUE

// Solutions
// 1. Use long
long result = (long)a + 1;

// 2. Check before operation
if (a > Integer.MAX_VALUE - 1) {
    // Handle overflow
}

// 3. For mid calculation in binary search
int mid = l + (r - l) / 2; // Avoids overflow
// Instead of: int mid = (l + r) / 2;
```

---

### 6.5 Modulo Operations

```java
// Negative numbers
System.out.println(-5 % 3);  // -2 (not 1!)

// Fix for positive modulo
int mod = ((a % m) + m) % m;

// Large number modulo
int MOD = 1000000007;
long result = (a * b) % MOD;

// Power with modulo
long power(long base, long exp, long mod) {
    long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
```

---

## 7. FAANG Problem → Template Mapping

*(This section includes the complete mapping from your original document)*

### 🟦 SLIDING WINDOW
**Template:**
```java
int left = 0;
Map<Character, Integer> map = new HashMap<>();

for (int right = 0; right < s.length(); right++) {
    char c = s.charAt(right);
    map.put(c, map.getOrDefault(c, 0) + 1);
    
    while (windowInvalid()) {
        char lc = s.charAt(left++);
        map.put(lc, map.get(lc) - 1);
        if (map.get(lc) == 0) map.remove(lc);
    }
}
```

**FAANG Problems:**
| Problem | Company | LeetCode |
|---------|---------|----------|
| Longest Substring Without Repeating | Google, Meta | LC 3 |
| Minimum Window Substring | Google, Amazon | LC 76 |
| Longest Repeating Character Replacement | Meta | LC 424 |
| Permutation in String | Amazon | LC 567 |

---

### 🟦 TWO POINTERS
**Template:**
```java
int l = 0, r = nums.length - 1;
while (l < r) {
    if (condition) l++;
    else r--;
}
```

**FAANG Problems:**
- Container With Most Water (LC 11)
- 3Sum (LC 15)
- Trapping Rain Water (LC 42)
- Valid Palindrome (LC 125)

---

### 🟦 MONOTONIC STACK
**Template:**
```java
Deque<Integer> stack = new ArrayDeque<>();

for (int i = 0; i < n; i++) {
    while (!stack.isEmpty() && nums[stack.peek()] < nums[i]) {
        stack.pop();
    }
    stack.push(i);
}
```

**FAANG Problems:**
- Daily Temperatures (LC 739)
- Largest Rectangle in Histogram (LC 84)
- Trapping Rain Water (LC 42)
- Next Greater Element (LC 496)

---

### 🟦 BINARY SEARCH (Standard)
**Template:**
```java
int l = 0, r = n - 1;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) l = mid + 1;
    else r = mid - 1;
}
```

**FAANG Problems:**
- Binary Search (LC 704)
- Search in Rotated Sorted Array (LC 33)
- Find Minimum in Rotated Array (LC 153)

---

### 🟦 BINARY SEARCH ON ANSWER
**Template:**
```java
int l = min, r = max;
while (l < r) {
    int mid = l + (r - l) / 2;
    if (can(mid)) r = mid;
    else l = mid + 1;
}
```

**FAANG Problems:**
- Koko Eating Bananas (LC 875)
- Capacity To Ship Packages (LC 1011)
- Split Array Largest Sum (LC 410)

---

### 🟦 TREE DFS (Post-Order)
**Template:**
```java
int dfs(TreeNode root) {
    if (root == null) return 0;
    int left = dfs(root.left);
    int right = dfs(root.right);
    return Math.max(left, right) + 1;
}
```

**FAANG Problems:**
- Diameter of Binary Tree (LC 543)
- Binary Tree Maximum Path Sum (LC 124)
- Balanced Binary Tree (LC 110)

---

### 🟦 TREE BFS (Level Order)
**Template:**
```java
Queue<TreeNode> q = new LinkedList<>();
q.offer(root);

while (!q.isEmpty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
        TreeNode node = q.poll();
    }
}
```

**FAANG Problems:**
- Level Order Traversal (LC 102)
- Right Side View (LC 199)
- Minimum Depth (LC 111)

---

### 🟦 GRAPH DFS/BFS
**Template:**
```java
void dfs(int node) {
    visited[node] = true;
    for (int nei : graph.get(node)) {
        if (!visited[nei]) dfs(nei);
    }
}
```

**FAANG Problems:**
- Number of Islands (LC 200)
- Clone Graph (LC 133)
- Course Schedule (LC 207)
- Pacific Atlantic Water Flow (LC 417)

---

### 🟦 HEAP
**Template:**
```java
PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
```

**FAANG Problems:**
- Kth Largest Element (LC 215)
- Top K Frequent Elements (LC 347)
- Find Median from Data Stream (LC 295)

---

### 🟦 DYNAMIC PROGRAMMING (1D)
**Template:**
```java
dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i]);
```

**FAANG Problems:**
- House Robber (LC 198)
- Climbing Stairs (LC 70)
- Coin Change (LC 322)

---

## 8. Interview Explanation Scripts

### 🎤 Sliding Window
> "This problem asks for a longest/shortest subarray, so I'll use a sliding window. I expand the window using the right pointer, and once the constraint is violated, I shrink it from the left. Each element enters and exits the window once, so time complexity is O(n)."

### 🎤 HashMap Choice
> "I'm using HashMap here because I need constant-time lookup and insertion. TreeMap isn't required since ordering doesn't matter."

### 🎤 Binary Search on Answer
> "The array itself isn't sorted, but the answer space is monotonic. If a value is feasible, all larger values are also feasible, which allows binary search."

### 🎤 Tree DFS Logic
> "I'm using post-order traversal because the current node's result depends on its children. This allows me to compute the result bottom-up in a single pass."

### 🎤 Graph Traversal
> "This is a connected components problem. I'll run DFS/BFS from each unvisited node to mark the entire component."

### 🎤 Heap Justification
> "I only need the top K elements, so I maintain a heap of size K. This reduces time complexity from O(n log n) to O(n log k)."

### 🎤 DP Explanation
> "The key part is defining the DP state. Here dp[i] represents the optimal answer considering the first i elements. The recurrence follows naturally from the choice at index i."

### 🎤 Java-Specific Gotcha
> "I'm using .equals() instead of == because == compares references for objects in Java."

---

## 🏁 Final Interview Edge

**FAANG interviewers look for:**

| Skill | Impact | Why |
|-------|--------|-----|
| Pattern recognition | ⭐⭐⭐⭐⭐ | Shows experience |
| Explanation clarity | ⭐⭐⭐⭐ | Communication matters |
| Java correctness | ⭐⭐⭐⭐ | No silly mistakes |
| Perfect syntax | ⭐⭐⭐ | Efficiency matters |

---

## 📌 Quick Reference Checklist

**Before Every Interview:**
- [ ] Clarify constraints (array size, value range, sorted?)
- [ ] Ask about duplicates, negatives, empty input
- [ ] State your approach before coding
- [ ] Mention time & space complexity upfront
- [ ] Use meaningful variable names (even in interviews)
- [ ] Test with edge cases (empty, single element, duplicates)

**During Coding:**
- [ ] Think aloud constantly
- [ ] Explain trade-offs
- [ ] Handle null/empty cases first
- [ ] Use ArrayDeque (not Stack)
- [ ] Use equals() for objects (not ==)
- [ ] Avoid integer overflow in binary search

**Common Mistakes to Avoid:**
- ❌ Not handling edge cases
- ❌ Using == for Integer comparison
- ❌ Forgetting to remove from map when count = 0
- ❌ Off-by-one errors in loops
- ❌ Not checking null before operations
- ❌ Using Stack instead of ArrayDeque

---

## 🎯 Time Complexity Quick Reference

| Data Structure | Access | Search | Insert | Delete |
|----------------|--------|--------|--------|--------|
| Array | O(1) | O(n) | O(n) | O(n) |
| ArrayList | O(1) | O(n) | O(1)* | O(n) |
| LinkedList | O(n) | O(n) | O(1) | O(1) |
| HashSet | - | O(1) | O(1) | O(1) |
| TreeSet | - | O(log n) | O(log n) | O(log n) |
| HashMap | - | O(1) | O(1) | O(1) |
| TreeMap | - | O(log n) | O(log n) | O(log n) |
| PriorityQueue | O(1)† | O(n) | O(log n) | O(log n) |

\* Amortized  
† peek() only

---

**END OF NOTES**
