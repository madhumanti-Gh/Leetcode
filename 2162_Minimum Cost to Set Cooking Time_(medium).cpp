class Solution {
private:
    int findCost( int startAt, int moveCost, int pushCost, int time ){
        int cost = 0;
        char prev = startAt + '0';
        string s = to_string( time );
        for( char& c : s ){
            if( c != prev )cost += moveCost;
            cost += pushCost;
            prev = c;
        }
        return cost;
    }
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int minute = 0, sec = 0, minCost = INT_MAX;
        minute = targetSeconds/60;
        sec = targetSeconds%60;
        if( minute > 99 ){
            minute = 99;
            sec += 60;
        }
        minCost = min( minCost, findCost( startAt, moveCost, pushCost, minute*100 +sec ) );
        if( minute > 0 && sec <= 39 ){
            minute -= 1;
            sec += 60;
            minCost = min( minCost, findCost( startAt, moveCost, pushCost, minute*100 +sec ) );
        }
        return minCost;
    }
};
