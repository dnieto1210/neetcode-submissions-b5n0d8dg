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

    int numberOfNodes(TreeNode* node, int max)
    {
        if(!node)
        {
            return 0;
        }
        int count = 0;
        if(node->val >= max)
        {
            ++count;
            max = node->val;
        }
        int left = numberOfNodes(node->left, max);
        int right = numberOfNodes(node->right, max);
        return count + left + right;

    }
    int goodNodes(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int max = INT_MIN;
        int result = numberOfNodes(root, max);
        return result;

    }
};
