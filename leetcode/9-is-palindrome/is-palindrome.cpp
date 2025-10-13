/*
Runtime
0ms
Beats100.00%
Analyze Complexity
Memory
8.45MB
Beats91.98%
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long r = 0;
        long long xs = x;
        while (x != 0)
        {
            int digit = x % 10;
            r = r * 10 + digit;
            x/=10;
        }
        return xs == r;
    }
};
