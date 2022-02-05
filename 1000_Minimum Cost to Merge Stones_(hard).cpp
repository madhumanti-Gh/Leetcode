class Solution {
private:
    int merge( int l, int r, int pile, vector<int>& pre, int& k, vector<vector<vector<int>>>& dp ){
        if( l == r ){
            if( pile == 1 )return 0;
            else return INT_MAX/4;
        }
        if( dp[l][r][pile] != -1 )return dp[l][r][pile];
        
        int sum = 0, cost = INT_MAX/4, ans = 0, i;
        if( pile == 1 ){
            // find k piles to merge into 1 pile-> dp(i,j,1) = dp(i,j,k) + sum[i..j]
            sum = pre[r];
            if( l > 0 )sum -= pre[l-1];
            ans = sum + merge( l, r, k, pre, k, dp );
        }
        else{
            // Split i to j elements into k plies-> dp(i,j,k) = dp(i,t,1) + dp(t+1,j,k-1)
            for( i = l; i < r; i++ ){
                cost = min( cost, merge( l, i, 1, pre, k, dp ) + merge( i+1, r, pile-1, pre, k, dp ) );
            }
            ans = cost;
        }
        return dp[l][r][pile] = ans;
    }
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size(), i;
        if( (n-1)%(k-1) != 0 )return -1;
        vector<vector<vector<int>>> dp( n+1, vector<vector<int>> ( n+1, vector<int> ( k+1, -1 ) ) );
        
        // Find Prefix sum
        for( i = 1; i < n; i++ )stones[i] += stones[i-1];
        // From 0 to (n-1) range, to make 1 pile of stones by merging k piles at a time
        return merge( 0, n-1, 1, stones, k, dp );
    }
};
