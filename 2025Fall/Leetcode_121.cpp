// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// 1. Double array
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        vector<int> end(prices);
        for(int i = n-2; i >= 0; i--) {
            if(end[i] < end[i+1]) {
                end[i] = end[i+1];
            }
        }


        for(int i = 0; i < n; i++) {
            if(end[i] - front[i] > res) {
                res = end[i] - front[i];
            }
        }
        return res;
    }
};

//