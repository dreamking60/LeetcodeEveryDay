class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            int size = intervals.size();
            vector<int> a;
            vector<int> b;
            vector<vector<int>> res;
    
            int i = 0;
            while(i < size && intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
                i++;
            }
    
            while(i < size && intervals[i][0] <= newInterval[1]) {
                newInterval[0] = (intervals[i][0] < newInterval[0]) ? intervals[i][0] : newInterval[0];
                newInterval[1] = (intervals[i][1] > newInterval[1]) ? intervals[i][1] : newInterval[1];
                i++;
            }
            res.push_back(newInterval);
    
            while(i < size && intervals[i][0] > newInterval[1]) {
                res.push_back(intervals[i]);
                i++;
            }
    
            return res;
        }
    };