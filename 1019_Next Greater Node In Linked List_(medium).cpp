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
    vector<int> nextLargerNodes(ListNode* head) {
        int n = 0, i;
        ListNode* cur = head;
        vector<int> ans;
        stack<pair<int, int>> st; // num, id
        
        while( cur ){
            ans.push_back( 0 );
            if( st.empty() || st.top().first >= cur->val ){
                st.push({ cur->val, n });
            }
            else{
                while( !st.empty() && cur->val > st.top().first ){
                    ans[st.top().second] = cur->val;
                    st.pop();
                }
                st.push({ cur->val, n });
            }
            cur = cur->next;
            n++;
        }
        return ans;
    }
};
