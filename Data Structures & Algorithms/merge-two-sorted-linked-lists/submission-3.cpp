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
        
        ListNode headOfMerged(0);
        ListNode * mergedList = &headOfMerged;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
                mergedList->next = list1;
                list1 = list1->next;
            }
            else
            {
                mergedList->next =list2;
                list2 = list2->next;
            }
            mergedList = mergedList->next;
        }
       mergedList->next = (list1 != nullptr)?list1:list2;

        return headOfMerged.next;
    }
};
