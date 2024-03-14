import java.util.HashMap;
import java.util.Map;

public class Solution {
    public String minWindow(String s, String t) {
        int len_s = s.length();
        int len_t = t.length();
        if(len_s < len_t) {
            return "";
        }

        Map<Character, Integer> t_map = new HashMap<>();
        for(char c: t.toCharArray()) {
            t_map.put(c, t_map.getOrDefault(c, 0)+1);
        }
        
        Map<Character, Integer> s_map = new HashMap<>();
        for(int i = 0; i < len_t; i++) {
            s_map.put(s.charAt(i), s_map.getOrDefault(s.charAt(i), 0)+1);
        }
        int prev = 0;
        int post = len_t;
        int min = Integer.MAX_VALUE;
        int min_prev = 0, min_post = 0;
        while(prev < post) {
            if(containMap(s_map, t_map)) {
                if(min > post-prev) {
                    min = post-prev;
                    min_prev = prev;
                    min_post = post;
                }
                s_map.put(s.charAt(prev), s_map.get(s.charAt(prev))-1);
                prev++;
            } else if(post < len_s){
                s_map.put(s.charAt(post), s_map.getOrDefault(s.charAt(post), 0)+1);
                post++;
            } else {
                return "";
            }
        }
        return s.substring(min_prev, min_post);
    }

    public boolean containMap(Map<Character, Integer> a, Map<Character, Integer> b) {
        for(char c: b.keySet()) {
            if(!a.containsKey(c)) {
                return false;
            }
            if(b.get(c) > a.get(c)) {
                return false;
            }
        }
        return true;
    }
}
