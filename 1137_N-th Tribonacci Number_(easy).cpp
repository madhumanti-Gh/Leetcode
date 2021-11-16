class Solution {
public:
    int dp[40];
    int recursion( int n ){
        if( dp[n] != -1 )return dp[n];
        if( n <= 1 )return n;
        else if( n == 2 )return 1;
        int ans = recursion( n-1 ) + recursion( n-2 ) + recursion( n-3 );
        dp[n] = ans;
        return ans;
    }
    int tribonacci(int n) {
        memset( dp, -1, 40*sizeof( dp[0] ) );
        return recursion(n);
    }
};
