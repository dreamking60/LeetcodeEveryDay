public class binarySearch_704 {
    public int search(int[] nums, int target) {
        int len = nums.length;
        return BinarySearch(nums, 0, len-1, target);
    }

    public int BinarySearch(int[] nums, int start, int end, int target) {
        int mid = (end-start)/2+start;
        if(start > end) {
            return -1;
        }
        if(nums[mid] > target) {
            return BinarySearch(nums, start, mid-1, target);
        } else if(nums[mid] < target) {
            return BinarySearch(nums, mid+1, end, target);
        } else {
            return mid;
        }
    }
}

// Other Solution
/*
 * class Solution {
    public int search(int[] nums, int target) {
        int start=0, end = nums.length - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target ){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return -1;
    }
}
 */


// Space Complexity: O(logn)
// Time Complexity: O(logn)