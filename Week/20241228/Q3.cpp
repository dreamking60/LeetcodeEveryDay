#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Final Solution: O(n^2logn)
class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        long long count = 0;
        int len = nums.size();
        map<double, vector<pair<int, int>>> value;
        double tmp = 0;

        for(int r = 4; r < len-2; r++) {
            for(int s = r+2; s < len; s++) {
                tmp = (double)nums[s] / (double)nums[r];
                if(value.count(tmp) > 0) {
                    value[tmp].push_back(make_pair(r, s));
                } else {
                    vector<pair<int, int>> line;
                    line.push_back(make_pair(r, s));
                    value[tmp] = line;
                }
            }
        }
        
        for(int p = 0; p < len-6; p++) {
            for(int q = p+2; q < len-4; q++) {
                tmp = (double)nums[p] / (double)nums[q];
                if(value.count(tmp) > 0) {
                    int j = value[tmp].size()-1;
                    int i = 0;
                    int mid = 0;
                    while(i < j) {
                        mid = i + (j-i)/2;
                        if(value[tmp][mid].first >= q+2) {
                            j = mid;
                        } else {
                            i = mid+1;
                        }
                    }
                    if(value[tmp][i].first >= q+2) {
                        count += value[tmp].size()-i;
                    }
                }
            }
        }

        return count;
    }
};


// 1st solution: TLE;
class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        long long count = 0;
        int len = nums.size();
        map<double, vector<pair<int, int>>> value;
        double tmp = 0;

        for(int r = 4; r < len-2; r++) {
            for(int s = r+2; s < len; s++) {
                tmp = (double)nums[s] / (double)nums[r];
                if(value.count(tmp) > 0) {
                    value[tmp].push_back(make_pair(r, s));
                } else {
                    vector<pair<int, int>> line;
                    line.push_back(make_pair(r, s));
                    value[tmp] = line;
                }
            }
        }
        
        for(int p = 0; p < len-6; p++) {
            for(int q = p+2; q < len-4; q++) {
                tmp = (double)nums[p] / (double)nums[q];
                if(value.count(tmp) > 0) {
                    for(int i = 0; i < value[tmp].size(); i++) {
                        if(value[tmp][i].first >= q+2) {
                            count += value[tmp].size() - i;
                            break;
                        }
                    }
                }
            }
        }

        return count;
    }
};

// 2nd solution: TLE;
class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        long long count = 0;
        int len = nums.size();
        map<double, vector<pair<int, int>>> value;
        double tmp = 0;

        for(int r = 4; r < len-2; r++) {
            for(int s = r+2; s < len; s++) {
                tmp = (double)nums[s] / (double)nums[r];
                if(value.count(tmp) > 0) {
                    value[tmp].push_back(make_pair(r, s));
                } else {
                    vector<pair<int, int>> line;
                    line.push_back(make_pair(r, s));
                    value[tmp] = line;
                }
            }
        }
        
        for(int p = 0; p < len-6; p++) {
            for(int q = p+2; q < len-4; q++) {
                tmp = (double)nums[p] / (double)nums[q];
                if(value.count(tmp) > 0) {
                    for(auto it = value[tmp].begin(); it != value[tmp].end(); it++) {
                        if(it->first < p+4) {
                            it = value[tmp].erase(it);
                            if(it == value[tmp].end()) {
                                break;
                            }
                        }
                        if(it->first >= q+2) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};
