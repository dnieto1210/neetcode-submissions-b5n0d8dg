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

    TreeNode* dfs(const std::vector<int>& preorder, int L, int R, int& preidx, std::unordered_map<int,int>& myMap)
    {
        if(L > R)
        {
            return nullptr;
        }

        int value = preorder[preidx++];
        int idx = myMap[value];
        TreeNode* node = new TreeNode(value);
        node->left = dfs(preorder, L, idx-1, preidx, myMap);
        node->right = dfs(preorder, idx + 1, R, preidx, myMap);

        return node;

        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        std::unordered_map<int,int> myMap;
        for(int i = 0; i < inorder.size(); ++i)
        {
            myMap[inorder[i]] = i;
        }
        int preidx = 0;

        TreeNode *bst = dfs(preorder, 0, inorder.size()-1, preidx, myMap);
        return bst;
        
    }


};
