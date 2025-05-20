class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            int num = 0;
            int prefix = 0;
            int len = words[0].length();
            vector<int> res;
    
            unordered_map<string, int> word_count;
            for(int i = 0; i < words.size(); i++)
            {
                word_count[words[i]]++;
            }
    
            for(int t = 0; t < len; t++)
            {
                num = 0;
                prefix = t;
                unordered_map<string, int> use_count;
                for(int j = t; j + len <= s.length(); j += len)
                {
                    string w = s.substr(j, len);
                    if(word_count.find(w) != word_count.end()) 
                    {
                        use_count[w]++;
                        while(use_count[w] > word_count[w]) {
                            string d = s.substr(prefix, len);
                            use_count[d]--;
                            prefix += len;
                            num--;
                        }
    
                        num += 1;
                        if(num == words.size())
                        {
                            res.push_back(prefix);
                            string d = s.substr(prefix, len);
                            use_count[d]--;
                            prefix += len;
                            num--;
                        }
                        
                    } else {
                        use_count.clear();
                        num = 0;
                        prefix = j+len;
                    }
                }
            }
    
    
            return res;
        }
    
    };