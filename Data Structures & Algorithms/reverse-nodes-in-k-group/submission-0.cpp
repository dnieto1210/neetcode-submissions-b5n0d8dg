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
    ListNode* reverse(ListNode* node)
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
        if(k == 1 || !head)
        {
            return head;
        }
        ListNode* reverse_head = nullptr;

        ListNode* start_head = head;
        ListNode* end_node = head;
        ListNode* tail_of_last_group = nullptr;
        bool head_found = false;

        while(end_node)
        {
            int count = k-1;

            while(count > 0 && end_node)
            {
                end_node = end_node->next;
                --count;
            }

            if(!end_node)
            {
                if(tail_of_last_group)
                {
                    tail_of_last_group->next = start_head;
                }
                else
                {
                    reverse_head = head;
                }
                break;
            }

            ListNode* future_group = end_node->next;
            end_node->next = nullptr;
            ListNode* head_of_reverse = reverse(start_head);
            if(!head_found)
            {
                head_found = true;
                reverse_head = head_of_reverse;
            }
            if(tail_of_last_group)
            {
                tail_of_last_group->next = head_of_reverse;
            }
            tail_of_last_group = start_head;
            start_head = future_group;
            end_node = start_head;

        }

        return reverse_head;
        
    }
};
