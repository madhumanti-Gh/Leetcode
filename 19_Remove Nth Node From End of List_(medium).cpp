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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int t = n-1;
        ListNode *temp = head;
        while(t--){
            temp= temp->next; 
        }
        ListNode *cur = head;
        ListNode *prev = NULL;
        while(temp->next != NULL){
            prev = cur;
            cur = cur->next;
            temp = temp->next;
        }
        if(prev == NULL){
            return head->next;
        }
        else{
            prev->next = cur->next;
            return head;
        }
    }
};
