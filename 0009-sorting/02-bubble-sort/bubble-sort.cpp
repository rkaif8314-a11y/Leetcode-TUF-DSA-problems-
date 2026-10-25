#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        int n = nums.size();

        // Each pass moves the largest remaining element to the end.
        for (int end = n - 1; end > 0; end--) {
            // Track whether this pass made any swaps.
            bool swapped = false;

            // Compare adjacent elements in the unsorted part.
            for (int i = 0; i < end; i++) {
                // If the pair is out of order, swap it.
                if (nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                    swapped = true;
                }
            }

            // If no swap occurred, the array is already sorted.
            // Stop early to avoid unnecessary passes.
            if (!swapped) {
                break;
            }
        }

        // Return the sorted vector.
        return nums;
    }
};
