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
    void preOrder(vector<TreeNode*>& arr, TreeNode* node)
    {
        if(!node)
        {
            arr.push_back(nullptr);
            return;
        }

        arr.push_back(node);
        preOrder(arr, node->left);
        preOrder(arr, node->right);
        return;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {

        vector<TreeNode*> p_arr;
        vector<TreeNode*> q_arr;
        preOrder(p_arr, p);
        preOrder(q_arr, q);

        if(p_arr.size() != q_arr.size())
        {
            return false;
        }

        //otherwise they are same size
        for(int i = 0; i < p_arr.size(); ++i)
        {
            TreeNode* pCurr = p_arr[i];
            TreeNode* qCurr = q_arr[i];
            if(!pCurr && qCurr)
            {
                return false;
            }
            else if(pCurr && !qCurr)
            {
                return false;
            }
            else if(!pCurr && !qCurr)
            {
                continue;
            }
            else if(pCurr->val != qCurr->val)
            {
                return false;
            }
        }
        return true;
        
    }
};
