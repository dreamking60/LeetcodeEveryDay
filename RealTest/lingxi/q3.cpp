#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int start = 0;

    for (int i = 0; i <= n; i++) {
        // 遇到坏边或到数组末尾 -> 切分一段
        if (i == n || (i > 0 && llabs(a[i] - a[i-1]) > k)) {
            if (i > start) {
                long long sum = 0;
                for (int j = start; j < i; j++) sum += a[j];
                int len = i - start;

                if (sum % 2 == 0) {
                    ans = max(ans, len);
                } else {
                    int leftOdd = -1, rightOdd = -1;
                    for (int j = start; j < i; j++) {
                        if (a[j] % 2 != 0) { leftOdd = j; break; }
                    }
                    for (int j = i-1; j >= start; j--) {
                        if (a[j] % 2 != 0) { rightOdd = j; break; }
                    }
                    if (leftOdd != -1)
                        ans = max(ans, len - (leftOdd - start + 1));
                    if (rightOdd != -1)
                        ans = max(ans, len - (i-1 - rightOdd + 1));
                }
            }
            start = i;
        }
    }

    cout << ans << "\n";
    return 0;
}
