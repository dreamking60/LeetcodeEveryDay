#include <iostream>
using namespace std;

unsigned long long k1, k2;

void setSeed(unsigned long long a, unsigned long long b) {
    k1 = a;
    k2 = b;
}

unsigned long long f() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);

    return k2 + k4;
}

unsigned long long solve(unsigned long long a, unsigned long long b, unsigned long long n) {
    setSeed(a, b);
    for(a = 0; a != n; ++a) {
        b = f();
    }
    return b;
}

int main() {
    int T;
    unsigned long long a, b, n;
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        cin >> a;
        cin >> b;
        cin >> n;

        cout << solve(a,b,n) << endl;
    }

    return 0;

}
// 64 位输出请用 printf("%lld")