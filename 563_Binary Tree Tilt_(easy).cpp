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
    int tilt = 0;
    int nodesum( TreeNode* root ){
        if( !root )return 0;
        int leftsum = nodesum( root->left );
        int rightsum = nodesum( root->right );
        tilt += abs( leftsum - rightsum );
        return leftsum+rightsum+root->val;
    }
    int findTilt(TreeNode* root) {
        int rootsum = nodesum( root );
        return tilt;
    }
};
