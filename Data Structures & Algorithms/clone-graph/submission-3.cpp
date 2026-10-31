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
        if(node == nullptr) {
            return nullptr;
        }
        unordered_map<Node*, Node*> myMap;

        queue<Node*> myQ;
        myQ.push(node);

        while(!myQ.empty()) {
            Node* curr = myQ.front();
            myQ.pop();
            
            if(myMap.find(curr) != myMap.end()) {
                continue;
            }

            Node* copy = new Node();
            copy->val = curr->val;
            myMap[curr] = copy;
            for(int i = 0; i < curr->neighbors.size(); ++i) {
                Node* nei = curr->neighbors[i];
                myQ.push(nei);
            }
        }

        for(const auto kv: myMap) {
            Node* curr = kv.first;
            Node* copy = kv.second;
            for(int i = 0; i < curr->neighbors.size(); ++i){
                Node* nei = curr->neighbors[i];
                copy->neighbors.push_back(myMap[nei]);
            }
        }

        return myMap[node]; 
    }
};
