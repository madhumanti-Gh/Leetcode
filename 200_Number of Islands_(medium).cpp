class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y ){
        int n = grid.size();
        int m = grid[0].size();
        if( x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '0' )return;
        
        if( grid[x][y] == '1' ){
            grid[x][y] = '0';
            dfs( grid, x-1, y );
            dfs( grid, x, y+1 );
            dfs( grid, x+1, y );
            dfs( grid, x, y-1 );
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        
        for( int x = 0; x < n; x++ ){
            for( int y = 0; y < m; y++ ){
                if( grid[x][y] == '1' ){
                    cnt++;
                    grid[x][y] = '0';
                    dfs( grid, x-1, y );
                    dfs( grid, x, y+1 );
                    dfs( grid, x+1, y );
                    dfs( grid, x, y-1 );
                }
            }
        }
        return cnt;
    }
};
