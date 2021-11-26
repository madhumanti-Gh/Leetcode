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
    ListNode* merge( ListNode *l1, ListNode *l2 ){
        if( !l1 && !l2 )return NULL;
        if( !l1 )return l2;
        if( !l2 )return l1;
        ListNode *head = new ListNode(0), *i = l1, *j = l2, *temp = head;
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
        while( i ){
            temp->next = i;
            i = i->next;
            temp = temp->next;
        }
        while( j ){
            temp->next = j;
            j = j->next;
            temp = temp->next;
        }
        return head->next;
    }
    ListNode* MergeSort( vector<ListNode*>& lists, int left, int right ){
        int mid = (left + right)/2;
        if( left < right ){
            ListNode *A = MergeSort( lists, left, mid );
            ListNode *B = MergeSort( lists, mid+1, right );
            return merge( A, B );
        }
        return lists[left];
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if( n == 0 )return NULL;
        return MergeSort( lists, 0, n-1 );
    }
};
