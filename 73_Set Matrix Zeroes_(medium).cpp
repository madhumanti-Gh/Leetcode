class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rows(m,1), cols(n,1);
        int i, j;
        for( i = 0; i < m; i++ ){
            for( j = 0; j < n; j++ ){
                if( matrix[i][j] == 0 ){
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }
        for( i = 0; i < m; i++ ){
            for( j = 0; j < n; j++ ){
                if( rows[i] == 0 ){
                    matrix[i][j] = 0;
                }
                else if( cols[j] == 0 ){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
