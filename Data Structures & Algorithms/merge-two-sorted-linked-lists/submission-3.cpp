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
        if(list1 && !list2)
        {
            return list1;
        }
        if(list2 && !list1)
        {
            return list2;
        }
        if(!list2 && !list1)
        {
            return nullptr;
        }

        //otherwise both lists have elements

        ListNode* merge_head = nullptr;
        ListNode* merge_tail = nullptr;

        if(list1->val < list2->val)
        {
            merge_head = list1;
            list1 = list1->next;
        }
        else
        {
            merge_head = list2;
            list2 = list2->next;
        }

        merge_tail = merge_head;

        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                merge_tail->next = list1;
                merge_tail = merge_tail->next;
                list1 = list1->next;
            }
            else
            {
                merge_tail->next = list2;
                merge_tail = merge_tail->next;
                list2 = list2->next;
            }
        }

        if(list1)
        {
            merge_tail->next = list1;
        }
        else
        {
            merge_tail->next = list2;
        }

        return merge_head;
        
    }
};
