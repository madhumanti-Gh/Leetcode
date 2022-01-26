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
private:
    vector<int> ans;
    // Iterative Inorder Traversal
    void inorder( TreeNode* root ){
        if( !root )return;
        stack<TreeNode*> st;
        while( true ){
            if( root ){
                st.push( root );
                root = root->left;
            }
            else{
                if( st.empty() )break;
                ans.push_back( st.top()->val );
                root = st.top()->right;
                st.pop();
            }
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder( root1 );
        inorder( root2 );
        sort( ans.begin(), ans.end() );
        return ans;
    }
};
