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
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    void reorderList(ListNode* head) {

        if(!head || !head->next)
        {
            return;
        }

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        //disconnect first half 
        prev->next = nullptr;

        //now slow is the second half of the list 
        //reverse second half
        ListNode* reverse_head = reverseList(slow);

        ListNode* new_head = head;
        ListNode* new_tail = new_head;
        head = head->next;

        while(head && reverse_head)
        {
            new_tail->next = reverse_head;
            reverse_head = reverse_head->next;
            new_tail = new_tail->next;
            new_tail->next = head;
            head = head->next;
            new_tail = new_tail->next;
        }

        if(head)
        {
            new_tail->next = head;
        }
        else
        {
            new_tail->next = reverse_head;
        }




        return;
        
    }
};
