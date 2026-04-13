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
    int Height(TreeNode* node)
    {
        if(!node)
        {
            return -1;
        }

        int left = Height(node->left);
        int right = Height(node->right);

        if(left == -3 || right == -3)
        {
            return -3;
        }

        if(std::abs(left-right) > 1)
        {
            return -3;
        }

        int height = std::max(left, right);
        return height + 1;
    }
    bool isBalanced(TreeNode* root) {
        int height = Height(root);
        if(height == -3)
        {
            return false;
        }
        return true;

        


        
    }
private:
};
