# Sum of First N Numbers

## Problem Statement

Given an integer **N**, return the sum of the first N natural numbers using recursion.

## Examples

### Example 1

```text
Input: N = 4
Output: 10
```

**Explanation:**

The first four natural numbers are:

```text
1, 2, 3, 4
```

Therefore:

```text
1 + 2 + 3 + 4 = 10
```

### Example 2

```text
Input: N = 2
Output: 3
```

**Explanation:**

```text
1 + 2 = 3
```

## Approach

Use recursion to break the problem into smaller sums.

For any positive N:

```text
sum(N) = N + sum(N - 1)
```

The base case is:

```cpp
if (N == 0) {
    return 0;
}
```

When N reaches 0, there are no more natural numbers to add.

## C++ Solution

```cpp
class Solution {
public:
    int NnumbersSum(int N) {

        if (N == 0) {
            return 0;
        }

        int sum = N;
        sum += NnumbersSum(N - 1);

        return sum;
    }
};
```

## Code Explanation

### 1. Base Case

```cpp
if (N == 0) {
    return 0;
}
```

When `N` becomes 0, recursion stops and returns 0.

### 2. Store the Current Number

```cpp
int sum = N;
```

The current value of `N` is the first part of the sum.

### 3. Recursive Call

```cpp
sum += NnumbersSum(N - 1);
```

This adds the sum of all numbers from `1` to `N - 1`.

### 4. Return the Result

```cpp
return sum;
```

The calculated sum is returned to the previous recursive call.

## Recursion Walkthrough

For `N = 5`:

```text
NnumbersSum(5)
= 5 + NnumbersSum(4)
= 5 + 4 + NnumbersSum(3)
= 5 + 4 + 3 + NnumbersSum(2)
= 5 + 4 + 3 + 2 + NnumbersSum(1)
= 5 + 4 + 3 + 2 + 1 + NnumbersSum(0)
```

At `N = 0`:

```text
NnumbersSum(0) = 0
```

Now the values return upward:

```text
NnumbersSum(1) = 1
NnumbersSum(2) = 2 + 1 = 3
NnumbersSum(3) = 3 + 3 = 6
NnumbersSum(4) = 4 + 6 = 10
NnumbersSum(5) = 5 + 10 = 15
```

Therefore:

```text
Output = 15
```

## Simplified Version

The same logic can be written more directly:

```cpp
class Solution {
public:
    int NnumbersSum(int N) {

        if (N == 0) {
            return 0;
        }

        return N + NnumbersSum(N - 1);
    }
};
```

## Complexity

- **Time:** `O(N)` — one recursive call for each value from N down to 0.
- **Space:** `O(N)` — recursive calls use the call stack.

## Key Recursion Pattern

```text
Base case
   ↓
Solve a smaller problem
   ↓
Add current value
   ↓
Return result
```

For this problem:

```text
sum(N) = N + sum(N - 1)
```
