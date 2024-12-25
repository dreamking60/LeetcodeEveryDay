public class minSubArray_209 {
    public int minSubArrayLen(int target, int[] nums) {
        int res = 0;
        int sum = 0;
        int i = 0;
        int j = 0;
        int len = nums.length;
        while(j < len) {
            sum += nums[j];
            while(sum >= target) {
                if(res == 0) {
                    res = j-i+1;
                } else {
                    res = Math.min(res, j-i+1);
                }
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return res;
    }
}