# Second Largest Element in an Array

## Problem

Find the **second-largest distinct element** in an integer array.

Example:

- Input: `[4, 8, 2, 10, 10]`
- Output: `8`

The answer must be distinct from the largest value. In this example, the two `10` values count as one distinct value, so the second-largest is `8`.

## Approach: One-pass scan

We can solve this without sorting the array. We examine every element once and keep track of two values:

- `largest`: the biggest value found so far.
- `secondLargest`: the biggest value that is strictly smaller than `largest`.
- `foundSecond`: a Boolean flag that tells us whether a valid second-largest value has been found.

### Steps

1. Initialize `largest` with the first array element.
2. Visit each remaining element.
3. If the current element is greater than `largest`, first move the old `largest` into `secondLargest`, then update `largest`.
4. Otherwise, if the current element is smaller than `largest` and better than the current second-largest value, update `secondLargest`.
5. Return `secondLargest` if found. If every element is equal, return `-1`.

## Dry run

Input: `[4, 8, 2, 10, 10]`

| Current element | Largest | Second largest | Explanation |
| ---: | ---: | ---: | --- |
| 4 | 4 | Not found | Initialize largest with the first value |
| 8 | 8 | 4 | The old largest (4) becomes second largest |
| 2 | 8 | 4 | 2 is smaller than the current second largest |
| 10 | 10 | 8 | The old largest (8) becomes second largest |
| 10 | 10 | 8 | Duplicate largest; no update |

Final answer: `8`.

## Concepts to understand

### 1. Why save `largest` before updating it?

When a new largest value appears, the previous largest value becomes the second largest.

Correct order:

```cpp
secondLargest = largest; // Save the old largest first.
largest = nums[i];       // Then replace largest.
```

If we update `largest` first, we lose the old value and could incorrectly make both variables equal.

### 2. Why use `foundSecond`?

We cannot assume the second-largest value is positive. For example, in `[-8, -3, -6]`, the answer is `-6`.

The Boolean flag tells us whether `secondLargest` contains a real answer. Its initial value of `0` is only a placeholder, not an assumed answer.

### 3. Why use `nums[i] < largest`?

This strict comparison prevents a duplicate of the largest element from being treated as the second largest. For `[5, 5, 5]`, no second-largest distinct value exists.

### 4. What does `!foundSecond` mean?

The exclamation mark `!` means “not”. Therefore, `!foundSecond` is true while we have not yet found a second-largest value.

### 5. Why return `-1`?

This solution uses `-1` as the convention when no second-largest distinct element exists. Check your platform's instructions if it specifies a different value.

## Complexity

- **Time: `O(n)`** — each array element is checked once.
- **Auxiliary space: `O(1)`** — only a fixed number of variables are used.

## Edge cases

- Duplicate largest values: `[4, 10, 10]` → `4`
- Negative values: `[-8, -3, -6]` → `-6`
- All values equal: `[5, 5, 5]` → `-1` (no distinct second largest)
- One-element and empty arrays: this implementation assumes a non-empty array; confirm the platform's requirements for these cases.

## File

- `second-largest-element.cpp` — platform-style `Solution` class with beginner-friendly comments.
