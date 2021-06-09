// Method 1 (iterative)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node*> q;
        q.push( root );
        while( !q.empty() ){
            int sz = q.size();
            Node* temp;
            for( int i = 0; i < sz; i++ ){
                temp = q.front();
                q.pop();
                if( temp->left != NULL )q.push( temp->left );
                if( temp->right != NULL )q.push( temp->right );
                if( i == sz-1 ){
                    temp->next = NULL;
                }
                else{
                    temp->next = q.front();
                }
            }
        }
        return root;
    }
};

// Method 2 (recursive)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        if(root->left){
            if(root->right)
                root->left->next=root->right;
            else
                root->left->next=root->next->left;
        } 
        if(root->right){
            if(root->next)
            root->right->next=root->next->left;
            else
                root->right->next=NULL;
                
        }
        if(root->left)
        root->left=connect(root->left);
        if(root->right)
        root->right=connect(root->right);
        return root;
    }
};
