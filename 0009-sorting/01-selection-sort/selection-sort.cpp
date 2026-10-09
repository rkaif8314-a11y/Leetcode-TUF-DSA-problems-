#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {
        int n = nums.size();

        // Each pass places the smallest remaining element in its correct position.
        for (int i = 0; i < n - 1; i++) {
            // Assume the first element of the unsorted section is the minimum.
            int minIdx = i;

            // Search the rest of the unsorted section for a smaller element.
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[minIdx]) {
                    minIdx = j;
                }
            }

            // Put the minimum element at the beginning of the unsorted section.
            swap(nums[i], nums[minIdx]);
        }

        // Return the sorted array.
        return nums;
    }
};
