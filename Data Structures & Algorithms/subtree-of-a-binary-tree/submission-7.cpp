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
    bool subPreOrder(TreeNode* node, TreeNode* sub)
    {
        if(!node && !sub)
        {
            return true;
        }
        if(!node && sub)
        {
            return false;
        }
        if(node && !sub)
        {
            return false;
        }

        //otherwise both valid
        if(node->val != sub->val)
        {
            return false;
        }

        bool l = subPreOrder(node->left, sub->left);
        bool r = subPreOrder(node->right, sub->right);
        return l && r;
    }
    void preOrder(TreeNode* node, TreeNode* sub)
    {
        if(!node)
        {
            return;
        }

        if(node->val == sub->val)
        {
            //start the search
            bool check = subPreOrder(node, sub);
            ans = max(check, ans);
        }

        preOrder(node->left, sub);
        preOrder(node->right, sub);
        return;
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(!root && subRoot)
        {
            return false;
        }
        if(!root && !subRoot)
        {
            return true;
        }
        if(root && !subRoot)
        {
            return true;
        }

        //both are valid nodes
        ans = false;
        preOrder(root, subRoot);
        return ans;
    }
private:
    bool ans;
};
