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
    int find_len( TreeNode *root, TreeNode *parent, int& ans ){
        if( !root )return 0;
        int left_len = find_len( root->left, root, ans );
        int right_len = find_len( root->right, root, ans );
        ans = max( ans, left_len + right_len + 1 );
        
        if( parent && root->val == parent->val ){
            return max( left_len, right_len ) +1;
        }
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        if( !root )return 0;
        int res = find_len( root, NULL, ans );
        return ans-1;
    }
};
