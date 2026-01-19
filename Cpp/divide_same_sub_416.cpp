class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() < 2) {
            return false;
        }

        int total = 0;
        for(int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }

        if(total % 2 != 0) {
            return false;
        }

        int target = total / 2;
        sort(nums.begin(), nums.end());
        if(nums[nums.size()-1] > target) {
            return false;
        } else if(nums[nums.size()-1] == target) {
            return true;
        }

        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = target-nums[i]; j >= 0; j--) {
                if(dp[j] == 1) {
                    dp[j+nums[i]] = 1;
                }
            }
            if(dp[target] == 1) {
                return true;
            }
        }

        return false;
    }
};