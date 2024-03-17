public class sortedSquares_977 {
    // Method1: 找最小值顺着做
    public int[] sortedSquares(int[] nums) {
        if(nums[0] >= 0) {
            for(int i = 0; i < nums.length; i++) {
                nums[i] = nums[i] * nums[i];
            }
            return nums;
        } else if(nums[nums.length-1] <= 0) {
            int tmp = 0;
            for(int i = 0; i <= (nums.length-1)/2; i++) {
                tmp = nums[i];
                nums[i] = nums[nums.length-1-i] * nums[nums.length-1-i];
                nums[nums.length-1-i] = tmp * tmp;
            }
            return nums;
        } else {
            int left = 0;
            int right = 0;
            for(int i = 0; i < nums.length; i++) {
                if(nums[i] < 0 && nums[i+1] >= 0) {
                    left = i;
                    right = i+1;
                    break; 
                }
            }
            int[] res = new int[nums.length];
            for(int i = 0; i < nums.length; i++) {
                if(left >= 0 && (right > nums.length-1 || -nums[left] < nums[right])) {
                    res[i] = nums[left] * nums[left];
                    left--;
                } else {
                    res[i] = nums[right] * nums[right];
                    right++;
                }
            }
            return res;
        }
    }

    // Method2: 找最大值逆着做
    public int[] sortedSquares_2(int[] nums) {
        int left = 0;
        int right = nums.length-1;
        int index = nums.length-1;
        int[] res = new int[nums.length];
        while(left <= right) {
            if(nums[left] * nums[left] > nums[right] * nums[right]) {
                res[index--] = nums[left] * nums[left];
                left++;
            } else {
                res[index--] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
}

// Time Complexity: O(n)
// Space Complexity: O(n)