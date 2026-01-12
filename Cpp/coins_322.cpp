class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> dp(amount+1, amount+2);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i-coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        if(dp[amount] == amount+2) return -1;
        return dp[amount];
    }
};