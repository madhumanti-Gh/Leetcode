class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i, j, u, l, d, max_size = 0;
        vector<vector<int>> mat( m, vector<int> (n, 0));
        for( i = 0; i < m; i++ ){
            for( j = 0; j < n; j++ ){
                mat[i][j] = (matrix[i][j] - 48);
                max_size = max( max_size, mat[i][j] );
            }
        }
        for( i = 1; i < m; i++ ){
            for( j = 1; j < n; j++ ){
                if( mat[i][j] == 1 ){
                    u = mat[i-1][j];
                    l = mat[i][j-1];
                    d = mat[i-1][j-1];
                    mat[i][j] = min( u, min( l, d ) ) +1;
                    max_size = max( max_size, mat[i][j] );
                }
            }
        }
        return max_size*max_size;
    }
};
