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
    int height(TreeNode* root)
    {
        if(!root)
        {
            return -1;
        }
        else if(!root->right && !root->left)
        {
            return 0;
        }

        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
        {
            return true;
        }

        int left = height(root->left);
        int right = height(root->right);
        int b = left-right;
        bool res = false;
        if(abs(b) > 1)
        {
            return false;
        }

        //otherwise so far it is balanced 
        bool tog = isBalanced(root->left) && isBalanced(root->right);
        return tog;
        
        
    }
};
