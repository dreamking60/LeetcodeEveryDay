public class findStr_28 {
    public int strStr(String haystack, String needle) {
        char[] hay_char = haystack.toCharArray();
        char[] ndl_char = needle.toCharArray();

        int hay_len = hay_char.length;
        int ndl_len = ndl_char.length;
        int[] next = new int[ndl_len];

        for(int i  = 0; i < ndl_len; i++) {
            if(i == 0) {
                next[i] = -1;
            } else {
                int j = next[i-1];
                while(j >= 0 && ndl_char[i] != ndl_char[j+1]) {
                    j = next[j];
                }
                if(ndl_char[i] == ndl_char[j+1]) {
                    next[i] = j+1;
                } else {
                    next[i] = -1;
                }
            }
        }

        int j = -1;
        for(int i = 0; i < hay_len; i++) {
            while(j >= 0 && hay_char[i] != ndl_char[j+1]) {
                j = next[j];
            }
            if(hay_char[i] == ndl_char[j+1]) {
                j++;
            }
            if(j == ndl_len-1) {
                return i-ndl_len+1;
            }
        }

        return -1;
    }
}
