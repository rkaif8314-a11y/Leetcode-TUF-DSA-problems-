#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // Sort the array so smaller elements come before larger elements.
        sort(nums.begin(), nums.end());

        // Sum of all elements currently inside the sliding window.
        long long windowSum = 0;

        // Left boundary of the sliding window.
        int left = 0;

        // Stores the maximum valid frequency found so far.
        int maxFreq = 1;

        // Expand the window one element at a time.
        for (int right = 0; right < nums.size(); right++) {
            // Add the new element to the current window.
            windowSum += nums[right];

            /*
                We want to make every element in the window equal
                to nums[right].

                Example:
                window = [1, 2, 4]
                target = 4

                Operations needed:
                (4 - 1) + (4 - 2) + (4 - 4)

                This can be simplified to:
                target * windowSize - windowSum
            */
            long long operationsNeeded =
                1LL * nums[right] * (right - left + 1) - windowSum;

            // If the window needs more than k operations,
            // remove elements from the left until it becomes valid.
            while (operationsNeeded > k) {
                windowSum -= nums[left];
                left++;

                // Recalculate the cost for the smaller window.
                operationsNeeded =
                    1LL * nums[right] * (right - left + 1) - windowSum;
            }

            // The current valid window represents a possible frequency.
            int currentFreq = right - left + 1;

            // Keep the largest frequency found.
            maxFreq = max(maxFreq, currentFreq);
        }

        return maxFreq;
    }
};
