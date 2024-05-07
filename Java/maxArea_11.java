public class maxArea_11 {
    public int maxArea(int[] height) {
        int i = 0;
        int j = height.length-1;

        int max_area = 0;
        int left = 0;
        int right = 0;
        int area = 0;
        while(i < j) {
            if(left < height[i]) {
                left = height[i];
                if(left < right) {
                    area = left * (j-i);
                } else {
                    area = right * (j-i);
                }
                if(area > max_area) {
                    max_area = area;
                }
            }
            if(right < height[j]) {
                right = height[j];
                if(left < right) {
                    area = left * (j-i);
                } else {
                    area = right * (j-i);
                }
                if(area > max_area) {
                    max_area = area;
                }
            }       

            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }

        }

        return max_area;
    }
}
