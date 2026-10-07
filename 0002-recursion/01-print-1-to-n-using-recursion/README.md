# Print 1 to N using Recursion

## Problem Statement

Given an integer `n`, print all numbers from **1 to n (inclusive)** using recursion.

### Requirements

- Do not use any loops such as `for`, `while`, or `do-while`.
- Print each number on a separate line.
- Numbers must be printed in increasing order from 1 to n.

## Example

### Input

```text
n = 5
```

### Output

```text
1
2
3
4
5
```

## Approach

Use recursion to reduce the problem from `n` to `n - 1`.

The base case is:

```cpp
if (n == 0) {
    return;
}
```

This stops the recursion when there are no numbers left to print.

The recursive call is made **before** printing:

```cpp
printNumbers(n - 1);
cout << n << endl;
```

This causes the function to reach `0` first and then print the numbers while the recursive calls return.

## C++ Solution

```cpp
class Solution {
public:
    void printNumbers(int n) {

        if (n == 0) {
            return;
        }

        printNumbers(n - 1);

        cout << n << endl;
    }
};
```

## How the Recursion Works

For `n = 5`:

```text
printNumbers(5)
    ↓
printNumbers(4)
    ↓
printNumbers(3)
    ↓
printNumbers(2)
    ↓
printNumbers(1)
    ↓
printNumbers(0)
```

At `n = 0`, the function returns.

Then the calls complete in reverse order:

```text
printNumbers(1) → print 1
printNumbers(2) → print 2
printNumbers(3) → print 3
printNumbers(4) → print 4
printNumbers(5) → print 5
```

Therefore the output is:

```text
1
2
3
4
5
```

## Key Concept

The position of the recursive call is important.

### Recursive call first

```cpp
printNumbers(n - 1);
cout << n << endl;
```

Output:

```text
1
2
3
4
5
```

### Print first

```cpp
cout << n << endl;
printNumbers(n - 1);
```

Output:

```text
5
4
3
2
1
```

So, to print **1 to N**, make the recursive call first and print after it.

## Complexity

- **Time:** `O(n)` — one recursive call is made for each number.
- **Space:** `O(n)` — recursive calls are stored on the call stack.

## Learning Goal

This problem introduces the basic structure of recursion:

1. Define a **base case**.
2. Make the problem smaller.
3. Call the same function recursively.
4. Perform the required work while returning from recursion.
