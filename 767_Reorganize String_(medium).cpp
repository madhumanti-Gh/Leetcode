class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq( 26, 0 );
        for( char& c : s )freq[c-'a']++;
        
        int i, a, b, c, d;
        priority_queue<pair<int, int>> pq;
        for( i = 0; i < 26; i++ ){
            if( freq[i] > 0 )pq.push({ freq[i], i });
        }
        
        pair<int, int> mx, cur;
        s = "";
        while( !pq.empty() ){
            mx = pq.top();pq.pop();
            a = mx.first;
            b = mx.second;
            s.push_back( b + 'a' );
            a--;
            if( !pq.empty() ){
                cur = pq.top();pq.pop();
                c = cur.first;
                d = cur.second;
                s.push_back( d + 'a' );
                c--;
                if( c > 0 )pq.push({ c, d });
            }
            if( a > 0 )pq.push({ a, b });
        }
        a = s.size();
        for( i = 1; i < a; i++ ){
            if( s[i] == s[i-1] )return "";
        }
        return s;
    }
};
