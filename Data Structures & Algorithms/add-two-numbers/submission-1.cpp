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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        
        int num1 = 0;
        int num2 = 0;
        int power = 1;
        while(l1)
        {
            int val = l1->val;
            num1 += (val * power);
            l1 = l1->next;
            power *= 10;
        }

        power = 1;

        while(l2)
        {
            int val = l2->val;
            num2 += (val * power);
            l2 = l2->next;
            power *= 10;
        }

        int result = num1 + num2;

        ListNode* head = nullptr;
        if(result == 0)
        {
            ListNode* temp = new ListNode(0);
            head = temp;
            return head;
        }
        ListNode* traverse = nullptr;

        while(result > 0)
        {
            int val = result % 10;
            if(!head)
            {
                ListNode* temp = new ListNode(val);
                head = temp;
                traverse = head;
            }
            else
            {
                ListNode* temp = new ListNode(val);
                traverse->next = temp;
                traverse = traverse->next;
            }

            result = (result - val) / 10;

        }

        return head;
        
    }
};
