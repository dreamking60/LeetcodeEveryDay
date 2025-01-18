#include <vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        int xor1 = 0;
        int xor2 = 0;
        if(len2 % 2 != 0) {
            for(int i = 0; i < len1; i++) {
                xor1 = xor1 ^ nums1[i];
            }
        }

        if(len1 % 2 != 0) {
            for(int i = 0; i < len2; i++) {
                xor2 = xor2 ^ nums2[i];
            }
        }

        return xor1 ^ xor2;
    }
};