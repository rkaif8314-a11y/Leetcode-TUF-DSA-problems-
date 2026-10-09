# Selection Sort

## Goal
Sort an array in ascending order by repeatedly selecting the smallest element from the unsorted part and moving it to the beginning of that part.

## How it works
1. Start at index `i`.
2. Assume `nums[i]` is the smallest element in the unsorted section.
3. Scan the remaining elements using `j` to find the actual minimum index (`minIdx`).
4. Swap the minimum element with `nums[i]`.
5. Repeat until the unsorted section has one element left.

## Example
For `[5, 3, 4, 1]`:
- Pass 1: minimum is `1`; swap with `5` → `[1, 3, 4, 5]`
- Pass 2: minimum of `[3, 4, 5]` is `3`; no change
- Pass 3: minimum of `[4, 5]` is `4`; no change

Result: `[1, 3, 4, 5]`

## Complexity
- **Time:** O(n²) in best, average, and worst cases because the nested loops scan the remaining array.
- **Extra space:** O(1) auxiliary space; sorting is done in-place.
- **Stable:** No, not in its usual form.
- **In-place:** Yes.

## Key concepts
- Nested loops
- Finding a minimum
- Index variables
- Swapping
- Sorted and unsorted portions of an array

## Important note
This implementation modifies the input vector and returns the sorted vector.