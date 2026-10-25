# Recursive Insertion Sort

## Problem

Sort the given array in ascending order using **recursion only**. Do not use loops or a built-in sorting function.

## Main idea

Insertion sort keeps a part of the array sorted. We grow that sorted part one element at a time.

For recursion, imagine solving a smaller version of the same problem first:

1. Sort the first `n - 1` elements.
2. Save the last element as `key`.
3. Insert `key` into the correct place in the already-sorted part.
4. Repeat until only zero or one element remains.

An array with zero or one element is already sorted. This is our **base case**.

## Example

Input:

```text
[7, 4, 1, 5, 3]
```

The recursive calls first reach the smallest part:

- Sort `[7]` — one element, so it is already sorted.
- Insert `4` into `[7]` → `[4, 7]`.
- Insert `1` into `[4, 7]` → `[1, 4, 7]`.
- Insert `5` into `[1, 4, 7]` → `[1, 4, 5, 7]`.
- Insert `3` into `[1, 4, 5, 7]` → `[1, 3, 4, 5, 7]`.

Output:

```text
[1, 3, 4, 5, 7]
```

## How the two helper functions work

### 1. `sortRecursive(nums, n)`

- **Base case:** If `n <= 1`, return because that part is already sorted.
- **Recursive step:** Call `sortRecursive(nums, n - 1)` to sort a smaller part.
- **Work after the recursive call:** Save `nums[n - 1]` as `key`, then insert it into the sorted part.

Notice that the insertion happens **after** the recursive call returns. This is how the sorted part grows.

### 2. `insertElement(nums, index, key)`

This function checks the sorted part from right to left:

- If `index < 0`, the key belongs at the beginning.
- If `nums[index] <= key`, the key belongs just after that number.
- Otherwise, shift `nums[index]` one position right and call the function again with `index - 1`.

The key is saved in a separate variable before shifting. This prevents its value from being lost.

## Concepts to remember

- **Recursion:** A function calls itself with a smaller problem.
- **Base case:** The stopping condition that prevents endless recursive calls.
- **Recursive step:** The part that reduces the problem size.
- **Insertion:** Move larger values right, then place the key in the empty position.
- **In-place sorting:** The original vector is modified; no second array is needed.
- **Pass by reference (`vector<int>&`):** The function works on the original vector instead of making a copy.
- **`return`:** Ends the current function call. In `insertElement`, it stops further shifting after the key is placed.

## Complexity

- **Time:** `O(n^2)` in the worst case, because each insertion may move through many elements.
- **Auxiliary space:** `O(n)` for recursive call stacks. The algorithm does not create another array.

## Common mistakes

- Forgetting the base case (`n <= 1`).
- Inserting the key before the first `n - 1` elements are sorted.
- Shifting elements without saving the key first.
- Using the wrong platform function signature. This solution provides `void insertionSort(vector<int>& nums)`, which accepts one vector and sorts it in place.

## Files

- `recursive-insertion-sort.cpp` — solution with beginner-friendly comments.
- `README.md` — explanation of the intuition, recursion, example, complexity, and common mistakes.
