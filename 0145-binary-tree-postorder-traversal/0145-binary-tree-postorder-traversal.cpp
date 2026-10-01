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
    void postOrder(vector<int>& ret,TreeNode* node)
    {
        if(node == nullptr)
            return;
        
        postOrder(ret,node->left);
        postOrder(ret,node->right);
        ret.push_back(node->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postOrder(ret,root);
        return ret;
    }
};