class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> check( 10, 0 );
        int i, j, k, l, num;
        for( i = 0; i < 9; i++ ){
            for( j = 0; j < 9; j++ ){
                if( board[i][j] != '.' ){
                    num = board[i][j] - '0';
                    check[num]++;
                    if( check[num] > 1 )return false;
                }
            }
            for( j = 1; j <= 9; j++ )check[j] = 0;
        }
        for( i = 0; i < 9; i++ ){
            for( j = 0; j < 9; j++ ){
                if( board[j][i] != '.' ){
                    num = board[j][i] - '0';
                    check[num]++;
                    if( check[num] > 1 )return false;
                }
            }
            for( j = 1; j <= 9; j++ )check[j] = 0;
        }
        for( k = 0; k < 9; k+=3 ){
            for( l = 0; l < 9; l+=3 ){
                for( i = k; i < k+3; i++ ){
                    for( j = l; j < l+3; j++ ){
                        if( board[i][j] != '.' ){
                            num = board[i][j] - '0';
                            check[num]++;
                            if( check[num] > 1 )return false;
                        }
                    }
                }
                for( j = 1; j <= 9; j++ )check[j] = 0;
            }
        }
        return true;
    }
};
