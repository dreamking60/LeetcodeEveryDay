class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dpin(nums.size(), INT_MAX);
        vector<int> dpax(nums.size(), INT_MIN);
        int top = nums[0];
        dpin[0] = nums[0];
        dpax[0] = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            dpin[i] = min(nums[i], min(nums[i]*dpin[i-1], nums[i]*dpax[i-1]));
            dpax[i] = max(nums[i], max(nums[i]*dpax[i-1], nums[i]*dpin[i-1]));
            top = max(top, dpax[i]);
        }

        return top;
    }
};