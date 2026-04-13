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
    int maxLen = 0;

    int height(TreeNode* root)
    {
        if(!root)
        {
            return -1;
        }
        if(root->left == nullptr && root->right == nullptr)
        {
            return 0;
        }

        return 1 + max(height(root->left), height(root->right));

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
        {
            return 0;
        }

        int left = 1+ height(root->left);
        int right = 1 + height(root->right);
        int comb = left + right;

        return max({comb, diameterOfBinaryTree(root->right), diameterOfBinaryTree(root->left)});


        
    }
};
