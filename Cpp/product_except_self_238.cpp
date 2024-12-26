#include<vector>
using namespace std;

// 1st solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count_zero = 0;
        int product_all = 1;
        int len = nums.size();
        vector<int> product(len);

        for(int i = 0; i < len; i++) {
            if(nums[i] == 0) {
                count_zero++;
            } else {
                product_all *= nums[i];
            }
        }

        if(count_zero == 0) {
            for(int i = 0; i < len; i++) {
                product[i] = product_all / nums[i];
            }
        } else if(count_zero == 1) {
            for(int i = 0; i < len; i++) {
                if(nums[i] != 0) {
                    product[i] = 0;
                } else {
                    product[i] = product_all;
                }
            }
        } else {
            for(int i = 0; i < len; i++) {
                product[i] = 0;
            }
        }

        return product;
    }
};

// 2nd solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int right = 1;
        vector<int> left(len);
        vector<int> res(len);

        left[0] = 1;
        for(int i = 1; i < len; i++) {
            left[i] = left[i-1] * nums[i-1];
        }

        for(int i = len-1; i >= 0; i--) {
            res[i] = left[i] * right;
            right *= nums[i];
        }

        return res;
    }
};
