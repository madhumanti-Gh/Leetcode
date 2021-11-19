class Solution {
public:
    int dp[1002];
    int cal_cost( vector<int>& cost, int n ){
        if( (n == cost.size() -1 ) || ( n == cost.size() -2 ) )return cost[n];
        if( dp[n] != -1 )return dp[n];
        int ans = min( cost[n] + cal_cost( cost, n+1 ) , cost[n] + cal_cost( cost, n+2 ) );
        return dp[n] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset( dp, -1, sizeof(dp) );
        int ans = min( cal_cost( cost, 0 ), cal_cost( cost, 1 ) );
        return ans;
    }
};
