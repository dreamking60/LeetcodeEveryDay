#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n, res = 0;
    int m;
    cin >> n;
    cin >> m;
    
    for(int i = 0; i < m; i++) {    
        res += n;
        n = sqrt(n);
    }
    
    res = res * 100;
    res = (int) res;
    res = res / 100;
    cout << res << endl;
    
    return 0;
}