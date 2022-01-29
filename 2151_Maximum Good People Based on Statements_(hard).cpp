class Solution {
private:
    int check( string s, vector<vector<int>>& statements ){
        int n = statements.size(), i, j, cnt = 0;
        for( i = 0; i < n; i++ ){
            if( s[i] == '0' )continue;
            cnt++;
            for( j = 0; j < n; j++ ){
                if( statements[i][j] == 0 && s[j] == '1' )return false;
                if( statements[i][j] == 1 && s[j] == '0' )return false;
            }
        }
        return cnt;
    }
    int generate( int id, string s, vector<vector<int>>& statements ){
        int n = statements.size();
        if( id == n )return check( s, statements );
        
        int good = generate( id + 1, s + '1', statements );
        int bad = generate( id + 1, s + '0', statements );
        return max( good, bad );
    }
public:
    int maximumGood(vector<vector<int>>& statements) {
        return generate( 0, "", statements );
    }
};
