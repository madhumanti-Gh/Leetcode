class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int i = 0, count = 0, n = costs.size();
        sort( costs.begin(), costs.end() );
        while( i < n && coins >= costs[i] ){
            count++;
            coins -= costs[i];
            i++;
        }
        return count;
    }
};
