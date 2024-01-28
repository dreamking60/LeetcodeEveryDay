package Week;

class Solution {
    // Method1
    public long flowerGame_1(int n, int m) {
        long min = n < m ? n : m;
        long max = n > m ? n : m;
        long min_odd, min_even, max_odd, max_even;
        if(min % 2 == 0) {
            min_odd = min/2;
            min_even = min/2;
        } else {
            min_odd = min/2+1;
            min_even = min/2;
        }
        if(max % 2 == 0) {
            max_odd = max/2;
            max_even = max/2;
        } else {
            max_odd = max/2+1;
            max_even = max/2;
        }
        
        long res = min_odd * max_even + min_even * max_odd;
        return res;
    }
    // Time Complexity: O(1)
    // Space Complexity: O(1)

    //Method2
    public long flowerGame_2(int n, int m) {
        long[] n_sub = oddAndEven(n);
        long[] m_sub = oddAndEven(m);
        long res = n_sub[0] * m_sub[1] + n_sub[1] * m_sub[0];
        return res;
    }
    
    public long[] oddAndEven(int num) {
        if(num % 2 == 0) {
            return new long[]{num/2, num/2};
        } else {
            return new long[]{num/2+1, num/2};
        }
    }
    // Time Complexity: O(1)
    // Space Complexity: O(1)
}
