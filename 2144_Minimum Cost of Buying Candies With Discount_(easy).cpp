class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort( cost.begin(), cost.end() );
        int n = cost.size(), i, ans = 0;
        i = 0; n = n%3;
        while( n > 0 ){
            ans += cost[i];
            i++;n--;
        }
        n = cost.size();
        for( i = n-3; i >= 0; i -= 3 ){
            ans += cost[i+2];
            ans += cost[i+1];
        }
        return ans;
    }
};
