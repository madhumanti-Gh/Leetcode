/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0, n = 0;
        ListNode *head = headA;
        while( head ){
            head = head->next;
            m++;
        }
        head = headB;
        while( head ){
            head = head->next;
            n++;
        }
        int dif;
        if( m >= n ){
            dif = m-n;
            while( dif-- ){
                headA = headA->next;
            }
        }
        else{
            dif = n-m;
            while( dif-- ){
                headB = headB->next;
            }
        }
        while( headA && headB ){
            if( headA == headB )return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
