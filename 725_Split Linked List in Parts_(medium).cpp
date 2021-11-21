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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode *cur = head, *temp = NULL, *prev = NULL;
        int n = 0, rem, count;
        while( cur ){
            cur = cur->next;
            n++;
        }
        rem = n%k, n = n/k, count;
        cur = head;
        while( cur != NULL ){
            head = cur;
            count = n;
            while( count > 0 ){
                prev = cur;
                cur = cur->next;
                count--;
            }
            if( rem ){
                rem--;
                prev = cur;
                cur = cur->next;
            }
            prev->next = NULL;
            ans.push_back( head );
        }
        rem = k - ans.size();
        while( rem-- ){
            head = NULL;
            ans.push_back( head );
        }
        return ans;
    }
};
