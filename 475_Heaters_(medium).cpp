class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort( heaters.begin(), heaters.end() );
        sort( houses.begin(), houses.end() );
        int n = houses.size(), m = heaters.size(), i, max_Rad = INT_MIN, right, cur_rad;
        for( i = 0; i < n; i++ ){
            right = lower_bound( heaters.begin(), heaters.end(), houses[i] ) - heaters.begin();
            cur_rad = INT_MAX;
            // find heater at the house-position or next right to the house
            if( right != m )cur_rad = abs(heaters[right] - houses[i]);
            // find next left heater to the house
            // find minimum distance of right & left heaters with the house
            if( right != 0 )cur_rad = min( cur_rad, abs( heaters[right-1] - houses[i] ) );
            // store overall maximum distance of closest heater
            max_Rad = max( max_Rad, cur_rad );
        }
        return max_Rad;
    }
};
