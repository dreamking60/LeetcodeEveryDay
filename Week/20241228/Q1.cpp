#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int base = 0;
        int operation = 0;

        for(int j = 0; j < n; j++) {
            base = grid[0][j];
            for(int i = 1; i < m; i++) {
                if(base >= grid[i][j]) {
                    operation += base - grid[i][j] + 1;
                    grid[i][j] = base + 1;
                }
                base = grid[i][j];
            }
        }

        return operation;
    }
};