/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if( !root )return ans;
        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() ){
            vector<int> temp;
            int sz = q.size();
            for( int i = 0; i < sz; i++ ){
                TreeNode *p = q.front();
                q.pop();
                temp.push_back(p->val);
                if( p->left )q.push( p->left );
                if( p->right )q.push( p->right );
            }
            ans.push_back(temp);
        }
        int sz = ans.size(), i = 0;
        while( i < sz/2 ){
            swap( ans[i], ans[sz-1-i] );
            i++;
        }
        return ans;
    }
};
