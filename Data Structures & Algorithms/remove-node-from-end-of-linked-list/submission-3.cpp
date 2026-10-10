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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* slow = head;
        ListNode* fast = head;
        for(int i = 0; i < n && fast; ++i)
        {
            fast = fast->next;
        }

        if(!fast)
        {
            ListNode* temp = head->next;
            head->next = nullptr;
            head = temp;
            return head;
        }

        //otherwise fast is stil valid
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        //slow is pointing to the node that needs to get removed
        ListNode* rem = slow->next;
        ListNode* temp = rem->next;
        slow->next = temp;
        rem->next = nullptr;
        return head;
    }
};
