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
    int getDecimalValue(ListNode* head) {
        if( !head )return 0;
        ListNode *cur = head;
        int k = 0, res = 1, ans = 0;
        while( cur->next ){
            k++;
            res *= 2;
            cur = cur->next;
        }
        cur = head;
        while( cur ){
            ans += (res * cur->val );
            res /= 2;
            cur = cur->next;
        }
        return ans;
    }
};
