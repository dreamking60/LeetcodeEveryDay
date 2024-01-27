class Solution {
    public boolean isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        int mid = 0;
        while(left <= right) {
            mid = (right-left)/2+left;
            if(num/mid < mid) {
                right = mid-1;
            } else if(num/mid > mid){
                left = mid+1;
            } else if(mid * mid == num){
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
}