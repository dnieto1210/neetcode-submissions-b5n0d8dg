/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        {
            return {};
        }
        unordered_map<Node*, int> myMap;

        Node* traverse = head;
        int i = 0;
        vector<Node*> myList;

        while(traverse)
        {
            Node* n = new Node(traverse->val);
            myList.push_back(n);
            myMap[traverse] = i;
            traverse = traverse->next;
            ++i;
        }

        traverse = head;

        for(int i = 0; i < myList.size(); ++i)
        {
            Node* n = myList[i];

            //next pointers
            if(i == myList.size()-1)
            {
                n->next = nullptr;
            }
            else
            {
                n->next = myList[i+1];
            }

            //random pointers
            Node* r = traverse->random;
            if(!r)
            {
                n->random = nullptr;
            }
            else
            {
                int idx = myMap[r];
                n->random = myList[idx];
            }
            traverse = traverse->next;

        }

        return myList[0];


        
    }
};
