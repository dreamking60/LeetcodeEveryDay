#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int len;
    cin >> len;
    vector<int> arr(len);
    vector<int> res;
    for(int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int pre = arr[0] % 2;
    res.push_back(arr[0]);

    for(int i = 1; i < len; i++) {
        if(arr[i] % 2 != pre) {
            res.push_back(arr[i]);
            pre = arr[i] % 2;
        }
    }

    return res.size();
}