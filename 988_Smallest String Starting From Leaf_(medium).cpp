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
    string ans = "";
    bool compare( string str ){
        int i = 0, n = min( str.size(), ans.size() );
        while( i < n ){
            if( str[i] == ans[i] )i++;
            else return str[i] < ans[i];
        }
        return str.size() < ans.size();
    }
    void find_str( TreeNode* root, string str ){
        if( !root )return;
        string cur = (char)(root->val+97) +str;
        if( !root->left && !root->right ){
            if( ans == "" )ans = cur;
            else if( compare(cur) )ans = cur;
            return;
        }
        find_str( root->left, cur );
        find_str( root->right, cur );
    }
    string smallestFromLeaf(TreeNode* root) {
        find_str( root, "" );
        return ans;
    }
};
