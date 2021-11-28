class Solution {
public:
    int dp[102][102][602];
    int countOne( string num ){
        int count = 0;
        for( int i = 0; i < num.size(); i++ ){
            if( num[i] == '1' )count++;
        }
        return count;
    }
    int recursion( vector<string>& strs, int m, int n, int idx ){
        if( dp[m][n][idx] != -1 )return dp[m][n][idx];
        
        int str_len, arr_len, Ones, Zeros, take = 0, skip = 0, ans = 0;
        arr_len = strs.size();
        if( (m <= 0 && n <= 0) || idx >= arr_len )return 0;
        
        str_len = strs[idx].size();
        Ones = countOne( strs[idx] );
        Zeros = str_len - Ones;
        if( m >= Zeros && n >= Ones ){
            take = 1+ recursion( strs, m - Zeros, n - Ones, idx+1 );
        }
        skip = recursion( strs, m, n, idx+1 );
        ans = max( take, skip );
        return dp[m][n][idx] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset( dp, -1, 102*102*602*sizeof(dp[0][0][0]) );
        return recursion( strs, m, n, 0 );
    }
};
