/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* node)
    {
        ListNode* curr = node;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(!head)
        {
            return nullptr;
        }

        ListNode* dummy = new ListNode();
        dummy->next= head;
        ListNode* lastList = dummy;
        ListNode* traverse = dummy->next;
        int count = 1;
       // ListNode* finalHead = nullptr;


        while(traverse)
        {

            if(count % k == 0)
            {
                //traverse is in the last node
                ListNode* target = lastList->next;
                ListNode* save = traverse->next;
                traverse->next = nullptr;
                lastList->next = nullptr;
                ListNode* reverseHead = reverseList(target);
                /*
                if(!finalHead)
                {
                    finalHead = reverseHead;
                }
                */

                lastList->next = reverseHead;
                lastList = target;
                traverse = target;
                traverse->next = save;
            }
            traverse = traverse->next;
            ++count;
        }

        //dummy->next = nullptr;
       // delete dummy;
        return dummy->next;
        
    }
};
