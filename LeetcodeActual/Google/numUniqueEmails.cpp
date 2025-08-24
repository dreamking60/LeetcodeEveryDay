#include <set>
#include <string>
#include <vector>
using namespace std;

// Solution 1
// Note good for time and c-style string using.
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        int size = emails.size();
        int len = 0;
        string res;
        int name = 0;
        int add = 0;
        const char *e;
        for(int i = 0; i < size; i++) {
            e = emails[i].c_str();
            len = emails[i].length();
            res = "";
            name = 0;
            add = 0;
            for(int j = 0; j < len; j++) {
                if(name == 0 && add == 0) {
                    if(e[j] == '@') {
                        name = 1;
                        res = res + e[j];
                    } else if(e[j] == '+'){
                        add = 1;
                    } else if(e[j] == '.'){
                        continue;
                    } else {
                        res = res + e[j];
                    }
                } else if(name == 0 && add == 1){
                    if(e[j] == '@') {
                        name = 1;
                        res = res + e[j];
                    }
                } else {
                    res = res + e[j];
                }
            }
            s.insert(res);
        }
        return s.size();
    }
};

// Solution 2
class Solution {
    public:
        int numUniqueEmails(vector<string>& emails) {
            set<string> s;
            for(string e : emails) {
                string username = "";
                string domain = "";
                size_t pos = e.find('@');
                
                for(char c : e) {
                    if(c == '+' || c == '@') {
                        break;
                    } else if(c == '.') {
                        continue;
                    } else {
                        username = username + c;
                    }
                }
                domain = e.substr(pos);
                s.insert(username+domain);
            }
            
            return s.size();
        }
    };