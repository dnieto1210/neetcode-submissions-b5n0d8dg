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

        int left  = dfs(node->left);
        int right = dfs(node->right);
        int val = node->val;
        maxSum = max({left+val, right+val, left+right+val, val, maxSum});
        return max({left+val, right+val, val});

    }
    int maxPathSum(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        dfs(root);
        return maxSum;
    }
private:
    int maxSum = INT_MIN;
};
