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
        unordered_map<Node*, Node*> myMap;

        myMap[node] = new Node(node->val);
        queue<Node*> myQueue;
        myQueue.push(node);

        while(!myQueue.empty())
        {
            Node* temp = myQueue.front();
            myQueue.pop();
            int size = temp->neighbors.size();
            Node* clone = myMap[temp];
            for(int i = 0; i < size; ++i)
            {
                Node* n = temp->neighbors[i];
                if(myMap.find(n) == myMap.end())
                {
                    //we have not reached that node yet
                    myMap[n] = new Node(n->val);
                    myQueue.push(n);
                }
                clone->neighbors.push_back(myMap[n]);
            }
        }

        return myMap[node];
        
    }
};
