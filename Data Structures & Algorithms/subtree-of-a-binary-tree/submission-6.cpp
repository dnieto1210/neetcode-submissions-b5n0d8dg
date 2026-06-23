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
    bool preOrder(TreeNode* root, TreeNode* subRoot)
    {
        if(!root && subRoot)
        {
            return false;
        }
        else if(root && !subRoot)
        {
            return false;
        }
        else if(!root && !subRoot)
        {
            return true;
        }

        //both valid
        int r_v = root->val;
        int s_v = subRoot->val;
        if(r_v != s_v)
        {
            return false;
        }
        //otherwise they are equal

        bool lb = preOrder(root->left, subRoot->left);
        bool rb = preOrder(root->right, subRoot->right);
        return lb && rb;
    }
    void dfs(TreeNode* root, TreeNode* subRoot)
    {
        if(!root)
        {
            return;
        }

        //check if they are same value
        int r_v = root->val;
        int s_v = subRoot->val;
        if(r_v == s_v)
        {
           bool check = preOrder(root, subRoot);
           if(check)
           {
            isEqual = true;
            return;
           }
        }

        //otherwise keep going
        dfs(root->left, subRoot);
        dfs(root->right, subRoot);
        return;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root, subRoot);
        return isEqual;
        
    }
private:
    bool isEqual = false;
};
