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
private:
    int max_dif;
    void find_dif( int mn, int mx, TreeNode* root ){
        if( !root ) return;
        int cur = root->val;
        mn = min( mn, cur );
        mx = max( mx, cur );
        max_dif = max( max_dif, max( abs(mn-cur), abs(mx-cur) ) );
        find_dif( mn, mx, root->left );
        find_dif( mn, mx, root->right );
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        max_dif = 0;
        if( !root ) return 0;
        find_dif( root->val, root->val, root );
        return max_dif;
    }
};
