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
    vector<string> ans;
    void find_str( TreeNode* root, string str ){
        if( !root )return;
        string cur = str + "->" + to_string(root->val );
        if( !root->left && !root->right ){
            ans.push_back( cur );
            return;
        }
        find_str( root->left, cur );
        find_str( root->right, cur );
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if( !root )return ans;
        string cur = to_string(root->val);
        if( root->left )find_str( root->left, cur );
        if( root->right )find_str( root->right, cur );
        if( !root->left && !root->right ){
            ans.push_back( cur );
        }
        return ans;
    }
};
