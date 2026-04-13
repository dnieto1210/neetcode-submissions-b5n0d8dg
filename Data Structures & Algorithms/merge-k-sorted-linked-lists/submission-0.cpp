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

        ListNode* mergeHead = nullptr;
        ListNode* mergeTail = nullptr;

        if(l1->val < l2->val)
        {
            mergeHead = l1;
            mergeTail = l1;
            l1 = l1->next;
        }
        else
        {
            mergeHead = l2;
            mergeTail = l2;
            l2 = l2->next;
        }

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                mergeTail->next = l1;
                mergeTail = l1;
                l1 = l1->next;
            }
            else
            {
                mergeTail->next = l2;
                mergeTail = l2;
                l2 = l2->next;
            }

        }

        if(!l1)
        {
            mergeTail->next = l2;
        }
        else
        {
            mergeTail->next = l1;
        }

        return mergeHead;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
        {
            return nullptr;
        }
        if(lists.size() == 1)
        {
            return lists[0];
        }

        //otherwise there are at least two lists
        ListNode* potential_head = merge(lists[0], lists[1]);

        for(int i = 2; i < lists.size(); ++i)
        {
            potential_head = merge(potential_head, lists[i]);
        }

        return potential_head;
        
    }
};
