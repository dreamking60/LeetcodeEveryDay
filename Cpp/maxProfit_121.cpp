#include <vector>
using namespace std;


// 1st solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> left(len);
        vector<int> right(len);

        left[0] = prices[0];
        right[len-1] = prices[len-1];
        for(int i = 1; i < len; i++) {
            if(prices[i] < left[i-1]) {
                left[i] = prices[i];
            } else {
                left[i] = left[i-1];
            }

            if(right[len-i] > prices[len-i-1]) {
                right[len-i-1] = right[len-i];
            } else {
                right[len-i-1] = prices[len-i-1];
            }
        }

        int max = right[0]-left[0];
        for(int i = 1; i < len; i++) {
            if(right[i]-left[i] > max) {
                max = right[i]-left[i];
            }
        }

        return max;
    }
};

// 2nd solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int min = prices[0];
        int max = prices[0];
        int res = 0;

        for(int i = 1; i < len; i++) {
            if(prices[i] < min) {
                min = prices[i];
                max = prices[i];
            } else if(prices[i] > max){
                max = prices[i];
            }

            if(res < max-min) {
                res = max-min;
            }
        }

        return res;
    }
};