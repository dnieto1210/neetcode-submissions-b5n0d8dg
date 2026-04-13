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
    int hei(TreeNode* root)
    {
        if(!root)
        {
            return -1;
        }
        else if(root->right == nullptr && root->left == nullptr)
        {
            return 0;
        }

        return 1 + max(hei(root->left), hei(root->right));
    }
    int maxDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }

        int h = hei(root);

        return h + 1;

        
        
    }
};
