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
    TreeNode* recursion( vector<int>& nums, int start, int end ){
        if( start > end )return NULL;
        int n = (start + end)/2;
        TreeNode *root = new TreeNode( nums[n] );
        root->left = recursion( nums, start, n-1 );
        root->right = recursion( nums, n+1, end );
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = recursion( nums, 0, nums.size()-1 );
        return root;
    }
};
