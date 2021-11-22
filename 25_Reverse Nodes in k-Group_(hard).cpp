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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if( k == 1 )return head;
        ListNode *prev = NULL, *ltr = NULL, *cur = head, *temp, *temphead = head, *temptail;
        int count = 1;
        bool flag = true;
        while( cur->next != NULL ){
            count++;
            cur = cur->next;
            if( count == k ){
                temp = cur;
                cur = cur->next;
                temp->next = NULL;
                prev = NULL; ltr = NULL; temp = temphead;
                while( temp ){
                    ltr = temp->next;
                    temp->next = prev;
                    prev = temp;
                    temp = ltr;
                }
                if( flag ){
                    head = prev;
                    flag = false;
                }
                else{
                    temptail->next = prev;
                }
                temptail = temphead;
                count = 1;
                temphead = cur;
            }
            if( !cur )break;
        }
        if( count < k && ( !cur || !cur->next ) ){
            temptail->next = temphead;
        }
        return head;
    }
};
