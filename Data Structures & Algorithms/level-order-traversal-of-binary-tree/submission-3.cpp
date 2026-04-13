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
        std::queue<TreeNode*> myQueue;
        vector<vector<int>> result;
        myQueue.push(root);

        while(!myQueue.empty())
        {
            int size = myQueue.size();
            vector<int> sublist;
            for(int i = 0; i < size; ++i)
            {
                TreeNode* temp = myQueue.front();
                int value = temp->val;
                sublist.push_back(value);
                myQueue.pop();
                if(temp->left)
                {
                    myQueue.push(temp->left);
                }
                if(temp->right)
                {
                    myQueue.push(temp->right);
                }
            }
            result.push_back(sublist);
        }

        return result;
        
    }
};
