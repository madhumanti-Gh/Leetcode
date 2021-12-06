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
    pair<int, int> houses( TreeNode *root ){
        if( !root )return{0,0};
        pair<int, int> A, B, C;
        A = houses( root->left );
        B = houses( root->right );
        C.first = root->val + A.second + B.second;
        C.second = max( A.first, A.second ) + max( B.first, B.second );
        return C;
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = houses( root );
        return max( ans.first, ans.second );
    }
};
