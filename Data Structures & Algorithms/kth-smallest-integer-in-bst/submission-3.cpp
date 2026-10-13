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
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
        {
            return -1; //error?
        }

        inOrder(root);
        return elements[k-1];
    }
private:
    vector<int> elements;
};
