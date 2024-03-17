import java.util.HashMap;
import java.util.Map;

public class minDeletion_3085 {
    public int minimumDeletions(String word, int k) {
        int n = word.length();
        int[] freq = new int[26];
        for(int i = 0; i < n; i++) {
            freq[word.charAt(i) - 'a']++;
        }
        Map<Integer, Integer> map = new HashMap<>();
        int maxFreq = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                map.put(freq[i], map.getOrDefault(freq[i], 0) + 1);
            }
            maxFreq = Math.max(maxFreq, freq[i]);
        }
        
        int max = 0;
        int count = 0;
        for(int i = 0; i <= maxFreq; i++) {
            count = 0;
            for(int ch: map.keySet()) {
                if(i-ch <= k && i-ch >= 0) {
                    count += map.get(ch)*ch;
                } else if(ch-i > 0){
                    count += map.get(ch)*i;
                }
            }
            if(count > max) {
                max = count;
            }
        }


        return n-max;
    }

    // Time complexity: O(n)
    // Space complexity: O(1)
}
