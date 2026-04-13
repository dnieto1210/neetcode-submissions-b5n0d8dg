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
    bool same = false;

    bool preorder(TreeNode* node, TreeNode* sub)
    {
        if(!node && sub || !sub && node)
        {
            return false;;
        }
        if(!node && !sub)
        {
            return true;
        }
        //both are not null
        if(node->val == sub->val)
        {
           bool l = preorder(node->left, sub->left);
            bool r = preorder(node->right, sub->right);
            return l && r;

        }
        else
        {
            return false;
        }
    }

    void dfs(TreeNode*node, TreeNode* sub)
    {
        if(!node)
        {
            return;
        }
        if(node->val == sub->val)
        {
            //start a dfs traversal
            same = max(preorder(node, sub), same);
            if(same == true)
            {
                return;
            }
        }

        dfs(node->left, sub);
        dfs(node->right, sub);
        return;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
        {
            return true;
        }

        dfs(root, subRoot);
        return same;
        
    }
};
