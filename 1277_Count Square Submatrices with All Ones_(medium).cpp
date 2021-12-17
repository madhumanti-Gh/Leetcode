class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i, j, u, l, d, count = 0;
        for( i = 0; i < m; i++ ){
            for( j = 0; j < n; j++ ){
                count += matrix[i][j];
            }
        }
        for( i = 1; i < m; i++ ){
            for( j = 1; j < n; j++ ){
                if( matrix[i][j] == 1 ){
                    u = matrix[i-1][j];
                    l = matrix[i][j-1];
                    d = matrix[i-1][j-1];
                    matrix[i][j] = min( u, min( l, d ) ) +1;
                    count += matrix[i][j] - 1;
                }
            }
        }
        return count;
    }
};
