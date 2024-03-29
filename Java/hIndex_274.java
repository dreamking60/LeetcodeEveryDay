public class hIndex_274 {
    public int hIndex(int[] citations) {
        mergeSort(citations);
        for(int i = 0; i < citations.length; i++) {
            if(citations[i] < i+1) {
                return i;
            }
        }
        return citations.length;
    }

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
}
