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
    vector< vector<int> > ans;
    void paths( TreeNode* root, int Sum, vector<int> path ){
        if( root == NULL )return;
        Sum = Sum - root->val;
        path.push_back( root->val );
        if( Sum == 0 && !root->left && !root->right ){
            ans.push_back( path );
            return;
        }
        paths( root->left, Sum, path );
        paths( root->right, Sum, path );
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        paths( root, targetSum, path );
        return ans;
    }
};
