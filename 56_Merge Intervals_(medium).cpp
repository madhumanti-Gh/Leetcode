class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort( intervals.begin(), intervals.end() );
        pair<int, int> p = { intervals[0][0], intervals[0][1] };
        vector<vector<int>> ans;
        int n = intervals.size(), i;
        for( i = 1; i < n; i++ ){
            if( intervals[i][0] <= p.second ){
                p.second = max( p.second, intervals[i][1] );
            }
            else{
                ans.push_back({ p.first, p.second });
                p = { intervals[i][0], intervals[i][1] };
            }
        }
        ans.push_back({ p.first, p.second });
        return ans;
    }
};
