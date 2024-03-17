package Week;

public class minimumMove_3086 {
    public long minimumMoves(int[] nums, int k, int maxChanges) {
        int maxContinue = 0;
        int cont = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] == 1) {
                cont++;
            } else {
                maxContinue = Math.max(maxContinue, cont);
                cont = 0;
            }
        }
        maxContinue = Math.max(maxContinue, cont);
        if(maxContinue == 0) {
            return 2*k;
        } else if(maxContinue == 1) {
            return 2*(k-1);
        } else {
            if(k == 1) {
                return 0;
            } else if(k == 2) {
                return 1;
            } else if(k == 3) {
                if(maxContinue == 2) {
                    return 3;
                } else {
                    return 2;
                }
            } else {
                 
            }
        }
        
        

        return 0;
    }
}
