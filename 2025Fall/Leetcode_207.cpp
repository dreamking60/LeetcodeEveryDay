// Leetcode 207: Course Schedule
// https://leetcode.com/problems/course-schedule/

#include <vector>
using namespace std;


// 1. DFS + Graph
struct Node {
    int id;
    int isVisited;
    vector<Node*> next;
    Node(int i) : id(i), isVisited(0) {}
};

class Solution {
public:
    bool dfs(Node* n) {
        if(n->isVisited == 2) {
            return true;
        } else if(n->isVisited == 1) {
            return false;
        } else {
            n->isVisited = 1;
            for(int i = 0; i < (n->next).size(); i++) {
                if(!dfs(n->next[i])) {
                    return false;
                }
            }
            n->isVisited = 2;
            return true;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<Node*> courses;
        for(int i = 0; i < numCourses; i++) {
            Node* c = new Node(i);
            courses.push_back(c);
        }

        int m = prerequisites.size();
        int x, y;
        for(int i = 0; i < m; i++) {
            x = prerequisites[i][0];
            y = prerequisites[i][1];
            courses[y]->next.push_back(courses[x]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(courses[i]->isVisited == 0) {
                if(!dfs(courses[i])) {
                    return false;
                }            
            }
        }

        return true; 
    }
};