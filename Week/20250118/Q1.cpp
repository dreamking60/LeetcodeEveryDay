#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        int tmp = 0;

        for(int i = 0; i < len; i++) {
            tmp = max(0, i - nums[i]);
            for(int j = tmp; j <= i; j++) {
                res += nums[j];
            }
        }
        
        return res;
    }
};