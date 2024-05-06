import java.util.ArrayList;
import java.util.List;

public class textJustify_68 {
    public List<String> fullJustify(String[] words, int maxWidth) {
        int words_len = words.length;
        List<String> res = new ArrayList<>();
        int count = 0;
        int width = 0;
        int mid = 0;
        int leftmost = 0;
        for(int i = 0; i < words_len; i++) {
            if(width + words[i].length() <= maxWidth) {
                width += words[i].length() + 1;
                count++;
            } else if(count > 1){
                StringBuilder sb = new StringBuilder();
                mid = (maxWidth-width+count)/(count-1);
                leftmost = (maxWidth-width+count) % (count-1);
                for(int j = i-count; j < i; j++) {
                    sb.append(words[j]);
                    if(leftmost > 0) {
                        for(int k = 0; k < mid+1; k++) {
                            sb.append(" ");
                        }
                        leftmost--;
                    } else if(j < i-1){
                        for(int k = 0; k < mid; k++) {
                            sb.append(" ");
                        }
                    }
                }
                res.add(sb.toString());
                width = words[i].length() + 1;
                count = 1;
            } else if(count == 1) {
                StringBuilder sb = new StringBuilder();
                sb.append(words[i-1]);
                for(int j = 0; j < maxWidth-words[i-1].length(); j++) {
                    sb.append(" ");
                }
                res.add(sb.toString());
                width = words[i].length() + 1;
                count = 1;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i = words_len-count; i < words_len; i++) {
            sb.append(words[i]);
            if(i < words_len-1) {
                sb.append(" ");
            } else {
                for(int j = 0; j < maxWidth-width+1; j++) {
                    sb.append(" ");
                }
            }
        }
        res.add(sb.toString());
        return res;
    }
}
