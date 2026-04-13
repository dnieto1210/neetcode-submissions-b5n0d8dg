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
    bool check = false;

    bool sameTree(TreeNode* root, TreeNode* subRoot)
    {
        if(!root && !subRoot)
        {
            return true;
        }
        if(root && subRoot && root->val == subRoot->val)
        {
            return sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
        }
        return false;
    }


    void dfs(TreeNode* root, TreeNode* subRoot)
    {
        if(!root)
        {
            return;
        }

        //check
        if(root->val == subRoot->val)
        {
            check = sameTree(root, subRoot);
            if(check)
            {
                return;
            }

        }
        dfs(root->left, subRoot);
        dfs(root->right, subRoot);
        return;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot)
        {
            return true;
        }
        if(!root)
        {
            return false;
        }

        dfs(root, subRoot);
        return check;
        
    }
};
