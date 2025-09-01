// Pdd 2025 Fall Campus Recruitment Test 2: Problem 2

// 1. Stack (TLE)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    vector<int> dp;
    vector<int> ans;

    dp.push_back(0);
    for(int i = 1; i <= n; i++) {
        cin >> a;
        dp.push_back(a);
    }

    for(int i = 0; i <= n; i++) {
        ans.push_back(n+1);
    }
    ans[1] = 0;
    
    stack<int> s;
    int id = 0;
    s.push(1);
    while(!s.empty()) {
        id = s.top();
        s.pop();
        if(id > 1 && ans[id-1] > ans[id] + 1) {
            ans[id-1] = ans[id] + 1;
            s.push(id-1);
        }
        if(id < n && ans[id+1] > ans[id] + 1 ) {
            ans[id+1] = ans[id] + 1;
            s.push(id+1);            
        }
        if(ans[dp[id]] > ans[id]) {
            ans[dp[id]] = ans[id];
            s.push(dp[id]);
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
// 64 位输出请用 printf("%lld")

// 2. Deque (AC)
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    vector<int> dp;
    vector<int> ans;

    dp.push_back(0);
    for(int i = 1; i <= n; i++) {
        cin >> a;
        dp.push_back(a);
    }

    for(int i = 0; i <= n; i++) {
        ans.push_back(n+1);
    }
    ans[1] = 0;
    
    deque<int> q;
    int id = 0;
    q.push_back(1);

    while(!q.empty()) {
        id = q.front();
        q.pop_front();

        if(id > 1 && ans[id-1] > ans[id] + 1) {      // 权重 1
            ans[id-1] = ans[id] + 1;
            q.push_back(id-1);
        }
        if(id < n && ans[id+1] > ans[id] + 1 ) {     // 权重 1
            ans[id+1] = ans[id] + 1;
            q.push_back(id+1);            
        }
        if(ans[dp[id]] > ans[id]) {                  // 权重 0
            ans[dp[id]] = ans[id];
            q.push_front(dp[id]);
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
