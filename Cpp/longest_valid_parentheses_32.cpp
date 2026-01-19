class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0, left = 0, right = 0;
        int jump = 0;
        const char * ss = s.c_str();
        for(int i = 0; i < s.size(); i++) {
            if(ss[i] == '(') {
                left++;
            } else {
                right++;
            }
            if(right > left) {
                left = 0;
                right = 0;
                jump = 0;
            } else if(right == left && max < right * 2) {
                max = right * 2;
            }
        }

        left = 0;
        right = 0;
        for(int i = s.size()-1; i >= 0; i--) {
            if(ss[i] == '(') {
                left++;
            } else {
                right++;
            }
            if(left > right) {
                left = 0;
                right = 0;
                jump = 0;
            } else if(right == left && max < left * 2) {
                max = left * 2;
            }
        }
        

        return max;
    }
};