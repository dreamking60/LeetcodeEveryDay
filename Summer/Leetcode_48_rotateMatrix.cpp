class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int len = matrix.size();
            int pre = 0;
            int mid = 0;
            int x = 0;
            int y = 0;
            int SpinI = 0;
            int SpinJ = 0;
            int times = 4;
            
            for(int i = 0; i < len/2; i++) {
                for(int j = i; j < len-i-1; j++) {
                    times = 4;
                    x = j;
                    y = i;
                    pre = matrix[i][j];
                    while(times-- > 0) {
                        SpinJ = (len-1) - y;
                        SpinI = x;
    
                        mid = matrix[SpinI][SpinJ];
                        matrix[SpinI][SpinJ] = pre;
                        pre = mid;
    
                        x = SpinJ;
                        y = SpinI;
                    }
                }
            }
        }
    };