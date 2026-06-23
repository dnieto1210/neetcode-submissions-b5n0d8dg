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
            vector<int> nodes;
            for(int i = 0; i < size; ++i)
            {
                TreeNode* check = myQueue.front();
                myQueue.pop();
                nodes.push_back(check->val);

                if(check->left)
            {
                myQueue.push(check->left);
            }
            if(check->right)
            {
                myQueue.push(check->right);
            }

            }
            result.push_back(nodes);


        }

        return result;
    }
};
