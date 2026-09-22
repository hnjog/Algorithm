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
    bool checkSym(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right == nullptr)
            return true;
        else if(left == nullptr || right == nullptr)
            return false;
        
        if(left->val != right->val)
            return false;

        bool a = checkSym(left->left,right->right);
        bool b = checkSym(left->right,right->left);
        return a && b;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        return checkSym(root->left,root->right);
    }
};