public class remove_Element_27 {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        int j = nums.length-1;
        while(i <= j) {
            if(nums[i] == val) {
                nums[i] = nums[j];
                nums[j] = val;
                j--;
            } else {
                i++;
            }
        }
        return i;
    } 
}

// Time Complexity: O(n)
// Space Complexity: O(1)