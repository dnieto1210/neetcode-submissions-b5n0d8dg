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
        if(head == nullptr)
        {
            return nullptr;
        }
        Node *new_head = new Node(head->val);
        Node *new_traverse = new_head;
        std::unordered_map<Node*, Node*> myMap;

        Node *traverse = head;
        myMap[traverse] = new_traverse;
        while (traverse)
        {
            traverse = traverse->next;
            Node* new_node = nullptr;
            if(traverse)
            {
                new_node = new Node(traverse->val);
                myMap[traverse] = new_node;
            }
            new_traverse->next = new_node;
            new_traverse = new_node;

        }

        traverse = head;
        new_traverse = new_head;
        while(traverse)
        {
            Node* ran = traverse->random;
            if(ran == traverse)
            {
                new_traverse->random = new_traverse;
            }
            else if(ran == nullptr)
            {
                new_traverse->random = nullptr;
            }

            Node* temp = myMap[ran];
            new_traverse->random = temp;

            new_traverse = new_traverse->next;
            traverse = traverse->next;
        }

        return new_head;
        
    }
};
