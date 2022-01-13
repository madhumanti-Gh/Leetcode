class Solution {
private:
    bool static compare( vector<int>& a, vector<int>& b ){
        if( a[1] < b[1] )return true;
        return false;
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort( points.begin(), points.end(), compare );
        int count = 1, End = points[0][1];
        for( auto& point : points ){
            if( point[0] > End ){
                count++;
                End = point[1];
            }
        }
        return count;
    }
};
