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
    int Sum = 0;
    int B2D( string s ){
        int n = s.size();
        int base = 1;
        int sum = 0;
        for( int i = n-1; i >= 0; i-- ){
            if( s[i] == '1' ){
                sum += ( 1* base );
            }
            base *= 2;
        }
        return sum;
    }
    void dfs( TreeNode* root, string s ){
        if( !root->left && !root->right ){
            Sum += B2D( s );
        }
        string x;
        if( root->left != NULL ){
            x = s;
            x.push_back( (char)(root->left->val + 48) );
            dfs( root->left, x );
        }
        if( root->right != NULL ){
            x = s;
            x.push_back( (char)(root->right->val + 48) );
            dfs( root->right, x );
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        if( root != NULL ){
            string s = "";
            s.push_back( (char)(root->val + 48) );
            dfs( root, s );
            return Sum;
        }
        return 0;
    }
};
