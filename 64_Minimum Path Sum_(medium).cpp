class Solution {
private:
    int Path( vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dp ){
        int m = grid.size(), n = grid[0].size();
        
        if( x >= m || y >= n )return INT_MAX;
        if( x == m-1 && y == n-1 )return grid[x][y];
        
        if( dp[x][y] != -1 )return dp[x][y];
        
        int ans = grid[x][y] + min( Path( grid, x+1, y, dp ), Path( grid, x, y+1, dp ) );
        return dp[x][y] = ans;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp( m+1, vector<int> ( n+1, -1 ) );
        return Path( grid, 0, 0, dp );
    }
};
