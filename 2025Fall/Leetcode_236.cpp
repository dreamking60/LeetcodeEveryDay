// Leetcode 236: Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 1. DFS + two vector
#include <vector>
using namespace std;
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* t, vector<TreeNode*>& v) {
        if(root == nullptr) {
            return false;
        }

        v.push_back(root);
        if(root == t) {
            return true;
        }

        if(dfs(root->left, t, v)) {
            return true;
        }

        if(dfs(root->right, t, v)) {
            return true;
        }
        v.pop_back();

        return false;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> u;
        vector<TreeNode*> v;
        dfs(root, p, u);
        dfs(root, q, v);
    
        for(int i = 0; i < u.size(); i++) {
            if(i == v.size()) {
                return u[v.size()-1];
            }
            if(u[i] != v[i]) {
                return u[i-1];
            }
        }

        return u[u.size()-1];
    }
};

// 2. DFS one pass
class Solution {
    public:
        TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root == nullptr) {
                return nullptr;
            }
            
            TreeNode* left = dfs(root->left, p, q);
            TreeNode* right = dfs(root->right, p, q);
    
            if(root == p || root == q) {
                return root;
            }
            if(left != nullptr && right != nullptr) {
                return root;
            } else if(left != nullptr){
                return left;
            } else {
                return right;
            }
    
        }
    
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            return dfs(root, p, q);
        }
    };