public class moveZero_283 {

    // method1
    public void moveZeroes_1(int[] nums) {
        int slow = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] != 0) {
                if(slow < i) {
                    nums[slow++] = nums[i];
                    nums[i] = 0;
                } else {
                    slow++;
                }
            }
        }
    }
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    // method2
    public void moveZeroes_2(int[] nums) {
        int slow = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] != 0) {
                nums[slow++] = nums[i];
            }
        }
        for(int i = slow; i < nums.length; i++) {
            nums[i] = 0;
        }
    }
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}