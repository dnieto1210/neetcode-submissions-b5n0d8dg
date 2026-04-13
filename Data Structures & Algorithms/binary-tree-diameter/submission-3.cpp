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
    int dfs(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        dia = max(dia, left+right);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia = 0;
        dfs(root);
        return dia;
        
    }
private:
    int dia;
};
