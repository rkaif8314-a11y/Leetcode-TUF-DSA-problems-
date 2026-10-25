#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        // This solution assumes nums is not empty.
        // Start by treating the first element as the largest.
        int largest = nums[0];

        // This value is only used as an answer after foundSecond becomes true.
        int secondLargest = 0;
        bool foundSecond = false;

        int n = nums.size();

        // Check each element after the first one.
        for (int i = 1; i < n; i++) {

            // Case 1: We found a new largest number.
            if (nums[i] > largest) {
                // Save the OLD largest as the second largest first.
                secondLargest = largest;

                // Now update largest to the new, bigger number.
                largest = nums[i];

                // We now have a valid second-largest distinct value.
                foundSecond = true;
            }

            // Case 2: The number is smaller than largest and could be
            // the best second-largest value found so far.
            // The strict '< largest' check skips duplicate largest values.
            else if (nums[i] < largest &&
                     (!foundSecond || nums[i] > secondLargest)) {
                secondLargest = nums[i];
                foundSecond = true;
            }
        }

        // If a second-largest distinct value was found, return it.
        if (foundSecond) {
            return secondLargest;
        }

        // If all elements are equal, no second-largest distinct value exists.
        return -1;
    }
};
