class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> key = new HashMap<>();
        int len = fruits.length;
        int max = 0;
        int j = 0;
        for(int i = 0; i < len; i++) {
            key.put(fruits[i], key.getOrDefault(fruits[i], 0)+1);
            while(key.size() > 2) {
                key.put(fruits[j], key.get(fruits[j])-1);
                if(key.get(fruits[j]) == 0) {
                    key.remove(fruits[j]);
                }
                j++;
            }
            if(max < i-j+1) {
                max = i-j+1;
            }
        }
        return max;

    }
}