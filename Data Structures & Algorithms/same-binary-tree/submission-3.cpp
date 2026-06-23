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
    void dfs(TreeNode* p, TreeNode* q)
    {
        if(!p && q)
        {
            isEqual = false;
            return;
        }
        else if(p && !q)
        {
            isEqual = false;
            return;
        }
        else if(!p && !q)
        {
            return;
        }

        //otherwise both nodes valid
        //check values
        int p_v = p->val;
        int q_v = q->val;
        if(p_v != q_v)
        {
            isEqual = false;
            return;
        }

        //otherwise keep doing dfs
        dfs(p->left, q->left);
        dfs(p->right, q->right);
        return;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p, q);
        return isEqual;
    }
private:
    bool isEqual = true;
};
