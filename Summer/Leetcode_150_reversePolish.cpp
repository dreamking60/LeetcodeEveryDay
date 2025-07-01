class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> val;
            int a, b, c;
            char p;
            
            for(int i = 0; i < tokens.size(); i++) {
                if(tokens[i] == "+" || tokens[i] == "-" ||
                   tokens[i] == "*" || tokens[i] == "/") {
                    a = val.top();
                    val.pop();
                    b = val.top();
                    val.pop();
                    p = tokens[i].c_str()[0];
                    switch(p) {
                        case '+':
                            c = b+a;
                            break;
                        case '-':
                            c = b-a;
                            break;
                        case '*':
                            c = b*a;
                            break;
                        case '/':
                            c = b/a;
                            break;
                    }
                    val.push(c);
                } else {
                    val.push(stoi(tokens[i]));
                }
            }
    
            return val.top();
        }
    
    };