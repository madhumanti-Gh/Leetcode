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
    void InOrd( vector<int>& inord, TreeNode* root ){
        if( root == NULL ){
            return;
        }
        InOrd( inord, root->left);
        inord.push_back( root->val );
        InOrd( inord, root->right );
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inord;
        InOrd( inord, root );
        int sz = inord.size();
        for( int i = 1; i < sz; i++ ){
            if( inord[i] <= inord[i-1] ){
                return false;
            }
        }
        return true;
    }
};
