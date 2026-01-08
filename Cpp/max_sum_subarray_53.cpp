class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> cal_max;
        int max = nums[0];
        cal_max.push_back(max);
        for(int i = 1; i < nums.size(); i++) {
            if(cal_max[i-1] < 0) {
                cal_max.push_back(nums[i]);
                if(nums[i] > max) {
                    max = nums[i];
                }
            } else {
                cal_max.push_back(nums[i]+cal_max[i-1]);
                if(cal_max[i] > max) {
                    max = cal_max[i];
                }
            }
        }
        return max;
    }
};