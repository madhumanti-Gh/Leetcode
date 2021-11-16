class Solution {
public:
    int dp[47];
    int recursion( int n ){
        if( dp[n] != -1 )return dp[n];
        if( n <= 2 )return n;
        
        int ans = recursion(n-1) + recursion(n-2);
        dp[n] = ans;
        return ans;
    }
    int climbStairs(int n) {
        memset( dp, -1, 47*sizeof(dp[0]) );
        return recursion(n);
    }
};
