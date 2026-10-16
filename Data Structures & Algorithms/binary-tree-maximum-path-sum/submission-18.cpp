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
        result = max({result, node->val, node->val + left, node->val + right, node->val + left + right});



        return max({node->val, node->val + left, node->val + right});
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        result = INT_MIN;
        postOrder(root);
        return result;
    }
private:
    int result;
};
