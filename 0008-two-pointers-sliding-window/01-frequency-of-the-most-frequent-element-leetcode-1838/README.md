# LeetCode 1838 — Frequency of the Most Frequent Element

## Problem
Given an integer array `nums` and an integer `k`, you may perform at most `k` operations. In one operation, you can increment any element by 1.

Return the maximum possible frequency of an element after at most `k` operations.

## Approach

### 1. Sort the array
After sorting, smaller values are before larger values. For a sliding window ending at `right`, we can try to make every element in that window equal to `nums[right]`.

### 2. Maintain a sliding window
Use two pointers:
- `left` — beginning of the window
- `right` — end of the window

The window contains elements that we are trying to make equal.

### 3. Calculate required operations
If the target is `nums[right]`:

```text
operations = target × windowSize − windowSum
```

For example:

```text
window = [1, 2, 4]
target = 4

operations = 4 × 3 − (1 + 2 + 4)
           = 5
```

### 4. Shrink an invalid window
If the required operations are greater than `k`, move `left` forward and remove the leftmost element from the window.

### 5. Track the answer
The size of every valid window is a possible frequency. Keep the maximum window size.

## Why `long long` and `1LL`?

The operation calculation can become larger than the range of a normal `int`.

- `long long` stores much larger integer values.
- `1LL` makes the multiplication happen using `long long`.

## Complexity

- Sorting: **O(n log n)**
- Sliding window: **O(n)**
- Total: **O(n log n)**
- Extra space: **O(1)** apart from sorting implementation details.

## Key DSA Pattern

**Sorting + Sliding Window + Running Sum**

This pattern is useful when we need to find the largest group/window that can satisfy a cost or constraint.
