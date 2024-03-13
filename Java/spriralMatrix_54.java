import java.util.ArrayList;
import java.util.List;

public class spriralMatrix_54 {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        int loop = 0;
        int row = matrix.length;
        int col = matrix[0].length;
        int min = Math.min(row, col);
        while(loop < min/2) {
            int i = loop;
            int j = loop;
            for(; j < col-loop-1; j++) {
                res.add(matrix[i][j]);
            }
            for(; i < row-loop-1; i++) {
                res.add(matrix[i][j]);
            }
            for(; j > loop; j--) {
                res.add(matrix[i][j]);
            }
            for(; i > loop; i--) {
                res.add(matrix[i][j]);
            }
            loop++;
        }
        if(min % 2 != 0) {
            if(min == row) {
                for(int j = loop; j < col-loop; j++) {
                    res.add(matrix[min/2][j]);
                }
            } else {
                for(int i = loop; i < row-loop; i++) {
                    res.add(matrix[i][min/2]);
                }
            }
        }
        return res;
    }
    
}
