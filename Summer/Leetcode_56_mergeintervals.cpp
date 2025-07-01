class Solution {

    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>> res;
            sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b){
                return a[0] < b[0];
            });
    
            res.push_back(intervals[0]);
            int j = 0;
    
            for(int i = 1; i < intervals.size(); i++) {
                if(res[j][1] < intervals[i][0]) {
                    res.push_back(intervals[i]);
                    j++;
                } else if(res[j][1] < intervals[i][1]) {
                    res[j][1] = intervals[i][1];
                }
            }
            
            return res;
        }
    };