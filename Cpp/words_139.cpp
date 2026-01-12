class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), s.size()+1);
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < wordDict.size(); j++) {
                if(i+wordDict[j].size()-1 < s.size()) {
                    string sub = s.substr(i, wordDict[j].size());
                    if(sub == wordDict[j]) {
                        if(i == 0) {
                            dp[i+wordDict[j].size()-1] = 1;
                            continue;
                        }
                        dp[i+wordDict[j].size()-1] = min(dp[i+wordDict[j].size()-1], dp[i-1] + 1);
                    }
                }
            }
        }
        if(dp[s.size()-1] != s.size()+1) {
            return true;
        }
        return false;
    }
};