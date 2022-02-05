class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), i, j, len, cnt = 0;
        vector<vector<bool>> dp( n, vector<bool> ( n, false ) );
        for( i = 0; i < n; i++ ){
            dp[i][i] = true;
            cnt++;
        }
        for( i = 0; i < n-1; i++ ){
            if( s[i] == s[i+1] ){
                dp[i][i+1] = true;
                cnt++;
            }
        }
        for( len = 3; len <= n; len++ ){
            for( i = 0, j = i+len-1; j < n; i++, j++ ){
                if( s[i] == s[j] && dp[i+1][j-1] == true ){
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};
