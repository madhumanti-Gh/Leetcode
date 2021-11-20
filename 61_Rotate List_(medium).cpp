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
    ListNode* rotateRight(ListNode* head, int k) {
        if( !head )return head;
        ListNode *cur = head, *temp = head;
        int n = 1;
        while( cur->next ){
            cur = cur->next;
            n++;
        }
        k = k%n;
        n = n-k;
        cur->next = head;
        while( n-- ){
            cur = cur->next;
        }
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};
