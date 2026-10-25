# Bubble Sort

## Goal
Sort a vector in ascending order by repeatedly comparing adjacent elements and swapping them when they are in the wrong order.

## How it works
1. Start with the last index of the unsorted section (`end`).
2. Compare each adjacent pair from index `0` through `end`.
3. If `nums[i] > nums[i + 1]`, swap the two values.
4. After one pass, the largest value in the unsorted section reaches index `end`.
5. Reduce `end` and repeat.
6. If a pass makes no swaps, stop early because the vector is already sorted.

## Example
Input: `[5, 1, 4, 2]`

- Pass 1: `[1, 4, 2, 5]` — the largest value, `5`, reaches the end.
- Pass 2: `[1, 2, 4, 5]` — the next largest value reaches its final position.
- Pass 3: no swaps are needed, so the algorithm stops early.

Output: `[1, 2, 4, 5]`

## Why use `swapped`?
`swapped` starts as `false` at the beginning of each pass. If any pair is swapped, it becomes `true`. If it remains `false`, every adjacent pair was already in order, so another pass is unnecessary.

## Complexity
- **Best-case time:** O(n), when the vector is already sorted and early exit happens after one pass.
- **Average-case time:** O(n²).
- **Worst-case time:** O(n²).
- **Auxiliary space:** O(1), because sorting happens in the original vector.
- **Stable:** Yes, because equal values are not swapped (`>` is used instead of `>=`).

## Key concepts
- Nested loops
- Adjacent element comparisons
- Swapping
- Boolean flags
- Early termination

## DSA pattern
**Sorting — Bubble Sort with Early-Exit Optimization**

Bubble sort is useful for learning sorting fundamentals, but its O(n²) average and worst-case time makes it inefficient for large arrays.