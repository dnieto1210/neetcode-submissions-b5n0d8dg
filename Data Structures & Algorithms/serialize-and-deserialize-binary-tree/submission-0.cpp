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

class Codec {
public:
    string result;

    void dfs(TreeNode* node)
    {
        if(!node)
        {
            result += "null,";
            return;
        }

        result += to_string(node->val) + ",";
        dfs(node->left);
        dfs(node->right);
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //we will perform a pre order dfs traversal
        if(!root)
        {
            return "null,";
        }

        dfs(root);
        return result;
    }

    // Decodes your encoded data to tree.

    void dfs(TreeNode*& ref, int& idx, string& data)
    {
        //get value
        string value;
        int i = idx;
        for(;i < data.size(); ++i)
        {
            if(data[i] == ',')
            {
                break;
            }
            else
            {
                value += data[i];
            }
        }
        i++;
        idx = i;
        if(value == "null")
        {
            ref = nullptr;
            return;
        }
        int v = stoi(value);
        TreeNode* node = new TreeNode(v);
        ref = node;
        dfs(node->left, idx, data);
        dfs(node->right, idx, data);
    }
    TreeNode* deserialize(string data) {
        if(data == "null,")
        {
            return nullptr;
        }


        TreeNode* root = nullptr;
        int index = 0;
        dfs(root, index, data);
        return root;
    }
};
