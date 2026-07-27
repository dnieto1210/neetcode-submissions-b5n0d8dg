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
            return nullptr;
        }

        Node* copyHead = new Node(head->val);
        unordered_map<Node*, Node*> myMap;
        myMap[head] = copyHead;
        Node* traverse = head->next;

        while(traverse)
        {
            Node* node = new Node(traverse->val);
            myMap[traverse] = node;
            traverse = traverse->next;
        }

        for(auto kv: myMap)
        {
            Node* key = kv.first;
            Node* val = kv.second;

            Node* next = key->next;
            Node* ran = key->random;

            if(next)
            {
                Node* copyNext = myMap[next];
                val->next = copyNext;
            }
            else
            {
                val->next = nullptr;
            }

            if(ran)
            {
                Node* ranNext = myMap[ran];
                val->random = ranNext;
            }
            else
            {
                val->random = nullptr;
            }
        }

        return copyHead;
        
    }
};
