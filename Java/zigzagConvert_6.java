public class zigzagConvert_6 {
    public String convert(String s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        int loop = numRows+numRows-2;
        int len = s.length();
        StringBuilder sb = new StringBuilder();
        int i = 0;
        int j = len;
        int tmp = 0;
        while(j-- > 0) {
            sb.append(s.charAt(i));
            if(i % loop < numRows-1 && i%loop > 0) {
                tmp = ((numRows-1) - i%loop) * 2 + i;
            } else if(i % loop > numRows-1) {
                tmp = (loop - i % loop) * 2 + i;
            } else {
                tmp += loop;
            }

            if(tmp < len) {
                i = tmp;
            } else {
                if(i % loop < numRows-1) {
                    i = i % loop + 1;
                } else {
                    i = i%loop - (i%loop - (numRows-1)) * 2 + 1;
                }
            }
        }
        return sb.toString();
    }
}
