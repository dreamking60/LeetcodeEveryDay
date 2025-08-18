#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int gcd(int p, int q) {
    int t;

    if(p < q) {
        t = p;
        p = q;
        q = t;
    }

    t = p % q;
    if(t != 0) {
        return gcd(q, t);
    } else {
        return q;
    }

}

int testIfLimit(int q) {
    while(q % 2 == 0) {
        q = q / 2;
    }
    while(q % 5 == 0) {
        q = q / 5;
    }
    return q;
}

int main() {
    int T;
    int p, q, t, check;

    cin >> T;

    for(int i = 0; i < T; i++) {
        set<int> s;
        vector<int> v;
        vector<int> v2;
        cin >> p;
        cin >> q;
        if(p % q == 0) {
            cout << 0 << endl;
            continue;
        }
        if(q % p == 0) {
            q = q / p;
            p = p / p;
        }
        
        t = gcd(p, q);
        p = p / t;
        q = q / t;
        if(p > q) {
            p = p / q;
        }

        if(testIfLimit(q) == 1) {
            cout << 0 << endl;
        } else {
            do {
                p = p * 10;
                t = p % q;
                if(s.count(t) == 0) {
                    s.insert(t);
                    v.push_back(t);
                    v2.push_back(p/q);
                    p = t;
                } else {
                    check = 0;
                    for(int i = 0; i < v.size(); i++) {
                        if(check == 0 && v[i] == t) {
                            cout << v2[i];
                            check = 1;
                        } else if(check == 1){
                            cout << v2[i];
                        }
                    }
                    cout << endl;
                    break;
                }            
            } while(1);
        }

        // 3不成立，两自然数相除必不是无限不循环小数
    }

    return 0;
}




// 64 位输出请用 printf("%lld")