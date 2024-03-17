public class RunningSum_1480{
    public int[] runningSum(int[] nums) {
        int len = nums.length;
        int[] res = new int[len];
        res[0] = nums[0];
        for(int i = 1; i < len; i++) {
            res[i] = nums[i] + res[i-1];
        }
        return res;
    }
}
    