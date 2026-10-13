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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
        {
            return {};
        }

        queue<TreeNode*> myQ;
        vector<int> result;
        myQ.push(root);

        while(!myQ.empty())
        {
            int n = myQ.size();
            for(int i = 0; i < n; ++i)
            {
                TreeNode* curr = myQ.front();
                myQ.pop();
                if(i == 0)
                {
                    result.push_back(curr->val);
                }
                
                if(curr->right)
                {
                    myQ.push(curr->right);
                }

                if(curr->left)
                {
                    myQ.push(curr->left);
                }
            }

        }

        return result;
        
    }
};
