import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> ans = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            if((i+1) % 3 == 0) {
                if((i+1) % 5 == 0) {
                    ans.add("FizzBuzz");
                } else {
                    ans.add("Fizz");
                }
            } else if((i+1) % 5 == 0) {
                ans.add("Buzz");
            } else {
                ans.add(String.valueOf(i+1));
            }

        }
        return ans;
    }

    public List<String> fizzBuzz_2 (int n) {
        List<String> ans = new ArrayList<>();
        for(int i = 1; i <= n; i++) {
            if(i % 3 == 0 && i % 5 == 0) {
                ans.add("FizzBuzz");
            } else if(i % 3 == 0) {
                ans.add("Fizz");
            } else if(i % 5 == 0) {
                ans.add("Buzz");
            } else {
                ans.add(String.valueOf(i));
            }

        }
        return ans;
    }
}