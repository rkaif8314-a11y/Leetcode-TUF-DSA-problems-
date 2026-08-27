# Check for Prime Number

## Problem Statement

You are given an integer `n`. Check whether the number is **prime** or not.

Return `true` if `n` is a prime number; otherwise, return `false`.

A **prime number** is a number that has no divisors except **1** and **itself**.

## Examples

### Example 1

```text
Input: n = 5
Output: true
```

**Explanation:** The only divisors of 5 are 1 and 5, so 5 is prime.

### Example 2

```text
Input: n = 8
Output: false
```

**Explanation:** 8 is divisible by 2, so it has a divisor other than 1 and itself. Therefore, 8 is not prime.

## Approach

First, handle numbers less than 2 because they are not prime.

Then check every number from `2` to `n - 1`.

For each number `i`, check:

```cpp
n % i == 0
```

If the remainder is `0`, then `i` divides `n` completely, so `n` is not prime and we return `false`.

If no divisor is found, return `true`.

## C++ Solution

```cpp
class Solution {
public:
    bool isPrime(int n) {

        if (n < 2) {
            return false;
        }

        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
};
```

## Code Explanation

### 1. Handle numbers less than 2

```cpp
if (n < 2) {
    return false;
}
```

Numbers such as `0` and `1` are not prime.

### 2. Check possible divisors

```cpp
for (int i = 2; i < n; i++)
```

Start from `2` because every number is divisible by `1`, and 1 does not help us determine whether the number is prime.

We check up to `n - 1` because a prime number has no divisor between `2` and `n - 1`.

### 3. Check divisibility

```cpp
if (n % i == 0)
```

The modulo operator gives the remainder.

If the remainder is `0`, then `i` is a divisor of `n`.

Therefore, the number is not prime:

```cpp
return false;
```

### 4. Return true

```cpp
return true;
```

If the loop finishes without finding any divisor, the number is prime.

## Example Walkthrough

For `n = 7`:

```text
7 % 2 != 0
7 % 3 != 0
7 % 4 != 0
7 % 5 != 0
7 % 6 != 0
```

No divisor was found, so:

```text
Output: true
```

For `n = 8`:

```text
8 % 2 == 0
```

A divisor was found, so:

```text
Output: false
```

## Complexity

- **Time:** `O(n)` in the worst case.
- **Space:** `O(1)`.

## Optimization Note

This solution is correct, but it can be optimized to check only up to `sqrt(n)`, giving approximately `O(sqrt(n))` time.

For learning the basic prime-checking logic, checking from `2` to `n - 1` is straightforward.
