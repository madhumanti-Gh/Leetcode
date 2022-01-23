class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size(), i;
        long long mn = 0, mx = 0, pre = 0;
        for( i = 0; i < n; i++ ){
            pre = pre + (long long)differences[i];
            mn = min( mn, pre );
            mx = max( mx, pre );
        }
        if( mx-mn > upper-lower )return 0;
        return ( upper-lower ) - ( mx-mn ) +1;
    }
};
