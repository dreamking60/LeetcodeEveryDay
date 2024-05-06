public class twoSum_167 {
    public int[] twoSum(int[] numbers, int target) {
        for(int i = 0; i < numbers.length-1; i++) {
            for(int j = i+1; j < numbers.length; j++) {
                if(numbers[i]+numbers[j] == target) {
                    return new int[]{i+1, j+1};
                }
            }
        }
        return new int[]{0,1};
    }
    // Time complexity: O(n^2)

    public int[] twoSum_2(int[] numbers, int target) {
        int i = 0;
        int j = numbers.length-1;
        while(i < j) {
            if(numbers[i]+numbers[j] == target) {
                return new int[]{i+1, j+1};
            } else if(numbers[i]+numbers[j] < target) {
                i++;
            } else {
                j--;
            }
        } 
        return new int[]{-1,-1};
    }
    
}
