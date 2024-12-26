#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        int diz = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            diz = target - nums[i];
            if(nums_map.count(diz) == 1) {
                return {nums_map[diz], i};
            } else {
                nums_map[nums[i]] = i;
            }
        }
        return {};

    }
};