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
    ListNode* partition(ListNode* head, int x) {
        if( !head )return head;
        ListNode *smallhead = new ListNode(0), *small = smallhead;
        ListNode *eqlhead = new ListNode(0), *eql = eqlhead, *cur = head;
        while( cur ){
            if( cur->val < x ){
                small->next = cur;
                small = small->next;
            }
            else{
                eql->next = cur;
                eql = eql->next;
            }
            cur = cur->next;
        }
        small->next = eqlhead->next;
        eql->next = NULL;
        if( smallhead->next )
            return smallhead->next;
        return eqlhead->next;
    }
};
