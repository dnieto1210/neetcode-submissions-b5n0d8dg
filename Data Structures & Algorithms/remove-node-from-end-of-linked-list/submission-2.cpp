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

        ListNode* first = head;
        ListNode* second = head;

        for(int i = 0; i < n; ++i)
        {
            second = second->next;
        }

        while(second && second->next)
        {
            first = first->next;
            second = second->next;
        }

        if(!second)
        {
            return head->next;
        }

        ListNode* rem = first->next;
        first->next = rem->next;
        rem->next = nullptr;
        return head;
    }
};
