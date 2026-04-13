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
        std::queue<TreeNode*> myQueue;
        myQueue.push(root);
        std::vector<int> result;

        while(!myQueue.empty())
        {
            int size = myQueue.size();
            bool check = true;
            for(int i = 0; i < size; ++i)
            {
                TreeNode* temp = myQueue.front();
                if(temp)
                {
                    if(check)
                    {
                        result.push_back(temp->val);
                        check = false;
                    }
                    myQueue.push(temp->right);
                    myQueue.push(temp->left);
                }
                myQueue.pop();
            }
        }

        return result;

        
    }
};
