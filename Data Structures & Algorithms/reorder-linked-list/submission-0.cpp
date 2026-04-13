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
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* FindMiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next)
        {
            fast = fast->next->next;
            if(!fast)
            {
                break;
            }
            slow = slow->next;
        }

        return slow;
    }


    void reorderList(ListNode* head) {

        ListNode* middle = FindMiddle(head);
        ListNode* temp = middle->next;
        middle->next = nullptr;
        ListNode* secondList = ReverseList(temp);

        //now we merge
        ListNode* firstList = head;

        while(secondList)
        {
            ListNode* temp1 = firstList->next;
            ListNode* temp2 = secondList->next;

            firstList->next = secondList;
            secondList->next = temp1;

            firstList = temp1;
            secondList = temp2;
            
        }



        
    }
};
