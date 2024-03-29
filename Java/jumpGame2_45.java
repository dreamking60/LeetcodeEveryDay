public class jumpGame2_45 {
    public int jump(int[] nums) {
        int n = nums.length;
        if(n == 1) return 0;

        int max = Math.min(nums[0], n-1);
        int newMax = 0;
        int step = 1;
        int cur = 1;
        while(true) {
            newMax = 0;
            if(max >= n-1) {
                return step;
            }
            for(int i = cur; i <= max; i++) {
                newMax = Math.max(newMax, i+nums[i]);
            }
            cur = max+1;
            max = newMax;
            step++;
            
        }

    }
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}