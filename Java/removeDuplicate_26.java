public class removeDuplicate_26 {
    public int removeDuplicates(int[] nums) {
        // 快慢指针
        if(nums.length <= 1) {
            return nums.length;
        }
        int slow = 0;
        int fast = 1;
        while(fast < nums.length) {
            if(nums[slow] != nums[fast]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow+1;
    }
}

// 快慢指针，快指针遍历，慢指针更新数组
// Time Complexity: O(n)
// Space Complexity: O(1)