#include <vector>
using namespace std;

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> res;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i < row; i++) {
            if(i % 2 == 0) {
                for(int j = 0; j < col; j++) {
                    if(j % 2 == 0) {
                        res.push_back(grid[i][j]);
                    }
                }
            } else {
                for(int j = col-1; j >= 0; j--) {
                    if(j % 2 == 1) {
                        res.push_back(grid[i][j]);
                    }
                }
            }
        }
        return res;
    }
};