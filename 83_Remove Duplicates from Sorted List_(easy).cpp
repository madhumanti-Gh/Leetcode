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
    ListNode* deleteDuplicates(ListNode* head) {
        if( head == NULL )return head;
        ListNode *cur = head, *nextNode = head->next;
        while( nextNode ){
            if( cur->val == nextNode->val ){
                cur->next = nextNode->next;
                nextNode = nextNode->next;
            }
            else{
                cur = cur->next;
                nextNode = cur->next;
            }
        }
        return head;
    }
};
