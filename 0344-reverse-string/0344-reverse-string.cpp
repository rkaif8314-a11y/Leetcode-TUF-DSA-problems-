class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> rev;
        int n =s.size();
        for(int i = n-1; i>=0;i--){
            rev.push_back(s[i]);
        }
        s= rev;
        
    }
};