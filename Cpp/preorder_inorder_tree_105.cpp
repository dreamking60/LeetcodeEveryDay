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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        if(size == 0) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 0; i < size; i++) {
            if(preorder[0] == inorder[i]) {
                vector<int> left(preorder.begin()+1, preorder.begin()+1+i);
                vector<int> inle(inorder.begin(),inorder.begin()+1+i);
                vector<int> right(preorder.begin()+1+i, preorder.begin()+size);
                vector<int> inri(inorder.begin()+1+i, inorder.begin()+size);
                root->left = buildTree(left, inle);
                root->right = buildTree(right, inri);
                break;
            }
        }
        return root;
    }
};