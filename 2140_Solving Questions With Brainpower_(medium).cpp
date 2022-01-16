class Solution {
private:
    long long Points( vector<vector<int>>& qs, int id, vector<long long>& dp ){
        int n = qs.size();
        if( id >= n )return 0;
        if( dp[id] != -1 )return dp[id];
        long long ans = 0;
        long long isSkipped = Points( qs, id+1, dp );
        long long notSkipped = qs[id][0] + Points( qs, id+qs[id][1]+1, dp );
        return dp[id] = max( isSkipped, notSkipped );
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp( n+1, -1 );
        return Points( questions, 0, dp );
    }
};
