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
    bool isEvenOddTree(TreeNode* root) {
        if((root->val)%2 == 0 )return false;
        queue<TreeNode*> q;
        q.push(root);
        int i, sz, prev = 0;
        bool flag = false;
        while( !q.empty() ){
            sz = q.size();
            for( i = 0; i < sz; i++ ){
                TreeNode *p = q.front();
                q.pop();
                if( !flag ){
                    if( p->val %2 == 0 || p->val <= prev )return false;
                    prev = p->val;
                }
                if( flag ){
                    if( p->val %2 == 1 || p->val >= prev )return false;
                    prev = p->val;
                }
                if( p->left )q.push( p->left );
                if( p->right )q.push( p->right );
            }
            if( !flag )prev = 1000005;
            else prev = 0;
            flag = !flag;
        }
        return true;
    }
};
