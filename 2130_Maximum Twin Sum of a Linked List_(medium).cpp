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
    int pairSum(ListNode* head) {
        int n = 0, mid, max_twinSum = 0;
        ListNode *cur = head, *head2, *prev = NULL;
        while( cur ){
            cur = cur->next;
            n++;
        }
        mid = n/2;
        n = 0;
        cur = head;
        while( n < mid ){
            prev = cur;
            cur = cur->next;
            n++;
        }
        head2 = prev->next;
        prev->next = NULL;
        prev = NULL;
        cur = head2;
        while( cur ){
            head2 = cur->next;
            cur->next = prev;
            prev = cur;
            cur = head2;
        }
        head2 = prev;
        cur = head;
        while( cur ){
            max_twinSum = max( max_twinSum, cur->val + head2->val );
            cur = cur->next;
            head2 = head2->next;
        }
        return max_twinSum;
    }
};
