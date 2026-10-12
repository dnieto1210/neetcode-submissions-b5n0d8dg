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
            l1 = l1->next;
        }
        else
        {
            mergeHead = l2;
            l2 = l2->next;
        }

        mergeTail = mergeHead;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                mergeTail->next = l1;
                l1 = l1->next;
                mergeTail = mergeTail->next;
            }
            else
            {
                mergeTail->next = l2;
                l2 = l2->next;
                mergeTail = mergeTail->next;
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


        vector<ListNode*> myList = lists;

        while(myList.size() != 1)
        {
            lists = myList;
            myList.resize(0);
            for(int i = 0; i < lists.size(); i += 2)
            {
                ListNode* one = lists[i];
                ListNode* two = (i + 1 < lists.size()) ? lists[i+1] : nullptr;
                ListNode* combine = merge(one, two);
                myList.push_back(combine);
            }

        }

        return myList[0];
    }
};
