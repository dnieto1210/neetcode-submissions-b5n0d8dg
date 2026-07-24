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

    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr= head;
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

    ListNode* midList(ListNode* head)
    {
        if(!head)
        {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            if(!fast || !(fast->next))
            {
                ListNode* res = slow->next;
                slow->next = nullptr;
                return res;
            }
            slow = slow->next;
        }

        return slow;
    }
    void reorderList(ListNode* head) {

        if(!head || !(head->next))
        {
            return;
        }

        ListNode* secondHalf = midList(head);
        ListNode* rsecondHalf = reverseList(secondHalf);

        ListNode* firstHalf = head;
        ListNode* traverse = new ListNode(0);
        ListNode* dummy = traverse;

        while(firstHalf && rsecondHalf)
        {
            traverse->next = firstHalf;
            firstHalf = firstHalf->next;
            traverse = traverse->next;
            traverse->next = rsecondHalf;
            rsecondHalf = rsecondHalf->next;
            traverse = traverse->next;  
        }

        if(rsecondHalf)
        {
            traverse->next = secondHalf;
        }

        //dummy->next = nullptr;
        //delete dummy;
        return;
        
    }
};
