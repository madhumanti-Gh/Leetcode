class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size(), i, id = n-1;
        long long hash = 0, p = 1;
        for( i = n-1; i >= 0; i-- ){
            hash = ( ( hash * power )%modulo + ( s[i] - 'a' +1 ) )%modulo;
            if( i + k >= n ){
                p = ( p * power )%modulo;
            }
            else{
                hash = ( hash - (( s[i+k] - 'a' +1 ) *p )%modulo + modulo )%modulo;
            }
            
            if( hash == hashValue ){
                id = i;
            }
        }
        return s.substr( id, k );
    }
};
