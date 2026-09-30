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
    void preorderTraversal(vector<int>& ret,TreeNode* node)
    {
        if(node == nullptr)
            return;
        
        ret.push_back(node->val);
        preorderTraversal(ret,node->left);
        preorderTraversal(ret,node->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorderTraversal(ret,root);
        return ret;
    }
};