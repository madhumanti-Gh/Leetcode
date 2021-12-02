// Top-Down Approach
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int Sum = 0, n = nums.size();
        if( n == 1 )return false;
        for( int i = 0; i < n; i++ ){
            Sum += nums[i];
        }
        if( Sum%2 == 1 )return false;
        Sum = Sum/2;
        vector<vector<bool>> dp(n+1, vector<bool> ( Sum+1, 0) );
        for( int i = 0; i <= n; i++ ){
            dp[i][0] = true;
        }
        for( int j = 1; j <= Sum; j++ ){
            dp[0][j] = false;
        }
        for( int i = 1; i <= n; i++ ){
            for( int j = 1; j <= Sum; j++ ){
                if( nums[i-1] <= j ){
                    dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][Sum];
    }
};

// Using Recursion
class Solution {
public:
    int dp[203][30000];
    bool subsetSum( vector<int>& nums, int sum, int Sum, int n ){
        if( dp[n][sum] != -1 )return dp[n][sum];
        if( n == 0 ){
            if( sum == Sum/2 )return true;
            return false;
        }
        return dp[n][sum] = subsetSum( nums, sum+ nums[n-1], Sum, n-1 ) || subsetSum( nums, sum, Sum, n-1 );
    }
    bool canPartition(vector<int>& nums) {
        int Sum = 0, n = nums.size();
        if( n == 1 )return false;
        for( int i = 0; i < n; i++ ){
            Sum += nums[i];
        }
        if( Sum%2 == 1 )return false;
        memset( dp, -1, sizeof(dp) );
        return subsetSum( nums, 0, Sum, nums.size() );
    }
};
