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
    int BST( vector<int>& pre, int n, TreeNode *root, int idx, int Start, int End ){
        if( idx == n || pre[idx] < Start || pre[idx] > End )return idx;
        
        if( pre[idx] < root->val ){
            root->left = new TreeNode(pre[idx]);
            idx += 1;
            idx = BST( pre, n, root->left, idx, Start, root->val -1 );
        }
        if( idx == n || pre[idx] < Start || pre[idx] > End )return idx;
        
        root->right = new TreeNode(pre[idx]);
        idx += 1;
        idx = BST( pre, n, root->right, idx, root->val +1, End );
        return idx;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode *root = new TreeNode( preorder[0] );
        if( n == 1 )return root;
        int ans = BST( preorder, n, root, 1, INT_MIN, INT_MAX );
        return root;
    }
};
