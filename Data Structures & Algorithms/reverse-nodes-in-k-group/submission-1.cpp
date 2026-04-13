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
    ListNode* reverseKGroup(ListNode* head, int k) {

        int count = 0;
        ListNode* traverse= head;
        while(traverse)
        {
            ++count;
            traverse = traverse->next;
        }

        if(count < k)
        {
            return head;
        }

        //otherwise there are >= k nodes

        ListNode* left = head;
        ListNode* right = head;
        ListNode* temp = nullptr;
        ListNode* r_head = nullptr;
        ListNode* last_tail = nullptr;
        count = 0;

        while(right)
        {
            ++count;
            if(count % k == 0)
            {
                temp = right->next;
                right->next = nullptr;
                ListNode* r = reverse(left);
                left->next = temp;
                if(last_tail)
                {
                    last_tail->next = r;
                    last_tail = left;
                }
                else
                {
                    last_tail = left;
                }

                if(!r_head)
                {
                    r_head = r;
                }

                left = temp;
                right = left;
                continue;


            }
            right = right->next;
            

        }
        
        return r_head;
    }
};
