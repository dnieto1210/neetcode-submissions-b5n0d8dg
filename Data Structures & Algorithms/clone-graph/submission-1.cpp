/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* dfs(Node* n, unordered_map<Node*, Node*>& oldNew)
    {
        if(!n)
        {
            return nullptr;
        }

        //otherwise we have a valid node
        Node* temp = new Node(n->val);
        oldNew[n] = temp;

        for(int i = 0; i < n->neighbors.size(); ++i)
        {
            Node* o = n->neighbors[i];
            if(oldNew.find(o) != oldNew.end())
            {
                //already visisted 
                temp->neighbors.push_back(oldNew[o]);
            }
            else
            {
                //not visisted yet
                temp->neighbors.push_back(dfs(o, oldNew));
            }
        }

        return temp;
    }
    Node* cloneGraph(Node* node) {

        unordered_map<Node*, Node*> oldNew;
        Node* deep = dfs(node, oldNew);
        return deep;
        
    }
};
