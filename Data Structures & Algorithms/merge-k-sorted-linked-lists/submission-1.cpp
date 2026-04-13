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
        if(!l1 && !l2)
        {
            return nullptr;
        }

        //both lists are non empty
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
            l2 = l2 = l2->next;
        }

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                merge_tail->next = l1;
                l1 = l1->next;
                merge_tail = merge_tail->next;
            }
            else
            {
                merge_tail->next = l2;
                l2 = l2->next;
                merge_tail = merge_tail->next;
            }
        }

        if(!l1)
        {
            merge_tail->next = l2;
        }
        else
        {
            merge_tail->next = l1;
        }

        return merge_head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0)
        {
            return nullptr;
        }

        ListNode* m_head = nullptr;

        for(int i = 0; i < lists.size(); ++i)
        {
            ListNode* temp1 = lists[i];
            ListNode* t = merge(m_head, temp1);
            m_head = t;
        }
        return m_head;
    }
};
