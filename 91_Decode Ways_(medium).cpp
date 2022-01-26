class Solution {
private:
    int find_ways( string s, int id, vector<int>& dp ){
        int n = s.size();
        if( id == n )return 1;
        if( id == n-1 )return 1;
        if( dp[id] != -1 )return dp[id];
        
        int a = 0, b = 0, num = 0, ans = 0;
        if( id + 1 <= n ){
            if( id+1 == n || s[id+1] != '0' )a = find_ways( s, id+1, dp );
            else a = 0;
        }
        if( id + 2 <= n ){
            num = ( s[id] - '0' ) *10 + ( s[id+1] - '0' );
            if( num > 9 && num <= 26 && ( id+2 == n || s[id+2] != '0' ) )b = find_ways( s, id+2, dp );
            else b = 0;
        }
        ans = b + a;
        return dp[id] = ans;
    }
public:
    int numDecodings(string s) {
        int n = s.size(), i = 0;
        if( s[0] == '0' )return 0;
        for( i = 1; i < n; i++ ){
            if( s[i] == '0' && s[i-1] == '0' )return 0;
        }
        vector<int> dp( n+1, -1 );
        return find_ways( s, 0, dp );
    }
};
