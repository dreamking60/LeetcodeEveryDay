public class longestCommonPrefix_14 {
    public String longestCommonPrefix(String[] strs) {
        int i = 0;
        int len = strs[0].length();
        int len_strs = strs.length; 
        for(; i < len; i++) {
            char c = strs[0].charAt(i);
            for(int j = 1; j < len_strs; j++) {
                if(i == strs[j].length() || strs[j].charAt(i) != c) {
                    return strs[0].substring(0, i);
                }
            }
        }

        return strs[0].substring(0, i);
    }
}
