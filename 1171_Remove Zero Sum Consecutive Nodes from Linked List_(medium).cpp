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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if( !head )return NULL;
        unordered_map<int, ListNode*> mp;
        ListNode *dummy = new ListNode(0), *cur = head, *left;
        dummy->next = head;
        mp[0] = dummy;
        
        int n = 0, pre = 0, sum;
        while( cur ){
            n++;
            pre += cur->val;
            if( mp.find(pre) != mp.end() ){
                left = mp[pre];
                sum = pre;
                while( left && left != cur ){
                    left = left->next;
                    sum += left->val;
                    if( left != cur )mp.erase(sum);
                }
                mp[pre]->next = cur->next;
            }
            else{
                mp[pre] = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
