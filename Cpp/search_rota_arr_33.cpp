#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len-1;
        int mid = 0;
        int res = -1;

        if(len == 1) {
            if(nums[0] == target) {
                return 0;
            } else {
                return res;
            }
        }

        while(left < right) {
            mid = left + (right - left)/2;
            if(nums[mid] > nums[right]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }

        int bgn = left;
        int end = left+len-1;
        int idx = 0;

        while(bgn < end) {
            mid = bgn + (end-bgn) / 2;
            idx = mid % len;
            if(nums[idx] == target) {
                return idx;
            } else if(nums[idx] < target) {
                bgn = mid+1;
            } else {
                end = mid;
            }
        }

        if(nums[bgn % len] == target) {
            return bgn % len;
        }

        return res;
    }
};