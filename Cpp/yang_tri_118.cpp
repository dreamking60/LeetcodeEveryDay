class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> row1;
        row1.push_back(1);
        res.push_back(row1);

        for(int i = 1; i < numRows; i++) {
            vector<int> raw;
            raw.push_back(1);
            for(int j = 1; j < i; j++) {
                raw.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            raw.push_back(1);
            res.push_back(raw);
        }

        return res;
    }
};
