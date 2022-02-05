class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), i, j, len, start = 0, end = 0;
        vector<vector<bool>> dp( n, vector<bool> ( n, false ) );
        for( i = 0; i < n; i++ )dp[i][i] = true;
        for( i = 0; i < n-1; i++ ){
            if( s[i] == s[i+1] ){
                dp[i][i+1] = true;
                start = i;
                end = i+1;
            }
        }
        for( len = 3; len <= n; len++ ){
            for( i = 0, j = i+len-1; j < n; i++, j++ ){
                if( s[i] == s[j] && dp[i+1][j-1] ){
                    dp[i][j] = true;
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr( start, end - start +1 );
    }
};
