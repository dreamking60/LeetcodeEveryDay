class Solution {
    public:
        bool isValid(string s) {
            stack<char> ss;
            const char * s_char = s.c_str();
    
            for(int i = 0; i < s.length(); i++) {
                switch(s_char[i]) {
                    case '(':
                    case '[':
                    case '{':
                        ss.push(s_char[i]);
                        break;
                    case ')':
                        if(ss.empty()) {
                            return false;
                        } else if(ss.top() != '(') {
                            return false;
                        } else {
                            ss.pop();
                            break;
                        }
                    case ']':
                        if(ss.empty()) {
                            return false;
                        } else if(ss.top() != '[') {
                            return false;
                        } else {
                            ss.pop();
                            break;
                        }
                    case '}':
                        if(ss.empty()) {
                            return false;
                        } else if(ss.top() != '{') {
                            return false;
                        } else {
                            ss.pop();
                            break;
                        } 
                }       
            }
            if(!ss.empty()) {
                return false;
            }
            return true;
        }
    };