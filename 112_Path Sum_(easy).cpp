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
    bool checksum( TreeNode* root, int sum ){
        if( !root->left && !root->right ){
            if( sum == 0 )return true;
            else return false;
        }
        bool f1 = false,f2 = false;
        if( root->left ){
            f1 = checksum( root->left, (sum - root->left->val) );
        }
        if( root->right ){
            f2 = checksum( root->right, (sum - root->right->val) );
        }
        return f1||f2;
    }
    bool hasPathSum(TreeNode* root, int Sum) {
        if( root == NULL ){
            return false;
        }
        if( Sum == root->val && !root->left && !root->right )return true;
        return checksum( root, ( Sum - root->val ) );
    }
};
