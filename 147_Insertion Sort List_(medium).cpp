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
    ListNode* insertionSortList(ListNode* head) {
        if( !head || !head->next )return head;
        ListNode *dummy = new ListNode(-6000);
        dummy->next = head;
        ListNode *pivot = head->next, *cur = head, *temp, *t;
        while( pivot ){
            if( pivot->val < cur->val ){
                temp = dummy;
                while( temp->next->val <= pivot->val )temp = temp->next;
                t = pivot;
                cur->next = pivot->next;
                pivot = cur;
                t->next = temp->next;
                temp->next = t;
            }
            cur = pivot;
            pivot = pivot->next;
        }
        return dummy->next;
    }
};
