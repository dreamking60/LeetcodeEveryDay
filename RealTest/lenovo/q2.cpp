#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int T, n, total, max, tp, tt;
    cin >> T;
    for(int i = 0; i < T; i++) {
        vector<int> a;
        unordered_map<int, int> m;
        cin >> n;
        total = 0;
        for(int j = 0; j < n; j++) {
            cin >> tp;
            a.push_back(tp);
            if(m.count(tp) == 0) {
                m[tp] = 1;
            } else {
                m[tp]++;
            }
            total += tp;
        }
        
        if(total % 4 != 0) {
            cout << "no" << endl;
            continue;
        }
        max = total / 4;
        int tt = n-1, t;
        int mid = 0, suc = 0;
        int fail = 0;
        
        sort(a.begin(), a.end(), greater<int>());
        for(int j = 0; j < n; j++) {
            if(a[j] > max) {
                cout << "no" << endl;
                fail = 1;
                break;
            } else if(a[j] == max) {
                continue;
            }
            if(m.count(a[j]) == 0) {
                break;
            } 
            if(--m[a[j]] == 0) {
                m.erase(a[j]);
            }
            if(m.count(max-a[j]) != 0) {
                if(--m[max-a[j]] == 0) {
                    m.erase(max-a[j]);
                }
            } else {
                t = tt;
                suc = 0;
                while(t > j) {
                    if(m.count(a[t]) == 0) {
                        t--;
                        tt--;
                        continue;
                    }
                    
                    if(m.count(max-a[j]-a[t]) != 0) {
                        if(--m[a[t]] == 0) {
                            m.erase(a[t]);
                        }
                        if(--m[max-a[j]-a[t]] == 0) {
                            m.erase(max-a[j]-a[t]);
                        }
                        suc = 1;
                        break;
                    } else {
                        mid = max-a[j];
                        if(mid % a[t] == 0 && (mid / a[t]) >= m[a[t]]) {
                            m[a[t]] -= mid / a[t];
                            if(m[a[t]] == 0) {
                                m.erase(a[t]);
                            }
                            suc = 1;
                            break;
                        }
                    }
                    
                    t--;
                }
                if(suc == 1) {
                    continue;
                } else {
                    cout << "no" << endl;
                    fail = 1;
                    break;
                }
            }
        }
        if(fail == 1) {
            continue;
        } else {
            cout << "yes" << endl;
        }    
    }
    
    
    return 0;
}