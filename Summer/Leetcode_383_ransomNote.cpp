class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            unordered_map<char, int> rn;
            const char * rn_cstr = ransomNote.c_str();
            const char * mz_cstr = magazine.c_str();
            int tmp = 0;
    
            for(int i = 0; i < ransomNote.length(); i++) {
                rn[rn_cstr[i]]++;
            }
    
            for(int i = 0; i < magazine.length(); i++) {
                if(rn.count(mz_cstr[i])) {
                    rn[mz_cstr[i]]--;
                    if(rn[mz_cstr[i]] == 0) {
                        rn.erase(mz_cstr[i]);
                    }
                }
            }
    
            if(rn.empty())
            {
                return true;
            }
            
            return false;
        }
    };