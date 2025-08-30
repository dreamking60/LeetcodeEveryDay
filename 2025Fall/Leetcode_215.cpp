// Leetcode 215: Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

// 1. Heap K, O(nlogk)
#include <queue>
#include <vector>
using namespace std;
class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int, vector<int>, greater<int>> q;
            for(int i = 0; i < k; i++) {
                q.push(nums[i]);
            }
    
            for(int i = k; i < nums.size(); i++) {
                q.push(nums[i]);
                q.pop();
            }
    
            return q.top();
        }
    };


// 2. Quick Sort O(n)
#include <random>
#include <vector>
using namespace std;
class Solution {
    public:
        int findK(vector<int>& nums, int l, int r, int k) {
            if(l == r) {
                return nums[l];
            }
    
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dist(l,r);
    
            int random = dist(gen);
            int tmp = nums[random];
            nums[random] = nums[r];
            nums[r] = tmp;
            int w = l;
    
            for(int i = l; i < r; i++) {
                if(nums[i] > nums[r]) {
                    tmp = nums[w];
                    nums[w] = nums[i];
                    nums[i] = tmp;
                    w++;
                }
            }
            
            tmp = nums[w];
            nums[w] = nums[r];
            nums[r] = tmp;
            if(w == l && nums[l] == nums[r]) {
                return nums[w];
            }
    
            if(w+1 == k) {
                return nums[w];
            } else if(w+1 < k) {
                return findK(nums, w+1, r, k);
            } else {
                return findK(nums, l, w-1, k);
            }
        }
    
        int findKthLargest(vector<int>& nums, int k) {
            return findK(nums, 0, nums.size()-1, k);
        }
    };