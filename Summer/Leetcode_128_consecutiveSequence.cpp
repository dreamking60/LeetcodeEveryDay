class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if(nums.size() == 0) {
                return 0;
            }
    
            unordered_set<int> s;
            int next = 0;
            int max = 1;
            int tmp = 0;
    
    
            for(int i = 0; i < nums.size(); i++) {
                if(!s.count(nums[i])) {
                    s.insert(nums[i]);
                }
            }
    
            for(int n : s) {
                if(s.find(n-1) == s.end()) {
                    tmp = 0;
                    while(s.count(n++)) {
                        tmp++;
                    }
                    if(tmp > max) {
                        max = tmp;
                    }
                }
            }  
    
            return max;
        }
    };