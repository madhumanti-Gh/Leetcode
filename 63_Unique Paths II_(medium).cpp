// Botton-Up approach
class Solution {
public:
    int dp[102][102];
    int dfs( vector<vector<int>>& grid, int row, int col ){
        int m = grid.size();
        int n = grid[0].size();
        if( row >= m || col >= n || grid[row][col] == 1 )return 0;
        if( row == m-1 && col == n-1 ){
            return 1;
        }
        if( dp[row][col] != -1 )return dp[row][col];
        int ans = dfs( grid, row+1, col ) + dfs( grid, row, col+1 );
        return dp[row][col] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memset( dp, -1, 102*102*sizeof(dp[0][0]) );
        return dfs( obstacleGrid, 0, 0 );
    }
};

// Top-Down approach 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), i, j;
        int n = obstacleGrid[0].size();
        if( obstacleGrid[0][0] == 1 )return 0;
        obstacleGrid[0][0] = 1;
        for( i = 1; i < m; i++ ){
            if( obstacleGrid[i][0] == 1 )obstacleGrid[i][0] = 0;
            else obstacleGrid[i][0] = obstacleGrid[i-1][0];
        }
        for( j = 1; j < n; j++ ){
            if( obstacleGrid[0][j] == 1 )obstacleGrid[0][j] = 0;
            else obstacleGrid[0][j] = obstacleGrid[0][j-1];
        }
        for( int i = 1; i < m; i++ ){
            for( int j = 1; j < n; j++ ){
                if( obstacleGrid[i][j] == 1 )obstacleGrid[i][j] = 0;
                else obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};
