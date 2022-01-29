class Solution {
public:
    int numberOfWays(string corridor) {
        int seat = 0, n = corridor.size(), i = 0;
        long long ways = 1, s = 0, M = 1000000007;
        
        while( i < n ){
            if( corridor[i] == 'S' )seat++;
            i++;
            if( seat > 0 && seat%2 == 0 ){
                s = 0;
                while( i < n && corridor[i] == 'P' ){
                    s++;
                    i++;
                }
                s++;
                if( i == n && corridor[i-1] == 'P' )s = 1;
                ways = ( (ways%M) * (s%M) )%M;
            }
        }
        if( seat == 0 || seat%2 != 0 )return 0;
        
        return ways;
    }
};
