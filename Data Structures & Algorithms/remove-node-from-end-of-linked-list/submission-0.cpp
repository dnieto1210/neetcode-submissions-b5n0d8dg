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

        ListNode* left = head;
        ListNode* right = head;

        int count = n;

        while(count > 0)
        {
            right = right->next;
            --count;
        }

        if(right == NULL)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        

        while(right->next)
        {
            right = right->next;
            left = left->next;
        }

        ListNode* t = left->next;
        left->next = t->next;
        t->next = nullptr;
        delete t;
        t = NULL;
        return head;
        
    }
};
