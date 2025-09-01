// Pdd 2025 Fall Campus Recruitment Test 2: Problem 1

// 1. Sort + Scan (Stack Overflow)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareV(vector<long long> &a, vector<long long> &b) {
    return (a[0] > b[0]) ? false : true;
}

int main() {
    int T, N;
    long long H, x, y;
    long long prevleft, prevright;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> H;
        cin >> N;
        vector<vector<long long>> v;
        for(int j = 0; j < N; j++) {
            cin >> x;
            cin >> y;
            v.push_back({x,y});
        }

        sort(v.begin(), v.end(), compareV);
        prevleft = v[0][0];
        prevright = v[0][1];
        for(int j = 1; j < N; j++) {
            if(prevright >= v[j][0]) {
                prevright = max(v[j][1], prevright);
            } else {
                H = H - (prevright - prevleft + 1);
                prevleft = v[j][0];
                prevright = v[j][1];
            }
        }
        H = H - (prevright - prevleft + 1);     
        cout << H << endl;
        v.clear();
    }
}
// 64 位输出请用 printf("%lld")

// 2, Use pair instead of vector (AC)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareV(pair<long long, long long> &a, pair<long long, long long> &b) {
    return (a.first > b.first) ? false : true;
}

int main() {
    int T, N;
    long long H, x, y;
    long long prevleft, prevright;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> H;
        cin >> N;
        vector<pair<long long, long long>> v;
        for(int j = 0; j < N; j++) {
            cin >> x;
            cin >> y;
            v.push_back(make_pair(x,y));
        }

        sort(v.begin(), v.end(), compareV);
        prevleft = v[0].first;
        prevright = v[0].second;
        for(int j = 1; j < N; j++) {
            if(prevright >= v[j].first) {
                prevright = max(v[j].second, prevright);
            } else {
                H = H - (prevright - prevleft + 1);
                prevleft = v[j].first;
                prevright = v[j].second;
            }
        }
        H = H - (prevright - prevleft + 1);     
        cout << H << endl;
        v.clear();
    }
}