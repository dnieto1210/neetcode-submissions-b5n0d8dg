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

    ListNode* rev(ListNode* head)
    {
        ListNode* curr = head;
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

    ListNode* mid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            if(!fast || !fast->next)
            {
                return slow;
            }
            slow = slow->next;
        }
        return nullptr;
    }
    void reorderList(ListNode* head) {
        if(!head)
        {
            return;
        }

        ListNode* cut = mid(head);
        if(!cut)
        {
            //single point
            return;
        }

        ListNode* secondHalf = cut->next;
        cut->next = nullptr;
        ListNode* l2 = rev(secondHalf);
        ListNode* l1 = head;

        ListNode* dummy = new ListNode();
        ListNode* traverse = dummy;

        while(l1 && l2)
        {
            ListNode* l1Next = l1->next;
            ListNode* l2Next = l2->next;

            dummy->next = l1;
            dummy = l1;
            dummy->next = l2;
            dummy = l2;

            l1 = l1Next;
            l2= l2Next;
        }

        return;  
    }
};
