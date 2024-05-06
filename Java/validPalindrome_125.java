public class validPalindrome_125 {
    public boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length()-1; 
        char[] s_char = s.toCharArray();

        while(i <= j) {
            if(s_char[i] != s_char[j]) {
                return false;
            } else {
                i++;
                j--;
            }
        }

        return true;
    }
}