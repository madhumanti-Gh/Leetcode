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
    ListNode* swapNodes(ListNode* head, int k) {
        if( !head || !head->next )return head;
        int idx1 = 0, idx2 = 0;
        int cnt = 0;
        ListNode *temp = head, *first = head, *last = head;
        while( temp != NULL ){
            idx1++;cnt++;
            if( k > idx1 ){
                first = first->next;
            }
            temp = temp->next;
        }
        cout<<cnt<<" ";
        cnt = cnt - k;
        temp = head;
        while( idx2 < cnt ){
            last = last->next;
            idx2++;
        }
        swap( first->val, last->val );
        
        return head;
    }
};
