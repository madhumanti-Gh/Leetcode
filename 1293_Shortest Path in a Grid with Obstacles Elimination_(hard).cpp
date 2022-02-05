class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), i, j;
        int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        vector<int> temp;
        vector<vector<vector<bool>>> vis( m, vector<vector<bool>> ( n, vector<bool> ( k+1, false ) ) );
        
        queue<vector<int>> q;
        q.push({ 0, 0, k });
        vis[0][0][k] = true;
        
        int steps = 0, sz, x, y, z;
        while( !q.empty() ){
            sz = q.size();
            while( sz-- ){
                temp = q.front();q.pop();
                if( temp[0] == m-1 && temp[1] == n-1 )return steps;
                for( j = 0; j < 4; j++ ){
                    x = temp[0] + dir[j][0];
                    y = temp[1] + dir[j][1];
                    z = temp[2];
                    if( x >= 0 && x < m && y >= 0 && y < n ){
                        if( grid[x][y] == 0 && !vis[x][y][z] ){
                            q.push({ x, y, z });
                            vis[x][y][z] = true;
                        }
                        else if( grid[x][y] == 1 && z > 0 && !vis[x][y][z-1] ){
                            q.push({ x, y, z-1 });
                            vis[x][y][z-1] = true;
                        }
                    }
                }
                
            }
            
            steps++;
        }
        
        return -1;
    }
};
