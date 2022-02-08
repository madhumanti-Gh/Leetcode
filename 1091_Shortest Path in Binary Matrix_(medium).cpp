class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if( grid[0][0] == 1 || grid[n-1][n-1] == 1 )return -1;
        if( n == 1 && grid[0][0] == 0 )return 1;
        
        vector<vector<int>> dir = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
        vector<vector<bool>> vis( n, vector<bool> ( n, false ) );
        queue<pair<int, int>> q;
        pair<int, int> cur;
        q.push({ 0, 0 });
        vis[0][0] = true;
        
        int len = 0, i, j, x, y, steps = 0;
        while( !q.empty() ){
            len = q.size();
            steps++;
            for( i = 0; i < len; i++ ){
                cur = q.front();
                q.pop();
                for( j = 0; j < 8; j++ ){
                    x = cur.first + dir[j][0];
                    y = cur.second + dir[j][1];
                    if( x == n-1 && y == n-1 )return steps + 1;
                    if( x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && !vis[x][y] ){
                        q.push({ x, y });
                        vis[x][y] = true;
                    }
                }
            }
        }
        return -1;
    }
};
