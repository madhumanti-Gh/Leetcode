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
    map<int,int> mp;
    void mapping(TreeNode* root){
        if( root == NULL )return;
        mp[root->val]++;
        mapping(root->left);
        mapping(root->right);
        return;
    }
    bool findNode(TreeNode* root, int target){
        if( root==NULL )return false;
        if( mp[target - root->val] > 0 ){
            if( target - root->val == root->val && mp[target - root->val] > 1 ){
                return true;
            }
            else if( target - root->val != root->val && mp[target - root->val] > 0 ){
                return true;
            }
        }
        return findNode(root->left, target) || findNode(root->right, target);
    }
    
    bool findTarget(TreeNode* root,int k) {
        mapping( root);
        return findNode(root, k);
    }
};
