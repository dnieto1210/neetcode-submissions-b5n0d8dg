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

    ListNode* ReverseList(ListNode* head)
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

    int number(ListNode* list)
    {
        int number1 = 0;
        int exponent = 0;
        while(list)
        {
            int val = list->val;
            number1 += static_cast<int>(pow(10, exponent)) * val;
            ++exponent;
            list = list->next;

        }

        return number1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int number1 = number(l1);
        int number2 = number(l2);
        int result = number1 + number2;
        bool head_found = false;
        ListNode* head_sum_list = nullptr;
        if(result == 0)
        {
            head_sum_list = new ListNode(0);
            return head_sum_list;
        }

        ListNode* traverse = new ListNode(0);
        head_sum_list = traverse;
        ListNode* temp = nullptr;

        while(result > 0)
        {
            int to_put = result % 10;
    

            traverse->val = to_put;
            temp = traverse;
            traverse->next = new ListNode(0);
            traverse = traverse->next;
            result = (result - to_put) / 10;
        }

        delete traverse;
        traverse = nullptr;
        temp->next = nullptr;

        return head_sum_list;



        
    }
};
