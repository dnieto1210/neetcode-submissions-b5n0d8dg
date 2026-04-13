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
        if(!list1 && !list2)
        {
            return nullptr;
        }
        else if(!list1)
        {
            return list2;
        }
        else if(!list2)
        {
            return list1;
        }

        //otherwise both lists have an element 

        ListNode* merged_head = nullptr;
        ListNode* merged_tail = nullptr;
        if(list1->val < list2->val)
        {
            merged_head = list1;
            list1 = list1->next;
        }
        else
        {
            merged_head = list2;
            list2 = list2->next;
        }

        merged_tail = merged_head;

        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                merged_tail->next = list1;
                list1 = list1->next;
                merged_tail = merged_tail->next;
            }
            else
            {
                merged_tail->next = list2;
                list2 = list2->next;
                merged_tail = merged_tail->next;
            }
        }

        if(!list1)
        {

            merged_tail->next = list2;
        }
        else
        {
            merged_tail->next = list1;
        }

        return merged_head;
        
    }
};
