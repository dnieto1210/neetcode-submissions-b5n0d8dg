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
    int height(TreeNode* node)
    {
        if(!node)
        {
            return -1;
        }
        return 1 + max(height(node->left), height(node->right));
    }
    bool postOrder(TreeNode* node)
    {
        if(!node)
        {
            res = min(res, 1);
            return true;
        }

        bool leftSub = postOrder(node->left);
        bool rightSub = postOrder(node->right);

        if((leftSub && !rightSub )|| (!leftSub && rightSub))
        {
            res = min(res, 0);
            return false;
        }
        int l = height(node->left);
        int r = height(node->right);
        if(l-r < -1 || l-r > 1)
        {
            res = min(res, 0);
            return false;
        }

        res = min(res, 1);
        return true;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        res = 1;

        bool ans = postOrder(root);
        return (res == 0) ? false : true;
    }
private:
    int res;
};
