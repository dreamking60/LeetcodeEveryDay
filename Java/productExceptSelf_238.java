public class productExceptSelf_238 {
    public int[] productExceptSelf(int[] nums) {
        int zeros = 0;
        int len = nums.length;
        int product = 1;
        int[] answer = new int[len];
        for(int i = 0; i < len; i++) {
            if(nums[i] == 0) {
                zeros++;
            }
        }
        if(zeros == 0) {
            for(int i = 0; i < len; i++) {
                product *= nums[i];
            }
            for(int i = 0; i < len; i++) {
                answer[i] = product / nums[i];
            }
        } else if(zeros == 1) {
            int zeroItem = 0;
            for(int i = 0; i < len; i++) {
                if(nums[i] != 0) {
                    product *= nums[i];
                    answer[i] = 0;
                } else {
                    zeroItem = i;
                }
            }
            answer[zeroItem] = product;
        } else {
            for(int i = 0; i < len; i++) {
                answer[i] = 0;
            }
        }
        return answer;
    }
    // Time complexity: O(n)
    // Space complexity: O(n)
}
