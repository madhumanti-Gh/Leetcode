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
    ListNode* swapPairs(ListNode* head) {
        if( !head || !head->next )return head;
        
        ListNode *temp, *slow = head, *fast = head->next;
        head = fast;
        while( slow && fast ){
            temp = fast->next;
            fast->next = slow;
            
            if( !temp || !temp->next ){
                slow->next = temp;
                break;
            }
            slow->next = temp->next;
            
            slow = temp;
            fast = slow->next;
        }
        return head;
    }
};
