# Search in Rotated Sorted Array — Lecture 18

This folder contains my solution and notes for **Search in Rotated Sorted Array**, based on Lecture 18/144.

## Problem

Given a sorted array that has been rotated, find the index of a given target.

### Example

```text
Input:
A = [4,5,6,7,0,1,2]
target = 0

Output:
4
```

## Approach

A normal Linear Search would take **O(n)** time.

The optimized solution uses **Binary Search**, giving **O(log n)** time.

The key observation is:

> In a rotated sorted array, at least one half around the middle is sorted.

At every step:

1. Find `mid`.
2. If `A[mid] == target`, return `mid`.
3. Determine whether the left half is sorted.
4. If the left half is sorted:
   - Check whether the target lies inside it.
   - Search the appropriate half.
5. Otherwise, the right half is sorted:
   - Check whether the target lies inside it.
   - Search the appropriate half.
6. If the search range becomes empty, return `-1`.

## Important Conditions

### Left half is sorted

```cpp
if (A[st] <= A[mid])
```

Then check:

```cpp
if (A[st] <= tar && tar <= A[mid])
```

If true, search left:

```cpp
end = mid - 1;
```

Otherwise search right:

```cpp
st = mid + 1;
```

### Right half is sorted

If the left half is not sorted, the right half is considered sorted.

Check:

```cpp
if (A[mid] <= tar && tar <= A[end])
```

If true, search right:

```cpp
st = mid + 1;
```

Otherwise search left:

```cpp
end = mid - 1;
```

## Complexity

| Approach | Time | Space |
|---|---:|---:|
| Linear Search | O(n) | O(1) |
| Rotated Binary Search | O(log n) | O(1) |

## Important Learning

The main idea to remember:

```text
Find middle
    ↓
Is target found?
    ↓ No
Which half is sorted?
    ↓
Does target belong to sorted half?
   ↙                    ↘
 Yes                     No
  ↓                       ↓
Search that half      Search other half
```

## File

- `searchinrotatedsortedarraylec18.cpp` — C++ solution with detailed learning comments.

## Language

C++

## Lecture

18/144
