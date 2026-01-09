// Good Solution
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }

        return dp[n];
    }
};

// Bad solution
class Solution {
    bool isSquare(int num) {
        if(num < 0) return false;

        int t = round(sqrt(num));
        return t * t == num;
    }

public:
    int numSquares(int n) {
        vector<int> minNum;
        minNum.push_back(1);
        minNum.push_back(1);
        int min = 0;

        for(int i = 2; i <= n; i++) {
            if(isSquare(i)) {
                minNum.push_back(1);
                continue;
            }
            min = minNum[1] + minNum[i-1];
            for(int j = 2; j <= i/2; j++) {
                if(minNum[j] + minNum[i-j] < min) {
                    min = minNum[j] + minNum[i-j];
                }
            }
            minNum.push_back(min);
        }

        return minNum[n];
    }
};