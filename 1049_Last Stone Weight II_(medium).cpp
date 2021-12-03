class Solution {
public:
    void subsetSum( vector<int>& stones, int n, int sum, vector<vector<bool>>& dp ){
        int i, j;
        for( i = 0; i <= n; i++ ){
            dp[i][0] = true;
        }
        for( j = 1; j <= sum; j++ ){
            dp[0][j] = false;
        }
        for( i = 1; i <= n; i++ ){
            for( j = 1; j <= sum; j++ ){
                if( stones[i-1] <= j ){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j- stones[i-1]];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
    }
    int lastStoneWeightII(vector<int>& stones) {
        int i, diff, sum = 0, min_dif = INT_MAX, n = stones.size();
        if( n == 1 )return stones[0];
        if( n == 2 )return max(stones[0], stones[1]) - min(stones[0], stones[1]);
	    for( i = 0; i < n; i++ ){
	        sum += stones[i];
	    }
	    vector<vector<bool>> dp(n+1, vector<bool> (sum+1, 0) );
	    subsetSum( stones, n, sum, dp );
	    for( i = 0; i <= (sum)/2; i++ ){
	        if( dp[n][i] == true ){
	            diff = abs( sum - (2*i) );
	            min_dif = min( min_dif, diff );
	        }
	    }
	    return min_dif;
    }
};
