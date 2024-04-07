public class trapRainWater_42 {
    public int trap(int[] height) {
        int len = height.length;
        int[] left = new int[len];
        int[] right = new int[len];
        for(int i = 0; i < len; i++) {
            if(i == 0) {
                left[i] = height[i];
            } else {
                left[i] = Math.max(left[i-1], height[i]);
            }
        }
        for(int i = len-1; i >= 0; i--) {
            if(i == len-1) {
                right[i] = height[i];
            } else {
                right[i] = Math.max(right[i+1], height[i]);
            }
        }
        int sum = 0;
        for(int i = 0; i < len; i++) {
            sum += Math.min(left[i], right[i]) - height[i];
        }
        return sum;
    }
}
