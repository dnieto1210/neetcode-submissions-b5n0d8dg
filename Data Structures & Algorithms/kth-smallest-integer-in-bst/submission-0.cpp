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
    int kthSmallest(TreeNode* root, int k) {
        InOrder(root);



        return result[k-1];

        
    }

    void InOrder(TreeNode* node)
    {
        if(!node)
        {
            return;
        }

        InOrder(node->left);
        result.push_back(node->val);
        InOrder(node->right);

    }
private:
    std::vector<int> result;
};
