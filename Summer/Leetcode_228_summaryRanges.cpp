class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            vector<string> res;
            int start = 0;
    
            if(nums.size() == 0) return res;
    
            for(int i = 1; i < nums.      size(); i++) {
                if(nums[i] != nums[i-1]+1) {
                    if(start != i-1) {
                        string s = to_string(nums[start]) + "->" + to_string(nums[i-1]);
                        res.push_back(s);
                    } else {
                        res.push_back(to_string(nums[start]));
                    }
                    start = i;
                }
            }
    
            if(start != nums.size()-1) {
                string s = to_string(nums[start]) + "->" + to_string(nums[nums.size()-1]);
                res.push_back(s);
            } else {
                res.push_back(to_string(nums[start]));
            }
    
            return res;
        }
    };