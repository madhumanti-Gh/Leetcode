class Solution {
public:
    int uniquePaths(int m, int n) {
        vector< vector<int> > dp(m, vector<int> (n,1) );
        for( int i = 1; i < m; i++ ){
            for( int j = 1; j < n; j++ ){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// Memoization approach
class Solution {
public:
    int cache[102][102];
    int recursion(int m, int n){
        if( cache[m][n] != -1 )return cache[m][n];
        if( m == 0 || n == 0 )return 1;
        int ans = recursion( m, n-1 ) + recursion( m-1, n );
        cache[m][n] = ans;
        return ans;
    }
    int uniquePaths(int m, int n) {
        memset( cache, -1, 102*102*sizeof(cache[0][0]) );
        return recursion( m-1, n-1);
    }
};
