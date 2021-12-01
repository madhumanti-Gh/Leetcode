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
    void check_GParent( TreeNode* root, TreeNode *parent, TreeNode *Gparent, int& sum ){
        if( !root )return;
        if( Gparent && (Gparent->val)%2 == 0 )sum += root->val;
        check_GParent( root->left, root, parent, sum );
        check_GParent( root->right, root, parent, sum );
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        check_GParent( root, NULL, NULL, sum );
        return sum;
    }
};
