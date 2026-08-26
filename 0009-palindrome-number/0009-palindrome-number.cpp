class Solution {
public:
    bool isPalindrome(int x) {
        int rev = 0;
        if (x<0){
            return false;
        }
        int original = x;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (rev > INT_MAX / 10 || 
                (rev == INT_MAX / 10 && digit > 7)) {
                return 0;
            }

            if (rev < INT_MIN / 10 || 
                (rev == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            rev = rev * 10;
            rev = rev + digit;
        }

        return original ==rev;
    }
};