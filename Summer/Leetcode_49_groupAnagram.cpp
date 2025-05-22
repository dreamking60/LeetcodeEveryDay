class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> res;
            unordered_map<string, vector<string> > strMap;
            int len = strs.size();
    
            for(int i = 0; i < len; i++) {
                string ts(strs[i]);
                sort(ts.begin(), ts.end());            
                if(!strMap.count(ts)) {
                    vector<string> mid;
                    mid.push_back(strs[i]);
                    strMap[ts] = mid;
                } else {
                    strMap[ts].push_back(strs[i]);
                }
            }
            
            for(auto it = strMap.begin(); it != strMap.end(); it++) {
                res.push_back(it->second);
            }
    
            return res;
        }
    };