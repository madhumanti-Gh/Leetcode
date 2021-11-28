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
    int pathsum( TreeNode *root, int& max_sum ){
        if( !root )return 0;
        int Leftsum = max( 0, pathsum( root->left, max_sum ) );
        int Rightsum = max( 0, pathsum( root->right, max_sum ) );
        max_sum = max( max_sum, Leftsum+Rightsum+root->val );
        return max( Leftsum, Rightsum ) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        int ans = pathsum( root, max_sum );
        return max_sum;
    }
};
