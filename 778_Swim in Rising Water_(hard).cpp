class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), i, t, x, y, newx, newy, ans;
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        ans = grid[0][0];
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({ grid[0][0]*(-1), { 0, 0 } });
        
        pair<int, pair<int, int>> cur;
        while( !pq.empty() ){
            cur = pq.top();
            pq.pop();
            t = cur.first * (-1);
            x = cur.second.first;
            y = cur.second.second;
            ans = max( ans, grid[x][y] );
            
            vis[x][y] = true;
            if( x == n-1 && y == n-1 )return ans;
            for( i = 0; i < 4; i++ ){
                newx = x + dir[i][0];
                newy = y + dir[i][1];
                if( newx >= 0 && newx < n && newy >= 0 && newy < n && !vis[newx][newy] ){
                    pq.push({ grid[newx][newy] * (-1), { newx, newy } });
                }
            }
        }
        return 0;
    }
};
