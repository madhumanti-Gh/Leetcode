// O(N) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i;
        vector<int> no_stock( n, 0 ), in_hand( n, 0 ), sold( n, 0 );
        in_hand[0] = - prices[0];
        for( i = 1; i < n; i++ ){
            no_stock[i] = max( no_stock[i-1], sold[i-1] );
            in_hand[i] = max( ( no_stock[i-1] - prices[i] ), in_hand[i-1] );
            sold[i] = prices[i] + in_hand[i-1];
        }
        return max( no_stock[n-1], sold[n-1] );
    }
};


// O(1) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i, no_stock_prev = 0, in_hand_prev = 0- prices[0], sold_prev = 0, no_stock, in_hand, sold;
        for( i = 1; i < n; i++ ){
            no_stock = max( no_stock_prev, sold_prev );
            in_hand = max( ( no_stock_prev - prices[i] ), in_hand_prev );
            sold = prices[i] + in_hand_prev;
            no_stock_prev = no_stock;
            in_hand_prev = in_hand;
            sold_prev = sold;
        }
        return max( no_stock, sold );
    }
};
