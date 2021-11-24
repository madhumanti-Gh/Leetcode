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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummyhead = new ListNode(502, head);
        ListNode *cur = dummyhead, *Lnode = NULL, *Rnode = NULL, *temptail = NULL, *temphead = NULL;
        int n = 0;
        while( cur ){
            if( n == left-1 ){
                Lnode = cur->next;
                n++;
                temptail = cur;
                cur = Lnode;
                ListNode *prev = NULL, *ltr = NULL;
                while( cur && n <= right ){
                    ltr = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = ltr;
                    n++;
                }
                temptail->next = prev;
                Lnode->next = cur;
                break;
            }
            cur = cur->next;
            n++;
        }
        return dummyhead->next;
    }
};
