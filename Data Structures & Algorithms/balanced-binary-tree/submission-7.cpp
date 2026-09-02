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
public:
    int height(TreeNode* node)
    {
        if(!node)
        {
            return -1;
        }
        return max(height(node->left), height(node->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
        {
            return true;
        }

        int l_h = height(root->left);
        int r_h = height(root->right);
        if(abs(l_h-r_h) > 1)
        {
            return false;
        }

        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);

        return l && r;
        
    }
};
