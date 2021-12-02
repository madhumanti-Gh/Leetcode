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
    void find_sum( TreeNode* root, int count, int& sum ){
        if( !root )return;
        count = (10*count) + root->val;
        if( !root->left && !root->right )sum += count;
        find_sum( root->left, count, sum );
        find_sum( root->right, count, sum );
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        find_sum( root, 0, sum );
        return sum;
    }
};
