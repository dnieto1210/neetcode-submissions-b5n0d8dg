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
    int dfs(TreeNode* node)
    {
        if(node == nullptr)
        {
            return 0;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);
        diameter = std::max(diameter, left + right);

        return 1 + std::max(left, right);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height = dfs(root);

        return diameter;
        
    }
private:
    int diameter = 0;
};
