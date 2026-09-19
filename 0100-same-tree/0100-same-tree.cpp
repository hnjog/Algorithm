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
    bool CheckTree(TreeNode* p, TreeNode* q)
    {
        if(p == nullptr && q == nullptr)
        {
            return true;
        }
        else if(p == nullptr ||
        q == nullptr)
        {
            return false;
        }

        if(p->val != q->val)
            return false;

        if(CheckTree(p->left,q->left) == false)
        {
            return false;
        }

        return CheckTree(p->right,q->right);
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
         return CheckTree(p,q);
    }
};