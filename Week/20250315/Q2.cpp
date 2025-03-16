class Solution {
    public:
        vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
            const int maxLength = 1000000;
            int minDistance[maxLength];
            int lastIndex[maxLength];
            int firstIndex[maxLength];
            int size = queries.size();
            int len = nums.size();
            vector<int> res;
            int tmp, bmp;
    
            for(int i = 0; i < maxLength; i++) {
                minDistance[i] = -1;
                lastIndex[i] = -1;
                firstIndex[i] = -1;
            }
    
            for(int i = 0; i < len; i++) {
                tmp = nums[i];
                if(lastIndex[tmp] != -1) {
                    if(i - lastIndex[nums[i]] < len - i + lastIndex[nums[i]]) {
                        bmp = i - lastIndex[nums[i]];
                    } else {
                        bmp = len - i + lastIndex[nums[i]];
                    }

                    if(minDistance[lastIndex[tmp]] == -1 || bmp < minDistance[lastIndex[tmp]]) {
                        minDistance[lastIndex[tmp]] = bmp;
                    }

                    if(len - i + firstIndex[tmp] < bmp) {
                        bmp = len - i + firstIndex[nums[i]];
                        minDistance[i] = bmp;
                        if(minDistance[firstIndex[tmp]] == -1 || bmp < minDistance[firstIndex[tmp]]) {
                            minDistance[firstIndex[tmp]] = bmp;
                        }
                        lastIndex[tmp] = i;
                        continue;
                    }

                    if(minDistance[firstIndex[tmp]] == -1 || len - i + firstIndex[tmp] < minDistance[firstIndex[tmp]]) {
                        cout << "Cur Index: " << i << endl;
                        minDistance[firstIndex[tmp]] = len - i + firstIndex[tmp];
                    }

                    if(minDistance[lastIndex[tmp]] != -1) {
                        minDistance[i] = bmp;
                    } else {
                        minDistance[lastIndex[tmp]] = bmp;
                        minDistance[i] = bmp;
                    }
                } else {
                    firstIndex[tmp] = i;
                }
                lastIndex[tmp] = i;
            }
            
            for(int i = 0; i < size; i++) {
                res.push_back(minDistance[queries[i]]);
            }
            
            return res;
        }
    };