// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/


// 1. DP
// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(1);
        int max = 1;
        int res = 1;
        for(int i = 1; i < nums.size(); i++) {
            max = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i] && dp[j]+1 > max) {
                    max = dp[j]+1;
                }
            }
            if(max > res) {
                res = max;
            }
            dp.push_back(max);
        }
        return res;
    }
};