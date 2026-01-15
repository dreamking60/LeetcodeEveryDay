class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param num int整型vector 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > threeSum(vector<int>& num) {
        // write code here
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        int tmp = 0;
        sort(num.begin(), num.end());
  
        for(int t = 0; t < num.size(); t++) {
            tmp = num[t];
            if(t > 0 && num[t] == num[t-1]) {
                continue;
            }
            i = t+1;
            j = num.size()-1;
            while(i < j) {
                if(tmp + num[i] + num[j] < 0) {
                    i++;
                    while(nums[i] == nums[i-1]) {
                        i++;
                    }
                } else if(tmp + num[i] + num[j] > 0) {
                    j--;
                    while(nums[j] == nums[j+1]) {
                        j--;
                    }
                } else {
                    vector<int> p;
                    p.push_back(num[t]);
                    p.push_back(num[i]);
                    p.push_back(num[j]);
                    res.push_back(p);
                    i++;
                    while(num[i] == num[i-1]) {
                        i++;
                    }
                    while(num[j] == num[j+1]) {
                        j--;
                    }
                }
            }

        }
        return res;
    }
};