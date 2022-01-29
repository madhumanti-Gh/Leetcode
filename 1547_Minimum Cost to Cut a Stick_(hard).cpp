class Solution {
private:
    int find_cost( int i, int j, int l, int r, vector<vector<int>>& dp, vector<int>& cuts ){
        if( i < 0 || j >= cuts.size() || i > j )return 0;
        if( i == j )return r - l;
        
        if( dp[i][j] != -1 )return dp[i][j];
        
        int ans = INT_MAX;
        for( int k = i; k <= j; k++ ){
            ans = min( ans, (r-l) + find_cost( i, k-1, l, cuts[k], dp, cuts ) + find_cost( k+1, j, cuts[k], r, dp, cuts ) );
        }
        
        return dp[i][j] = ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size(), i;
        sort( cuts.begin(), cuts.end() );
        vector<vector<int>> dp( m + 1, vector<int> ( m + 1, -1 ) );
        
        return find_cost( 0, m-1, 0, n, dp, cuts );
    }
};
