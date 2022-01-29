// Iterative approach
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<pair<int, int>> mxh;    // element, index
        int n = target.size(), i, high, id;
        long sum = 0, dif = 0;
        for( i = 0; i < n; i++ ){
            sum += target[i];
            mxh.push({ target[i], i });
        }
        pair<int, int> cur;
        while( sum > n ){
            high = mxh.top().first;
            id = mxh.top().second;
            mxh.pop();
            dif = sum - high;
            if( dif == 1 || high == 1 )return true;
            if( dif == 0 || high%dif == 0 || dif > high )return false;
            cur.first = high%dif;
            cur.second = id;
            sum -= ( high - cur.first );
            mxh.push( cur );
        }
        if( mxh.top().first == 1 )return true;
        return false;
    }
};

// Recurssive approach
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size(), i, mx = 0;
        long sum = 0, dif = 0;
        for( i = 0; i < n; i++ ){
            sum += target[i];
            if( target[i] > target[mx] )mx = i;
        }
        dif = sum - target[mx];
        if( target[mx] == 1 || dif == 1 )return true;
        if( dif > target[mx] || dif == 0 || target[mx]%dif == 0 )return false;
        target[mx] %= dif;
        
        return isPossible( target );
    }
};
