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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        {
            return {};
        }

        queue<TreeNode*> myQ;
        vector<vector<int>> result;
        myQ.push(root);

        while(!myQ.empty())
        {
            vector<int> level;
            int n = myQ.size();

            for(int i = 0; i < n; ++i)
            {
                TreeNode* curr = myQ.front();
                myQ.pop();
                if(curr->left)
                {
                    myQ.push(curr->left);
                }
                if(curr->right)
                {
                    myQ.push(curr->right);
                }
                level.push_back(curr->val);
            }
            result.push_back(level);
        }

        return result;
        
    }
};
