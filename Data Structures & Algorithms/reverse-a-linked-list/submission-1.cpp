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
    ListNode* reverseList(ListNode* head) {
        ListNode *prevNode = nullptr;
        ListNode *nextNode = nullptr;
        ListNode *curNode = head;

        while(curNode != nullptr) 
        {
            nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        head = prevNode;
        return head;
    }
};
