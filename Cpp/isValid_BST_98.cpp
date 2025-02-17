/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root != nullptr) {
            long long min = root->val;
            long long max = root->val;
            return isValid_helper(root, min, max);
        }
        return true;
    }

    bool isValid_helper(TreeNode* root, long long& MIN, long long& MAX) {
        if(root == nullptr) {
            return true;
        }

        bool valid_left = true;
        bool valid_right = true;

        if(root->left != nullptr) {
            long long left_min = root->left->val;
            long long left_max = root->left->val;
            valid_left = isValid_helper(root->left, left_min, left_max);
            if(valid_left) {
                if(left_max >= root->val) {
                    return false;
                } else {
                    MIN = min(MIN, left_min);
                }
            } else {
                return false;
            }
        }

        if(root->right != nullptr) {
            long long right_min = root->right->val;
            long long right_max = root->right->val;
            valid_right = isValid_helper(root->right, right_min, right_max);
            if(valid_right) {
                if(right_min <= root->val) {
                    return false;
                } else {
                    MAX = max(MAX, right_max);
                }
            } else {
                return false;
            }
        }
        
        return true;

    }
    
};
// @lc code=end

