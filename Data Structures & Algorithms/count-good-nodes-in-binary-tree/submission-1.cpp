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

    int dfs(TreeNode* node, int curr_max)
    {
        if(!node)
        {
            return 0;
        }
        int prev_max = curr_max;

        if(node->val > curr_max)
        {
            curr_max = node->val;
        }

        int left = dfs(node->left, curr_max);
        int right = dfs(node->right, curr_max);
        int result = (node->val >= prev_max) ? left+right+1 : left+right;

        return result;
        

    }
    int goodNodes(TreeNode* root) {
        if(!root)
        {
            return 0;
        }

        int res = dfs(root, -1000);   
        return res; 
    }
};
