class Solution {
    public:
    long long fast_pow(long long base, long long exp, long long mod) {
        long long result = 1;
        while(exp > 0) {
            if( exp % 2 == 1 ) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    
    // Calculate C(n, k) % mod
    // Use Fermat's little theorem to calculate the modular inverse
    long long mod_comb(int n, int k, long long mod) {
        long long c_up = 1;
        long long c_down = 1;
        for(int i = 0; i < k; i++) {
            c_up = (c_up * (n-i)) % mod;
            c_down = (c_down * (i+1)) % mod;
        }

        return (c_up * fast_pow(c_down, mod-2, mod)) % mod;
    }
    
    int countGoodArrays(int n, int m, int k) {
        const long long mod = 1000000007;
        
        if(n == k+1) {
            return m % mod;
        }

        long long select = mod_comb(n-1, k, mod);

        long long res = (m * select) % mod;
        res = (res * fast_pow(m-1, n-1-k, mod)) % mod;

        return res;
    }

};