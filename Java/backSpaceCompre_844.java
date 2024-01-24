class Solution {
    // method1: 标准双指针
    public boolean backspaceCompare(String s, String t) {
        char[] s_char = s.toCharArray();
        char[] t_char = t.toCharArray();
        int s_num = 0;
        int t_num = 0;
        for(int i = 0; i < s_char.length; i++) {
            if(s_char[i] == '#') {
                if(s_num > 0) {
                    s_num--;
                }
            } else {
                s_char[s_num++] = s_char[i];
            }
        }
        for(int i = 0; i < t_char.length; i++) {
            if(t_char[i] == '#') {
                if(t_num > 0) {
                    t_num--;
                }
            } else {
                t_char[t_num++] = t_char[i];
            }
        }
        if(s_num != t_num) {
            return false;
        } else {
            for(int i = 0; i < s_num; i++) {
                if(s_char[i] != t_char[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    // method2: stack
    // 暂不提供细节

    // method3: 双指针，逆序
    public boolean backspaceCompare_2(String s, String t) {
        int i = s.length()-1;
        int j = t.length()-1;
        int tmp = 0;
        while(i >= 0 || j >= 0) {
            while(i >= 0) {
                if(s.charAt(i) == '#') {
                    tmp++;
                    i--;
                } else if(tmp > 0) {
                    i--;
                    tmp--;
                } else {
                    break;
                }
            }
            tmp = 0;
            while(j >= 0) {
                if(t.charAt(j) == '#') {
                    tmp++;
                    j--;
                } else if(tmp > 0) {
                    j--;
                    tmp--;
                } else {
                    break;
                }
            }
            if(i >= 0 && j >= 0 && s.charAt(i) != t.charAt(j)) {
                return false;
            }
            if((i < 0) ^ (j < 0)) {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
    // Time Complexity: O(n)
    // Space Complexity: O(1)
}