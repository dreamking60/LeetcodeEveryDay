public class validPalindrome_125 {
    public boolean isPalindrome(String s) {
        char[] s_char = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase().toCharArray();
        int i = 0;
        int j = s_char.length-1; 

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