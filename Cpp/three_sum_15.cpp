#include <vector>
#include <set>
using namespace std;

// 1st solution: O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        int k = nums.size()-1;
        int tmp = 0;

        for(int i = 0; i < nums.size()-1; i++) {
            tmp = 0 - nums[i];
            j = i+1;
            k = nums.size()-1;
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            while(j < k) {
                if(nums[j]+nums[k] < tmp) {
                    j++;
                } else if(nums[j]+nums[k] > tmp){
                    k--;
                } else {
                    res.push_back({nums[i],nums[j],nums[k]});
                    do {
                        j++;
                    } while(j < k && nums[j] == nums[j - 1]);
                    do{
                        k--;
                    } while(j < k && nums[k] == nums[k + 1]);
                }
            }
        }
        
        return res;
    }
};


// 2nd solution: O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        int k = nums.size()-1;
        int tmp = 0;

        for(int i = 0; i < nums.size(); i++) {
            tmp = 0 - nums[i];
            j = i+1;
            k = nums.size()-1;
            while(j < k) {
                if(nums[j]+nums[k] < tmp) {
                    j++;
                } else if(nums[j]+nums[k] > tmp){
                    k--;
                } else {
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
            }
        }

        set<vector<int>> unique_set(res.begin(), res.end());

        res.assign(unique_set.begin(), unique_set.end());


        return res;
    }
};

