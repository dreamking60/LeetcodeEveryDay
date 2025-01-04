class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        const long long MOD = 1000000007;

        // 快速幂计算 (a^b) % MOD
        auto mod_pow = [](long long base, long long exp, long long mod) -> long long {
            long long result = 1;
            while (exp > 0) {
                if (exp % 2 == 1) {
                    result = (result * base) % mod;
                }
                base = (base * base) % mod;
                exp /= 2;
            }
            return result;
        };

        // 组合数计算 C(n, k) % MOD，使用快速幂求模逆元
        auto mod_comb = [&](int n, int k, long long mod) -> long long {
            long long numerator = 1;  // 分子
            long long denominator = 1;  // 分母
            for (int i = 0; i < k; i++) {
                numerator = (numerator * (n - i)) % mod;
                denominator = (denominator * (i + 1)) % mod;
            }
            return (numerator * mod_pow(denominator, mod - 2, mod)) % mod; // 费马小定理
        };

        // 特殊情况：如果 n == k + 1
        if (n == k + 1) {
            return m % MOD;
        }

        // 计算 C(n-1, k) % MOD
        long long select = mod_comb(n - 1, k, MOD);

        // 计算最终结果
        long long res = (m * select) % MOD;  // m * C(n-1, k)
        res = (res * mod_pow(m - 1, n - 1 - k, MOD)) % MOD;  // m * C(n-1, k) * (m-1)^(n-1-k)

        return (int)res;
    }
};
