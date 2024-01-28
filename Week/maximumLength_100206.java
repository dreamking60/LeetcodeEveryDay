package Week;

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maximumLength(int[] nums) {
        Map<Integer, Integer> key = new HashMap<>();
        int n = nums.length;
        int max = 1;
        int next = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            key.put(nums[i], key.getOrDefault(nums[i],0)+1);
        }
        for(int k : key.keySet()) {
            if(k == 1) {
                count = key.get(k);
                if(count % 2 == 0) {
                    count -= 1;
                }
                if(count > max) {
                    max = count;
                }
                continue;
            }
            if(key.get(k) >= 2) {
                next = k*k;
                count = 1;
                while(key.containsKey(next)) {
                    count += 2;
                    if(key.get(next) < 2) {
                       break;
                    }
                    next = next * next;
                }
                if(count > max) {
                    max = count;
                }
            }
        }
        return max;
    }
}