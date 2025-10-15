// Runtime 35ms Beats 39.16% Memory 13.88MB Beats 99.53%
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = nums.size();
        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i]+nums[j] == target)
                {
                    return {i,j};
                }
            }
        }
        return nums;
    }
};
