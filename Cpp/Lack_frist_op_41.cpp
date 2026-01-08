class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int min = nums[0];
        int max = nums[0];
        int res = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < min) {
                min = nums[i];
            }
            if(nums[i] > max) {
                max = nums[i];
            }
        }

        if(min > 1 || max < 1) {
            return res;
        }

        int swap = 0;
        int target = 0;
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] > 0 && nums[i] <= nums.size() && i != nums[i] - 1) {
                swap = nums[nums[i] - 1];
                if(swap == nums[i]) {
                    break;
                }
                nums[nums[i] - 1] = nums[i];
                nums[i] = swap;
            }
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0 || (nums[i] > 0 && nums[i] != i+1)) {
                return i+1;
            }
        }

        return nums.size()+1;
    }
};