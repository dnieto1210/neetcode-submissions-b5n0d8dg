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
    int maxSum;
    int dfs(TreeNode* node)
    {
        if(!node)
        {
            return 0;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);
        int sum = left + right;
        maxSum = max({sum + node->val, maxSum, max({left,right,0}) + node->val});
        int result = max({left, right, 0}) + node->val;
        return result;
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        if(!root)
        {
            return 0;
        }
        dfs(root);
        return maxSum;
    }
};
