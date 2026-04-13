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
    int max_num = INT_MIN;

    int dfs(TreeNode* node)
    {
        if(!node)
        {
            return 0;
        }

        int node_left = dfs(node->left);
        int node_right = dfs(node->right);

        if(node->val >= 0)
        {
            if(max_num < node_left + node->val)
            {
                max_num = node_left + node->val;
            }
            if(max_num < node_right + node->val)
            {
                max_num = node_right + node->val;
            }
            if(max_num < node_right + node_left + node->val)
            {
                max_num = node_right + node_left + node->val;
            }
            if(max_num < node->val)
            {
                max_num = node->val;
            }
        }
        else
        {
            if(max_num < node_left + node->val)
            {
                max_num = node_left + node->val;
            }
            if(max_num < node_right + node->val)
            {
                max_num = node_right + node->val;
            }
            if(max_num < node_right + node_left + node->val)
            {
                max_num = node_right + node_left + node->val;
            }
            if(max_num < node->val)
            {
                max_num = node->val;
            }

        }

        return std::max({node_left + node->val, node_right + node->val, node->val});
    }
    int maxPathSum(TreeNode* root) {

        if(!root)
        {
            return 0;
        }

        dfs(root);
        return max_num;

    }
};
