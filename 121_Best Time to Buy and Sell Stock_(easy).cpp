class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i, mn = INT_MAX, profit = 0;
        for( i = 0; i < n; i++ ){
            mn = min( mn, prices[i] );
            profit = max( profit, prices[i] - mn );
        }
        return profit;
    }
};
