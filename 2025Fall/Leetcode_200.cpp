// Leetcode 200: Number of Islands
// https://leetcode.com/problems/number-of-islands/

#include <vector>
#include <set>
using namespace std;


// 1. Set + Node (TTL) (not good)
struct Node{
    Node* next;
    Node() {}
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<Node*>> nodes;

        for(int i = 0; i < m; i++) {
            vector<Node*> raw;
            for(int j = 0; j < n; j++) {
                raw.push_back(new Node());
            }
            nodes.push_back(raw);
        }
        
        vector<set<Node*>> s;
        int t1 = 0;
        int t2 = 0;
        int tag1 = 0;
        int tag2 = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    t1 = -1;
                    t2 = -1;
                    tag1 = 0;
                    if(i >= 1) {
                        for(t1 = 0; t1 < s.size(); t1++) {
                            if(s[t1].count(nodes[i-1][j]) == 1) {
                                tag1 = 1;
                                break;
                            }
                        }
                    }

                    tag2 = 0;
                    if(j >= 1) {
                        for(t2 = 0; t2 < s.size(); t2++) {
                            if(s[t2].count(nodes[i][j-1]) == 1) {
                                tag2 = 1;
                                break;
                            }
                        }
                    }

                    if(tag1 == 1 && tag2 == 1) {
                        if(t1 == t2) {
                            s[t1].insert(nodes[i][j]);
                        } else {
                            for(auto n : s[t2]) {
                                s[t1].insert(n);
                            }
                            s[t1].insert(nodes[i][j]);
                            s.erase(s.begin()+t2);
                        }
                    } else if(tag1 == 1) {
                        s[t1].insert(nodes[i][j]);
                    } else if(tag2 == 1) {
                        s[t2].insert(nodes[i][j]);
                    } else {
                        set<Node*> newS;
                        newS.insert(nodes[i][j]);
                        s.push_back(newS);
                    }
                }
            }
        }

        return s.size();
    }
};