class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int m = digits.size();
        string N = to_string(n);
        int sz = N.size(), i, count = 0;
        for( i = 1; i < sz; i++ )count += pow( m, i );
        bool flag = false;
        for( i = 0; i < sz; i++ ){
            flag = false;
            for( auto digit:digits ){
                if( digit[0] < N[i] )count += pow( m, sz -1 -i );
                else if( digit[0] == N[i] )flag = true;
            }
            if( !flag )return count;
        }
        return count+1;
    }
};
