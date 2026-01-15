// Alogirthm1:
// Complexity: O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 1);
        int top = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            if(dp[i] > top) {
                top = dp[i];
            }
        }
        return top;
    }
};

// Algorithm2:
// Complexity: O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        int len = 0;
        int left = 0, right = 0;
        int mid = 0;
        dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > dp[len]) {
                dp.push_back(nums[i]);
                len++;
            } else if(nums[i] < dp[len]) {
                left = 0;
                right = len;
                while(left <= right) {
                    mid = (right - left) / 2 + left;
                    if(nums[i] > dp[mid]) {
                        left = mid+1;
                    } else if(nums[i] < dp[mid]) {
                        right = mid-1;
                    } else {
                        left = mid;
                        break;
                    }
                }
                dp[left] = nums[i];
            }
        }
        return dp.size();
    }
};