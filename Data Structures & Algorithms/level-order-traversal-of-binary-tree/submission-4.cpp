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

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> result;

        while(!q.empty())
        {
            int size = q.size();
            vector<int> nodes;
            int i = 0;
            while(i < size)
            {
                nodes.push_back(q.front()->val);
                if(q.front()->left)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right)
                {
                    q.push(q.front()->right);
                }
                q.pop();
                ++i;
            }
            result.push_back(nodes);
        }

        return result;
        
    }
};
