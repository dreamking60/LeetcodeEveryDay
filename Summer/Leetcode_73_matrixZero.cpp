class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int raw_len = matrix.size();
            int col_len = matrix[0].size();
    
            vector<int> raw(raw_len);
            vector<int> col(col_len);
    
            for(int i = 0; i < raw_len; i++) {
                for(int j = 0; j < col_len; j++) {
                    if (matrix[i][j] == 0) {
                        raw[i] = 1;
                        col[j] = 1;
                    }
                }
            }
    
            for(int i = 0; i < raw_len; i++) {
                for(int j = 0; j < col_len; j++) {
                    if(raw[i] == 1 || col[j] == 1) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    };