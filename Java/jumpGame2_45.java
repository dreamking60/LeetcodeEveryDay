public class jumpGame2_45 {
    public int jump(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= nums[i]; j++) {
                if(dp[i+j] == 0 || dp[i+j] > dp[i] + 1) {
                    dp[i+j] = dp[i] + 1;
                }
            }
        }
        return dp[n-1];
    }
    // Time Complexity: O(n^2)
    // Space Complexity: O(n) 
}