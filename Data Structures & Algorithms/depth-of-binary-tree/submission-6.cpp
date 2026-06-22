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
    int findHeight(TreeNode* node)
    {
        if(!node)
        {
            return -1;
        }

        return 1 + max(findHeight(node->left), findHeight(node->right));
    }
    int maxDepth(TreeNode* root) {
        int h = findHeight(root);
        return h + 1;
        
    }
};
