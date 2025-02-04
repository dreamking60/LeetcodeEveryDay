// Solution 1: O(n*m)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root != nullptr && subRoot != nullptr) {
            if(isSub(root, subRoot)) {
                return true;
            }
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        } else {
            return false;
        }
    }

    bool isSub(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) {
            return true;
        } else if(p == nullptr || q == nullptr) {
            return false;
        } else {
            if(p->val == q->val) {
                return isSub(p->left, q->left) && isSub(p->right, q->right);
            }
            return false;
        }
    }
};

// Solution 2: O(n+m)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string rootStr("(");
        string subStr("(");
        serialize(root, rootStr);
        serialize(subRoot, subStr); 


        if(rootStr.contains(subStr)) {
            return true;
        }
        return false;
    }
    
    void serialize(TreeNode* root, string& s) {
        if(root == nullptr) {
            s.append(")");
        }

        s.append(to_string(root->val));
        if(root->left != nullptr) {
            s.append("(");
            serialize(root->left, s);
        } else {
            s.append("N");
        }

        if(root->right != nullptr) {
            s.append("(");
            serialize(root->right, s);
        } else {
            s.append("N");
        }
        s.append(")");
    }

};