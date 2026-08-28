# Print N to 1 using Recursion

## Problem Statement

Given an integer `n`, print all numbers from **n to 1 (inclusive) using recursion**.

### Requirements

- Do not use any loops such as `for`, `while`, or `do-while`.
- Print each number on a separate line.
- Print the numbers in decreasing order from `n` to `1`.

## Example

### Input

```text
n = 5
```

### Output

```text
5
4
3
2
1
```

## Approach

Use recursion to reduce `n` by 1 on every function call.

The base case is:

```cpp
if (n == 0) {
    return;
}
```

This stops the recursion when `n` reaches 0.

For printing **N to 1**, print the current value **before** making the recursive call:

```cpp
cout << n << endl;
printNumbers(n - 1);
```

## C++ Solution

```cpp
class Solution {
public:
    void printNumbers(int n) {

        if (n == 0) {
            return;
        }

        cout << n << endl;
        printNumbers(n - 1);
    }
};
```

## Code Explanation

### 1. Base Case

```cpp
if (n == 0) {
    return;
}
```

When `n` becomes 0, stop the recursion.

### 2. Print the Current Number

```cpp
cout << n << endl;
```

The current number is printed before the recursive call.

### 3. Recursive Call

```cpp
printNumbers(n - 1);
```

The function calls itself with a smaller value.

For `n = 5`:

```text
5 → 4 → 3 → 2 → 1 → 0
```

The numbers are printed while going down, so the output is:

```text
5
4
3
2
1
```

## Recursion Flow

```text
printNumbers(5)
    ↓ print 5
printNumbers(4)
    ↓ print 4
printNumbers(3)
    ↓ print 3
printNumbers(2)
    ↓ print 2
printNumbers(1)
    ↓ print 1
printNumbers(0)
    ↓ return
```

## Important Recursion Concept

The position of the print statement determines the order.

### Print before recursion

```cpp
cout << n << endl;
printNumbers(n - 1);
```

Produces:

```text
5
4
3
2
1
```

This is used for **N to 1**.

### Print after recursion

```cpp
printNumbers(n - 1);
cout << n << endl;
```

Produces:

```text
1
2
3
4
5
```

This is used for **1 to N**.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)` because of the recursion call stack.

## Learning Goal

This problem reinforces the basic recursion pattern:

1. Define a base case.
2. Perform the required operation.
3. Call the same function with a smaller input.
