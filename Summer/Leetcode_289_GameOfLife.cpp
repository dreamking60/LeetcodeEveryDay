class Solution {
    public:
        void gameOfLife(vector<vector<int>>& board) {
            int raw_len = board.size();
            int col_len = board[0].size();
            int neighbour[25][25] = {0};
    
            for(int i = 0; i < raw_len; i++) {
                for(int j = 0; j < col_len; j++) {
                    if(board[i][j] == 1) {
                        for(int t = Max(0, i-1); t <= Min(raw_len-1, i+1); t++) {
                            for(int s = Max(0, j-1); s <= Min(col_len-1, j+1); s++) {
                                if(!(t == i && s ==j)) {
                                    neighbour[t][s]++;
                                }
                            }
                        }
                    }
                }
            }
    
            for(int i = 0; i < raw_len; i++) {
                for(int j = 0; j < col_len; j++) {
                    if(neighbour[i][j] < 2 || neighbour[i][j] > 3) {
                        board[i][j] = 0;
                    } else if(neighbour[i][j] == 3){
                        board[i][j] = 1;
                    }
                }
            }
        }
    
        int Min(int a, int b) {
            return (a < b)? a : b;
        }
    
        int Max(int a, int b) {
            return (a > b)? a : b;
        }
    };