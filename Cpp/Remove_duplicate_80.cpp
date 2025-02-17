#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int j = 0;
        int n = 0;
        for(int i = 1; i < size; i++) {
            if(nums[i] == nums[i-1]) {
                n++;
                if(n < 2) {
                    nums[++j] = nums[i];
                }
            } else {
                n = 0;
                nums[++j] = nums[i];
            }
        }

        return j+1;
    }
};