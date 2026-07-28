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
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(!l1)
        {
            return l2;
        }
        if(!l2)
        {
            return l1;
        }

        ListNode* merge_head = nullptr;
        ListNode* merge_tail = nullptr;

        if(l1->val < l2->val)
        {
            merge_head = l1;
            merge_tail = merge_head;
            l1 = l1->next;
        }
        else
        {
            merge_head = l2;
            merge_tail = merge_head;
            l2 = l2->next;
        }

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                merge_tail->next = l1;
                merge_tail = merge_tail->next;
                l1 = l1->next;
            }
            else
            {
                merge_tail->next = l2;
                merge_tail = merge_tail->next;
                l2 = l2->next;
            }
        }

        if(l1)
        {
            merge_tail->next = l1;
        }
        else
        {
            merge_tail->next = l2;
        }

        return merge_head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    
        ListNode* merge_head = nullptr;
        ListNode* temp = lists[0];

        for(int i = 1; i < lists.size(); ++i)
        {
            temp = merge(temp, lists[i]);
            merge_head = temp;
        }

        return merge_head;
    }
};
