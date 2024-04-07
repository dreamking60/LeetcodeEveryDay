public class candy_135 {
    public int candy(int[] ratings) {
        int len = ratings.length;
        int cur = 1;
        int sum = 0;
        int[] left = new int[len];
        int[] right = new int[len];
        left[0] = 1;
        right[len-1] = 1;
        for(int i = 0; i < len-1; i++) {
            if(ratings[i] < ratings[i+1]) {
                cur++;
            } else {
                cur = 1;
            }
            left[i+1] = cur;
        }
        cur = 1;
        for(int i = len-1; i > 0; i--) {
            if(ratings[i] < ratings[i-1]) {
                cur++;
            } else {
                cur = 1;
            }
            right[i-1] = cur;
        }
        for(int i = 0; i < len; i++) {
            sum += Math.max(left[i], right[i]);
        }

        return sum;
    }


    public static void main(String[] args) {
        candy_135 test = new candy_135();
        int[] ratings = {1,0,2};
        System.out.println(test.candy(ratings));
    }
}
