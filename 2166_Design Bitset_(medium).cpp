class Bitset {
private:
    vector<int> bits;
    int n, countSet;
    bool isFlip;
    string s;
public:
    Bitset(int size) {
        bits.clear();
        bits.assign( size, 0 );
        n = size;
        countSet = 0;
        isFlip = false;
    }
    
    void fix(int idx) {
        if( !isFlip && bits[idx] == 0 ){
            bits[idx] = 1;
            countSet++;
        }
        else if( isFlip && bits[idx] == 1 ){
            bits[idx] = 0;
            countSet++;
        }
    }
    
    void unfix(int idx) {
        if( !isFlip && bits[idx] == 1 ){
            bits[idx] = 0;
            countSet--;
        }
        else if( isFlip && bits[idx] == 0 ){
            bits[idx] = 1;
            countSet--;
        }
    }
    
    void flip() {
        isFlip = !isFlip;
        countSet = n - countSet;
    }
    
    bool all() {
        if( countSet == n )return true;
        return false;
    }
    
    bool one() {
        if( countSet > 0 )return true;
        return false;
    }
    
    int count() {
        return countSet;
    }
    
    string toString() {
        s = "";
        if( !isFlip ){
            for( auto& it : bits ){
                if( it == 0 )s.push_back( '0' );
                else s.push_back( '1' );
            }
        }
        else{
            for( auto& it : bits ){
                if( it == 0 )s.push_back( '1' );
                else s.push_back( '0' );
            }
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
