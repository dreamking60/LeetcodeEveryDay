#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, t;
    vector<int> odd;
    vector<int> even;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> t;
        if(t % 2 == 0) {
            even.push_back(t);
        } else {
            odd.push_back(t);
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    auto et = even.begin();
    auto ot = odd.begin();
    int state = 0;
    int pre = 0;
    int len = 0;

    if(*et < *ot) {
        pre = *et;
        ++et;
        state = 1;
    } else {
        pre = *ot;
        ++ot;
        state = 2;
    }
    len++;
    while(et != even.end() && ot != odd.end()) {
        if(state == 1) {
            while(pre > *ot) {
                ++ot;
            }
            pre = *ot;
            ++ot;
            len++;
            state = 2;
        } else if(state == 2) {
            while(pre > *et) {
                ++et;
            }
            pre = *et;
            ++et;
            len++;                     
            state = 1;
        }
        
    }

    cout << len << endl;

    return 0;
}
