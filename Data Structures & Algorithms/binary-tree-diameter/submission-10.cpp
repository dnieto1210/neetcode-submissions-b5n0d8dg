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
    int postOrder(TreeNode* node)
    {
        if(!node)
        {
            return 0;
        }

        int l = postOrder(node->left);
        int r = postOrder(node->right);

        diameter = max(diameter, l+r);

        return max(l,r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
        {
            return 0;
        }

        postOrder(root);
        return diameter;
    }
private:
    int diameter = INT_MIN;
};
