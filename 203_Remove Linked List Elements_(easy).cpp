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
    ListNode* removeElements(ListNode* head, int val) {
        if( !head )return head;
        ListNode *prev = head, *cur = head->next, *temp = NULL;
        if( head->val == val && head->next == NULL )return head->next;
        
        while( cur ){
            if( head->val == val ){
                prev = head;
                head = head->next;
                cur = head;
                continue;
            }
            if( cur->val == val && ( cur->next == NULL || cur->next->val != val ) && prev->val != val ){
                prev->next = cur->next;
            }
            else if( cur->val != val ){
                if( prev->next->val != val )prev = prev->next;
            }
            cur = cur->next;
        }
        return head;
    }
};
