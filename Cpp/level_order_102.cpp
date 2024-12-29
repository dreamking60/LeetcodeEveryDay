#include <vector>
#include "binary_tree.cpp"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        goDeep(root, 1, res);
        return res;
    }

    void goDeep(TreeNode* root, int depth, vector<vector<int>> &res) {
        if(root != nullptr) {
            if(res.size() < depth) {
                vector<int> level;
                level.push_back(root->val);
                res.push_back(level);
            } else {
                res[depth-1].push_back(root->val);
            }

            goDeep(root->left, depth+1, res);
            goDeep(root->right, depth+1, res);
        }
    }

};