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
    vector<int> nodes;
    void PreordTrav(TreeNode* root){
        if(root == nullptr)
            return;
        nodes.push_back(root->val);
        PreordTrav(root->left);
        PreordTrav(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        PreordTrav(root);
        return nodes;
    }
};
