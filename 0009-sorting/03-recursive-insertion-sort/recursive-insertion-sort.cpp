#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Put 'key' into its correct place in the sorted part nums[0...index].
    // We move bigger numbers one step to the right until there is room for key.
    void insertElement(vector<int>& nums, int index, int key) {
        // If index is before the array, key belongs at the beginning.
        // If nums[index] <= key, key belongs just after nums[index].
        if (index < 0 || nums[index] <= key) {
            nums[index + 1] = key;
            return; // The key has been inserted, so this recursive call is finished.
        }

        // This number is bigger than key, so shift it one position right.
        nums[index + 1] = nums[index];

        // Keep moving left to find the correct place for key.
        insertElement(nums, index - 1, key);
    }

    // Sort only the first n elements of nums using recursion.
    void sortRecursive(vector<int>& nums, int n) {
        // Base case: an array with 0 or 1 element is already sorted.
        if (n <= 1) {
            return;
        }

        // First, sort the first n - 1 elements.
        // When this call returns, nums[0...n-2] is sorted.
        sortRecursive(nums, n - 1);

        // Save the last element; it needs to be inserted into the sorted part.
        int key = nums[n - 1];

        // Insert key into the sorted part nums[0...n-2].
        insertElement(nums, n - 2, key);
    }

public:
    // Platform-facing function: accepts one vector and sorts it in place.
    // No loops and no built-in sorting function are used.
    void insertionSort(vector<int>& nums) {
        sortRecursive(nums, static_cast<int>(nums.size()));
    }
};
