class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            unordered_map<char, char> chMap;
            int len = s.length();
            const char * s_char = s.c_str();
            const char * t_char = t.c_str();
            int alpha[120] = {0};
    
            for(int i = 0; i < len; i++) {
                if(!chMap.count(s_char[i])) {
                    if(alpha[t_char[i]-' '] == 1) {
                        return false;
                    }
                    chMap[s_char[i]] = t_char[i];
                    alpha[t_char[i]-' '] = 1;
                } else if(chMap[s_char[i]] != t_char[i]) {
                    return false;
                }
            }
    
            return true;
        }
    };