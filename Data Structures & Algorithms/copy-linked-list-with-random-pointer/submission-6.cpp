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


        unordered_map<Node*, Node*> myMap;
        Node* dummy = new Node(0);
        Node* traverse = dummy;
        Node* follow = head;
        while(follow)
        {
            Node* temp = new Node(follow->val);
            traverse->next = temp;
            traverse = traverse->next;
            myMap[follow] = traverse;
            follow = follow->next;
        }

        //should be the same length
        traverse = dummy->next;
        follow = head;
        while(follow)
        {
            //get follow's random pointer
            if(follow->random == nullptr)
            {
                traverse->random = nullptr;
            }
            else
            {
                Node* newRan = myMap[follow->random];
                traverse->random = newRan;
            }
            traverse = traverse->next;
            follow = follow->next;
        }

        return dummy->next;
    }
};
