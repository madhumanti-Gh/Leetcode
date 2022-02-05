class Solution {
private:
    bool isSafe( vector<vector<int>>& sum, int x1, int y1, int x2, int y2 ){
        int X = 0, Y = 0, Z = 0;
        if( x1 > 0 )X = sum[x1-1][y2];
        if( y1 > 0 )Y = sum[x2][y1-1];
        if( x1 > 0 && y1 > 0 )Z = sum[x1-1][y1-1];
        return (sum[x2][y2] - X - Y + Z ) == 0;
    }
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size(), m = grid[0].size(), i, j, k, down;
        vector<vector<int>> matrix( n, vector<int> ( m, 0 ) );
        vector<vector<bool>> mark( n, vector<bool> ( m, 0 ) );
        vector<vector<int>> sum( grid.begin(), grid.end() );
        for( j = 0; j < m; j++ ){
            for( i = 1; i < n; i++ ){
                sum[i][j] += sum[i-1][j];
            }
        }
        for( i = 0; i < n; i++ ){
            for( j = 1; j < m; j++ ){
                sum[i][j] += sum[i][j-1];
            }
        }
        for( i = 0; i < n; i++ ){
            for( j = 0; j < m; j++ ){
                if( grid[i][j] == 0 && i+stampHeight <= n && j+stampWidth <= m && isSafe( sum, i, j, i+stampHeight-1, j+stampWidth-1 ) ){
                    matrix[i][j]++;
                    if( j+stampWidth < m )matrix[i][j+stampWidth]--;
                }
            }
        }
        for( i = 0; i < n; i++ ){
            for( j = 1; j < m; j++ ){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        for( i = 0; i < n; i++ ){
            for( j = 0; j < m; j++ ){
                if( !grid[i][j] && matrix[i][j] )mark[i][j] = true;
            }
        }
        for( j = 0; j < m; j++ ){
            for( i = 0; i < n; i++ ){
                if( grid[i][j] || !matrix[i][j] )continue;
                k = i;
                while( k < n && matrix[k][j] )k++;
                down = stampHeight;
                k--;
                while( down-- )mark[k++][j] = true;
                i = k-1;
            }
        }
        for( i = 0; i < n; i++ ){
            for( j = 0; j < m; j++ ){
                if( !grid[i][j] && !mark[i][j] )return false;
            }
        }
        return true;
    }
};
