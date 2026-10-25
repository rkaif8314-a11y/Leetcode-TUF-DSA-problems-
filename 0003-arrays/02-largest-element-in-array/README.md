# Largest Element in an Array

## Problem

Given a **non-empty array of integers**, find and return its largest element.

Example:

- Input: `[3, 8, 2, 10, 5]`
- Output: `10`

## Core idea

We do not need to sort the array. We can find the answer by checking each element once.

1. Assume the first element is the largest.
2. Visit every remaining element.
3. If the current element is greater than the largest value we have saved, update that saved value.
4. Once every element has been checked, return the saved value.

## Step-by-step dry run

For `[3, 8, 2, 10, 5]`:

| Current element | Largest before comparison | What happens | Largest after comparison |
| ---: | ---: | --- | ---: |
| 3 | — | Use the first element to initialize | 3 |
| 8 | 3 | 8 is greater than 3 | 8 |
| 2 | 8 | 2 is not greater than 8 | 8 |
| 10 | 8 | 10 is greater than 8 | 10 |
| 5 | 10 | 5 is not greater than 10 | 10 |

The final answer is `10`.

## Concepts explained

### 1. `vector<int>`

A `vector<int>` is a resizable collection of integers in C++. We use `arr[i]` to access the element at index `i`. Indexing starts at `0`.

### 2. `largest = arr[0]`

We initialize the answer using an actual array element instead of using `0`. This is important because the array might contain only negative numbers, such as `[-8, -3, -11]`. The correct largest element there is `-3`.

### 3. The `for` loop

`for (int i = 1; i < arr.size(); i++)` starts at the second element and moves forward until all elements have been checked.

- `int i = 1`: start at index 1.
- `i < arr.size()`: stop when the index reaches the array length.
- `i++`: increase the index by one after each iteration.

### 4. The `if` condition

`if (arr[i] > largest)` checks whether the current element is bigger than the saved largest value. If so, `largest = arr[i]` updates the saved value.

### 5. Pass by reference: `vector<int>& arr`

The `&` means the function receives a reference to the original vector rather than making a copy. This function only reads the vector; it does not modify its elements.

### 6. `return largest`

The function sends the final largest value back to the code that called it.

## Complexity

- **Time complexity: `O(n)`** — each of the `n` elements is examined at most once.
- **Auxiliary space: `O(1)`** — only a fixed number of extra variables are used.

## Important edge cases

- **Negative numbers:** Works because we initialize from `arr[0]`, not from zero.
- **Duplicates:** Still returns the largest value even if it appears more than once.
- **One element:** Returns that element.
- **Empty array:** This implementation assumes the array is non-empty. Accessing `arr[0]` on an empty vector is invalid, so check for emptiness first if your platform allows empty input.

## File

- `largest-element.cpp` — complete beginner-friendly C++ example with comments and a `main()` function.
