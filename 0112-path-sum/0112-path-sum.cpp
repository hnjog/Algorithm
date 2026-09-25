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
    bool checkSum(TreeNode* node, int targetSum, int nowSum)
    {
        if(node == nullptr)
            return false;
        
        nowSum += node->val;

        if(node->left == nullptr &&
            node->right == nullptr)
        {
            if(nowSum == targetSum)
                return true;
            
            return false;
        }
        
        return checkSum(node->left,targetSum,nowSum) || checkSum(node->right,targetSum,nowSum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkSum(root,targetSum,0);
    }
};