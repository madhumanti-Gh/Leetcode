class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i;
        long long max_profit = 0, profit = 0, mn = (long long)prices[0], mx = (long long)prices[n-1];
        long long B2S[n], S2B[n];
        B2S[0] = 0;
        S2B[n-1] = 0;
        for( i = 1; i < n; i++ ){
            mn = min( (long long)prices[i], mn );
            mx = max( (long long)prices[n-1-i], mx );
            profit = prices[i] - mn;
            max_profit = max( max_profit, profit );
            B2S[i] = max( B2S[i-1], profit );
            S2B[n-1-i] = max( S2B[n-i], mx - prices[n-1-i] );
        }
        for( i = 1; i < n; i++ ){
            profit = B2S[i-1] + S2B[i];
            max_profit = max( max_profit, profit );
        }
        return max_profit;
    }
};
