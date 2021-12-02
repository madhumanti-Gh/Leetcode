// Top-Down Approach
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 )return nums[0];
        if( n == 2 )return max( nums[0], nums[1] );
        vector<int> dp = nums;
        dp[n-2] = max( nums[n-2], nums[n-1] );
        for( int i = n-3; i >= 0; i-- ){
            dp[i] = max( dp[i+1], dp[i+2] + dp[i] );
        }
        return dp[0];
    }
};

// Using Recursion
class Solution {
public:
    int dp[102];
    int house( vector<int>& nums, int money, int n ){
        
        if( n <= 0 )return 0;
        if( dp[n] != -1 )return dp[n];
        int ans;
        return dp[n] = max( house( nums, money, n-1 ), nums[n-1] + house( nums, money, n-2 ) );
    }
    int rob(vector<int>& nums) {
        memset( dp, -1, sizeof(dp) );
        return house( nums, 0, nums.size() );
    }
};
