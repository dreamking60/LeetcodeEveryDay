class Solution {
    public:
        string simplifyPath(string path) {
            stack<string> ss;
            const char * cc = path.c_str();
            int i = 0;
            int begin = 0;
            int end = 0;
    
            while(i < path.length()) {
                if(cc[i] == '/') {
                    if(begin != end) {
                        string sub = path.substr(begin+1, end-begin);
                        if(sub == "..") {
                            if(!ss.empty()) {
                                ss.pop();
                            }
                        } else if(sub != ".") {
                            ss.push(sub);
                        }
                    }
                    begin = i;
                    end = i;
                } else {
                    end++;
                }
                i++;
            }
            if(begin != end) {
                string sub = path.substr(begin+1, end-begin);
                if(sub == "..") {
                    if(!ss.empty()) {
                        ss.pop();
                    }
                } else if(sub != ".") {
                    ss.push(sub);
                }
            }
    
            if(ss.empty()) {
                return "/";
            }
            string s = "";
            while(!ss.empty()) {
                s = "/" + ss.top() + s;
                ss.pop();
            }
    
            return s;
        }
    };