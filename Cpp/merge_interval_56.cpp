class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] < b[0]) {
                return true;
            } else if(a[0] == b[0] && a[1] < b[1]) {
                return true;
            } else {
                return false;
            }
        });

        vector<vector<int>> res;
        int j = 0;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if(res[j][1] >= intervals[i][0]) {
                res[j][1] = max(res[j][1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
                j++;
            }
        }

        return res;
    }
};