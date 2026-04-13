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

        return 1 + std::max(height(node->left), height(node->right));
    }
    int maxDepth(TreeNode* root) {

        int depth = height(root);
        return depth+1;
        
    }
};
