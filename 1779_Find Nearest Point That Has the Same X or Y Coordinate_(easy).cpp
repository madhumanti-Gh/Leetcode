class Solution {
public:
    int find_dist( int x1, int y1, int x2, int y2 ){
        return abs(x1-x2) + abs(y1-y2);
    }
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size(), d, i, min_dist = INT_MAX, idx = -1;
        for( i = 0; i < n; i++ ){
            if( points[i][0] == x || points[i][1] == y ){
                d = find_dist( x, y, points[i][0], points[i][1] );
                if( min_dist > d ){
                    min_dist = d;
                    idx = i;
                }
            }
        }
        return idx;
    }
};
