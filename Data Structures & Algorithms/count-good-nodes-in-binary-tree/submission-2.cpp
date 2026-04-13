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
    int good_nodes = 0;

    void dfs(TreeNode* node, int num)
    {
        if(!node)
        {
            return;
        }
        if(node->val >= num)
        {
            ++good_nodes;
        }

        int max_num = std::max(node->val, num);
        dfs(node->left, max_num);
        dfs(node->right, max_num);
        return;
    }
    int goodNodes(TreeNode* root) {

        if(!root)
        {
            return 0;
        }
        dfs(root, -1000);
        return good_nodes;
        
    }
};
