public class maxProfit_122 {
    public int maxProfit(int[] prices) {
        int res = 0;
        int p = 0;
        for(int i = 1; i < prices.length; i++) {
            p = prices[i] - prices[i-1];
            if(p > 0) {
                res += p;
            }
        }
        return res;
    }
    // Time: O(n), Space: O(1)
}