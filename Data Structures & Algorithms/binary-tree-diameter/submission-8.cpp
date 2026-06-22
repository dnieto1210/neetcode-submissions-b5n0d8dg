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
        //post order
        if(!node)
        {
            return 0;
        }

        int l = height(node->left);
        int r = height(node->right);
        maxHeight = max(maxHeight, l+r);
        return 1 + max(l, r);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int res = height(root);
        return maxHeight;
    }
private:
    int maxHeight = 0;
};
