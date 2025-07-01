class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& points) {
            sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
                return a[0] < b[0];
            });
    
            vector<vector<int>> res;
            vector<int> tmp;
            res.push_back(points[0]);
    
            for(int i = 1; i  < points.size(); i++) {
                tmp = res[res.size()-1];
                if(tmp[1] >= points[i][0]) {
                    res[res.size()-1][0] = points[i][0];
                    res[res.size()-1][1] = (points[i][1] < tmp[1]) ? points[i][1] : tmp[1];
                } else {
                    res.push_back(points[i]);
                }
            }
    
            return res.size();
        }
    };