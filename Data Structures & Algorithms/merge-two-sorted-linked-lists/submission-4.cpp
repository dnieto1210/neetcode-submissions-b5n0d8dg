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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
        {
            return list2;
        }
        else if(!list2)
        {
            return list1;
        }

        //both lists are non empty
        ListNode* nhead = nullptr;
        ListNode* ntail = nullptr;
        if(list1->val < list2->val)
        {
            nhead = list1;
            ntail = nhead;
            list1 = list1->next;
        }
        else
        {
            nhead = list2;
            ntail = nhead;
            list2 = list2->next;
        }

        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                ntail->next = list1;
                ntail = ntail->next;
                list1 = list1->next;
            }
            else
            {
                ntail->next = list2;
                ntail = ntail->next;
                list2 = list2->next;
            }
        }

        //check if any list is null
        if(!list1)
        {
            ntail->next = list2;
        }
        else
        {
            ntail->next = list1;
        }

        return nhead;
    }
};
