public class mergeSortedArray_88 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] res = new int[m+n];
        int i = 0;
        int j = 0;
        for(int t = 0; t < n+m; t++) {
            if(j == n || (i < m && nums1[i] <= nums2[j])) {
                res[t] = nums1[i];
                i++;
            } else {
                res[t] = nums2[j];
                j++;
            }
        }
        for(int t = 0; t < n+m; t++) {
            nums1[t] = res[t];
        }
    }

    // Time Complexity: O(n+m)
    // Space Complexity: O(n+m)
}
