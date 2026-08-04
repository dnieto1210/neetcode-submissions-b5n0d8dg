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
    Node* cloneGraph(Node* node) {

        if(!node)
        {
            return nullptr;
        }

        //otherwise we are guaranteed at least one node

        unordered_map<int, Node*> newNodes;
        unordered_map<int, Node*> oldNodes;
        stack<Node*> myStack;
        myStack.push(node);

        while(!myStack.empty())
        {
            Node* curr = myStack.top();
            myStack.pop();

            int val = curr->val;
            //we will treat marking as being in the map so if you are not in the map then you have not been visited yet
            if(oldNodes.find(val) == oldNodes.end())
            {
                //has not been visited yet
                oldNodes[val] = curr;
                newNodes[val] = new Node(val);
                vector<Node*>& n = curr->neighbors;
                for(int i = 0; i < n.size(); ++i)
                {
                    Node* temp = n[i];
                    myStack.push(temp);
                }
            }
        }

        for(auto kv: newNodes)
        {
            int val = kv.first;
            Node* curr = kv.second;
            vector<Node*>& neighs = oldNodes[val]->neighbors;
            for(int i = 0; i < neighs.size(); ++i)
            {
                Node* temp = neighs[i];
                int temp_val = temp->val;
                Node* newAdj = newNodes[temp_val];
                curr->neighbors.push_back(newAdj);
            }
        }

        return newNodes[1];
    }
};
