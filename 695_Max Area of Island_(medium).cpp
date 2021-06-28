class Solution {
public:
    int maxArea = 0;
    int dfs( vector<vector<int>>& grid, vector<vector<bool>>& vis, int Area, int r, int c ){
        int n = grid.size();
        int m = grid[0].size();
        if( ( r >= 0 && r < n ) && ( c >= 0 && c < m ) && grid[r][c] == 1 && vis[r][c] == false ){
            vis[r][c] = true;
            Area++;
            Area = dfs( grid, vis, Area, r, c-1 );
            Area = dfs( grid, vis, Area, r, c+1 );
            Area = dfs( grid, vis, Area, r-1, c );
            Area = dfs( grid, vis, Area, r+1, c );
        }
        return Area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>( m, false ) );
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++ ){
                int cur = dfs( grid, vis, 0, i, j );
                maxArea = max( maxArea, cur );
            }
        }
        return maxArea;
    }
};
