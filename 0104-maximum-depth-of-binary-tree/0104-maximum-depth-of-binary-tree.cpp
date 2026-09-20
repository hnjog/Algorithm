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
    int FindDepth(TreeNode* node, int nowDepth)
    {
        if(node == nullptr)
            return nowDepth;
        nowDepth++;

        return max(FindDepth(node->left,nowDepth),FindDepth(node->right,nowDepth));
    }

public:
    int maxDepth(TreeNode* root) {
        return FindDepth(root,0);
    }
};