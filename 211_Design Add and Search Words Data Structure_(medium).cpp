class WordDictionary {
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
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *cur = root;
        for( auto& c : word ){
            if( !cur->chars[c - 'a'] )cur->chars[c - 'a'] = new Node();
            cur = cur->chars[c - 'a'];
        }
        cur->is_end = true;
    }
    
    bool found( int id, string word, Node* cur ){
        if( id == word.size() )return cur->is_end;
        
        if( word[id] != '.' ){
            if( cur->chars[word[id] - 'a'] && found( id + 1, word, cur->chars[word[id] - 'a'] ) )
                return true;
        }
        else if( word[id] == '.' ){
            for( int i = 0; i < 26; i++ ){
                if( cur->chars[i] && found( id + 1, word, cur->chars[i] ) )return true;
            }
        }
        return false;
    }
    
    bool search(string word) {
        Node* cur = root;
        return found( 0, word, cur );
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
