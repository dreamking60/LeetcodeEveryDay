// Leetcode 221: Maximal Square
// https://leetcode.com/problems/maximal-square/

// 1. DP O(mn)
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            int dp[300][300];
            int max;
    
            dp[0][0] = (matrix[0][0] == '1') ? 1 : 0;
            max = dp[0][0];
            for(int j = 1; j < n; j++) {
                if(matrix[0][j] == '1') {
                    dp[0][j] = 1;
                    max = dp[0][j];
                } else {
                    dp[0][j] = 0;
                }
            }
            for(int i = 1; i < m; i++) {
                if(matrix[i][0] == '1') {
                    dp[i][0] = 1;
                    if(dp[i][0] > max) {
                        max = dp[i][0];
                    }
                } else {
                    dp[i][0] = 0;
                }
                for(int j = 1; j < n; j++) {
                    if(matrix[i][j] == '1') {
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                        if(dp[i][j] > max) {
                            max = dp[i][j];
                        }
                    } else {
                        dp[i][j] = 0;               
                    }
                }
            }
    
            return max * max;  
        }
    
    };