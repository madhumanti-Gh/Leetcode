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
    TreeNode *find_right( TreeNode *root ){
        if( !root->right )return root;
        return find_right( root->right );
    }
    TreeNode *Delete( TreeNode *root ){
        if( !root->left )return root->right;
        if( !root->right )return root->left;
        TreeNode *R = root->right;
        TreeNode *last_right = find_right( root->left );
        last_right->right = R;
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if( !root )return NULL;
        if( root->val == key )return Delete( root );
        TreeNode* tempHead = root;
        while( root ){
            if( root->val > key ){
                if( root->left && root->left->val == key ){
                    root->left = Delete( root->left );
                    break;
                }
                else root = root->left;
            }
            else{
                if( root->right && root->right->val == key ){
                    root->right = Delete( root->right );
                    break;
                }
                else root = root->right;
            }
        }
        return tempHead;
    }
};
