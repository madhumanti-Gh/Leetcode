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
    int count;
    void find_good( TreeNode* root, int max_val, int& count ){
        if( !root )return;
        if( root->val >= max_val ){
            count += 1;
        }
        find_good( root->left, max( max_val, root->val ), count );
        find_good( root->right, max( max_val, root->val ), count );
    }
    int goodNodes(TreeNode* root) {
        count = 0;
        if( !root )return 0;
        int max_val = root->val;
        find_good( root, root->val, count );
        return count;
    }
};
