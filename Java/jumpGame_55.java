public class jumpGame_55 {
    public boolean canJump(int[] nums) {
        int max = 0;
        int jmp = 0;
        for(int i = 0; i < nums.length-1; i++) {
            if(i <= max) {
                jmp = nums[i]+i;
                if(max < jmp) {
                    max = jmp;
                }
            } else {
                return false;
            }
        }
        return (max >= nums.length-1) ? true : false;
    }
    // Time: O(n), Space: O(1)
}
