public class spiralMatrix2_59 {
    public int[][] generateMatrix(int n) {
        int[][] res= new int[n][n];
        int k = 0;
        int start = 0;
        int count = 1;
        while(k++ < n/2) {
            for(int i = start; i < n-k; i++) {
                res[start][i] = count++;
            }
            for(int i = start; i < n-k; i++) {
                res[i][n-k] = count++;
            }
            for(int i = n-k; i >= k; i--) {
                res[n-k][i] = count++;
            }
            for(int i = n-k; i >= k; i--) {
                res[i][start] = count++;
            }
            start++;
        }   
        if(n % 2 == 1) {
            res[start][start] = count++;
        }
        return res;
    }
}