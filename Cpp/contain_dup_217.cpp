#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        int len = nums.size();

        for(int i = 0; i < len; i++) {
            if(hash.find(nums[i]) != hash.end()) {
                return true;
            } else {
                hash.insert(nums[i]);
            }
        }
        return false;
    }
};