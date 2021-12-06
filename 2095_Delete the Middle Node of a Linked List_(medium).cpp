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
    ListNode* deleteMiddle(ListNode* head) {
        if( !head )return head;
        if( !head->next )return NULL;
        ListNode *fast = head, *slow = head, *prev = NULL;
        while( fast && fast->next ){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if( prev )prev->next = slow->next;
        else slow->next = NULL;
        return head;
    }
};
