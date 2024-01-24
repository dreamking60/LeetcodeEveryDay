class Solution {
    public int mySqrt(int x) {
        if(x == 0) {
            return 0;
        }
        int left = 1;
        int right = x;
        while(left < right) {
            int mid = (right-left+1)/2+left;
            if(x / mid  < mid) {
                right = mid-1;
            } else if(x / mid > mid) {
                left = mid;
            } else {
                return mid;
            }
        }
        return left;
    }
}

// 一种变形
/*
 * class Solution {
    public int mySqrt(int x) {
        if(x == 0) {
            return 0;
        }
        int left = 1;
        int right = x;
        while(left < right) {
            int mid = (right-left+1)/2+left;
            if(x / mid  < mid) {
                right = mid-1;
                left = x / mid;
            } else if(x / mid > mid) {
                left = mid;
                right = x / mid;
            } else {
                return mid;
            }
        }
        return left;
    }
}
 */

// 第二种变形
/*
 * class Solution {
    public int mySqrt(int x) {
        if(x == 0) {
            return 0;
        }
        int left = 1;
        int right = x;
        while(left < right) {
            int mid = (right-left+1)/2+left;
            if(x / mid  < mid) {
                right = mid-1;
                if(left < x / mid) {
                    left = x / mid;
                }
            } else if(x / mid > mid) {
                left = mid;
                if(right > x / mid) {
                    right = x / mid;
                }
            } else {
                return mid;
            }
        }
        return left;
    }
}
 */

// Time Complexity: O(logn) 
// Space Complexity: O(n)