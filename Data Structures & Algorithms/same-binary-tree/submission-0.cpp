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
    bool PreOrder(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
        {
            return true;
        }
        else if(p && q)
        {
            if(p->val != q->val)
            {
                return false;
            }
            bool left = PreOrder(p->left, q->left);
            bool right = PreOrder(p->right, q->right);
            if(!left || !right)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool result = PreOrder(p, q);
        return result;

    }
};
