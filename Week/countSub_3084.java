package Week;

public class countSub_3084 {
    public long countSubstrings(String s, char c) {
        long count = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s.charAt(i) == c) {
                count++;
            }
        }
        return count * (count + 1) / 2;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)
}
