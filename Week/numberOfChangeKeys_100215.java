package Week;
class Solution {
    public int countKeyChanges(String s) {
        char pre = Character.toUpperCase(s.charAt(0));
        int count = 0;
        for(char c: s.toCharArray()) {
            if(Character.toUpperCase(c) != pre) {
                count++;
                pre = Character.toUpperCase(c);
            }
        }
        return count;
    }
}