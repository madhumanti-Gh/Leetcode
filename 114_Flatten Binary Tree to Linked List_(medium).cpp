// Morris Traversal
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
    void flatten(TreeNode* root) {
        if( root == NULL )return;
        while( root ){
            if( root->left ){
                TreeNode *left = root->left;
                TreeNode *cur = left;
                while( cur->right ){
                    cur = cur->right;
                }
                cur->right = root->right;
                root->right = left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};

// Recurssive
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
    TreeNode* inorder( TreeNode* root ){
        if( root == NULL )return root;
        if( root->left && root->right ){
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;
            root = inorder( root->right );
            root->right = temp;
            root->left = NULL;
            return inorder( root->right );
        }
        else if( root->left ){
            root->right = root->left;
            root->left = NULL;
            return inorder( root->right );
        }
        else if( root->right ){
            return inorder( root->right );
        }
        return root;
    }
    void flatten(TreeNode* root) {
        if( root == NULL )return;
        root = inorder( root );
    }
};

