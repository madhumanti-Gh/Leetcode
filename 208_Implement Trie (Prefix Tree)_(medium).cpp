class Trie {
public:
    struct Node{
        bool is_end;
        vector<Node*> chars;
        Node(){
            is_end = false;
            chars.assign( 26, nullptr );
        }
    };
    
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        int n = word.size(), i;
        for( auto& c : word ){
            if( !cur->chars[c - 'a'] )cur->chars[c - 'a'] = new Node();
            cur = cur->chars[c - 'a'];
        }
        cur->is_end = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        int n = word.size(), i;
        for( auto& c : word ){
            if( !cur->chars[c - 'a'] )return false;
            cur = cur->chars[c - 'a'];
        }
        return cur->is_end;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        int n = prefix.size(), i;
        for( auto& c : prefix ){
            if( !cur->chars[c - 'a'] )return false;
            cur = cur->chars[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
