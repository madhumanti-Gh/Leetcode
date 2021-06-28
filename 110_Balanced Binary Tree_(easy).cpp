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
    bool flag = true;
    int height( TreeNode* root ){
        if( !root )return 0;
        int p = height( root->left );
        int q = height( root->right );
        if( abs(p - q) > 1 ){
            flag = false;
        }
        if( flag == false )return 0;
        return 1 + max(p,q);
    }
    bool isBalanced(TreeNode* root) {
        int v = height( root );
        return flag;
    }
};
