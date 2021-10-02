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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head =NULL,*cur = NULL;
        if( l1 == NULL && l2==NULL )return head;
        if( l1 == NULL )return l2;
        if( l2 ==NULL)return l1;
        int sum = l1->val+l2->val;
        int carry = sum/10;
        ListNode* nw = new ListNode(sum%10);
        head = nw;
        cur = head;
        while( l1->next && l2->next ){
            l1 = l1->next;
            l2 = l2->next;
            sum = carry+ (l1->val + l2->val);
            nw = new ListNode(sum%10);
            cur->next = nw;
            cur = cur->next;
            carry = sum/10;
        }
        while( l1->next == NULL && l2->next ){
            l2 = l2->next;
            sum = carry + l2->val;
            nw = new ListNode(sum%10);
            cur->next = nw;
            cur = cur->next;
            carry = sum/10;
        }
        while( l2->next == NULL && l1->next ){
            l1 = l1->next;
            sum = carry+ l1->val;
            nw = new ListNode(sum%10);
            cur->next = nw;
            cur = cur->next;
            carry = sum/10;
        }
        while( carry> 0 ){
            nw = new ListNode(carry%10);
            cur->next = nw;
            cur = cur->next;
            carry/=10;
        }
        return head;
    }
};
