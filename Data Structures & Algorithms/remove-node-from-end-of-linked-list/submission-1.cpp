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

        int times = n;
        ListNode* right = head;
        ListNode* left = head;

        while(right && times > 0)
        {
            right = right->next;
            --times;
        }

        if(!right)
        {
            head = head->next;
            return head;
        }

        //otherwise

        while(right->next)
        {
            right = right->next;
            left = left->next;
        }

        ListNode* remove = left->next;
        left->next = remove->next;
        remove->next = nullptr;

        return head;
        
    }
};
