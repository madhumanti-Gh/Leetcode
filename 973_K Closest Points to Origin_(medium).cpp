class Solution {
public:
    int find_dist( int x, int y ){
        return (x*x)+(y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> maxh;
        int n = points.size(), i, d;
        for( i = 0; i < n; i++ ){
            d = find_dist( points[i][0], points[i][1] );
            maxh.push({ d, i });
            if( maxh.size() > k )maxh.pop();
        }
        while( maxh.size() > 0 ){
            ans.push_back( points[maxh.top().second] );
            maxh.pop();
        }
        return ans;
    }
};
