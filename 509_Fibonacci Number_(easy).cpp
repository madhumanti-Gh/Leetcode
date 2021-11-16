class Solution {
public:
    int dp[32];
    int recursion(int n){
        if( dp[n] != -1 )return dp[n];
        if( n <= 1 )return n;
        int ans = recursion(n-1) + recursion(n-2);
        dp[n] = ans;
        return ans;
    }
    int fib(int n) {
        memset( dp, -1, 32*sizeof(dp[0]) );
        return recursion(n);
    }
};
