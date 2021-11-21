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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddhead = new ListNode(0), *odd = oddhead;
        ListNode *evenhead = new ListNode(0), *even = evenhead;
        while( head && head->next ){
            even->next = head;
            even = even->next;
            odd->next = head->next;
            odd = odd->next;
            head = head->next->next;
        }
        if( head ){
            even->next = head;
            even = even->next;
        }
        even->next = oddhead->next;
        odd->next = NULL;
        return evenhead->next;
    }
};
