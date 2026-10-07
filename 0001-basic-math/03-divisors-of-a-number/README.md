# Divisors of a Number

## Problem Statement

You are given an integer `n`. Find **all divisors** of `n` and return them in **sorted order**.

A divisor is a number that divides another number completely without leaving a remainder.

## Examples

### Example 1

```text
Input: n = 6
Output: [1, 2, 3, 6]
```

**Explanation:** The divisors of `6` are `1, 2, 3, 6`.

### Example 2

```text
Input: n = 8
Output: [1, 2, 4, 8]
```

**Explanation:** The divisors of `8` are `1, 2, 4, 8`.

### Example 3

```text
Input: n = 7
Output: [1, 7]
```

**Explanation:** `7` is a prime number, so its only divisors are `1` and `7`.

## Approach

The simple approach is to check every number from `1` to `n`.

For each `i`, check whether:

```cpp
n % i == 0
```

If the remainder is `0`, then `i` is a divisor of `n`, so add it to the answer vector.

Because we check the numbers from `1` to `n` in increasing order, the divisors are automatically returned in sorted order.

## C++ Solution

```cpp
class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> divisors;

        for (int i = 1; i < n + 1; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
            }
        }

        return divisors;
    }
};
```

## Code Explanation

### 1. Create the result vector

```cpp
vector<int> divisors;
```

This stores all the divisors we find.

### 2. Check every number

```cpp
for (int i = 1; i < n + 1; i++)
```

We check every number from `1` through `n`.

### 3. Check divisibility

```cpp
if (n % i == 0)
```

`%` gives the remainder.

If the remainder is `0`, `i` divides `n` completely, so `i` is a divisor.

### 4. Add the divisor

```cpp
divisors.push_back(i);
```

Add the divisor to the vector.

### 5. Return the answer

```cpp
return divisors;
```

Since we checked numbers in increasing order, the result is already sorted.

## Example Walkthrough

For `n = 6`:

```text
1 → 6 % 1 = 0 → divisor
2 → 6 % 2 = 0 → divisor
3 → 6 % 3 = 0 → divisor
4 → 6 % 4 ≠ 0
5 → 6 % 5 ≠ 0
6 → 6 % 6 = 0 → divisor
```

Result:

```text
[1, 2, 3, 6]
```

## Complexity

- **Time:** `O(n)` — we check every number from `1` to `n`.
- **Space:** `O(k)` — where `k` is the number of divisors stored in the result.

## Optimization Note

A faster approach can check only up to `sqrt(n)` and add divisor pairs. However, the solution above is simple, correct, and naturally produces the divisors in sorted order.
