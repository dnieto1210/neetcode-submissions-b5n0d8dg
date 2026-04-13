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
        if(!node)
        {
            return 0;
        }


        int l = (node->left) ? dfs(node->left) : 0;
        int r = (node->right) ? dfs(node->right) : 0;
        maxDiameter = max(maxDiameter, l + r);


        return 1 + std::max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        maxDiameter = 0;
        dfs(root);
        return maxDiameter;
        
    }
private:
    int maxDiameter;
};
