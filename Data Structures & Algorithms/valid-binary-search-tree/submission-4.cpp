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
    void dfs(TreeNode* node, vector<int>& order)
    {
        if(!node)
        {
            return;
        }
        dfs(node->left, order);
        order.push_back(node->val);
        dfs(node->right, order);
        return;
    }
    bool isValidBST(TreeNode* root) {

        std::vector<int> order;
        dfs(root, order);
        if(order.size() == 0)
        {
            return true;
        }

        for(int i = 1; i < order.size(); ++i)
        {
            if(order[i] <= order[i-1])
            {
                return false;
            }

        }
        return true;
        
    }
};
