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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
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

    ListNode* findSecond(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;

        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return prev;
    }
    void reorderList(ListNode* head) {

        //find second half
        ListNode* prev = findSecond(head);

        if(!prev)
        {
            return;
        }
        ListNode* list2 = prev->next;
        prev->next = nullptr;

        //reverse second list
        ListNode* reverse2 = reverse(list2);

        //interleave nodes

        ListNode* tail = head;
        ListNode* list1 = head->next;
        

        while(list1 && reverse2)
        {
            tail->next = reverse2;
            reverse2 = reverse2->next;
            tail = tail->next;
            tail->next = list1;
            list1 = list1->next;
            tail = tail->next;
        }

        if(reverse2)
        {
            tail->next = reverse2;
        }
        else
        {
            tail->next = list1;
        }

        return;
        
    }
};
