package Week;

import java.util.HashMap;
import java.util.Map;

public class findRevrseSub_3083 {
    public boolean isSubstringPresent(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        int n = s.length();
        Map<String, Integer> map = new HashMap<>();
        for(int i = 0; i < n-1; i++) {
            String sub = s.substring(i, i+2);
            map.put(sub, 1);
        }
        for(int i = 0; i < n-1; i++) {
            String sub = rev.substring(i, i+2);
            if(map.containsKey(sub)) {
                return true;
            }
        }

        return false;
    }
    // Time complexity: O(n)
    // Space complexity: O(n)
}
