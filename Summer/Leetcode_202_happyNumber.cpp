class Solution {
    public:
        bool isHappy(int n) {
            unordered_set<int> s;
            int next = n;
            int tmp = 0;
            int mid = 0;
    
            while(next != 1) {
                tmp = 0;
                mid = 0;
                do{
                    tmp = next % 10;
                    mid += tmp * tmp;
                    next = next / 10;
                } while(next != 0);
                if(!s.count(mid)) {
                    s.insert(mid);
                    next = mid;
                } else {
                    return false;
                }
            }
    
            return true;
        }
    };