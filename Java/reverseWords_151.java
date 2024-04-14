public class reverseWords_151 {
    public String reverseWords(String s) {
        // Use built-in function
        String[] words = s.trim().split("\\s+");
        StringBuilder sb = new StringBuilder();
        for(int i = words.length-1; i >= 0; i--) {
            sb.append(words[i]);
            if(i != 0) {
                sb.append(" ");
            }
        }
        return sb.toString();
    }

    public String reverseWords_2(String s) {
        // Not use built-in function
        char[] s_char = s.toCharArray();
        int len = s_char.length;
        int start = 0;
        int end = len-1;
        while(start < len && s_char[start] == ' ') {
            start++;
        }
        while(end >= 0 && s_char[end] == ' ') {
            end--;
        }
        if(start > end) {
            return "";
        }

        StringBuilder sb = new StringBuilder();
        int w_end = 0;
        int w_len = 0;
        for(int i = start; i <= end; i++) {
            if(s_char[i] != ' ') {
                sb.insert(w_end, s_char[i]);
                w_len++;
            } else {
                if(w_len != 0) {
                    sb.append(' ');
                    w_end += w_len+1;
                    w_len = 0;
                }
            }
        }
        return sb.reverse().toString();

    }
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    public static void main(String[] args) {
        String s = "the sky is blue";
        char[] s_char = s.toCharArray();

        StringBuilder sb = new StringBuilder();
        int w_end = 0;
        int w_len = 0;
        for(int i = 0; i < s_char.length; i++) {
            if(s_char[i] != ' ') {
                sb.insert(w_end, s_char[i]);
                w_len++;
            } else {
                if(w_len != 0) {
                    sb.append(' ');
                    w_end += w_len+1;
                    w_len = 0;
                }
            }
        }
        System.out.println(sb.reverse().toString());
    }
}
