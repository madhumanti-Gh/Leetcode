class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int n = heights.size(), i, dif;
        for( i = 1; i < n; i++ ){
            dif = heights[i] - heights[i-1];
            if( dif <= 0 )continue;
            if( pq.size() < ladders )pq.push( dif * (-1) );
            else{
                int cur_bricks = dif;
                if( pq.size() > 0 && abs( pq.top() ) < dif ){
                    cur_bricks = pq.top() * (-1);
                    pq.pop();
                    pq.push( dif * (-1) );
                }
                if( bricks >= cur_bricks )bricks -= cur_bricks;
                else return i - 1;
            }
        }
        return n-1;
    }
};
