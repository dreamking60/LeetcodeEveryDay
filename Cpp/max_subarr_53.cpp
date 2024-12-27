#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sub = nums[0];
        int max = nums[0];
        int len = nums.size();
        for(int i = 1; i < len; i++) {
            if(sub + nums[i] < nums[i]) {
                sub = nums[i];
            } else {
                sub = sub + nums[i];
            }

            if(max < sub) {
                max = sub;
            }
        }

        return max;
    }
};