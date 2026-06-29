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
    void dfs(TreeNode* node, int curr_max)
    {
        if(!node)
        {
            return;
        }

        int curr_val = node->val;
        if(curr_val >= curr_max)
        {
            ++count;
            curr_max = curr_val;
        }

        dfs(node->left, curr_max);
        dfs(node->right, curr_max);
        return;
    }
    int goodNodes(TreeNode* root) {
        if(!root)
        {
            return 0;
        }

        dfs(root, INT_MIN);
        return count;
    }
private:
    int count = 0;
};
