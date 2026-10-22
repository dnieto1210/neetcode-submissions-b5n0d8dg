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
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int& pre, int left, int right)
    {
        if(pre >= preorder.size())
        {
            return nullptr;
        }

        TreeNode* curr = new TreeNode(preorder[pre]);
        int curr_idx = myMap[preorder[pre]];
        
        //check if it has left subtree
        if(abs(curr_idx - left) <= 1)
        {
            //it has not left subtree
            curr->left = nullptr;
        }
        else
        {
            ++pre;
            curr->left = dfs(preorder, inorder, pre, left, curr_idx);
        }

        //check if it has right subtree
        if(abs(curr_idx - right) <= 1)
        {
            curr->right = nullptr;
        }
        else
        {
            ++pre;
            curr->right = dfs(preorder, inorder, pre, curr_idx, right);
        }

        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i)
        {
            myMap[inorder[i]] = i;
        }

        //we will use open parenthesies so for example(1,5) means elements between index 1 and 5 not including elements at index 1 and 5 so in this case elements at index 2,3,4 are valid only
        int pre = 0;
        TreeNode* root = dfs(preorder, inorder, pre, -1, inorder.size());
        return root;
    }
private:
    unordered_map<int, int> myMap; //this maps value of node to their inorder index
};
