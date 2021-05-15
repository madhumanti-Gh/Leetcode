class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( __builtin_popcountll(n) == 1 ){
            return true;
        }
        else{
            return false;
        }
    }
};
