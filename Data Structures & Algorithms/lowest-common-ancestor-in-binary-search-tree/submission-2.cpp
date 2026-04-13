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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == root || q == root)
        {
            return root;
        }
        int middle = root->val;
        int p_val = p->val;
        int q_val = q->val;

        if((p_val < middle && q_val > middle) || (p_val > middle && q_val < middle))
        {
            return root;
        }
        if(p_val < middle && q_val < middle)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        if(p_val > middle && q_val > middle)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        
    }
};
