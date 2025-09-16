#include <iostream>
#include <set>
using namespace std;

int C(long long n, long long m) {
    long long res = 1;
    long long k = 1;
    if(n > m / 2) {
        n = m - n;
    }
    while(k <= n) {
        res = (res * (m-k+1) / k) % 1000000007;
        k++;
    }
    return res;
}

int main() {
    int T, n, a, b, c;
    int min;
    int moda, modb, modc;
    int tp1, tp2;
    long long count = 0;
    long long res1, res2;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> n >> a >> b >> c;
        min = (a > b) ? b : a;
        min = (min > c) ? c : min;
        for(int i = 1; i <= n; i++) {
            count = 0;
            if(i < min) {
                cout << 0 << " ";
                continue;
            }
            moda = -1;
            modb = -1;
            modc = -1;
            count = 0;
            if(a <= i) {
                moda = i % a;
            }
            if(b <= i) {
                modb = i % b;
            }
            if(c <= i) {
                modc = i % c;
            }
            if(moda == 0) {
                count++;
            } 
            if(modc == 0) {
                count++;
            }
            if(modb == 0) {
                count++;
                if(moda == 0) {
                    tp1 = i / a;
                    for(int j = 1; j < tp1; j++) {
                        if((i-a*j) % b == 0) {
                            count = (count + C(j, j+(i-a*j)/b)) % 1000000007;
                        }
                    }
                }
                if(modc == 0) {
                    tp2 = i / c;
                    for(int j = 1; j < tp2; j++) {
                        if((i-c*j) % b == 0) {
                            count = (count + C(j, j+(i-c*j)/b)) % 1000000007;
                        }
                    }
                }
                if(moda == 0 && modc == 0) {
                    for(int j = 1; j < tp1; j++) {
                        tp2 = (i-j*a) / c;
                        for(int m = 1; m < tp2; m++) {
                            if((i-j*a-m*c) % b == 0) {
                                res1 = C(j, j+m+(i-j*a-m*c) / b) % 1000000007;
                                res2 = C(m, m+(i-j*a-m*c) / b) % 1000000007;
                                count = (count + (res1 * res2) % 1000000007) % 1000000007;
                            }
                        }
                    }
                }
            } else if(modb > 0) {
                if(moda > 0) {
                    tp1 = i / a;
                    for(int j = 1; j < tp1; j++) {
                        if((i-a*j) % b == 0) {
                            count = (count + C(j, j+(i-a*j)/b)) % 1000000007;
                        }
                    }
                }
                if(modc > 0) {
                    tp2 = i / c;
                    for(int j = 1; j < tp2; j++) {
                        if((i-c*j) % b == 0) {
                            count = (count + C(j, j+(i-c*j)/b)) % 1000000007;
                        }
                    }
                }
                if(moda > 0 || modc > 0) {
                    for(int j = 1; j < tp1; j++) {
                        tp2 = (i-j*a) / c;
                        for(int m = 1; m < tp2; m++) {
                            if((i-j*a-m*c) % b == 0) {
                                res1 = C(j, j+m+(i-j*a-m*c) / b) % 1000000007;
                                res2 = C(m, m+(i-j*a-m*c) / b) % 1000000007;
                                count = (count + (res1 * res2) % 1000000007) % 1000000007;
                            }
                        }
                    }
                }
            }
            cout << count << " ";
        }
        cout << endl;
    }
    
    return 0;
}