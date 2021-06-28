/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    void preord( Node* root ){
        if( root == NULL )return;
        ans.push_back( root->val );
        int sz = root->children.size();
        for( int i = 0; i < sz; i++ ){
            preord( root->children[i] );
        }
    }
    vector<int> preorder(Node* root) {
        preord( root );
        return ans;
    }
};
