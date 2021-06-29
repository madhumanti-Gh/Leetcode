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
    void leftree( TreeNode* root, TreeNode* child ){
        if( root == NULL or child == NULL )return;
        if( root->val < child->val ){
            int temp = root->val;
            root->val = child->val;
            child->val = temp;
            leftree( root, root->left );
            rightree( root, root->right );
        }
        else{
            leftree( root, child->left );
            leftree( root, child->right );
        }
    }
    void rightree( TreeNode* root, TreeNode* child ){
        if( root == NULL or child == NULL )return;
        if( root->val > child->val ){
            int temp = root->val;
            root->val = child->val;
            child->val = temp;
            leftree( root, root->left );
            rightree( root, root->right );
        }
        else{
            rightree( root, child->left );
            rightree( root, child->right );
        }
    }
    
    void recoverTree(TreeNode* root) {
        if( root == NULL )return;
        leftree( root, root->left );
        rightree( root, root->right );
        recoverTree( root->left );
        recoverTree( root->right );
    }
};
