class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;
        for( int stone : stones ){
            maxh.push( stone );
        }
        int x,y;
        while( maxh.size() > 1 ){
            x = maxh.top();
            maxh.pop();
            y = maxh.top();
            maxh.pop();
            if( x > y )maxh.push( x-y );
        }
        if( maxh.size() == 0 )return 0;
        return maxh.top();
    }
};
