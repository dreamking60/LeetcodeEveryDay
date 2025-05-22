class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            const char * p_cstr = pattern.c_str();
            unordered_map<char, string> pTos;
            unordered_map<string, char> sTop;
            int len = pattern.length();
            istringstream iss(s);
            string w;
            vector<string> res;
    
            while(iss >> w) {
                res.push_back(w);
            }
    
            if(res.size() != len) {
                return false;
            }
    
            for(int i = 0; i < len; i++) {
                if(!pTos.count(p_cstr[i])) {
                    if(!sTop.count(res[i])) {
                        pTos[p_cstr[i]] = res[i];
                        sTop[res[i]] = p_cstr[i];
                    } else {
                        return false;
                    }
                } else if(pTos[p_cstr[i]] != res[i]){
                    return false;
                }
            }
            
            return true;
        }
    };