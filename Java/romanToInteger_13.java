import java.util.Map;

public class romanToInteger_13 {
    public int romanToInt(String s) {
        char[] s_char = s.toCharArray();
        int len = s_char.length;
        int sum = 0;
        Map<Character, Integer> roman = Map.of(
            'I', 1,
            'V', 5,
            'X', 10,
            'L', 50,
            'C', 100,
            'D', 500,
            'M', 1000
        );

        for(int i = 0; i < len; i++) {
            if(i < len-1 && roman.get(s_char[i]) < roman.get(s_char[i+1])) {
                sum -= roman.get(s_char[i]);
            } else {
                sum += roman.get(s_char[i]);
            }
        }

        return sum;
    }
}
