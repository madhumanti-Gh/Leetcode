class Solution {
public:
    int numTilings(int n) {
        int M = 1000000007;
        if( n == 1 )return 1;
        if( n == 2 )return 2;
        if( n == 3 )return 5;
        vector<long long int> dp(n+1, 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for( int i = 4; i <= n; i++ ){
            dp[i] = ((((dp[i-1] %M) *2) %M) + (dp[i-3] %M) )%M;
        }
        return dp[n];
    }
};
