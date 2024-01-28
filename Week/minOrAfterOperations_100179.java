package Week;

class Solution {
    public int minOrAfterOperations(int[] nums, int k) {
        int len = nums.length;
        int res = 0;
        int count = 0;
        int bit = 0;
        int cur = 0;
        for(int i = 29; i >= 0; i--) {
            count = 0;
            bit |= 1 << i;
            cur = bit; 
            for(int j = 0; j < len; j++) {
                cur &= nums[j];
                if((cur | res) != res) {
                    count++;
                } else {
                    cur = bit;
                }
                
            }
            if(count > k) {
                res |= (1 << i);
            }

        }
        return res;
    }
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}