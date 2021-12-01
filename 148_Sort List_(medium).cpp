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
    ListNode* find_mid( ListNode *head ){
        ListNode *slow = head, *fast = head, *prev = slow;
        while( fast && fast->next ){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        return slow;
    }
    ListNode* merge( ListNode *left, ListNode *right ){
        ListNode *i = left, *j = right, *temp;
        ListNode *dummyhead = new ListNode(0);
        temp = dummyhead;
        while( i && j ){
            if( i->val <= j->val ){
                temp->next = i;
                i = i->next;
            }
            else{
                temp->next = j;
                j = j->next;
            }
            temp = temp->next;
        }
        if( i ){
            temp->next = i;
            i = i->next;
            temp = temp->next;
        }
        if( j ){
            temp->next = j;
            j = j->next;
            temp = temp->next;
        }
        return dummyhead->next;
    }
    ListNode* MergeSort( ListNode *head ){
        if( !head )return head;
        ListNode *mid = find_mid( head );
        if( head != mid ){
            ListNode *left = MergeSort( head );
            ListNode *right = MergeSort( mid );
            head = merge( left, right );
            // return newhead;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        return MergeSort( head );
    }
};
