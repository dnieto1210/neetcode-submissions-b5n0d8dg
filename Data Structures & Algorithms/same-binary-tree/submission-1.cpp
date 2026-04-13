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
    bool same = true;
    void preOrder(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
        {
            return;
        }
        if(p && !q || !p && q)
        {
            same = false;
            return;
        }
        if(p && q && p->val != q->val)
        {
            same = false;
            return;
        }
        else
        {
            preOrder(p->left, q->left);
            preOrder(p->right, q->right);
            return;
        }

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        preOrder(p, q);
        return same;
        
    }
};
