public class canCompleteCircuit_134 {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int len = gas.length;
        int total = 0;
        int mid = 0;
        int start = 0;
        for(int i = 0; i  < len; i++) {
            total += gas[i] - cost[i];
            mid += gas[i] - cost[i];
            if(mid < 0) {
                start = i + 1;
                mid = 0;
            }
        }

        return total >= 0 ? start : -1;
    }
}
