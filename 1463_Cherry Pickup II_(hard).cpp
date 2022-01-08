class Solution {
private:
    int traverse( vector<vector<int>>& grid, int r, int c1, int c2, vector<vector<vector<int>>>& dp ){
        int n = grid.size(), m = grid[0].size();
        if( r == n )return 0;
        if( c1 < 0 || c1 >= m || c2 < 0 || c2 >= m )return INT_MIN;
        if( dp[r][c1][c2] != -1 )return dp[r][c1][c2];
        
        int ans = 0, i, j;
        for( i = -1; i <= 1; i++ ){
            for( j = -1; j <= 1; j++ ){
                ans = max( ans, traverse( grid, r+1, c1+i, c2+j, dp ) );
            }
        }
        
        if( c1 == c2 )ans += grid[r][c1];
        else ans += ( grid[r][c1] + grid[r][c2] );
        return dp[r][c1][c2] = ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp( n+1, vector<vector<int>> ( m+1, vector<int> ( m+1, -1 ) ) );
        return traverse( grid, 0, 0, m-1, dp );
    }
};
