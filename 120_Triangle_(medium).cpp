class Solution {
public:
    int dp[202][202];
    int recursion( vector<vector<int>>& triangle, int n, int m, int x, int y ){
        if( dp[y][x] != -1 )return dp[y][x];
        if( y == m )return min( triangle[y][x], triangle[y][x+1] );
        int ans = 0;
        ans = min( triangle[y][x] + recursion( triangle, n, m, x, y+1 ) , triangle[y][x+1] + recursion( triangle, n, m, x+1, y+1 ) );
        dp[y][x] = ans;
        return ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();n--;
        int m = n;
        if( m == 0 && n == 0 )return triangle[0][0];
        memset(dp, -1, sizeof( dp[0][0]) * 202 * 202 ); 
        int ans = triangle[0][0] + recursion( triangle, n, m, 0, 1 );
        return ans;
    }
};
