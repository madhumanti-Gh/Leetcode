class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> rows( 3, vector<int> ( 2, 0 ) );
        vector<vector<int>> cols( 3, vector<int> ( 2, 0 ) );
        vector<vector<int>> dias( 2, vector<int> ( 2, 0 ) );
        int A = 0, r, c, i, j, n = moves.size();
        for( i = 0; i < n; i++ ){
            r = moves[i][0];
            c = moves[i][1];
            rows[r][A]++;
            cols[c][A]++;
            if( r == c ){
                dias[0][A]++;
                if( r == 1 )dias[1][A]++;
            }
            if( ( r == 0 && c == 2 ) || ( r == 2 && c == 0 ) )dias[1][A]++;
            
            for( j = 0; j < 3; j++ ){
                if( rows[j][A] == 3 || cols[j][A] == 3 )return (A == 0)?"A":"B";
                if( j < 2 && dias[j][A] == 3 )return (A == 0)?"A":"B";
            }
            
            if( A == 0 )A = 1;
            else A = 0;
        }
        if( n == 9 )return "Draw";
        return "Pending";
    }
};
