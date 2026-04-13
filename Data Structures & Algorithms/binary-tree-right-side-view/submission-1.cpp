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
        std::vector<int> result;

        std::queue<TreeNode*> myQueue;
        myQueue.push(root);

        while(!myQueue.empty())
        {
            int size = myQueue.size();
            std::vector<int> currentLevel;
            for(int i = 0; i < size; ++i)
            {
                TreeNode* temp = myQueue.front();
                myQueue.pop();
                currentLevel.push_back(temp->val);
                
                if(temp->left)
                {
                    myQueue.push(temp->left);
                }
                if(temp->right)
                {
                    myQueue.push(temp->right);
                }
            }
            int group = currentLevel.size();
            if(group > 0)
            {
                result.push_back(currentLevel[group-1]);
            }
        }

        return result;

        
    }
};
