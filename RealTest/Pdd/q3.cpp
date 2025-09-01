#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    int n, m;
    long long k;
    vector<vector<int>> C;
    cin >> n;
    cin >> m;
    cin >> k;

    string s1, s2;
    cin >> s1;
    cin >> s2;

    const char * c1 = s1.c_str();
    const char * c2 = s2.c_str();

    for(int i = 0; i < n; i++) {
        vector<int> tmp;
        for(int j = 0; j < m; j++) {
            if(c1[i] == 'a' && c1[i] == c2[j]) {
                tmp.push_back(1);
            } else {
                tmp.push_back(0);
            }
        }
        C.push_back(tmp);
    }

    vector<int> col;
    int ra = 0;
    int co = 1;
    int count = 0;
    for(int i = 0; i < n; i++) {
        ra = 0;
        for(int j = 0; j < m; j++) {
            if(C[i][j] == 1) {
                ra++;
                if(col.size() < m) {
                    col.push_back(1);
                } else {
                    col[j]++;
                }
            } else {
                if(ra >= k) {
                    count += k-ra+1;
                }
                ra = 0;

                if(col.size() < m) {
                    col.push_back(0);
                } else {
                    if(col[j] >= k) {
                        count += k-col[i]+1;
                        col[j] = 0;
                    } else {
                        col[j] = 0;
                    }
                }            
            }
        }
    }

    for(int i = 0; i < m; i++) {
        if(col[i] >= k) {
            count += col[i]-k+1;
        }
    }
    
    vector<vector<int>> Cr(C);
    vector<vector<int>> Cc(C);
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {
            if(j == 0) {
                
            }
            if(Cr[i][j] == 1 && Cr[i][j-1] >= 1) {
                Cr[i][j] = Cr[i][j-1] + 1;
            }
        }
    }

    cout << count << endl;
    
}
// 64 位输出请用 printf("%lld")

// 精彩的行列拆分处理！降维。
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// 统计字符串 s 中，字符 'a' 构成的一维布尔串里：
// 对每个长度 h(1..|s|)，“长度恰为 h 的全 'a' 子段”的个数。
// 思路：每个最大连续段长 L 对 h=1..L 的贡献是 (L - h + 1) = (-1)*h + (L+1)
// 用线性差分在 O(|s|) 内一次性加完所有段的等差数列贡献。
static vector<int64> count_exact_all_lengths(const string& s) {
    int n = (int)s.size();
    vector<int> runs; runs.reserve(n);
    for (int i = 0; i < n; ) {
        if (s[i] != 'a') { ++i; continue; }
        int j = i;
        while (j < n && s[j] == 'a') ++j;
        runs.push_back(j - i);
        i = j;
    }
    // freq[h] = P_ps[h]*h + Q_ps[h]
    vector<int64> P(n + 2, 0), Q(n + 2, 0);
    for (int L : runs) {
        // 对区间 h ∈ [1, L] 加 v(h) = (-1)*h + (L+1)
        P[1]       += -1;    P[L + 1]   -= -1;
        Q[1]       += (L+1); Q[L + 1]   -= (L+1);
    }
    vector<int64> freq(n + 1, 0);
    for (int h = 1; h <= n; ++h) {
        P[h] += P[h - 1];
        Q[h] += Q[h - 1];
        freq[h] = P[h] * h + Q[h];
    }
    return freq; // 下标 1..n 有效
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;
    string s1, s2;
    cin >> s1 >> s2;   // |s1|=n, |s2|=m

    // 快速无解
    if (k > 1LL * n * m) {
        cout << 0 << "\n";
        return 0;
    }

    // 预处理：行/列方向，长度恰为 h 的全 'a' 子段个数
    vector<int64> cntRow = count_exact_all_lengths(s1); // 1..n
    vector<int64> cntCol = count_exact_all_lengths(s2); // 1..m

    long long ans = 0;
    for (long long h = 1; h * h <= k; ++h) {
        if (k % h) continue;
        long long w = k / h;

        if (h <= n && w <= m) ans += cntRow[(int)h] * cntCol[(int)w];
        if (h != w) { // 对称另一对
            if (w <= n && h <= m) ans += cntRow[(int)w] * cntCol[(int)h];
        }
    }

    cout << ans << "\n";
    return 0;
}
