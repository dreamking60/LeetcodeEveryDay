#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;

        int leftmost = 0;
        int rightmost = 0;
        int max = 0;
        int tmp = 0;
        while(i < j) {
            if(leftmost < height[i]) {
                leftmost = height[i];
                if(leftmost < rightmost) {
                    tmp = leftmost * (j-i);
                } else {
                    tmp = rightmost * (j-i);
                }

                if(tmp > max) {
                    max = tmp;
                }
            }

            if(rightmost < height[j]) {
                rightmost = height[j];
                if(leftmost < rightmost) {
                    tmp = leftmost * (j-i);
                } else {
                    tmp = rightmost * (j-i);
                }

                if(tmp > max) {
                    max = tmp;
                }
            }

            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return max;
    }
};