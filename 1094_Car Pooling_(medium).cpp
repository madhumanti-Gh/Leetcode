class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size(), i, cur_pass = 0;
        map<int, int> mp;
        for( i = 0; i < n; i++ ){
            mp[trips[i][1]] += trips[i][0];
            mp[trips[i][2]] -= trips[i][0];
        }
        for( auto& passanger : mp ){
            cur_pass += passanger.second;
            if( cur_pass > capacity )return false;
        }
        return true;
    }
};
