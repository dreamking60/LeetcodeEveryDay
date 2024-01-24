class Solution {
    public int searchInsert(int[] nums, int target) {
        return binarySearch(nums, 0, nums.length, target);
    }

    public int binarySearch(int[] nums, int start, int end, int target) {
        if(start >= end) {
            return start;
        }
        int mid = (end-start)/2 + start;
        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] < target) {
            return binarySearch(nums, mid+1, end, target);
        } else {
            return binarySearch(nums, start, mid, target);
        }
    }
}

// Space Complexity: O(1)
// Time Complexity: O(logn)