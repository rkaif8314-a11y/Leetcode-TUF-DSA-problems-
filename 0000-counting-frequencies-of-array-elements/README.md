# Counting Frequencies of Array Elements

## Problem

Given an array `nums` that may contain duplicate elements, return a list of pairs where each pair contains a unique element and its frequency.

Example:

```text
Input:  [1, 2, 2, 1, 3]
Output: [[1, 2], [2, 2], [3, 1]]
```

## Approach

This solution follows the sorting idea:

1. Sort the array so equal values are next to each other.
2. Traverse the sorted array using an index `i`.
3. For the current value, count consecutive equal elements using a `while` loop.
4. Store the pair `{element, frequency}` in the answer vector.
5. Move to the next unprocessed element.

After sorting:

```text
[1, 2, 2, 1, 3]
        ↓
[1, 1, 2, 2, 3]
```

Frequencies become:

```text
1 -> 2
2 -> 2
3 -> 1
```

## Key Concepts

### 1. Sorting

`sort(nums.begin(), nums.end())` arranges the elements in ascending order.

The important observation is that equal elements become adjacent, which makes frequency counting easy.

### 2. Two-Level Traversal

The outer `while` loop moves between unique elements.

The inner `while` loop counts how many times the current element appears consecutively.

### 3. 2D Vector

``vector<vector<int>> ans;``

stores multiple pairs such as:

```text
[[1, 2], [2, 2], [3, 1]]
```

A pair is added with:

``ans.push_back({element, frequency});``

## Complexity

- Time: **O(n log n)** because of sorting.
- Extra space: **O(k)** for the output, where `k` is the number of unique elements.
- The sorting is performed directly on the input vector.

## Important Learning

The main pattern to remember is:

```text
SORT -> COUNT CONSECUTIVE DUPLICATES -> STORE -> MOVE TO NEXT UNIQUE ELEMENT
```

## Common Mistakes

- Comparing `int[i]` instead of `nums[i]`.
- Adding the result to `nums` instead of `ans`.
- Forgetting to return `ans`.
- Forgetting to move `i` after finishing a frequency count.
- Using nested loops unnecessarily when sorting already groups duplicates.

## Alternative Approach

A frequency map such as `unordered_map<int, int>` can solve the problem in expected **O(n)** time without sorting. This exercise intentionally uses sorting to practice array traversal and duplicate counting.
