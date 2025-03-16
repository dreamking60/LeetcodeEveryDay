class Solution {
    public:
        int maxSum(vector<int>& nums) {   
            int size = nums.size();       
            int max = nums[0];
            int total = 0;
            unordered_set<int> isAdd;            
            
            for(int i = 0; i < size; i++) {
                 if(!isAdd.contains(nums[i])) {
                    if(nums[i] > 0) {
                        total += nums[i];
                     }
                    if(nums[i] > max) {  
                        max = nums[i];
                    }
                    isAdd.insert(nums[i]);
                 }
            }
    
            if(max < 0) {  
                return max;
            } else {
                return total;
            }
        }
    };©leetcode