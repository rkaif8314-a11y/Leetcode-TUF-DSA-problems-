#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Euclidean Algorithm: GCD(a, b) = GCD(b, a % b).
    int GCD(int n1, int n2) {
        while (n2 != 0) {
            int temp = n2;
            n2 = n1 % n2;
            n1 = temp;
        }
        return n1;
    }
};
