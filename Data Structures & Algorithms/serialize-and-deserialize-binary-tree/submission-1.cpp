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
    void dfs(TreeNode* node)
    {
        if(!node)
        {
            order.push_back(nullptr);
            return;
        }

        TreeNode* temp= new TreeNode(node->val);

        order.push_back(temp);

        dfs(node->left);
        dfs(node->right);
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
        {
            return "";
        }

        string result = "";
        dfs(root);

        for(int i = 0; i < order.size(); ++i)
        {
            TreeNode* node = order[i];
            if(!node)
            {
                result += "null,";
            }
            else
            {
                result += to_string(node->val)+ ",";
            }

        }

        return result;
        
    }

    TreeNode* construct(vector<TreeNode*>& arr, int& idx)
    {
        if(arr[idx] == nullptr)
        {
            return nullptr;
        }

        TreeNode* curr = arr[idx];

        curr->left = construct(arr, ++idx);
        curr->right = construct(arr, ++idx);
        return curr;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
        {
            return nullptr;
        }

        int left =0;
        int right = 0;
        vector<TreeNode*> build;

        while(right < data.size())
        {
            string word = "";
            bool null = false;
            while(data[right] != ',')
            {
                word += data[right];
                ++right;
            }

            if(word == "null")
            {
                build.push_back(nullptr);
            }
            else
            {
                int num = stoi(word);
                TreeNode* node = new TreeNode(num);
                build.push_back(node);
            }

            ++right;
        }

        int idx = 0;
        TreeNode* root = construct(build, idx);
        return root; 
    }
private:
    vector<TreeNode*> order;
};
