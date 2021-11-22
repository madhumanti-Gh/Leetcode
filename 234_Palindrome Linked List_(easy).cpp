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
    bool isPalindrome(ListNode* head) {
        ListNode *cur = head;
        int n = 0, mid;
        while( cur ){
            cur = cur->next;
            n++;
        }
        stack<int> st;
        cur = head;
        mid = 0;
        while( mid < n/2 ){
            st.push( cur->val );
            cur = cur->next;
            mid++;
        }
        if( n%2 != 0 ){
            cur = cur->next;
        }
        while( cur ){
            if( cur->val == st.top() ){
                st.pop();
                cur = cur->next;
            }
            else return false;
        }
        return true;
    }
};
