public class MergeSort {
    public void mergeSort(int[] arr) {
        int n = arr.length;
        Merge(arr, 0, n-1);
    }
    
    public void Merge(int[] arr, int l, int r) {
        if(r-l == 0) {
            return;
        }
        int mid = l+(r-l)/2;
        int[] dp = new int[r-l+1];
        Merge(arr, l, mid);
        Merge(arr, mid+1, r);
        int i = l;
        int j = mid+1;
        for(int t = 0; t <= r-l; t++) {
            if(j > r || (i <= mid && arr[i] >= arr[j])) {
                dp[t] = arr[i++];
            } else {
                dp[t] = arr[j++];
            }
        }
        for(int t = 0; t <= r-l; t++) {
            arr[l+t] = dp[t];
        }
    }
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)

    // test sort algorithm
    public static void main(String[] args) {
        int[] arr = {3, 2, 1, 5, 4};
        MergeSort ms = new MergeSort();
        ms.mergeSort(arr);
        for(int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}
