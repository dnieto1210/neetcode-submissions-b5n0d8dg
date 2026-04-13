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
    bool isValidBST(TreeNode* root) {
        InOrder(root);
        if(result.size() == 0 || result.size() == 1)
        {
            return true;
        }

        int size = result.size();

        for(int i = 1; i < size; ++i)
        {
            int prev = result[i-1];
            int curr = result[i];
            if(curr <= prev)
            {
                return false;
            }
        }

        return true;

        

        
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
