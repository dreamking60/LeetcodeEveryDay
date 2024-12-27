#include <vector>
using namespace std;

// Solution: use a max and a min to store the max and min product of subarray ending with nums[i];
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0];
        int min = nums[0];
        int ans = nums[0];
        int temp;

        for(int i = 1; i < nums.size(); i++) {
            temp = max;
            if(max * nums[i] > min * nums[i]) {
                if(max * nums[i] > nums[i]) {
                    max = max * nums[i];
                } else {
                    max = nums[i];
                }
            } else {
                if(min * nums[i] > nums[i]) {
                    max = min * nums[i];
                } else {
                    max = nums[i];
                }
            }

            if(temp * nums[i] < min * nums[i]) {
                if(temp * nums[i] < nums[i]) {
                    min = temp * nums[i];
                } else {
                    min = nums[i];
                }
            } else {
                if(min * nums[i] < nums[i]) {
                    min = min * nums[i];
                } else {
                    min = nums[i];
                }
            }
            if(max > ans) {
                ans = max;
            }
        }
       
        return ans;
    }
};