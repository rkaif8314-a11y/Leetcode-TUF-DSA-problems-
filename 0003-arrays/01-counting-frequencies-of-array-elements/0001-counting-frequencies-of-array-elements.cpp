#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> countFrequencies(vector<int>& nums) {
        // Step 1: Sort the array so that equal elements become adjacent.
        sort(nums.begin(), nums.end());

        // Store each unique element along with its frequency.
        vector<vector<int>> ans;

        int i = 0;

        // Traverse the sorted array one unique element at a time.
        while (i < static_cast<int>(nums.size())) {
            // Every element appears at least once.
            int frequency = 1;

            // Count consecutive occurrences of the current element.
            while (i + 1 < static_cast<int>(nums.size()) &&
                   nums[i] == nums[i + 1]) {
                frequency++;
                i++;
            }

            // Store the current element and its frequency.
            ans.push_back({nums[i], frequency});

            // Move to the next element that has not been processed yet.
            i++;
        }

        return ans;
    }
};
