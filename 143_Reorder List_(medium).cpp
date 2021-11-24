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
    void reorderList(ListNode* head) {
        ListNode *oddhead = head, *odd = oddhead, *evenhead = head, *even = evenhead;
        ListNode *cur = head, *prev = head, *ltr = NULL;
        int n = 1;                    // 0-indexing
        // Finding the middle
        while( odd && odd->next ){
            odd = odd->next->next;
            n += 2;
            if( !odd ){
                oddhead = prev->next;
                prev->next = NULL;
                n -= 1;
            }
            else prev = prev->next;
        }
        if( prev->next ){
            oddhead = prev->next;
            prev->next = NULL;
        }
        // Reverse left half
        odd = oddhead; prev = NULL;
        while( odd ){
            ltr = odd->next;
            odd->next = prev;
            prev = odd;
            odd = ltr;
        }
        oddhead = prev;
        // merging two halves
        odd = oddhead;
        while( oddhead && evenhead ){
            evenhead = even->next;
            even->next = oddhead;
            oddhead = odd->next;
            odd->next = evenhead;
            odd = oddhead;
            even = evenhead;
        }
        if( even )even->next = NULL;
    }
};
