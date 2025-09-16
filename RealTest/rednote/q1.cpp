#include <iostream>
using namespace std;

int main() {
    int n, a, max = 0;
    int c[101], pre[101];
    cin >> n;
    for(int i = 1; i <= 100; i++) {
        c[i] = 0;
        pre[i] = -2;
    }
    
    for(int i = 0; i < n; i++) {
        cin >> a;
        for(int j = 2; j <= a/2; j++) {
            if(a % j == 0 && pre[j] != i-1) {
                c[j]++;
                pre[j] = i;
            }
        }   
        if(pre[a] != i-1) {
            c[a]++;   
            pre[a] = i;
        }
    }
    
    for(int i = 1; i <= 100; i++) {
         if(c[i] > max) {
             max = c[i];
         }   
    }
    cout << max << endl;
    
    return 0;
}
