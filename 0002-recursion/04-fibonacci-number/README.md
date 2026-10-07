# 509. Fibonacci Number

**LeetCode:** https://leetcode.com/problems/fibonacci-number/

## Problem

The Fibonacci numbers form the sequence:

```text
0, 1, 1, 2, 3, 5, 8, 13, ...
```

The Fibonacci number is defined as:

```text
F(0) = 0
F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1
```

Given `n`, return `F(n)`.

## Approach

This solution uses recursion.

There are two base cases:

- If `n == 0`, return `0`.
- If `n == 1`, return `1`.

For every other value, use:

```text
F(n) = F(n - 1) + F(n - 2)
```

## C++ Solution

```cpp
class Solution {
public:
    int fib(int n) {

        // Base case: F(0) = 0
        if (n == 0) {
            return 0;
        }

        // Base case: F(1) = 1
        if (n == 1) {
            return 1;
        }

        // Recursive case:
        // F(n) = F(n-1) + F(n-2)
        return fib(n - 1) + fib(n - 2);
    }
};
```

## Example

For `n = 5`:

```text
fib(5)
= fib(4) + fib(3)
= 3 + 2
= 5
```

Therefore:

```text
Output: 5
```

## Recursion Tree

For `fib(5)`:

```text
                 fib(5)
                /      \
           fib(4)      fib(3)
           /   \       /   \
       fib(3) fib(2) fib(2) fib(1)
          ...
```

The recursive calls continue until they reach the base cases `fib(0)` and `fib(1)`.

## Complexity

- **Time:** `O(2^n)` approximately, because many Fibonacci values are calculated repeatedly.
- **Space:** `O(n)` due to the maximum recursion depth.

## Key Learning

This problem demonstrates how a mathematical recurrence can be directly translated into recursive code:

```text
Mathematical formula
       ↓
F(n) = F(n-1) + F(n-2)
       ↓
Recursive function
       ↓
return fib(n-1) + fib(n-2)
```

## LeetCode

Problem **509. Fibonacci Number** — Easy.
