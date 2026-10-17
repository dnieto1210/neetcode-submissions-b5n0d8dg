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
    void dfs(TreeNode* node, vector<TreeNode*>& arr)
    {
        if(!node)
        {
            arr.push_back(nullptr);
            return;
        }

        arr.push_back(node);
        dfs(node->left, arr);
        dfs(node->right, arr);
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        //preorder traversal
        if(!root)
        {
            return "nullptr";
        }

        vector<TreeNode*> arr;
        string result = "";
        dfs(root, arr);

        for(int i = 0; i < arr.size(); ++i)
        {
            TreeNode* curr = arr[i];
            if(curr == nullptr)
            {
                result += "nullptr,";
            }
            else
            {
                result += to_string(curr->val) + ',';
            }
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* mydfs(int& i, string& s)
    {
        //get substring
        int idx = s.find(',', i);
        string curr = s.substr(i, idx-i);
        i = idx+1;
        if(curr == "nullptr")
        {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(curr));
        node->left = mydfs(i, s);
        node->right = mydfs(i, s);
        return node;
    }
    TreeNode* deserialize(string data) {

        if(data == "nullptr")
        {
            return nullptr;
        }

        int i = 0;

        TreeNode* root = mydfs(i, data);
        return root;
    }
};
