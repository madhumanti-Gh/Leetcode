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
    bool find_path( TreeNode *root, int value, string& str ){
        if( !root )return false;
        if( root->val == value )return true;
        if( root->left && find_path( root->left, value, str ) ){
            str.push_back('L');
            return true;
        }
        if( root->right && find_path(root->right, value, str ) ){
            str.push_back('R');
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string r2s = "";
        find_path( root, startValue, r2s );
        string r2d = "";
        find_path( root, destValue, r2d );
        while( r2s.size() > 0 && r2d.size() > 0 && r2s.back() == r2d.back() ){
            r2s.pop_back();
            r2d.pop_back();
        }
        for( int i = 0; i < r2s.size(); i++ )r2s[i] = 'U';
        for( int i = 0; i < r2d.size()/2; i++ )swap( r2d[i], r2d[r2d.size()-1-i] );
        return r2s+r2d;
    }
};
