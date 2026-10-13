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
    void inOrder(TreeNode* node)
    {
        if(!node)
        {
            return;
        }

        inOrder(node->left);
        elements.push_back(node->val);
        inOrder(node->right);
        return;
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
        {
            return true;
        }

        inOrder(root);
        for(int i = 0; i < elements.size(); ++i)
        {
            if(i != 0 && elements[i] <= elements[i-1])
            {
                return false;
            }
        }
        return true;
        
    }
private:
    vector<int> elements;
};
