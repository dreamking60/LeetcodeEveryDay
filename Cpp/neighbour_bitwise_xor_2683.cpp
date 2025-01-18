#include <vector>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int len = derived.size();
        int total = 0;
        for(int i = 0; i < len; i++) {
            total = total ^ derived[i];
        }
        if(total == 0) {
            return true;
        } else {
            return false;
        }
    }
};