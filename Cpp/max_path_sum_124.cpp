#include <algorithm>
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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return res;
    }

    int maxPath(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int lmax = maxPath(root->left);
        int rmax = maxPath(root->right);

        int curMax = max(lmax, rmax) + root->val;
        curMax = max(curMax, root->val);
        if(curMax > res) {
            res = curMax;
        }

        if(lmax + rmax + root->val > res) {
            res = lmax + rmax + root->val;
        }

        return curMax;
    }
    
};