// #Accepted 1095 / 1095 testcases passed N. Adhikary submitted at Oct 16, 2025 00:28 Runtime 0ms Beats100.00% Memory 9.02MB Beats80.71%
/*
// no workie =(

class Solution {
public:
    int myAtoi(string s) {
        int n = 0;
        long long bit = 1;
        for (int i = s.length()-1; i >= 0; --i)
        {
            if (isdigit(s[i])){
                n += (s[i]-'0')*bit;
                bit *= 10;
            } else if (s[i] == '-') {
                n = -n;
                if (i == 0){
                    continue;
                } else if (s[i-1] != ' ') n = 0;
            } else if (s[i] == ' ') {
                continue;
            } else {
                n = 0;
                if (bit > 1) bit = 1;
            }
        }
        if (n <= INT_MAX) {
            return n;
        } else if (n < INT_MIN)
        {
            return INT_MIN;
        } else {
            return INT_MAX;
        }
    }
};*/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1, n = s.size();
        long long num = 0;
        while (i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        while (i < n && isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
            if (sign * num <= INT_MIN) return INT_MIN;
            if (sign * num >= INT_MAX) return INT_MAX;
            i++;
        }
        return sign * num;
    }
};
