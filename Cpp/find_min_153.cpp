#include <vector>   
using namespace std;

// 1st solution: O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) {
                return nums[i];
            }
        }
        return nums[0];
    }
};

// 2nd solution: O(logn)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len-1;
        int mid = 0;

        if(len == 2) {
            return (nums[left] < nums[right]) ? nums[left] : nums[right];
        }

        while(left+1 < right) {
            mid = (right-left+1)/2+left;
            if(nums[left] < nums[right]) {
                return nums[left];
            } else if(nums[left] < nums[mid]) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return nums[right];
    }
};

// 3rd solution: O(logn)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len-1;
        int mid = 0;
        
        while(left < right) {
            mid = left + (right - left)/2;
            if(nums[left] < nums[right]) {
                return nums[left];
            }
            
            if(nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid+1;
            }
        }

        return nums[left];
    }
};