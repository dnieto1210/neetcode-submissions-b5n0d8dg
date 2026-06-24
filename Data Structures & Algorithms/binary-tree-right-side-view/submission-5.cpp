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
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        vector<int> result;

        while(!myQueue.empty())
        {
            int size = myQueue.size();
            bool first_right = false;
            for(int i = 0; i < size; ++i)
            {
                TreeNode* node = myQueue.front();
                myQueue.pop();

                if(!first_right)
                {
                    first_right = true;
                    result.push_back(node->val);
                }

                if(node->right)
                {
                    myQueue.push(node->right);
                }
                if(node->left)
                {
                    myQueue.push(node->left);
                }
            }
        }

        return result;
        
    }
};
