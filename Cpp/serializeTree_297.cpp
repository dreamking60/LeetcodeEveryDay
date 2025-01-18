/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <queue>
#include <string>
#include "binary_tree.cpp"

using namespace std;

class Solution {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) {
            return "";
        }
        string s(to_string(root->val));
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0) {
            TreeNode* cur = q.front();
            q.pop();

            if(cur->left != nullptr) {
                s.append(",");
                s.append(to_string(cur->left->val));
                q.push(cur->left);
            } else {
                s.append(",NL");
            }

            if(cur->right != nullptr) {
                s.append(",");
                s.append(to_string(cur->right->val));
                q.push(cur->right);
            } else {
                s.append(",NL");
            }
        }

        return s;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") {
            return nullptr;
        }
        string parse;
        queue<TreeNode*> q;
        const char* del = ",";

        char *data_cstr = strdup(data.c_str());
        char *t = strtok(data_cstr, del);
        int num = atoi(t);
        t = strtok(nullptr, del);

        TreeNode* root = new TreeNode(num);
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(t != nullptr && strcmp(t, "NL") != 0) {
                num = atoi(t);
                TreeNode* left = new TreeNode(num);
                cur->left = left;
                q.push(cur->left);
            } else {
                cur->left = nullptr;
            }
            t = strtok(nullptr, del);

            if(t != nullptr && strcmp(t, "NL") != 0) {
                num = atoi(t);
                TreeNode* right = new TreeNode(num);
                cur->right = right;
                q.push(cur->right);
            } else {
                cur->right = nullptr;
            }
            t = strtok(nullptr, del);

        }
        
        free(data_cstr);
        return root;
    }
};
