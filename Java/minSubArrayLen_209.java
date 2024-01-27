class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int left = 0;
        int right = 0;
        int total = 0;
        int min = nums.length+1;
        while(right < nums.length) {
            total += nums[right];
            while(total >= target) {
                if(min > right-left+1) {
                    min = right-left+1;
                }
                total -= nums[left++];
            }
            right++;
        }
        if(min == nums.length+1) {
            return 0;
        }
        return min;
    }
    // Time Complexity: O(n);
    // Space Complexity: O(1);
}