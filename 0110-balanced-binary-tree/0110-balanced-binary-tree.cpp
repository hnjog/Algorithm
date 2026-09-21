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
    int GetMaxDepth(TreeNode* node)
    {
        if(node == nullptr)
            return 0;
        
        int lv = GetMaxDepth(node->left) + 1;
        int rv = GetMaxDepth(node->right) + 1;
        return max(lv,rv);
    }

    bool CheckBalanced(TreeNode* node)
    {
        if(node == nullptr)
            return true;

        int lv = GetMaxDepth(node->left);
        int rv = GetMaxDepth(node->right);
        if(abs(lv - rv) <= 1)
        {
            bool a = CheckBalanced(node->left);
            bool b = CheckBalanced(node->right);
            return a && b;
        }
            
        return false;
    }
public:
    bool isBalanced(TreeNode* root) {
        return CheckBalanced(root);
    }
};