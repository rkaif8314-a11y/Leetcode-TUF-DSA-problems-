#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        std::vector<char> rev;
        int n = static_cast<int>(s.size());
        for (int i = n - 1; i >= 0; --i) {
            rev.push_back(s[i]);
        }
        s = rev;
    }
};
