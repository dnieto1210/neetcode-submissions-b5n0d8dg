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

        int left = postOrder(node->left);
        int right = postOrder(node->right);

        int both = left + right;
        diameter = max(diameter, both);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        diameter = INT_MIN;

        postOrder(root);
        return diameter;
        
    }
private:
    int diameter;
};
