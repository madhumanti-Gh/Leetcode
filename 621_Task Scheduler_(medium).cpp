class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int i, Tidle, mx;
        vector<int> freq( 26, 0 );
        for( auto& c : tasks )freq[c - 'A']++;
        sort( freq.begin(), freq.end() );
        mx = freq[25];
        Tidle = ( mx - 1 ) *n;
        for( i = 24; i >= 0; i-- ){
            if( freq[i] > 0 )Tidle -= min( mx-1, freq[i] );
        }
        if( Tidle < 0 )return tasks.size();
        return tasks.size() + Tidle;
    }
};
