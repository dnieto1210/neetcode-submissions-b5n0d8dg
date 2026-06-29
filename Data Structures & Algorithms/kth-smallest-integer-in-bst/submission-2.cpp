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
    void dfs(TreeNode* node)
    {
        if(!node)
        {
            return;
        }
        dfs(node->left);

        int val = node->val;
        --check;
        if(check == 0)
        {
            smallest = val;
            return;
        }
        dfs(node->right);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
        {
            return 0;
        }
        check = k;

        dfs(root);
        return smallest;
        
    }
private:
    int smallest;
    int check;
};
