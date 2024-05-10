import java.lang.reflect.Array;
import java.util.List;

public class threeSum_15 {
/*     private int[] tmp;
 */
    public List<List<Integer>> threeSum(int[] nums) {
        int len = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        int i = 0;
        int j = 0;
        int sum = 0;
        for (int k = 0; k < len - 2; k++) {
            i = k + 1;
            j = len - 1;
            sum = 0 - nums[k];
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            if(sum < nums[k]) {
                break;
            }
            while (i < j) {
                if (nums[i] + nums[j] == sum) {
                    res.add(Arrays.asList(nums[k], nums[i], nums[j]));
                    while (i < j && nums[i] == nums[i + 1]) {
                        i++;
                    }
                    i++;
                } else if (nums[i] + nums[j] < sum) {
                    i++;
                } else {
                    j--;
                }
            }
        }

        return res;
    }

/*     public void Merge(int[] nums, int left, int right) {
        if (left < right) {
            int mid = (right - left) / 2 + left;
            Merge(nums, left, mid);
            Merge(nums, mid + 1, right);
            int i = left;
            int j = mid + 1;
            for (int k = left; k <= right; k++) {
                if (i > mid || (j <= right && nums[i] > nums[j])) {
                    tmp[k] = nums[j];
                    j++;
                } else {
                    tmp[k] = nums[i];
                    i++;
                }
            }
            for (int k = left; k <= right; k++) {
                nums[k] = tmp[k];
            }
        }

    } */
}
