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
    int GetVal(TreeNode* node, int nowDepth)
    {
        if(node == nullptr)
            return nowDepth;
        
        nowDepth++;
        int ret = nowDepth;
        if(node->left != nullptr &&
            node->right != nullptr)
        {
            ret = min(GetVal(node->left,nowDepth),GetVal(node->right,nowDepth));
        }
        else if(node->left != nullptr)
        {
            ret = GetVal(node->left,nowDepth);
        }
        else if(node->right != nullptr)
        {
            ret = GetVal(node->right,nowDepth);
        }

        return ret;
    }
public:
    int minDepth(TreeNode* root) {
        return GetVal(root,0);
    }
};