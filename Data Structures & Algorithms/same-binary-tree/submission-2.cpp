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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
        {
            return true;
        }

        if(!p && q || !q && p)
        {
            return false;
        }

        stack<TreeNode*> p_s;
        stack<TreeNode*> q_s;
        p_s.push(p);
        q_s.push(q);

        while(!p_s.empty() && !q_s.empty())
        {
            TreeNode* p_t = p_s.top();
            p_s.pop();
            TreeNode* q_t = q_s.top();
            q_s.pop();
            if(!p_t && q_t || !q_t && p_t)
            {
                return false;
            }
            if(!p_t && !q_t)
            {
                continue;
            }
            if(p_t->val != q_t->val)
            {
                return false;
            }
            p_s.push(p_t->right);
            p_s.push(p_t->left);
            q_s.push(q_t->right);
            q_s.push(q_t->left);

        }

        return true;
        
    }
};
