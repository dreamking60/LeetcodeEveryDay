public class searchRange_34 {
    public int[] searchRange(int[] nums, int target) {
        if(nums.length == 0) {
            return new int[]{-1,-1};
        }
        int left = 0;
        int right = nums.length-1;
        while(left < right) {
            int mid = (right-left)/2+left;
            if(nums[mid] == target) {
                right = mid;
            } else if(nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        if(nums[left] != target) {
            return new int[]{-1,-1};
        }
        int tmp = left;
        right = nums.length-1;
        while(left < right) {
            int mid = (right-left+1)/2 + left;
            if(nums[mid] == target) {
                left = mid;
            } else if(nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return new int[]{tmp, left};
    }
}

// Time Complexity: O(logn)
// Space Complexity: O(1)