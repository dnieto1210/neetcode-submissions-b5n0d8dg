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
    TreeNode* dfs(vector<int>& preorder, int l, int r, std::unordered_map<int,int>& indices, int& pre_idx)
    {
        if(l > r)
        {
            return nullptr;
        }
        int val = preorder[pre_idx];
        TreeNode* root = new TreeNode(val);
        int mid = indices[val];
        pre_idx++;
        root->left = dfs(preorder, l, mid-1, indices, pre_idx);
        root->right = dfs(preorder, mid+1, r, indices, pre_idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.size() == 0)
        {
            return nullptr;
        }

        std::unordered_map<int,int> indices;
        for(int i = 0; i < inorder.size(); ++i)
        {
            indices[inorder[i]] = i;
        }
        int pre_idx = 0;
        TreeNode* r = dfs(preorder, 0, inorder.size()-1, indices, pre_idx);
        return r;


        
    }
};
