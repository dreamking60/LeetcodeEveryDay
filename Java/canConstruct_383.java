class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] letterR = new int[26];
        int[] letterM = new int[26];
        for(int i = 0; i < magazine.length(); i++) {
            letterM[magazine.charAt(i)-'a']++;
        }
        for(int i = 0; i < ransomNote.length(); i++) {
            letterR[ransomNote.charAt(i)-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(letterR[i] > letterM[i]) {
                return false;
            }
        }
        return true;
    }

        // Solution 2
    public boolean canConstruct_2(String ransomNote, String magazine) {
        if(ransomNote.length() > magazine.length()) {
            return false;
        }
        
        int[] letter = new int[26];
        for(char c : magazine.toCharArray()) {
            letter[c-'a']++;
        }
        for(char c : ransomNote.toCharArray()) {
            if(letter[c-'a'] == 0) {
                return false;
            } else {
                letter[c-'a']--;
            }
        }
        return true;
    }
}

// Space Complexity: O(1)
// Time Complexity: O(n)
// 99.18%