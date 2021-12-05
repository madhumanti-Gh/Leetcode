class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> range(2);
        range[0] = INT_MAX;
        range[1] = INT_MIN;
        int k = nums.size(), count = 0, i, j, sz;
        vector<pair<int, int>> arr;
        for( i = 0; i < k; i++ ){
            sz = nums[i].size();
            for( j = 0; j < sz; j++ ){
                arr.push_back({ nums[i][j], i });
                range[0] = min( range[0], nums[i][j] );
                range[1] = max( range[1], nums[i][j] );
            }
        }
        sort( arr.begin(), arr.end() );
        sz = arr.size();
        vector<int> vis(k,0);
        i = 0;j = 0;
        while( i <= j && j < sz ){
            if( vis[arr[j].second] == 0 )count++;
            vis[arr[j].second]++;
            while( count == k && i <= j ){
                if( (arr[j].first - arr[i].first) < ( range[1] - range[0]) ){
                    range[0] = arr[i].first;
                    range[1] = arr[j].first;
                }
                vis[arr[i].second]--;
                if( vis[arr[i].second] == 0 )count--;
                i++;
            }
            j++;
        }
        return range;
    }
};
