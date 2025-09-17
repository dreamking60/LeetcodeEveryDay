// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

// 1. DP
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        vector<int> m;
        dp.push_back(nums[0]);
        m.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            dp.push_back(max(nums[i], dp[i-1]+nums[i]));
            m.push_back(max(dp[i],m[i-1]));
        }

        return m[nums.size()-1];
    }
};