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
    int dfs(TreeNode* node)
    {
        if(!node)
        {
            return 0;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);

        int check = std::abs(left-right);
        if(check > 1)
        {
            balance = 0;
        }

        return 1 + std::max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
        {
            return balance;
        }

        dfs(root);
        return balance;
        
    }
};
