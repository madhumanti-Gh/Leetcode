class Solution {
private:
    int findLen( string& s, int l, int r, vector<vector<int>>& dp ){
        if( l > r )return 0;
        if( l == r )return 1;
        if( dp[l][r] != -1 )return dp[l][r];
        int ans;
        if( s[l] == s[r] )ans = 2 + findLen( s, l+1, r-1, dp );
        else ans = max( findLen( s, l+1, r, dp ), findLen( s, l, r-1, dp ) );
        return dp[l][r] = ans;
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp( n, vector<int> ( n, -1 ) );
        return findLen( s, 0, n-1, dp );
    }
};
