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

        queue<TreeNode*> myQueue;
        myQueue.push(root);
        vector<vector<int>> result;

        while(!myQueue.empty())
        {
            int size = myQueue.size();
            vector<int> level;
            for(int i = 0; i < size; ++i)
            {
                TreeNode* node = myQueue.front();
                myQueue.pop();

                level.push_back(node->val);
                if(node->left)
                {
                    myQueue.push(node->left);
                }
                if(node->right)
                {
                    myQueue.push(node->right);
                }

            }
            result.push_back(level);
        }

        return result;
        
    }
};
