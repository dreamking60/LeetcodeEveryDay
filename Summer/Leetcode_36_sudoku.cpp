// Solution 1
class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            int tmp = 0;
            for(int j = 0; j < 9; j++) {
                int valid[9] = {0};
                for(int i = 0; i < 9; i++) {
                    if(board[j][i] <= '9' && board[j][i] >= '1') {
                        tmp = board[j][i] - '1';
                    } else {
                        continue;
                    }
                    if(valid[tmp] == 0) {
                        valid[tmp] = 1;
                    } else {
                        return false;
                    }
                }
            }
    
            for(int i = 0; i < 9; i++) {
                int valid[9] = {0};
                for(int j = 0; j < 9; j++)
                {
                    if(board[j][i] <= '9' && board[j][i] >= '1') {
                        tmp = board[j][i] - '1';
                    } else {
                        continue;
                    }
                    if(valid[tmp] == 0) {
                        valid[tmp] = 1;
                    } else {
                        return false;
                    }
                }
            }
    
    
            int valid[9][9] = {0};
            int index = 0;
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 9; j++) {
                    index = (i/3) * 3 + j/3;
                    if(board[j][i] <= '9' && board[j][i] >= '1') {
                        tmp = board[j][i] - '1';
                    } else {
                        continue;
                    }                
                    if(valid[index][tmp] == 0) {
                        valid[index][tmp] = 1;
                    } else {
                        return false;
                    }            
                }
            }
    
    
            return true;
    
        }
    };

// Solution 2
class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            unordered_set<char> raw[9];
            unordered_set<char> col[9];
            unordered_set<char> mtr[9];
            int index = 0;
            int tmp = 0;
    
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 9; j++) {
                    if(board[i][j] == '.') {
                        continue;
                    }
                    tmp = board[i][j] - '1';
                    index = (i/3) * 3 + (j/3);
        
                    if(!raw[i].count(tmp)) {
                        raw[i].insert(tmp);
                    } else {
                        return false;
                    }
    
                    if(!col[j].count(tmp)) {
                        col[j].insert(tmp);
                    } else {
                        return false;
                    }
    
                    if(!mtr[index].count(tmp)) {
                        mtr[index].insert(tmp);
                    } else {
                        return false;
                    }
                }
    
            }
            
    
            return true;
    
        }
    };