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
    void inOrderDFS(TreeNode* node)
    {
        if(!node)
        {
            return;
        }

        inOrderDFS(node->left);
        traversal.push_back(node->val);
        inOrderDFS(node->right);
        return;

    }
    bool isValidBST(TreeNode* root) {
        if(!root)
        {
            return true;
        }

        inOrderDFS(root);

        bool ordered = true;
        for(int i = 1; i < traversal.size(); ++i)
        {
            int num = traversal[i];
            if(num <= traversal[i-1])
            {
                return false;
            }

        }
        return true;
        
    }
private:
    vector<int> traversal;
};
