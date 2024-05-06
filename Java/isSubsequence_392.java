public class isSubsequence_392 {
    public boolean isSubsequence(String s, String t) {
        char[] t_char = t.toCharArray();
        char[] s_char = s.toCharArray();

        int i = 0;
        int j = 0;
        while(i < s_char.length && j < t_char.length) {
            if(s_char[i] == t_char[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        if(i == s_char.length) {
            return true;
        } else {
            return false;
        }
    }
}
