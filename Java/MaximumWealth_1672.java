    public int maximumWealth(int[][] accounts) {
        int[] result = new int[accounts.length];
        int max = 0;
        for(int i= 0; i < accounts.length; i++) {
            for(int j = 0; j < accounts[i].length; j++) {
                result[i] += accounts[i][j];
            }
            if(result[i] > max) {
                max = result[i];
            }
        }
        return max;
    }