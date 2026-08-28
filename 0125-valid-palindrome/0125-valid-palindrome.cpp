class Solution {
public:
    bool isPalindrome(string s) {

        // Two pointers:
        // left starts from the beginning
        // right starts from the end
        int left = 0;
        int right = s.size() - 1;

        // Continue until the two pointers meet
        while (left < right) {

            // If the left character is not a letter or number,
            // skip it and move left forward
            if (!isalnum(s[left])) {
                left++;
            }

            // If the right character is not a letter or number,
            // skip it and move right backward
            else if (!isalnum(s[right])) {
                right--;
            }

            else {
                // Convert both characters to lowercase
                // and compare them
                if (tolower(s[left]) != tolower(s[right])) {
                    // Characters don't match, so it is not a palindrome
                    return false;
                }

                // Move both pointers toward the center
                left++;
                right--;
            }
        }

        // All valid characters matched
        return true;
    }
};