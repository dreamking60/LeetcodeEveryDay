public class lenOfLastWord_58 {
    public int lengthOfLastWord(String s) {
        char[] s_char = s.toCharArray();
        int len = s_char.length;
        int sum = 0;
        for(int i = len-1; i >= 0; i--) {
            if(s_char[i] == ' ') {
                if(sum == 0){
                    continue;
                } else {
                    break;
                }
            } else {
                sum++;
            }
        }

        return sum;
    }
}
