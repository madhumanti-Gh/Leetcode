class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        long long M = 1000000007;
        sort( inventory.begin(), inventory.end() );
        int n = inventory.size(), i = n-1;
        long long profit = 0, dif, count, l, r;
        
        for( i = n-1; i >= 0; i-- ){
            if( i > 0 )dif = inventory[i] - inventory[i-1];
            else dif = inventory[i];
            count = min( (long long)orders, (n-i)* dif );
            r = inventory[i];
            l = r-count/(n-i);
            profit += ( ( r * ( r+1 )/2 - l* (l+1)/2 ) * (n-i) );
            profit %= M;
            profit += ( l* ( count%(n-i) ) );
            profit %= M;
            orders -= count;
        }
        return profit;
    }
};
