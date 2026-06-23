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
    int findHeight(TreeNode* node)
    {
        if(!node)
        {
            return -1;
        }

        return 1 + max(findHeight(node->left), findHeight(node->right));
    }

    bool dfs(TreeNode* node)
    {
        if(!node)
        {
            return true;
        }

        bool l = dfs(node->left);
        bool r = dfs(node->right);

        if(!l)
        {
            return false;
        }
        else if(!r)
        {
            return false;
        }

        int l_h = findHeight(node->left);
        int l_r = findHeight(node->right);
        int result = abs(l_h - l_r);

        if(result > 1)
        {
            return false;
        }
        return true;
    }


    bool isBalanced(TreeNode* root) {
       int res = dfs(root);
       return res;


        
    }
};
