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
    int balance = 1;
    int height(TreeNode* root)
    {
        if(!root)
        {
            return -1;
        }
        return 1 + max(height(root->right), height(root->left));
    }
    int dfs(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);
        int res = abs(left - right);
        int check = (res > 1) ? 0 : 1;
        balance = min(balance, check);

        return 1 + max(left, right);

    }
    bool isBalanced(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        dfs(root);

        return balance;
    }
};
