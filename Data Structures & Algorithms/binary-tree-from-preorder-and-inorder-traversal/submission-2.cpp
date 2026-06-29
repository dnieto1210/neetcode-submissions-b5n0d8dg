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

    TreeNode* build(vector<int>& preorder, vector<int>& inorder)
    {
        TreeNode* curr = nullptr;
        int size = preorder.size();
        if(size == 0)
        {
            return curr;
        }
        if(size == 1)
        {
            curr = new TreeNode(preorder[0]);
            curr->left = nullptr;
            curr->right = nullptr;
            return curr;
        }
        unordered_map<int, int> pre;
        unordered_map<int, int> in;

        for(int i =0; i < preorder.size(); ++i)
        {
            int n = preorder[i];
            int m = inorder[i];
            pre[n] = i;
            in[m] = i;
        }


        curr = new TreeNode(preorder[0]);

        vector<int> left_pre;
        vector<int> left_in;
        vector<int> right_pre;
        vector<int> right_in;

        for(int i = 0; i < in[preorder[0]]; ++i)
        {
            left_in.push_back(inorder[i]);
        }

        int left_size = left_in.size();
        for(int i = 1; i < 1+left_size; ++i)
        {
            left_pre.push_back(preorder[i]);
        }

        for(int i = in[preorder[0]]+1; i < preorder.size(); ++i)
        {
            right_in.push_back(inorder[i]);
        }

        int idx = 1 + left_size;
        for(int i = idx; i < preorder.size(); ++i)
        {
            right_pre.push_back(preorder[i]);
        }

        curr->left = build(left_pre, left_in);
        curr->right = build(right_pre, right_in);
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        TreeNode* root = build(preorder, inorder);
        return root;
        
    }
};
