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
    void inorder(TreeNode* node,vector<int>& ret)
    {
        if(node == nullptr)
            return;
        inorder(node->left,ret);
        ret.push_back(node->val);
        inorder(node->right,ret);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        ret.reserve(200);
        inorder(root,ret);
        return ret;
    }
};