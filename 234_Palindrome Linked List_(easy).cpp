// Another similar code
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
        ListNode *slow = head, *fast = head, *prev = NULL, *ltr = NULL;
        int odd = 0;
        while( fast->next && fast->next->next ){
            fast = fast->next->next;
            slow = slow->next;
        }
        if( !fast->next )odd = 1;
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        while( slow ){
            ltr = slow->next;
            slow->next = prev;
            prev = slow;
            slow = ltr;
        }
        head = prev;
        if( odd )head = head->next;
        while( fast ){
            if( fast->val != head->val )return false;
            fast = fast->next;
            head = head->next;
        }
        return true;
    }
};

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
