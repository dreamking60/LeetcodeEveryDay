class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }

        vector<int> res;
        res.push_back(nums[0]);
        res.push_back((nums[0] > nums[1]) ? nums[0] : nums[1]);

        for(int i = 2; i < nums.size(); i++) {
            if(res[i-2] + nums[i] > res[i-1]) {
                res.push_back(res[i-2] + nums[i]);
            } else {
                res.push_back(res[i-1]);
            }
        }

        return res[nums.size()-1];
    }
};