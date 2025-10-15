// N. Adhikary submitted at Oct 15, 2025 01:57 Runtime 0ms Beats100.00% Memory 11.82MB Beats68.86%

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (int j = 0; j < strs[0].size(); ++j)
        {
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); ++i)
            {
                if (j >= strs[i].size() || strs[i][j] != c)
                {
                    return strs[0].substr(0, j);
                }
            }
        }
        return strs[0];
    }
};
